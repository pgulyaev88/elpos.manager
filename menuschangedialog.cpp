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
#include "menuschangedialog.h"
#include "ui_menuschangedialog.h"

menusChangeDialog::menusChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menusChangeDialog)
{
    ui->setupUi(this);
}

menusChangeDialog::~menusChangeDialog()
{
    delete ui;
}
