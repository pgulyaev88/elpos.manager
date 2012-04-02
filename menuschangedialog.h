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

private:
    Ui::menusChangeDialog *ui;
    QString menuName;
    QString menuAltName;
    float menuPrice;
    QString categoryName;
    int categoryID;

private slots:
    void menusAdd();
    void menusMod();
    void getCategoryFromMenu();
};

#endif // MENUSCHANGEDIALOG_H
