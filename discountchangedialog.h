#ifndef DISCOUNTCHANGEDIALOG_H
#define DISCOUNTCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class discountchangedialog;
}

class discountchangedialog : public QDialog
{
    Q_OBJECT

public:
    explicit discountchangedialog(QWidget *parent = 0);
    ~discountchangedialog();

private:
    Ui::discountchangedialog *ui;
};

#endif // DISCOUNTCHANGEDIALOG_H
