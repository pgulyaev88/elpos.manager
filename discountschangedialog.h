#ifndef DISCOUNTSCHANGEDIALOG_H
#define DISCOUNTSCHANGEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QLineEdit>

namespace Ui {
    class discountsChangeDialog;
}

class discountsChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit discountsChangeDialog(QWidget *parent = 0);
    ~discountsChangeDialog();

private:
    Ui::discountsChangeDialog *ui;
    QString discountName;
    float discountPercent;

private slots:
    void discountNew();
    void discountMod();
};

#endif // DISCOUNTSCHANGEDIALOG_H
