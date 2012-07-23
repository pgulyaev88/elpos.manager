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

void menusChangeDialog::getCategoryByString(QString categoryName){
    QSqlDatabase::database();

    QSqlQuery *getCategory = new QSqlQuery();
    getCategory->prepare("SELECT category_id FROM "
                         "public.categories "
                         "WHERE name=:categoryName "
                         "AND deleted='0'");
    getCategory->bindValue(":categoryName",categoryName);
    getCategory->exec();
    if(getCategory->lastError().isValid())
        qDebug() << getCategory->lastError();
    while(getCategory->next()){
        categoryID = getCategory->value(0).toInt();
    }

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
    qDebug() << ui->menusComboBox->itemData(ui->menusComboBox->currentIndex(),Qt::DisplayRole).toString();
    QString categoryName = ui->menusComboBox->itemData(ui->menusComboBox->currentIndex(),Qt::DisplayRole).toString();
    getCategoryByString(categoryName);
    qDebug() << categoryID;

    QSqlDatabase::database();
    QSqlQuery *addMenu = new QSqlQuery();
    addMenu->prepare("INSERT INTO menus (menu_id,name,altname,price,category_id,menu_group_id,deleted) "
                     "VALUES(nextval('menus_menu_id_seq'::regclass), "
                     ":menuName, :menuAltName, :menuPrice,:categoryID,'1', false)");
    addMenu->bindValue(":menuName",menuName);
    addMenu->bindValue(":menuAltName",menuAltName);
    addMenu->bindValue(":menuPrice",menuPrice);
    addMenu->bindValue(":categoryID",categoryID);
    addMenu->exec();
    if(addMenu->lastError().isValid())
        qDebug() << addMenu->lastError();
        qDebug() << addMenu->lastQuery();
        qDebug() << addMenu->executedQuery();


//    menusChangeDialog::close();

}

void menusChangeDialog::menusUpdate(){


}

menusChangeDialog::~menusChangeDialog()
{
    delete ui;
}
