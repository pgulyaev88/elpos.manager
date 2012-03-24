#ifndef DISCOUNTSVIEWDIALOG_H
#define DISCOUNTSVIEWDIALOG_H

#include <QDialog>

namespace Ui {
    class discountsViewDialog;
}

class discountsViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit discountsViewDialog(QWidget *parent = 0);
    ~discountsViewDialog();

private:
    Ui::discountsViewDialog *ui;

private slots:
    void getDiscountsList();
};

#endif // DISCOUNTSVIEWDIALOG_H
