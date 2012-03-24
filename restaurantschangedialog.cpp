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
