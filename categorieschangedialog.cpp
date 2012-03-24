#include "categorieschangedialog.h"
#include "ui_categorieschangedialog.h"

categoriesChangeDialog::categoriesChangeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesChangeDialog)
{
    ui->setupUi(this);
}

categoriesChangeDialog::~categoriesChangeDialog()
{
    delete ui;
}
