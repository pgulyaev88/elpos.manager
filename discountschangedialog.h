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
    void discountNew();
    void discountEdit(int discountsID, QString discountsName, QString discountsPercent);

private:
    Ui::discountsChangeDialog *ui;
    QString discountsName;
    QString discountsPercent;
    int discountsID;
    int discountsCurrentID;

private slots:
    void discountInsert();
    void discountUpdate();
};

#endif // DISCOUNTSCHANGEDIALOG_H
