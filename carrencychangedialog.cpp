#include "carrencychangedialog.h"
#include "ui_carrencychangedialog.h"

carrencychangedialog::carrencychangedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carrencychangedialog)
{
    ui->setupUi(this);
}

carrencychangedialog::~carrencychangedialog()
{
    delete ui;
}
