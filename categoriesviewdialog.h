#ifndef CATEGORIESVIEWDIALOG_H
#define CATEGORIESVIEWDIALOG_H

#include <QDialog>

namespace Ui {
    class categoriesViewDialog;
}

class categoriesViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit categoriesViewDialog(QWidget *parent = 0);
    ~categoriesViewDialog();

private:
    Ui::categoriesViewDialog *ui;
    int categoryID;
    QString name;
    QString altname;
    int code;
    int currentID;

private slots:
    void getCategoriesList();
    void getCategoryID();
    void categoryAdd();
    void categoryModify();
    void categoryDelete();
};

#endif // CATEGORIESVIEWDIALOG_H
