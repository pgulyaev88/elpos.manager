#include "categorychangedialog.h"
#include "ui_categorychangedialog.h"

categorychangedialog::categorychangedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categorychangedialog)
{
    ui->setupUi(this);
}

categorychangedialog::~categorychangedialog()
{
    delete ui;
}
