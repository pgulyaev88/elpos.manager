#include "restaurantsviewdialog.h"
#include "ui_restaurantsviewdialog.h"

restaurantsViewDialog::restaurantsViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::restaurantsViewDialog)
{
    ui->setupUi(this);
}

restaurantsViewDialog::~restaurantsViewDialog()
{
    delete ui;
}
