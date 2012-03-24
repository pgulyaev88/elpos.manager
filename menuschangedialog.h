#ifndef MENUSCHANGEDIALOG_H
#define MENUSCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class menusChangeDialog;
}

class menusChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit menusChangeDialog(QWidget *parent = 0);
    ~menusChangeDialog();

private:
    Ui::menusChangeDialog *ui;
};

#endif // MENUSCHANGEDIALOG_H
