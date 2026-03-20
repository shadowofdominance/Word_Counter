#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QRegularExpression"

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

    QStringList words = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    int wordCount = words.count();

    QStringList sentences = text.split(QRegularExpression("[.!?]+"), Qt::SkipEmptyParts);
    int sentenceCount = sentences.count();


    ui->WordsLabel->setText("Words: " + QString::number(wordCount));
    ui->CharactersLabel->setText("Characters " + QString::number(characters));
    ui->SentencesLabel->setText("Sentences: " + QString::number(sentenceCount));
}

void MainWindow::on_ClearButton_clicked()
{
    ui->textEdit->clear();
}

