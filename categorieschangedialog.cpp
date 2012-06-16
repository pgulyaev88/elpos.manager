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
#include <QSqlRelationalTableModel>
#include <QSqlQueryModel>
#include <QSqlError>
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

    queryCategoryAdd->prepare("INSERT INTO categories (category_id,name,altName,code,deleted)  VALUES(nextval('categories_category_id_seq'::regclass), :categoriesName, :categoriesAltName, :categoriesCode, false)");
    queryCategoryAdd->bindValue(":categoriesName", categoriesName);
    queryCategoryAdd->bindValue(":categoriesAltName",categoriesAltName);
    queryCategoryAdd->bindValue(":categoriesCode",categoriesCode);
    queryCategoryAdd->exec();
//    if(queryCategoryAdd->lastError().isValid()) //временный камент для отладки, потом вернуть назад.
    qDebug() << queryCategoryAdd->lastError();
    qDebug() << trUtf8("Запрос:") << queryCategoryAdd->executedQuery();

    categoriesChangeDialog::close();

}

double categoriesChangeDialog::categoryMod(int categoryID, QString name, QString altname, int code){
     ui->categoriesNameLineEdit->setText(name);
     ui->categoriesAltNameLineEdit->setText(altname);
     ui->categoriesCodeLineEdit->setText(QString::number(code));
     categoriesChangeDialog dialog(this);
     dialog.exec();



}

categoriesChangeDialog::~categoriesChangeDialog()
{
    delete ui;
}
