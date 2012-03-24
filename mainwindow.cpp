#include <QtGui>
#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include "categoriesviewdialog.h"
#include "currencysviewdialog.h"
#include "discountsviewdialog.h"
#include "menusviewdialog.h"
#include "restaurantsviewdialog.h"
#include "settingsdialog.h"
#include "streetviewdialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadDatabaseConnection();
}

void MainWindow::loadDatabaseConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("elpos");
    db.setUserName("elpos");
    db.setPassword("elpos");
    if (!db.open()){
        qDebug() << QObject::trUtf8("Database error connect") << db.lastError().text();
    }
}


void MainWindow::menusViewDialogShow(){
    menusViewDialog dialog(this);
    dialog.exec();
}

void MainWindow::categoriesViewDialogShow(){
    categoriesViewDialog dialog(this);
    dialog.exec();
}

void MainWindow::currenscysViewDialogShow(){
    currencysViewDialog dialog(this);
    dialog.exec();
}

void MainWindow::discountsViewDialogShow(){
    discountsViewDialog dialog(this);
    dialog.exec();
}

void MainWindow::restaurantsViewDialogShow(){
    restaurantsViewDialog dialog(this);
    dialog.exec();
}

void MainWindow::streetViewDialogShow(){
    streetViewDialog dialog(this);
    dialog.exec();
}

void MainWindow::settingsViewDialogShow(){
    settingsDialog dialog(this);
    dialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
