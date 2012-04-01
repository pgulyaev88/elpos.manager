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
#include "currencyschangedialog.h"
#include "ui_currencyschangedialog.h"

currencysChangeDialog::currencysChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currencysChangeDialog)
{
    ui->setupUi(this);
}

void currencysChangeDialog::currensiesNew(){

    currencyName = ui->currenciesNameLineEdit->text();
    currencyAltName = ui->currenciesAltName->text();
    currencyRate = ui->currenciesRateLineEdit->text().toInt();
    currencyCode = ui->currenciesCodeLineEdit->text().toInt();
    currencyNational = ui->currenciesNationalCurrensyCheckBox->checkState();

    qDebug() << "Name: " << currencyName; //отладка
    qDebug() << "AltName: " << currencyAltName; //отладка
    qDebug() << "Rate: " << currencyRate; //отладка
    qDebug() << "Code: " << currencyCode; //отладка
    qDebug() << "NationalCheck: " << currencyNational; //отладка

    QSqlDatabase::database();
    QSqlQuery *queryCurrencyAdd =new QSqlQuery;

    queryCurrencyAdd->prepare("INSERT INTO currencies (currency_id,currency_name,currency_altname,currency_rate,currency_national,deleted)"
                              "VALUES(nextval('currencies_currency_id_seq'::regclass), :currencyName, :currencyAltName, :currencyRate ,:currencyCode, :currencyNational, false)");
    queryCurrencyAdd->bindValue(":currencyName",currencyName);
    queryCurrencyAdd->bindValue(":currencyAltName",currencyAltName);
    queryCurrencyAdd->bindValue(":currencyRate", currencyRate);
    queryCurrencyAdd->bindValue(":currencyCode", currencyCode);
    queryCurrencyAdd->bindValue(":currencyNational", currencyNational);
    queryCurrencyAdd->exec();
//    if(queryCurrencyAdd->lastError().isValid()) //временный камент для отладки, потом вернуть назад.
        qDebug() << queryCurrencyAdd->lastError();
  //  currencysChangeDialog::close();

}

void currencysChangeDialog::currensiesMod(){

}

currencysChangeDialog::~currencysChangeDialog()
{
    delete ui;
}
