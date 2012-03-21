#include "categorydialog.h"
#include "ui_categorydialog.h"

categorydialog::categorydialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categorydialog)
{
    ui->setupUi(this);
}

categorydialog::~categorydialog()
{
    delete ui;
}
