#ifndef CURRENCYSVIEWDIALOG_H
#define CURRENCYSVIEWDIALOG_H

#include <QDialog>

namespace Ui {
    class currencysViewDialog;
}

class currencysViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit currencysViewDialog(QWidget *parent = 0);
    ~currencysViewDialog();

private:
    Ui::currencysViewDialog *ui;

private slots:
    void getCurencysList();
};

#endif // CURRENCYSVIEWDIALOG_H
