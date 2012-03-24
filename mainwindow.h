#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void categoriesViewDialogShow();
    void currenscysViewDialogShow();
    void discountsViewDialogShow();
    void menusViewDialogShow();
    void restaurantsViewDialogShow();
    void settingsViewDialogShow();
    void streetViewDialogShow();
    void loadDatabaseConnection();

protected:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
