#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cmdYouTube_clicked()
{
    QUrl youtube("https://youtu.be/R6kvF0nlahE");
    QDesktopServices::openUrl(youtube);
}
