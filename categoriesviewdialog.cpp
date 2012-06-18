#include <QtGui>
#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QModelIndex>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "categoriesviewdialog.h"
#include "categorieschangedialog.h"
#include "ui_categoriesviewdialog.h"

categoriesViewDialog::categoriesViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesViewDialog)
{
    ui->setupUi(this);
    getCategoriesList();
}

void categoriesViewDialog::getCategoriesList(){

    QSqlDatabase::database();

    QSqlQueryModel *getCategories = new QSqlQueryModel(0);
    getCategories->setQuery("SELECT category_id, name, altname, code, deleted  FROM categories WHERE deleted='false'");
    getCategories->setHeaderData(0,Qt::Horizontal, QObject::trUtf8("Category ID"));
    getCategories->setHeaderData(1,Qt::Horizontal, QObject::trUtf8("Name"));
    getCategories->setHeaderData(2,Qt::Horizontal, QObject::trUtf8("AltName"));
    getCategories->setHeaderData(3,Qt::Horizontal, QObject::trUtf8("Code"));
    getCategories->setHeaderData(4,Qt::Horizontal, QObject::trUtf8("Deleted"));
    if(getCategories->lastError().isValid())
        qDebug() << getCategories->lastError();
    ui->categoryTableView->setModel(getCategories);
    ui->categoryTableView->hideColumn(4);
    ui->categoryTableView->verticalHeader()->hide(); //после дебага убрать камент
    qDebug() << "Get Gategory List";
}

void categoriesViewDialog::getCategoryID(){
    QModelIndex indexRow = ui->categoryTableView->currentIndex(); //получаем текущее положение курсора
    int selectedRow = indexRow.row(); //получаем значение сторки
    int selectedColumn = 0; //0-потому что колонка с ID всегда идёт первой
    currentID = ui->categoryTableView->model()->data(ui->categoryTableView->model()->index(selectedRow,selectedColumn)).toInt(); //получаем categoryID из ячейки
    qDebug() << trUtf8("Current ID:") << currentID; //debug
}

void categoriesViewDialog::categoryAdd(){
    categoriesChangeDialog dialog(this);
    dialog.categoryInsert();
    dialog.exec();
    if(dialog.close())
    getCategoriesList();
}

void categoriesViewDialog::categoryModify(){
    getCategoryID();

    QSqlQuery *getCategory = new QSqlQuery();
    getCategory->prepare("SELECT category_id, name, altname, code FROM "
                           "public.categories "
                         "WHERE "
                         "categories.deleted = 'false' AND "
                           "categories.category_id=:categoryID");
    getCategory->bindValue(":categoryID",currentID);
    getCategory->exec();
       if(getCategory->lastError().isValid()) //временный камент для отладки, потом вернуть назад.
    qDebug() << trUtf8("Запрос:") << getCategory->executedQuery();

    while (getCategory->next()){
        categoryID = getCategory->value(0).toInt();
        name = getCategory->value(1).toString();
        altname = getCategory->value(2).toString();
        code = getCategory->value(3).toInt();
        qDebug() << "Category ID:" << categoryID;
        qDebug() << "Name:" << name;
        qDebug() << "altName:" << altname;
        qDebug() << "Code:" << code;
    }

    categoriesChangeDialog dialog(this);
    dialog.categoryMod(categoryID,name,altname,code);
    dialog.exec();
    if(dialog.close())
    getCategoriesList();
}

void categoriesViewDialog::categoryDelete(){
    getCategoryID();

    QSqlQuery *removeCategory = new QSqlQuery();
    removeCategory->prepare("UPDATE categories SET deleted='true' "
                         "where category_id=:categoryID");
    removeCategory->bindValue(":categoryID",currentID);
    removeCategory->exec();
        if(removeCategory->lastError().isValid()) //временный камент для отладки, потом вернуть назад.
    qDebug() << trUtf8("Запрос:") << removeCategory->executedQuery();
    qDebug() << trUtf8("Ошибка:") << removeCategory->lastError();
    getCategoriesList();
}

categoriesViewDialog::~categoriesViewDialog()
{
    delete ui;
}
