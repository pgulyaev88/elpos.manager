#include "currencysviewdialog.h"
#include "ui_currencysviewdialog.h"

currencysViewDialog::currencysViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currencysViewDialog)
{
    ui->setupUi(this);
}

currencysViewDialog::~currencysViewDialog()
{
    delete ui;
}
