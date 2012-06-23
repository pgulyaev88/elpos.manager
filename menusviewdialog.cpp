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
    getMenusList();
}

void menusViewDialog::getMenusList(){
    QSqlDatabase::database();

    QSqlQueryModel *getMenus = new QSqlQueryModel;
    getMenus->setQuery("SELECT "
                       "c.name, "
                       "g.group_name, "
                       "c.category_id, "
                       "g.menu_group_id, "
                       "m.menu_id, "
                       "m.name, "
                       "m.price, "
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
    getMenus->setHeaderData(4,Qt::Horizontal,QObject::trUtf8("Category ID"));
    getMenus->setHeaderData(5,Qt::Horizontal,QObject::trUtf8("Menu Group ID"));
    getMenus->setHeaderData(6,Qt::Horizontal,QObject::trUtf8("Deleted"));
//    if(getMenus->lastError().isValid())
        qDebug() << getMenus->lastError();

    ui->menusTreeView->setModel(getMenus);
//    ui->menusTableView->hideColumn(6);
//    ui->menusTableView->verticalHeader()->hide();
    qDebug() << "Get Menu List";
}

void menusViewDialog::getMenusID(){
//    QModelIndex *menuIndex = ui->menusTableView->currentIndex();
//    int selectedRow = menuIndex->row();
//    int selectedColumn = 0;
//    menuCurrentID = ui->menusTableView->model()->data(ui->menusTableView->model()->index(selectedRow,selectedColumn)).toInt();
//    qDebug() << menuCurrentID;

}

void menusViewDialog::menusAdd(){
    menusChangeDialog dialog(this);
    dialog.menusNew();
    dialog.exec();
    if(dialog.close())
        getMenusList();
}

void menusViewDialog::menusModify(){
    menusChangeDialog dialog(this);
    dialog.menusEdit();
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
