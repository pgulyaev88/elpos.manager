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
#include "categorieschangedialog.h"
#include "ui_categorieschangedialog.h"

categoriesChangeDialog::categoriesChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesChangeDialog)
{
    ui->setupUi(this);
}

void categoriesChangeDialog::categoryNew(){
    categoriesCode = ui->categoriesCodeLineEdit->text().toInt();
    categoriesName = ui->categoriesNameLineEdit->text();
    categoriesAltName = ui->categoriesAltNameLineEdit->text();

    qDebug() << "Code: " << categoriesCode; //отладка
    qDebug() << "Name: " << categoriesName; //отладка
    qDebug() << "AltName: " << categoriesAltName; //отладка

    QSqlDatabase::database();
    QSqlQuery *queryCategoryAdd = new QSqlQuery;

    queryCategoryAdd->prepare("INSERT INTO categories (category_id,name,alt_name,code,deleted)  VALUES(nextval('categories_category_id_seq'::regclass), :categoriesName, :categoriesAltName, :categoriesCode, false)");
    queryCategoryAdd->bindValue(":categoriesName", categoriesName);
    queryCategoryAdd->bindValue(":categoriesAltName",categoriesAltName);
    queryCategoryAdd->bindValue(":categoriesCode",categoriesCode);
    queryCategoryAdd->exec();
//    if(queryCategoryAdd->lastError().isValid()) //временный камент для отладки, потом вернуть назад.
        qDebug() << queryCategoryAdd->lastError();

    categoriesChangeDialog::close();

}

void categoriesChangeDialog::categoryMod(){

}

categoriesChangeDialog::~categoriesChangeDialog()
{
    delete ui;
}
