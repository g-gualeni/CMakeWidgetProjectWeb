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

void MainWindow::on_cmdHello_clicked()
{
    m_engine.setLocale(QLocale(QLocale::Italian, QLocale::Italy));
    m_engine.say("Buon Giorno, Gualeni Gianbattista!");
}
