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
    void categoryNew();
    void categoryEdit(int categoryID, QString name, QString altname, int code);


private:
    Ui::categoriesChangeDialog *ui;
    int categoriesID;
    int categoriesCode;
    QString categoriesName;
    QString categoriesAltName;
    int categoryID;
    QString name;
    QString altname;
    int code;



private slots:
    void categoryInsert();
    void categoryUpdate();
};

#endif // CATEGORIESCHANGEDIALOG_H
