#include "carrencydialog.h"
#include "ui_carrencydialog.h"

carrencydialog::carrencydialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carrencydialog)
{
    ui->setupUi(this);
}

carrencydialog::~carrencydialog()
{
    delete ui;
}
