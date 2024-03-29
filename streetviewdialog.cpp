#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "streetchangedialog.h"
#include "streetviewdialog.h"
#include "ui_streetviewdialog.h"

streetViewDialog::streetViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::streetViewDialog)
{
    ui->setupUi(this);
    connect(ui->streetTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(streetsModiify()));
    getStreetList();
}

void streetViewDialog::getStreetList(){

    QSqlDatabase::database();

    QSqlQueryModel *getStreet = new QSqlQueryModel;
    getStreet->setQuery("SELECT * FROM street WHERE deleted='false'");
    if(getStreet->lastError().isValid())
        qDebug() << getStreet->lastError();

    ui->streetTableView->setModel(getStreet);

}

void streetViewDialog::streetsAdd(){
    streetChangeDialog dialog(this);
    dialog.exec();
    if(dialog.close())
        getStreetList();
}

void streetViewDialog::streetsModiify(){
    streetChangeDialog dialog(this);
    dialog.exec();
}

void streetViewDialog::streetsDelete(){
    streetChangeDialog dialog(this);
    dialog.exec();
}

streetViewDialog::~streetViewDialog()
{
    delete ui;
}
