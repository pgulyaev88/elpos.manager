#include "settingsdialog.h"
#include "ui_settingsdialog.h"

settingsDialog::settingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settingsDialog)
{
    ui->setupUi(this);
    settingsDialog::setWindowTitle("Edit Settings");
}

settingsDialog::~settingsDialog()
{
    delete ui;
}
