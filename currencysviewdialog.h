#ifndef CURRENCYSVIEWDIALOG_H
#define CURRENCYSVIEWDIALOG_H

#include <QDialog>
#include <QModelIndex>
#include <QSqlQueryModel>

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
    int currensyID;
    int currensyCode;
    QString currensyName;
    QString currensAltName;
    double currensyRate;
    bool currensyNational;
    bool currensyDeleted;
    int currensyCurrentID;

private slots:
    void getCurrenciesList();
    void getCurrenciesID();
    void currensiesAdd();
    void currensiesModify();
    void currensiesDelete();

protected:

};

#endif // CURRENCYSVIEWDIALOG_H
