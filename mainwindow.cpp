#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_textEdit_textChanged()
{
    QString text = ui->textEdit->toPlainText();

    int characters = text.length();

    QStringList words = text.split(" ", Qt::SkipEmptyParts);
    int wordCount = words.count();

    ui->WordsLabel->setText("Words: " + QString::number(wordCount));
    ui->CharactersLabel->setText("Characters " + QString::number(characters));
}
