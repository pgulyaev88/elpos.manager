#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "discountsviewdialog.h"
#include "ui_discountsviewdialog.h"

discountsViewDialog::discountsViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountsViewDialog)
{
    ui->setupUi(this);
    getDiscountsList();
}

void discountsViewDialog::getDiscountsList(){
    QSqlDatabase::database();

    QSqlQueryModel *getDiscounts = new QSqlQueryModel;
    getDiscounts->setQuery("SELECT * FROM discunts");
    if(getDiscounts->lastError().isValid())
        qDebug() << getDiscounts->lastError();

    ui->discountsTableView->setModel(getDiscounts);
}

discountsViewDialog::~discountsViewDialog()
{
    delete ui;
}
