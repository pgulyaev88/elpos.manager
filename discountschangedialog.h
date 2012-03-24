#ifndef DISCOUNTSCHANGEDIALOG_H
#define DISCOUNTSCHANGEDIALOG_H

#include <QDialog>

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
};

#endif // DISCOUNTSCHANGEDIALOG_H
