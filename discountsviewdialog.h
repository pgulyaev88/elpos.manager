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
    QString discountsName;
    QString discountsPercent;
    int discountsID;
    int discountsCurrentID;

private slots:
    void getDiscountsList();
    void getDiscountsID();
    void discountsAdd();
    void discountsModify();
    void discountsDelete();
};

#endif // DISCOUNTSVIEWDIALOG_H
