#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialogpreferences.h"

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
    void OpenPreferences();

private:
    Ui::MainWindow *ui;
    DialogPreferences *prefs;
};

#endif // MAINWINDOW_H
