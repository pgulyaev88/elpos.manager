#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "currencysviewdialog.h"
#include "ui_currencysviewdialog.h"

currencysViewDialog::currencysViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currencysViewDialog)
{
    ui->setupUi(this);
    getCurencysList();
}

void currencysViewDialog::getCurencysList(){

    QSqlDatabase::database();

    QSqlQueryModel *getCurencys = new QSqlQueryModel;
    getCurencys->setQuery("SELECT * FROM currencys");
    if(getCurencys->lastError().isValid())
        qDebug() << getCurencys->lastError();

    ui->currencysTableView->setModel(getCurencys);
}

currencysViewDialog::~currencysViewDialog()
{
    delete ui;
}
