#include "discountsviewdialog.h"
#include "ui_discountsviewdialog.h"

discountsViewDialog::discountsViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountsViewDialog)
{
    ui->setupUi(this);
}

discountsViewDialog::~discountsViewDialog()
{
    delete ui;
}
