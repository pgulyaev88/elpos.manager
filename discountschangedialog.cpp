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
#include "discountschangedialog.h"
#include "ui_discountschangedialog.h"

discountsChangeDialog::discountsChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountsChangeDialog)
{
    ui->setupUi(this);
}

void discountsChangeDialog::discountNew(){
    connect(ui->discountsButtonBox,SIGNAL(accepted()),this,SLOT(discountInsert()));
    discountsChangeDialog::setWindowTitle("Adding new discounts");
}

void discountsChangeDialog::discountEdit(int discountsID, QString discountsName, QString discountsPercent){
    connect(ui->discountsButtonBox,SIGNAL(accepted()),this,SLOT(discountUpdate()));
    discountsChangeDialog::setWindowTitle("Modify discounts");
    ui->discountsIdLineEdit->setText(QString::number(discountsID));
    ui->discountsNameLineEdit->setText(discountsName);
    ui->discountsPercentLineEdit->setText(QString::number(discountsPercent.toDouble(),'f',2));
}

void discountsChangeDialog::discountInsert(){
    discountsName = ui->discountsNameLineEdit->text();
//    discountsPercent = ui->discountsPercentLineEdit->text().toDouble();
    discountsPercent = QString::number(ui->discountsPercentLineEdit->text().toDouble(),'f',2);
//    qDebug() << "Percent:" << QString::number(ui->discountsPercentLineEdit->text().toDouble(),'f',2);

    qDebug() << "Name: " << discountsName;
    qDebug() << "Percent: " << discountsPercent;

    QSqlDatabase::database();
    QSqlQuery *insertDiscount = new QSqlQuery;

    insertDiscount->prepare("SELECT public.\"DiscountAdd\"(:discount_name, :discount_percent)");
    insertDiscount->bindValue(":discount_name", discountsName);
    insertDiscount->bindValue(":discount_percent", discountsPercent);
    insertDiscount->exec();
    if(insertDiscount->lastError().isValid())
        qDebug() << insertDiscount->lastError();
        qDebug() << insertDiscount->executedQuery();
    discountsChangeDialog::close();

}

void discountsChangeDialog::discountUpdate(){
    discountsID = ui->discountsIdLineEdit->text().toInt();
    discountsName = ui->discountsNameLineEdit->text();
    discountsPercent = QString::number(ui->discountsPercentLineEdit->text().toDouble(),'f',2);

    QSqlDatabase::database();
    QSqlQuery *updateDiscounts = new QSqlQuery;
    updateDiscounts->prepare("SELECT public.\"DiscountMod\"(:discount_id,:discount_name,:discount_percent)");
    updateDiscounts->bindValue(":discount_id", discountsID);
    updateDiscounts->bindValue(":discount_name", discountsName);
    updateDiscounts->bindValue(":discount_percent", discountsPercent);
    updateDiscounts->exec();
//    if(updateDiscounts->lastError().isValid())
        qDebug() << updateDiscounts->executedQuery();
        qDebug() << updateDiscounts->lastError();
//    discountsChangeDialog::close();
}

discountsChangeDialog::~discountsChangeDialog()
{
    delete ui;
}
