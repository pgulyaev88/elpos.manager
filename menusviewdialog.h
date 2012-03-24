#ifndef MENUSVIEWDIALOG_H
#define MENUSVIEWDIALOG_H

#include <QDialog>

namespace Ui {
    class menusViewDialog;
}

class menusViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit menusViewDialog(QWidget *parent = 0);
    ~menusViewDialog();

private:
    Ui::menusViewDialog *ui;
};

#endif // MENUSVIEWDIALOG_H
