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
}

void categoriesViewDialog::categoryAdd(){
    categoriesChangeDialog dialog(this);
    dialog.exec();
    if(dialog.close())
    getCategoriesList();
}

void categoriesViewDialog::categoryModify(){

//    QSqlDatabase::database();

    QModelIndex indexRow = ui->categoryTableView->currentIndex();
    int selectedRow = indexRow.row();
    int selectedColumn = 0;
    //
    qDebug() << trUtf8("Строка:") << selectedRow;
//    qDebug() << trUtf8("ID из БД:") << ui->categoryTableView->model()->data(ui->categoryTableView->model()->index(selectedRow,selectedColumn)).toString();
    //
    int ID = ui->categoryTableView->model()->data(ui->categoryTableView->model()->index(selectedRow,selectedColumn)).toInt();
    //
    qDebug() << trUtf8("ID из БД:") << ID;
    //
    QSqlQuery *getCategory = new QSqlQuery();
    getCategory->prepare("SELECT category_id, name, altname, code FROM "
                           "public.categories "
                         "WHERE "
                         "categories.deleted = 'false' AND "
                           "categories.category_id=:categoryID");
    getCategory->bindValue(":categoryID",ID);
    getCategory->exec();
//    if(queryCategoryAdd->lastError().isValid()) //временный камент для отладки, потом вернуть назад.

    qDebug() << trUtf8("Запрос:") << getCategory->executedQuery();
    qDebug() << trUtf8("Запрос:") << getCategory->lastQuery();
    qDebug() << trUtf8("Ошибка:") << getCategory->lastError();


    while (getCategory->next()){
        int categoryID = getCategory->value(0).toInt();
        QString name = getCategory->value(1).toString();
        QString altName = getCategory->value(2).toString();
        int code = getCategory->value(3).toInt();
        qDebug() << "Category ID:" << categoryID;
        qDebug() << "Name:" << name;
        qDebug() << "altName:" << altName;
        qDebug() << "Code:" << code;

//        categoriesChangeDialog::categoryMod(categoryID, name, altName, code);
    }



}

void categoriesViewDialog::categoryDelete(){
//    categoriesChangeDialog dialog(this);
//    dialog.exec();

    QModelIndex indexRow = ui->categoryTableView->currentIndex();
    int selectedRow = indexRow.row();
    int selectedColumn = 0;
    qDebug() << trUtf8("Строка:") << selectedRow;
    qDebug() << trUtf8("ID из БД:") << ui->categoryTableView->model()->data(ui->categoryTableView->model()->index(selectedRow,selectedColumn)).toString();
    int ID = ui->categoryTableView->model()->data(ui->categoryTableView->model()->index(selectedRow,selectedColumn)).toInt();
    qDebug() << trUtf8("ID из БД:") << ID;

    QSqlQuery *removeCategory = new QSqlQuery();
    removeCategory->prepare("UPDATE categories SET deleted='true' "
                         "where category_id=:categoryID");
    removeCategory->bindValue(":categoryID",ID);
    removeCategory->exec();
//    if(queryCategoryAdd->lastError().isValid()) //временный камент для отладки, потом вернуть назад.
    qDebug() << trUtf8("Запрос:") << removeCategory->executedQuery();
    qDebug() << trUtf8("Запрос:") << removeCategory->lastQuery();
    qDebug() << trUtf8("Ошибка:") << removeCategory->lastError();
    getCategoriesList();
}

categoriesViewDialog::~categoriesViewDialog()
{
    delete ui;
}
