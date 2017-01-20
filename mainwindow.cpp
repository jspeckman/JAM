#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTreeViewLibrary();
    initListViewLibrary();
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
    ui->treeViewLibrary->hideColumn(2);
    ui->treeViewLibrary->hideColumn(3);
    ui->treeViewLibrary->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
}

void MainWindow::initListViewLibrary()
{
    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(QDir::currentPath());
    fileModel->setFilter(QDir::Files | QDir::NoDotAndDotDot);
    ui->listViewLibrary->setViewMode(QListView::IconMode);
    ui->listViewLibrary->setIconSize(QSize(size().width()/8, size().height()/8));
    ui->listViewLibrary->setModel(fileModel);
}

void MainWindow::onTreeViewLibrary_clicked(const QModelIndex &index)
{
    QString sPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->listViewLibrary->setRootIndex(fileModel->setRootPath(sPath));
}
