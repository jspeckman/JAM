#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTreeViewLibrary();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenPreferences() {
    prefs = new DialogPreferences(this);
    prefs->show();
}

void MainWindow::initTreeViewLibrary()
{
    dirModel = new QFileSystemModel(this);
    dirModel->setRootPath("~/");
    dirModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);
    ui->treeViewLibrary->setHeaderHidden(true);


    ui->treeViewLibrary->setModel(dirModel);
    ui->treeViewLibrary->hideColumn(1);
    ui->treeViewLibrary->hideColumn(2);
    ui->treeViewLibrary->hideColumn(3);
}
