#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextToSpeech>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cmdYouTube_clicked();

    void on_cmdHello_clicked();

    void on_cmdAbout_clicked();

private:
    Ui::MainWindow *ui;
    QTextToSpeech m_engine;
};
#endif // MAINWINDOW_H
