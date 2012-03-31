#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "currencysviewdialog.h"
#include "currencyschangedialog.h"
#include "ui_currencysviewdialog.h"

currencysViewDialog::currencysViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currencysViewDialog)
{
    ui->setupUi(this);
    getCurrenciesList();
}

void currencysViewDialog::getCurrenciesList(){

    QSqlDatabase::database();

    QSqlQueryModel *getCurrencies = new QSqlQueryModel;
    getCurrencies->setQuery("SELECT * FROM currencys");
    if(getCurrencies->lastError().isValid())
        qDebug() << getCurrencies->lastError();

    ui->currencysTableView->setModel(getCurrencies);
}

void currencysViewDialog::currensiesAdd(){
    currencysChangeDialog dialog(this);
    dialog.exec();
}

void currencysViewDialog::currensiesModify(){
    currencysChangeDialog dialog(this);
    dialog.exec();
}

void currencysViewDialog::currensiesDelete(){
    currencysChangeDialog dialog(this);
    dialog.exec();
}

currencysViewDialog::~currencysViewDialog()
{
    delete ui;
}
