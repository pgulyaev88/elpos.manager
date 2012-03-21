#ifndef CATEGORYDIALOG_H
#define CATEGORYDIALOG_H

#include <QDialog>

namespace Ui {
    class categorydialog;
}

class categorydialog : public QDialog
{
    Q_OBJECT

public:
    explicit categorydialog(QWidget *parent = 0);
    ~categorydialog();

private:
    Ui::categorydialog *ui;
};

#endif // CATEGORYDIALOG_H
