#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDialog>
#include "menuschangedialog.h"
#include "ui_menuschangedialog.h"

menusChangeDialog::menusChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menusChangeDialog)
{
    ui->setupUi(this);
}

void menusChangeDialog::getCategoryFromMenu(){

    QSqlDatabase::database();
    QSqlQueryModel *getCategoryList = new QSqlQueryModel;
    getCategoryList->setQuery("SELECT name FROM categories WHERE deleted='false'");

    qDebug() << "Query: " << getCategoryList;
    if(getCategoryList->lastError().isValid())
        qDebug() << getCategoryList->lastError();

    ui->menusComboBox->setModel(getCategoryList);

}

void menusChangeDialog::menusNew(){
    connect(ui->menusButtonBox,SIGNAL(accepted()),this,SLOT(menusInsert()));

}

void menusChangeDialog::menusEdit(){
    connect(ui->menusButtonBox,SIGNAL(accepted()),this,SLOT(menusUpdate()));

}

void menusChangeDialog::menusInsert(){
    getCategoryFromMenu();
    menuName = ui->menusNameLineEdit->text();
    menuAltName = ui->menusAltNameLineEdit->text();
    menuPrice = ui->menusPriceLineEdit->text().toInt();

}

void menusChangeDialog::menusUpdate(){
    getCategoryFromMenu();

}

menusChangeDialog::~menusChangeDialog()
{
    delete ui;
}
