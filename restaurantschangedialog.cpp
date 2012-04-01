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
#include "restaurantschangedialog.h"
#include "ui_restaurantschangedialog.h"

restaurantsChangeDialog::restaurantsChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restaurantsChangeDialog)
{
    ui->setupUi(this);
}

restaurantsChangeDialog::~restaurantsChangeDialog()
{
    delete ui;
}
