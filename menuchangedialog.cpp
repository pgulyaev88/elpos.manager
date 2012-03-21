#include "menuchangedialog.h"
#include "ui_menuchangedialog.h"

menuchangedialog::menuchangedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuchangedialog)
{
    ui->setupUi(this);
}

menuchangedialog::~menuchangedialog()
{
    delete ui;
}
