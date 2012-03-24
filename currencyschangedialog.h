#ifndef CURRENCYSCHANGEDIALOG_H
#define CURRENCYSCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class currencysChangeDialog;
}

class currencysChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit currencysChangeDialog(QWidget *parent = 0);
    ~currencysChangeDialog();

private:
    Ui::currencysChangeDialog *ui;
};

#endif // CURRENCYSCHANGEDIALOG_H
