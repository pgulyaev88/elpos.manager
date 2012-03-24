#include "currencyschangedialog.h"
#include "ui_currencyschangedialog.h"

currencysChangeDialog::currencysChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currencysChangeDialog)
{
    ui->setupUi(this);
}

currencysChangeDialog::~currencysChangeDialog()
{
    delete ui;
}
