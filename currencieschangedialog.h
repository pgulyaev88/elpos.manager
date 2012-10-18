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
    void currensiesNew();
    void currensiesEdit(int currencyID, QString currencyName, QString currencyAltName, double currencyRate, bool currencyNational, int currencyCode);

private:
    Ui::currencysChangeDialog *ui;
    QString currencyName;
    QString currencyAltName;
    QString currencyRate;
    int currencyCode;
    bool currencyNational;
    int currencyID;


private slots:
    void currensiesInsert();
    void currensiesUpdate();


};

#endif // CURRENCYSCHANGEDIALOG_H
