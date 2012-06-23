#include <QtGui>
#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDialog>
#include <QModelIndex>
#include <QSqlQueryModel>
#include <QSqlError>
#include "categoriesviewdialog.h"
#include "categorieschangedialog.h"
#include "ui_categorieschangedialog.h"

categoriesChangeDialog::categoriesChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesChangeDialog)
{
    ui->setupUi(this);
}

void categoriesChangeDialog::categoryNew(){
    connect(ui->categoriesButtonBox,SIGNAL(accepted()),this,SLOT(categoryInsert()));
}

void categoriesChangeDialog::categoryEdit(int categoryID, QString name, QString altname, int code){
    connect(ui->categoriesButtonBox,SIGNAL(accepted()),this,SLOT(categoryUpdate()));
    ui->categoriesNameLineEdit->setText(name);
    ui->categoriesAltNameLineEdit->setText(altname);
    ui->categoriesCodeLineEdit->setText(QString::number(code));
    ui->categoriesIdLineEdit->setText(QString::number(categoryID));
}

void categoriesChangeDialog::categoryInsert(){
    qDebug() << trUtf8("Add Category");
    categoriesCode = ui->categoriesCodeLineEdit->text().toInt();
    categoriesName = ui->categoriesNameLineEdit->text();
    categoriesAltName = ui->categoriesAltNameLineEdit->text();

    qDebug() << "Code: " << categoriesCode; //отладка
    qDebug() << "Name: " << categoriesName; //отладка
    qDebug() << "AltName: " << categoriesAltName; //отладка

    QSqlDatabase::database();
    QSqlQuery *queryCategoryAdd = new QSqlQuery;

    queryCategoryAdd->prepare("INSERT INTO categories (category_id,name,altname,code,deleted) "
                              "VALUES(nextval('categories_category_id_seq'::regclass), "
                              ":categoriesName, :categoriesAltName, :categoriesCode, false)");
    queryCategoryAdd->bindValue(":categoriesName", categoriesName);
    queryCategoryAdd->bindValue(":categoriesAltName",categoriesAltName);
    queryCategoryAdd->bindValue(":categoriesCode",categoriesCode);
    queryCategoryAdd->exec();
    if(queryCategoryAdd->lastError().isValid()) //временный камент для отладки, потом вернуть назад.
    qDebug() << queryCategoryAdd->lastError();
    qDebug() << trUtf8("Запрос:") << queryCategoryAdd->executedQuery();

    categoriesChangeDialog::close();

}

void categoriesChangeDialog::categoryUpdate(){
    qDebug() << "Update Category";
    categoriesCode = ui->categoriesCodeLineEdit->text().toInt();
    categoriesName = ui->categoriesNameLineEdit->text();
    categoriesAltName = ui->categoriesAltNameLineEdit->text();
    categoriesID = ui->categoriesIdLineEdit->text().toInt();
    qDebug() << "Category ID:" << categoriesID;
    qDebug() << "Code: " << categoriesCode; //отладка
    qDebug() << "Name: " << categoriesName; //отладка
    qDebug() << "AltName: " << categoriesAltName; //отладка

    QSqlDatabase::database();
    QSqlQuery *updateCategory = new QSqlQuery;
    updateCategory->prepare("UPDATE categories SET "
                            "name=:categoriesName, "
                            "altname=:categoriesAltName, "
                            "code=:categoriesCode "
                            "WHERE deleted='false' "
                            "AND category_id=:categoriesID");
    updateCategory->bindValue(":categoriesID",categoriesID);
    updateCategory->bindValue(":categoriesCode",categoriesCode);
    updateCategory->bindValue(":categoriesName",categoriesName);
    updateCategory->bindValue(":categoriesAltName",categoriesAltName);
    updateCategory->exec();
    if(updateCategory->lastError().isValid())  //временный камент для отладки
    qDebug() << updateCategory->lastError();
    qDebug() << updateCategory->executedQuery();

    categoriesChangeDialog::close();
}

categoriesChangeDialog::~categoriesChangeDialog()
{
    delete ui;
}
