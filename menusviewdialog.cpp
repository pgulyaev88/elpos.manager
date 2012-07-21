#include <QtGui>
#include <QtSql>
#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "menuschangedialog.h"
#include "menusviewdialog.h"
#include "ui_menusviewdialog.h"

menusViewDialog::menusViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menusViewDialog)
{
    ui->setupUi(this);
    connect(ui->menusTreeView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(menusModify()));
    menusViewDialog::setWindowTitle("Browsing Menu");
    getMenusList();
}

void menusViewDialog::getMenusList(){
    QSqlDatabase::database();
    QSqlQueryModel *getMenus = new QSqlQueryModel;
    getMenus->setQuery("SELECT "
                       "m.menu_id, "
                       "m.name, "
                       "m.altname, "
                       "m.price, "
                       "c.name, "
                       "g.group_name, "
                       "m.category_id, "
                       "m.menu_group_id, "
                       "g.deleted, "
                       "c.deleted, "
                       "m.deleted "
                       "FROM "
                       "menus m "
                       "left join categories c on c.category_id = m.category_id "
                       "left join menu_groups g on g.menu_group_id = m.menu_group_id "
                       "WHERE "
                       "c.deleted = 'false' "
                       "AND g.deleted = 'false' "
                       "AND m.deleted = 'false' ");
    getMenus->setHeaderData(0,Qt::Horizontal,QObject::trUtf8("Menu ID"));
    getMenus->setHeaderData(1,Qt::Horizontal,QObject::trUtf8("Menu Name"));
    getMenus->setHeaderData(2,Qt::Horizontal,QObject::trUtf8("Alt Name"));
    getMenus->setHeaderData(3,Qt::Horizontal,QObject::trUtf8("Price"));
    getMenus->setHeaderData(4,Qt::Horizontal,QObject::trUtf8("Category Name"));
    getMenus->setHeaderData(5,Qt::Horizontal,QObject::trUtf8("Menu Group Name"));
    getMenus->setHeaderData(6,Qt::Horizontal,QObject::trUtf8("Category ID"));
    getMenus->setHeaderData(7,Qt::Horizontal,QObject::trUtf8("Menu Group ID"));
    getMenus->setHeaderData(8,Qt::Horizontal,QObject::trUtf8("Group Deleted"));
    getMenus->setHeaderData(9,Qt::Horizontal,QObject::trUtf8("Category Deleted"));
    getMenus->setHeaderData(10,Qt::Horizontal,QObject::trUtf8("Menu Deleted"));
//    if(getMenus->lastError().isValid())
        qDebug() << getMenus->lastError();

    ui->menusTreeView->setModel(getMenus);
    ui->menusTreeView->hideColumn(6);
    ui->menusTreeView->hideColumn(7);
    ui->menusTreeView->hideColumn(8);
    ui->menusTreeView->hideColumn(9);
    ui->menusTreeView->hideColumn(10);
    qDebug() << "Get Menu List";
}

void menusViewDialog::getMenusID(){
    QModelIndex menuIndex = ui->menusTreeView->currentIndex();
    int selectedRow = menuIndex.row();
    int selectedColumn = 0;
    menuCurrentID = ui->menusTreeView->model()->data(ui->menusTreeView->model()->index(selectedRow,selectedColumn)).toInt();
    qDebug() << menuCurrentID;

}

void menusViewDialog::menusAdd(){
    menusChangeDialog dialog(this);
    dialog.menusNew();
    dialog.exec();
    if(dialog.close())
        getMenusList();
}

void menusViewDialog::menusModify(){
    getMenusID();

    QSqlQuery *getMenu = new QSqlQuery();
    getMenu->prepare("SELECT menu_id, name, altname, price, category_id "
                     "FROM public.menus "
                     "WHERE deleted='0' "
                     "AND menu_id=:menuCurrentID");
    getMenu->bindValue(":menuCurrentID",menuCurrentID);
    getMenu->exec();
    if(getMenu->lastError().isValid())
        qDebug() << trUtf8("Запрос:") << getMenu->executedQuery();
    while (getMenu->next()){
        menuID = getMenu->value(0).toInt();
        menuName = getMenu->value(1).toString();
        menuAltName = getMenu->value(2).toString();
        menuPrice = getMenu->value(3).toInt();
        categoryID = getMenu->value(4).toInt();
        qDebug() << trUtf8("Menu ID: ") << menuID;
        qDebug() << trUtf8("Menu Name: ") << menuName;
        qDebug() << trUtf8("Menu Alt Name: ") << menuAltName;
        qDebug() << trUtf8("Menu Price: ") << menuPrice;
        qDebug() << trUtf8("Category ID: ") << categoryID;
    }

    menusChangeDialog dialog(this);
    dialog.menusEdit(menuID,menuName,menuAltName,menuPrice,categoryID);
    dialog.exec();
    if(dialog.close())
        getMenusList();
}

void menusViewDialog::menusDelete(){

}

menusViewDialog::~menusViewDialog()
{
    delete ui;
}
