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
    ui->menusComboBox->insertItem(categoryid);
    }
}

void menusChangeDialog::menusNew(){
    getCategoryFromMenu();
    connect(ui->menusButtonBox,SIGNAL(accepted()),this,SLOT(menusInsert()));
    menusChangeDialog::setWindowTitle("Adding new menu");
}

void menusChangeDialog::menusEdit(int menuID, QString menuName, QString menuAltName, int menuPrice, int categoryID){
    getCategoryFromMenu();
    connect(ui->menusButtonBox,SIGNAL(accepted()),this,SLOT(menusUpdate()));
    menusChangeDialog::setWindowTitle("Modify menu");
    ui->menusNameLineEdit->setText(menuName);
    ui->menusAltNameLineEdit->setText(menuAltName);
    ui->menusPriceLineEdit->setText(QString::number(menuPrice));
//    ui->menusCategoryComboBox->

}

void menusChangeDialog::menusInsert(){
//    QModelIndex categoryIndex = ui->menusComboBox->currentIndex();
//    int selectedRow = categoryIndex.row();
//    int dataIndex = ui->menusComboBox->model()->data(ui->menusComboBox->model()->index(selectedRow)).toInt();
//    qDebug() << "Data Index" << dataIndex;

    menuName = ui->menusNameLineEdit->text();
    menuAltName = ui->menusAltNameLineEdit->text();
    menuPrice = ui->menusPriceLineEdit->text().toInt();
    qDebug() << menuName;
    qDebug() << menuAltName;
    qDebug() << menuPrice;
    qDebug() << ui->menusComboBox->currentIndex();
//    menusChangeDialog::close();

}

void menusChangeDialog::menusUpdate(){


}

menusChangeDialog::~menusChangeDialog()
{
    delete ui;
}
