#include "menusviewdialog.h"
#include "ui_menusviewdialog.h"

menusViewDialog::menusViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menusViewDialog)
{
    ui->setupUi(this);
}

menusViewDialog::~menusViewDialog()
{
    delete ui;
}
