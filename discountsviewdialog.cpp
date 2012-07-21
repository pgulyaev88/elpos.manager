#include <QtGui>
#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QModelIndex>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "discountsviewdialog.h"
#include "discountschangedialog.h"
#include "ui_discountsviewdialog.h"

discountsViewDialog::discountsViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountsViewDialog)
{
    ui->setupUi(this);
    connect(ui->discountsTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(discountsModify()));
    discountsViewDialog::setWindowTitle("Browsing Discounts");
    getDiscountsList();
}

void discountsViewDialog::getDiscountsList(){
    QSqlDatabase::database();

    QSqlQueryModel *getDiscounts = new QSqlQueryModel;
    getDiscounts->setQuery("SELECT * FROM discounts WHERE deleted='false'");
    getDiscounts->setHeaderData(0,Qt::Horizontal,QObject::trUtf8("DiscountID"));
    getDiscounts->setHeaderData(1,Qt::Horizontal,QObject::trUtf8("Discount Name"));
    getDiscounts->setHeaderData(2,Qt::Horizontal,QObject::trUtf8("Discount Percent"));
    getDiscounts->setHeaderData(3,Qt::Horizontal,QObject::trUtf8("Deleted"));
//    if(getDiscounts->lastError().isValid())
        qDebug() << getDiscounts->lastError();
    ui->discountsTableView->setModel(getDiscounts);
    ui->discountsTableView->hideColumn(3);
    ui->discountsTableView->verticalHeader()->hide();
    qDebug() << "Get Discounts List";
}

void discountsViewDialog::getDiscountsID(){
    QModelIndex discountsIndex = ui->discountsTableView->currentIndex();
    int selectedRow = discountsIndex.row();
    int selectedColumn = 0;
    discountsCurrentID = ui->discountsTableView->model()->data(ui->discountsTableView->model()->index(selectedRow,selectedColumn)).toInt();
    qDebug() << trUtf8("CurrentID") << discountsCurrentID;
}

void discountsViewDialog::discountsAdd(){
    discountsChangeDialog dialog(this);
    dialog.discountNew();
    dialog.exec();
    if(dialog.close())
    getDiscountsList();
}

void discountsViewDialog::discountsModify(){
    getDiscountsID();
    qDebug() << discountsCurrentID;
    QSqlQuery *getDiscounts = new QSqlQuery;
    getDiscounts->prepare("SELECT "
                         "discounts.discount_id, "
                         "discounts.discount_name, "
                         "discounts.discount_percent, "
                         "discounts.deleted "
                         "FROM "
                         "public.discounts "
                         "WHERE "
                         "discounts.deleted ='false' "
                         "AND discounts.discount_id=:discountsCurrentID");
    getDiscounts->bindValue(":discountsCurrentID",discountsCurrentID);
    getDiscounts->exec();
//    if(getDiscounts->lastError().isValid())
        qDebug() << getDiscounts->lastError();
    while(getDiscounts->next()){
        discountsID = getDiscounts->value(0).toInt();
        discountsName = getDiscounts->value(1).toString();
        discountsPercent = getDiscounts->value(2).toInt();
        qDebug() << discountsID;
        qDebug() << discountsName;
        qDebug() << discountsPercent;
    }
    discountsChangeDialog dialog(this);
    dialog.discountEdit(discountsID,discountsName,discountsPercent);
    dialog.exec();
    if(dialog.close())
    getDiscountsList();
}

void discountsViewDialog::discountsDelete(){
    getDiscountsID();

    QSqlQuery *removeDiscounts = new QSqlQuery;
    removeDiscounts->prepare("UPDATE public.discounts SET "
                             "discounts.deleted ='true' "
                             "WHERE "
                             "discounts.discount_id=:discountsCurrentID");
    removeDiscounts->bindValue(":discountsCurrentID",discountsCurrentID);
    removeDiscounts->exec();
//    if(removeDiscounts->lastError().isValid())
        qDebug() << removeDiscounts->lastError();
    getDiscountsList();
}

discountsViewDialog::~discountsViewDialog()
{
    delete ui;
}
