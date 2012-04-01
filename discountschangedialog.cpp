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
#include "discountschangedialog.h"
#include "ui_discountschangedialog.h"

discountsChangeDialog::discountsChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountsChangeDialog)
{
    ui->setupUi(this);
}

discountsChangeDialog::~discountsChangeDialog()
{
    delete ui;
}
