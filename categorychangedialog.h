#ifndef CATEGORYCHANGEDIALOG_H
#define CATEGORYCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class categorychangedialog;
}

class categorychangedialog : public QDialog
{
    Q_OBJECT

public:
    explicit categorychangedialog(QWidget *parent = 0);
    ~categorychangedialog();

private:
    Ui::categorychangedialog *ui;
};

#endif // CATEGORYCHANGEDIALOG_H
