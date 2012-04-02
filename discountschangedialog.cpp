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
#include "discountschangedialog.h"
#include "ui_discountschangedialog.h"

discountsChangeDialog::discountsChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountsChangeDialog)
{
    ui->setupUi(this);
}

void discountsChangeDialog::discountNew(){
    discountName = ui->discountsNameLineEdit->text();
    discountPercent = ui->discountsPercentLineEdit->text().toFloat();

    qDebug() << "Name: " << discountName;
    qDebug() << "Percent: " << discountPercent;

    QSqlDatabase::database();
    QSqlQuery *queryDiscountAdd = new QSqlQuery;

    queryDiscountAdd->prepare("INSERT INTO discounts (discount_id, discount_name, discount_percent, deleted)"
                              "VALUES (nextval('discounts_discount_id_seq'::regclass), :discount_name, :discount_percent, false)");
    queryDiscountAdd->bindValue(":discount_name", discountName);
    queryDiscountAdd->bindValue(":discount_percent", discountPercent);
//    if(queryDiscountAdd->lastError().isValid())
        qDebug() << queryDiscountAdd->lastError();
//    discountsChangeDialog::close();

}

void discountsChangeDialog::discountMod(){

}

discountsChangeDialog::~discountsChangeDialog()
{
    delete ui;
}
