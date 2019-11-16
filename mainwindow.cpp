#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <question.h>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font(":/font/open-sans.ttf");
    font.setPointSize(14);
    ui->questionView->setVisible(false);
    ui->endMsg->setVisible(false);
    ui->endMsg->setFont(font);
    ui->startButton->setFont(font);
}

QuestionView* MainWindow::getQuestionView() {
    return ui->questionView;
}

QPushButton* MainWindow::getStartButton() {
    return ui->startButton;
}

QLabel* MainWindow::getEndMsg() {
    return ui->endMsg;
}


MainWindow::~MainWindow()
{
    delete ui;
}
