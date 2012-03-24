#include "categoriesviewdialog.h"
#include "ui_categoriesviewdialog.h"

categoriesViewDialog::categoriesViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesViewDialog)
{
    ui->setupUi(this);
}

categoriesViewDialog::~categoriesViewDialog()
{
    delete ui;
}
