#ifndef DISCOUNTDIALOG_H
#define DISCOUNTDIALOG_H

#include <QDialog>

namespace Ui {
    class discountdialog;
}

class discountdialog : public QDialog
{
    Q_OBJECT

public:
    explicit discountdialog(QWidget *parent = 0);
    ~discountdialog();

private:
    Ui::discountdialog *ui;
};

#endif // DISCOUNTDIALOG_H
