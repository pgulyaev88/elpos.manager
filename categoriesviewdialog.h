#ifndef CATEGORIESVIEWDIALOG_H
#define CATEGORIESVIEWDIALOG_H

#include <QDialog>

namespace Ui {
    class categoriesViewDialog;
}

class categoriesViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit categoriesViewDialog(QWidget *parent = 0);
    ~categoriesViewDialog();

private:
    Ui::categoriesViewDialog *ui;
};

#endif // CATEGORIESVIEWDIALOG_H
