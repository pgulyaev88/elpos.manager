#ifndef MENUSCHANGEDIALOG_H
#define MENUSCHANGEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QLineEdit>

namespace Ui {
    class menusChangeDialog;
}

class menusChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit menusChangeDialog(QWidget *parent = 0);
    ~menusChangeDialog();
    void menusNew();
    void menusEdit(int menuID, QString menuName, QString menuAltName, int menuPrice, int categoryID);

private:
    Ui::menusChangeDialog *ui;
    int menuPrice;
    int menuID;
    QString menuName;
    QString menuAltName;
    int categoryID;
    int menuGroupID;
    bool deleted;
    QString categoryName;

private slots:
    void menusInsert();
    void menusUpdate();
    void getCategoryFromMenu();
    void getCategoryByString(QString categoryName);
};

#endif // MENUSCHANGEDIALOG_H
