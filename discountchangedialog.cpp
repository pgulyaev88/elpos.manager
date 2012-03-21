#include "discountchangedialog.h"
#include "ui_discountchangedialog.h"

discountchangedialog::discountchangedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::discountchangedialog)
{
    ui->setupUi(this);
}

discountchangedialog::~discountchangedialog()
{
    delete ui;
}
