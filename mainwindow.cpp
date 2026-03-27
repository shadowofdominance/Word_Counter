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
    //Fetching the text from the textEdit
    QString text = ui->textEdit->toPlainText();

    //Counting the characters
    int characters = text.length();

    //Counting the words by splitting the whole text into words using spaces and next line characters!
    QStringList words = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    int wordCount = words.count();

    /* Counting the sentences through using regular expressions to check where in the text we have these ".!?"
    and split them into sentences. */
    QStringList sentences = text.split(QRegularExpression("[.!?]+"), Qt::SkipEmptyParts);
    int sentenceCount = sentences.count();

    //Updating the UI Labels
    ui->WordsLabel->setText("Words: " + QString::number(wordCount));
    ui->CharactersLabel->setText("Characters " + QString::number(characters));
    ui->SentencesLabel->setText("Sentences: " + QString::number(sentenceCount));
}

void MainWindow::on_ClearButton_clicked()
{
    ui->textEdit->clear();
}

//Searching a word and calculating the frequency of that word!
void MainWindow::on_SearchBoxLineEdit_returnPressed()
{
    QString text = ui->textEdit->toPlainText();
    QString searchWord = ui->SearchBoxLineEdit->text();

    text = text.toLower();
    searchWord = searchWord.toLower();

    QStringList words = text.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    int count = 0;

    //Seacrhing the word occurences
    for(const QString &word : words){
        if(word == searchWord){
            count++;
        }
    }

    ui->FrequencyLabel->setText("Occurrences: " + QString::number(count));
}

//Convert selected text into lowercase
void MainWindow::on_LowerCaseButton_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();

    if(cursor.hasSelection()){
        QString text = cursor.selectedText();
        text = text.toLower();
        cursor.insertText(text);
    }
}

//Convert selected text into UpperCase
void MainWindow::on_UpperCaseButton_clicked()
{
    QTextCursor cursor = ui->textEdit->textCursor();

    if(cursor.hasSelection()){
        QString text = cursor.selectedText();
        text = text.toUpper();
        cursor.insertText(text);
    }
}
