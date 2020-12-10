#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include <QPrinter>
#include <QPrintDialog>
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
    void on_actionOpen_triggered();

    void on_actionFile_triggered();

    void on_actionSave_as_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = " ";
};
#endif // MAINWINDOW_H
