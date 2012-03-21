#include "discountdialog.h"
#include "ui_discountdialog.h"

discountdialog::discountdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountdialog)
{
    ui->setupUi(this);
}

discountdialog::~discountdialog()
{
    delete ui;
}
