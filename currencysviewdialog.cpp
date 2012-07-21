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
#include "currencysviewdialog.h"
#include "currencyschangedialog.h"
#include "ui_currencysviewdialog.h"

currencysViewDialog::currencysViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currencysViewDialog)
{
    ui->setupUi(this);
    connect(ui->currenciesTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(currensiesModify()));
    getCurrenciesList();
}

void currencysViewDialog::getCurrenciesList(){
    qDebug() << trUtf8("Получаем список валют");
    QSqlDatabase::database();

    QSqlQueryModel *getCurrencies = new QSqlQueryModel;
    getCurrencies->setQuery("SELECT "
                            "currency_id, "
                            "currency_name, "
                            "currency_altname, "
                            "currency_rate, "
                            "currency_national, "
                            "currency_code, "
                            "deleted "
                            "FROM "
                            "currencies "
                            "WHERE "
                            "deleted='false'");
    getCurrencies->setHeaderData(0,Qt::Horizontal,QObject::trUtf8("Carrensy ID"));
    getCurrencies->setHeaderData(1,Qt::Horizontal,QObject::trUtf8("Currensy Name"));
    getCurrencies->setHeaderData(2,Qt::Horizontal,QObject::trUtf8("Currensy AltName"));
    getCurrencies->setHeaderData(3,Qt::Horizontal,QObject::trUtf8("Rate"),Qt::DisplayRole);
    getCurrencies->setHeaderData(4,Qt::Horizontal,QObject::trUtf8("National"));
    getCurrencies->setHeaderData(5,Qt::Horizontal,QObject::trUtf8("Code"));
    getCurrencies->setHeaderData(6,Qt::Horizontal,QObject::trUtf8("Deleted"));

//    if(getCurrencies->lastError().isValid())
        qDebug() << getCurrencies->lastError();
    ui->currenciesTableView->setModel(getCurrencies);
    ui->currenciesTableView->hideColumn(6);
    ui->currenciesTableView->verticalHeader()->hide(); //после отладки убрать
}

void currencysViewDialog::getCurrenciesID(){
    QModelIndex currensyIndex = ui->currenciesTableView->currentIndex();
    int selectedRow = currensyIndex.row();
    int selectedColumn = 0;
    currensyCurrentID =ui->currenciesTableView->model()->data(ui->currenciesTableView->model()->index(selectedRow,selectedColumn)).toInt();
    qDebug() << trUtf8("Current ID:") << currensyCurrentID;
}

void currencysViewDialog::currensiesAdd(){
    currencysChangeDialog dialog(this);
    dialog.currensiesNew();
    dialog.exec();
    if(dialog.close())
    getCurrenciesList();
}

void currencysViewDialog::currensiesModify(){

    getCurrenciesID();
    QSqlQuery *getCurrencies = new QSqlQuery;
    getCurrencies->prepare("SELECT "
                           "currency_id, "
                           "currency_name, "
                           "currency_altname, "
                           "currency_rate, "
                           "currency_national, "
                           "currency_code "
                           "FROM "
                           "currencies "
                           "WHERE "
                           "deleted='false' "
                           "AND currency_id=:currensyCurrentID");
    getCurrencies->bindValue(":currensyCurrentID",currensyCurrentID);
    getCurrencies->exec();
//    if(getCurrencies->lastError().isValid())
        qDebug() << trUtf8("Запрос:") << getCurrencies->executedQuery();
        qDebug() << trUtf8("Error:") << getCurrencies->lastError();
        while(getCurrencies->next()){
            currensyID = getCurrencies->value(0).toInt();
            currensyName = getCurrencies->value(1).toString();
            currensAltName = getCurrencies->value(2).toString();
            currensyRate = getCurrencies->value(3).toDouble();
            currensyNational = getCurrencies->value(4).toBool();
            currensyCode = getCurrencies->value(5).toInt();
            qDebug() << trUtf8("ID:") << currensyID;
            qDebug() << trUtf8("Имя валюты:") << currensyName;
            qDebug() << trUtf8("AltName:") << currensAltName;
            qDebug() << trUtf8("Rate:") << currensyRate;
            qDebug() << trUtf8("National:") << currensyNational;
            qDebug() << trUtf8("Code:") << currensyCode;
        }

    currencysChangeDialog dialog(this);
    dialog.currensiesEdit(currensyID,currensyName,currensAltName,currensyRate,currensyNational,currensyCode);
    dialog.exec();
    if(dialog.close());
    getCurrenciesList();
}

void currencysViewDialog::currensiesDelete(){
    getCurrenciesID();

    QSqlQuery *removeCurrencies = new QSqlQuery;
    removeCurrencies->prepare("UPDATE currencies SET deleted='true' "
                              "WHERE currency_id=:currensyCurrentID ");
    removeCurrencies->bindValue(":currensyCurrentID",currensyCurrentID);
    removeCurrencies->exec();
//    if(removeCurrencies->lastError().isValid())
        qDebug() << trUtf8("Ошибка при выполнении запроса:") << removeCurrencies->lastError();
        qDebug() << trUtf8("Запрос:") << removeCurrencies->executedQuery();
    getCurrenciesList();
}

currencysViewDialog::~currencysViewDialog()
{
    delete ui;
}
