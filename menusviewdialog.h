#ifndef MENUSVIEWDIALOG_H
#define MENUSVIEWDIALOG_H

#include <QDialog>

namespace Ui {
    class menusViewDialog;
}

class menusViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit menusViewDialog(QWidget *parent = 0);
    ~menusViewDialog();

private:
    Ui::menusViewDialog *ui;
    int menuPrice;
    int menuID;
    QString menuName;
    QString menuAltName;
    int categoryID;
    int menuGroupID;
    bool deleted;
    int menuCurrentID;

private slots:
    void getMenusList();
    void getMenusID();
    void menusAdd();
    void menusModify();
    void menusDelete();
};

#endif // MENUSVIEWDIALOG_H
