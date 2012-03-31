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
    getMenus->setQuery("SELECT * FROM menus");
    if(getMenus->lastError().isValid())
        qDebug() << getMenus->lastError();

    ui->menusTableView->setModel(getMenus);
}

void menusViewDialog::menusAdd(){
    menusChangeDialog dialog(this);
    dialog.exec();
}

void menusViewDialog::menusModify(){
    menusChangeDialog dialog(this);
    dialog.exec();
}

void menusViewDialog::menusDelete(){
    menusChangeDialog dialog(this);
    dialog.exec();
}

menusViewDialog::~menusViewDialog()
{
    delete ui;
}
