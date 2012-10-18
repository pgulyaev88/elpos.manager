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
#include "currencieschangedialog.h"
#include "ui_currencyschangedialog.h"

currencysChangeDialog::currencysChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currencysChangeDialog)
{
    ui->setupUi(this);
}

void currencysChangeDialog::currensiesNew(){
    connect(ui->currenciesButtonBox,SIGNAL(accepted()),this,SLOT(currensiesInsert()));
    currencysChangeDialog::setWindowTitle("Adding new currency");

}

void currencysChangeDialog::currensiesEdit(int currencyID, QString currencyName, QString currencyAltName, double currencyRate, bool currencyNational, int currencyCode){
    connect(ui->currenciesButtonBox,SIGNAL(accepted()),this,SLOT(currensiesUpdate()));
    currencysChangeDialog::setWindowTitle("Modify currency");
    ui->currenciesIdLineEdit->setText(QString::number(currencyID));
    ui->currenciesNameLineEdit->setText(currencyName);
    ui->currenciesAltName->setText(currencyAltName);
    ui->currenciesRateLineEdit->setText(QString::number(currencyRate,'f',2));
    ui->currenciesNationalCurrensyCheckBox->setChecked(currencyNational);
    qDebug() << ui->currenciesRateLineEdit->text();
    ui->currenciesCodeLineEdit->setText(QString::number(currencyCode));

}

void currencysChangeDialog::currensiesInsert(){

    currencyName = ui->currenciesNameLineEdit->text();
    currencyAltName = ui->currenciesAltName->text();
    currencyRate = QString::number(ui->currenciesRateLineEdit->text().toDouble(),'f',2);
    currencyCode = ui->currenciesCodeLineEdit->text().toInt();
    currencyNational = ui->currenciesNationalCurrensyCheckBox->checkState();

    qDebug() << "Name: " << currencyName; //отладка
    qDebug() << "AltName: " << currencyAltName; //отладка
    qDebug() << "Rate: " << currencyRate; //отладка
    qDebug() << "Code: " << currencyCode; //отладка
    qDebug() << "NationalCheck: " << currencyNational; //отладка

    QSqlDatabase::database();
    QSqlQuery *insertCurrency =new QSqlQuery;

    insertCurrency->prepare("SELECT public.\"CurrencyAdd\"(:currencyName, :currencyAltName, :currencyRate ,:currencyCode, :currencyNational)");
    insertCurrency->bindValue(":currencyName",currencyName);
    insertCurrency->bindValue(":currencyAltName",currencyAltName);
    insertCurrency->bindValue(":currencyRate", currencyRate);
    insertCurrency->bindValue(":currencyCode", currencyCode);
    insertCurrency->bindValue(":currencyNational", currencyNational);
    insertCurrency->exec();
    if(insertCurrency->lastError().isValid()) //временный камент для отладки, потом вернуть назад.
        qDebug() << insertCurrency->executedQuery();
    qDebug() << insertCurrency->lastError();
    currencysChangeDialog::close();

}

void currencysChangeDialog::currensiesUpdate(){
    currencyID = ui->currenciesIdLineEdit->text().toInt();
    currencyName = ui->currenciesNameLineEdit->text();
    currencyAltName = ui->currenciesAltName->text();
    currencyRate = QString::number(ui->currenciesRateLineEdit->text().toDouble(),'f',2);
    currencyCode = ui->currenciesCodeLineEdit->text().toInt();
    currencyNational = ui->currenciesNationalCurrensyCheckBox->checkState();

    QSqlDatabase::database();
    QSqlQuery *updateCurrency = new QSqlQuery;
    updateCurrency->prepare("UPDATE currencies SET "
                            "currency_name=:currencyName, "
                            "currency_altname=:currencyAltName, "
                            "currency_rate=:currencyRate, "
                            "currency_code=:currencyCode, "
                            "currency_national=:currencyNational "
                            "WHERE "
                            "currency_id=:currencyID");
    updateCurrency->bindValue(":currencyName",currencyName);
    updateCurrency->bindValue(":currencyAltName",currencyAltName);
    updateCurrency->bindValue(":currencyRate", currencyRate);
    updateCurrency->bindValue(":currencyCode", currencyCode);
    updateCurrency->bindValue(":currencyNational", currencyNational);
    updateCurrency->bindValue(":currencyID",currencyID);
    updateCurrency->exec();
    if(updateCurrency->lastError().isValid())
        qDebug() << updateCurrency->lastError();
        qDebug() << updateCurrency->executedQuery();
  currencysChangeDialog::close();
}

currencysChangeDialog::~currencysChangeDialog()
{
    delete ui;
}
