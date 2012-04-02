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
    getCategoryList->setQuery("SELECT category_id, category_name FROM categories WHERE deleted='false'");

    qDebug() << "Query: " << getCategoryList;
    if(getCategoryList->lastError().isValid())
        qDebug() << getCategoryList->lastError();

    ui->menusComboBox->setModel(getCategoryList);
}

void menusChangeDialog::menusAdd(){
    menuName = ui->menusNameLineEdit->text();
    menuAltName = ui->menusAltNameLineEdit->text();
    menuPrice = ui->menusPriceLineEdit->text().toFloat();

}

void menusChangeDialog::menusMod(){

}

menusChangeDialog::~menusChangeDialog()
{
    delete ui;
}
