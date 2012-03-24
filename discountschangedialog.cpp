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
