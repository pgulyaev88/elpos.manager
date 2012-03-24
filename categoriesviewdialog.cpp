#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "categoriesviewdialog.h"
#include "ui_categoriesviewdialog.h"

categoriesViewDialog::categoriesViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesViewDialog)
{
    ui->setupUi(this);
    getCategoriesList();
}

void categoriesViewDialog::getCategoriesList(){

    QSqlDatabase::database();

    QSqlQueryModel *getCategories = new QSqlQueryModel;
    getCategories->setQuery("SELECT * FROM categories");
    if(getCategories->lastError().isValid())
        qDebug() << getCategories->lastError();
    ui->categoryTableView->setModel(getCategories);
}

categoriesViewDialog::~categoriesViewDialog()
{
    delete ui;
}
