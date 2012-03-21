#ifndef CARRENCYDIALOG_H
#define CARRENCYDIALOG_H

#include <QDialog>

namespace Ui {
    class carrencydialog;
}

class carrencydialog : public QDialog
{
    Q_OBJECT

public:
    explicit carrencydialog(QWidget *parent = 0);
    ~carrencydialog();

private:
    Ui::carrencydialog *ui;
};

#endif // CARRENCYDIALOG_H
