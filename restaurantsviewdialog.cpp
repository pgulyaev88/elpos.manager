#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "restaurantsviewdialog.h"
#include "ui_restaurantsviewdialog.h"

restaurantsViewDialog::restaurantsViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restaurantsViewDialog)
{
    ui->setupUi(this);
    getRestaurantsList();
}

void restaurantsViewDialog::getRestaurantsList(){

    QSqlDatabase::database();

    QSqlQueryModel *getRestaurants = new QSqlQueryModel;
    getRestaurants->setQuery("SELECT * FROM restaurants");
    if(getRestaurants->lastError().isValid())
        qDebug() << getRestaurants->lastError();

    ui->restaurantsTableView->setModel(getRestaurants);

}

restaurantsViewDialog::~restaurantsViewDialog()
{
    delete ui;
}
