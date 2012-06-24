#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>
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
    QSqlQuery getCategoryList("SELECT category_id, name FROM categories WHERE deleted='false'");
    if(getCategoryList.lastError().isValid())
        qDebug() << getCategoryList.lastError();
    while(getCategoryList.next()){
    int categoryid = getCategoryList.value(0).toInt();
    QString categoryName = getCategoryList.value(1).toString();

    ui->menusComboBox->insertItem(categoryid,categoryName);

}

}

void menusChangeDialog::menusNew(){
    getCategoryFromMenu();
    connect(ui->menusButtonBox,SIGNAL(accepted()),this,SLOT(menusInsert()));

}

void menusChangeDialog::menusEdit(){
    getCategoryFromMenu();
    connect(ui->menusButtonBox,SIGNAL(accepted()),this,SLOT(menusUpdate()));

}

void menusChangeDialog::menusInsert(){
    menuName = ui->menusNameLineEdit->text();
    menuAltName = ui->menusAltNameLineEdit->text();
    menuPrice = ui->menusPriceLineEdit->text().toInt();
    qDebug() << menuName;
    qDebug() << menuAltName;
    qDebug() << menuPrice;
    qDebug() << ui->menusComboBox->currentIndex();

}

void menusChangeDialog::menusUpdate(){

}

menusChangeDialog::~menusChangeDialog()
{
    delete ui;
}
