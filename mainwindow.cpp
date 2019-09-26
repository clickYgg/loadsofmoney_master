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
}

QuestionView* MainWindow::getQuestionView() {
    return ui->questionView;
}

MainWindow::~MainWindow()
{
    delete ui;
}
