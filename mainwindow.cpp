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

void MainWindow::on_SearchBoxLineEdit_returnPressed()
{
    QString text = ui->textEdit->toPlainText();
    QString searchWord = ui->SearchBoxLineEdit->text();

    text = text.toLower();
    searchWord = searchWord.toLower();

    QStringList words = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    int count = 0;

    for(const QString &word : words){
        if(word == searchWord){
            count++;
        }
    }

    ui->FrequencyLabel->setText("Occurrences: " + QString::number(count));
}

