#ifndef STREETCHANGEDIALOG_H
#define STREETCHANGEDIALOG_H

#include <QDialog>

namespace Ui {
    class streetChangeDialog;
}

class streetChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit streetChangeDialog(QWidget *parent = 0);
    ~streetChangeDialog();

protected slots:
    void newStreet();
    void modStreet();


private:
    Ui::streetChangeDialog *ui;
};

#endif // STREETCHANGEDIALOG_H
