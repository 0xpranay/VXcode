#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    ui->textEdit->setFontPointSize(18);
    ui->textEdit->setCurrentFont(QFont("Monaco", 18, -1,false));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionFile_triggered()
{
    currentFile.clear();
    setWindowTitle("Untitled");
    ui->textEdit->setText(QString());
}

void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open the file"));
    //QT searches for file in the working directory using filename
    //No need of file paths for opening
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("warning"), "An error has occured" + file.errorString());
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save as"));
    QFile file(filename);
    //Open file with specified name or create new one if doesn't exist
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("warning"), "An error has occured" + file.errorString());
    }
    //Now, a file with user selected name is open...in the context of QT but not visible on TextEdit GUI
    QTextStream out(&file); //An output stream is open
    setWindowTitle(filename);
    QString text = ui->textEdit->toPlainText();
    //Output stream is open for file
    out<<text;
    file.close(); // close the current file..i.e the file open in backend QT context
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}
