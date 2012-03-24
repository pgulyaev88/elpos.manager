#ifndef RESTAURANTSCHANGEDIALOG_H
#define RESTAURANTSCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class restaurantsChangeDialog;
}

class restaurantsChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit restaurantsChangeDialog(QWidget *parent = 0);
    ~restaurantsChangeDialog();

private:
    Ui::restaurantsChangeDialog *ui;
};

#endif // RESTAURANTSCHANGEDIALOG_H
