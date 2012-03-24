#include "streetchangedialog.h"
#include "ui_streetchangedialog.h"

streetChangeDialog::streetChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::streetChangeDialog)
{
    ui->setupUi(this);
}

streetChangeDialog::~streetChangeDialog()
{
    delete ui;
}
