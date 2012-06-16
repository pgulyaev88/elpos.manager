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
//    int categoryID;


private:
    Ui::categoriesChangeDialog *ui;
    int categoriesCode;
    QString categoriesName;
    QString categoriesAltName;
//    int categoryID;
//    QString name;
//    QString altName;
//    int code;
//    QString query;


private slots:
    void categoryNew();
    void categoryMod(int categoryID, QString name, QString altname, int code);
//    void categoryMod(int ID);
};

#endif // CATEGORIESCHANGEDIALOG_H
