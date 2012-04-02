#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "discountsviewdialog.h"
#include "discountschangedialog.h"
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
    getDiscounts->setQuery("SELECT * FROM discounts WHERE deleted='false'");
    if(getDiscounts->lastError().isValid())
        qDebug() << getDiscounts->lastError();

    ui->discountsTableView->setModel(getDiscounts);
}

void discountsViewDialog::discountsAdd(){
    discountsChangeDialog dialog(this);
    dialog.exec();
    if(dialog.close())
        getDiscountsList();
}

void discountsViewDialog::discountsModify(){
    discountsChangeDialog dialog(this);
    dialog.exec();
}

void discountsViewDialog::discountsDelete(){
    discountsChangeDialog dialog(this);
    dialog.exec();
}

discountsViewDialog::~discountsViewDialog()
{
    delete ui;
}
