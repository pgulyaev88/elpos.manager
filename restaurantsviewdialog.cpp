#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "restaurantschangedialog.h"
#include "restaurantsviewdialog.h"
#include "ui_restaurantsviewdialog.h"

restaurantsViewDialog::restaurantsViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restaurantsViewDialog)
{
    ui->setupUi(this);
    connect(ui->restaurantsTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(restaurantsModify()));
    getRestaurantsList();
}

void restaurantsViewDialog::getRestaurantsList(){

    QSqlDatabase::database();

    QSqlQueryModel *getRestaurants = new QSqlQueryModel;
    getRestaurants->setQuery("SELECT * FROM restaurants WHERE deleted='false'");
    if(getRestaurants->lastError().isValid())
        qDebug() << getRestaurants->lastError();

    ui->restaurantsTableView->setModel(getRestaurants);

}

void restaurantsViewDialog::restaurantsAdd(){
    restaurantsChangeDialog dialog(this);
    dialog.exec();
    if(dialog.close())
        getRestaurantsList();
}

void restaurantsViewDialog::restaurantsModify(){
    restaurantsChangeDialog dialog(this);
    dialog.exec();
}

void restaurantsViewDialog::restaurantsDelete(){
    restaurantsChangeDialog dialog(this);
    dialog.exec();
}

restaurantsViewDialog::~restaurantsViewDialog()
{
    delete ui;
}
