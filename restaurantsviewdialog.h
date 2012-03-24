#ifndef RESTAURANTSVIEWDIALOG_H
#define RESTAURANTSVIEWDIALOG_H

#include <QDialog>

namespace Ui {
    class restaurantsViewDialog;
}

class restaurantsViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit restaurantsViewDialog(QWidget *parent = 0);
    ~restaurantsViewDialog();

protected slots:
    void getRestaurantsList();

private:
    Ui::restaurantsViewDialog *ui;
};

#endif // RESTAURANTSVIEWDIALOG_H
