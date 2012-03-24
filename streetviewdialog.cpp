#include "streetviewdialog.h"
#include "ui_streetviewdialog.h"

streetViewDialog::streetViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::streetViewDialog)
{
    ui->setupUi(this);
}

streetViewDialog::~streetViewDialog()
{
    delete ui;
}
