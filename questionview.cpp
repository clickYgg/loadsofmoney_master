#include "questionview.h"
#include <string>


QuestionView::QuestionView(QWidget *parent, string question,string answer1,string answer2,string answer3,string answer4) : QWidget(parent),
  ui(new Ui::QuestionView)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}
