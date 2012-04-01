#ifndef CURRENCYSCHANGEDIALOG_H
#define CURRENCYSCHANGEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QLineEdit>

namespace Ui {
    class currencysChangeDialog;
}

class QLineEdit;

class currencysChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit currencysChangeDialog(QWidget *parent = 0);
    ~currencysChangeDialog();

private:
    Ui::currencysChangeDialog *ui;
    QString currencyName;
    QString currencyAltName;
    int currencyRate;
    int currencyCode;
    bool currencyNational;


private slots:
    void currensiesNew();
    void currensiesMod();

};

#endif // CURRENCYSCHANGEDIALOG_H
