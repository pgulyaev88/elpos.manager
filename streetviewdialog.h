#ifndef STREETVIEWDIALOG_H
#define STREETVIEWDIALOG_H

#include <QDialog>

namespace Ui {
    class streetViewDialog;
}

class streetViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit streetViewDialog(QWidget *parent = 0);
    ~streetViewDialog();

private slots:
    void getStreetList();

private:
    Ui::streetViewDialog *ui;
};

#endif // STREETVIEWDIALOG_H
