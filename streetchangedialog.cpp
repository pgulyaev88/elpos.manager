#include <QApplication>
#include <QMessageBox>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <QDebug>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDialog>
#include "streetchangedialog.h"
#include "ui_streetchangedialog.h"

streetChangeDialog::streetChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::streetChangeDialog)
{
    ui->setupUi(this);
}

void streetChangeDialog::newStreet(){

}

void streetChangeDialog::modStreet(){

}

streetChangeDialog::~streetChangeDialog()
{
    delete ui;
}
