#include "menudialog.h"
#include "ui_menudialog.h"

menudialog::menudialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menudialog)
{
    ui->setupUi(this);
}

menudialog::~menudialog()
{
    delete ui;
}
