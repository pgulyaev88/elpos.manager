#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include <QDialog>

namespace Ui {
    class menudialog;
}

class menudialog : public QDialog
{
    Q_OBJECT

public:
    explicit menudialog(QWidget *parent = 0);
    ~menudialog();

private:
    Ui::menudialog *ui;
};

#endif // MENUDIALOG_H
