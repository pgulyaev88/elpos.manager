#include <QApplication>
#include <QMessageBox>
#include <QSettings>
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
}

MainWindow::menusViewDialogShow(){
    menusViewDialog dialog(this);
    dialog.exec;
}

MainWindow::categoriesViewDialogShow(){
    categoriesViewDialog dialog(this);
    dialog.exec;
}

MainWindow::currenscysViewDialogShow(){
    currencysViewDialog dialog(this);
    dialog.exec();
}

MainWindow::discountsViewDialogShow(){
    discountsViewDialog dialog(this);
    dialog.exec;
}

MainWindow::restaurantsViewDialogShow(){
    restaurantsViewDialog dialog(this);
    dialog.exec;
}

MainWindow::streetViewDialogShow(){
    streetViewDialog dialog(this);
    dialog.exec();
}

MainWindow::settingsViewDialogShow(){
    settingsDialog dialog(this);
    dialog.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
