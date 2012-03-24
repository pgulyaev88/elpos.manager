#include <QSqlQuery>
#include <QSqlQueryModel>
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
