#ifndef CATEGORIESCHANGEDIALOG_H
#define CATEGORIESCHANGEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QLineEdit>
namespace Ui {
    class categoriesChangeDialog;
}

class QLineEdit;


class categoriesChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit categoriesChangeDialog(QWidget *parent = 0);
    ~categoriesChangeDialog();

private:
    Ui::categoriesChangeDialog *ui;
    int categoriesCode;
    QString categoriesName;
    QString categoriesAltName;
//    QString query;


private slots:
    void categoryNew();
    void categoryMod();
};

#endif // CATEGORIESCHANGEDIALOG_H
