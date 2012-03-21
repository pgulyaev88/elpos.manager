#ifndef MENUCHANGEDIALOG_H
#define MENUCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class menuchangedialog;
}

class menuchangedialog : public QDialog
{
    Q_OBJECT

public:
    explicit menuchangedialog(QWidget *parent = 0);
    ~menuchangedialog();

private:
    Ui::menuchangedialog *ui;
};

#endif // MENUCHANGEDIALOG_H
