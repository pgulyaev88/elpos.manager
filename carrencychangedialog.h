#ifndef CARRENCYCHANGEDIALOG_H
#define CARRENCYCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class carrencychangedialog;
}

class carrencychangedialog : public QDialog
{
    Q_OBJECT

public:
    explicit carrencychangedialog(QWidget *parent = 0);
    ~carrencychangedialog();

private:
    Ui::carrencychangedialog *ui;
};

#endif // CARRENCYCHANGEDIALOG_H
