#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
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
    void onTreeViewLibrary_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    DialogPreferences *prefs;
    QFileSystemModel *dirModel, *fileModel;

    void initTreeViewLibrary();
    void initListViewLibrary();

};
#endif // MAINWINDOW_H
