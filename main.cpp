#include "mainwindow.h"

#include <QApplication>
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include <QPrinter>
#include <QPrintDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
