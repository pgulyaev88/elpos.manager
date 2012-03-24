#ifndef CATEGORIESCHANGEDIALOG_H
#define CATEGORIESCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class categoriesChangeDialog;
}

class categoriesChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit categoriesChangeDialog(QWidget *parent = 0);
    ~categoriesChangeDialog();

private:
    Ui::categoriesChangeDialog *ui;
};

#endif // CATEGORIESCHANGEDIALOG_H
