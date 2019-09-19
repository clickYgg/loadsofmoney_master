#include "questionview.h"
#include "ui_questionview.h"
#include <string.h>

using namespace std;

QuestionView::QuestionView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QuestionView) {
  ui->setupUi(this);

}


void QuestionView::answersClicked(int i) {
    printf("tets");
}

void QuestionView::setQuestion(Question question) {
    this->question = question;
    ui->questionLabel->setText(question.getQuestion());
    ui->pushButton->setText(question.getAnswer(0));
    ui->pushButton_2->setText(question.getAnswer(1));
    ui->pushButton_3->setText(question.getAnswer(2));
    ui->pushButton_4->setText(question.getAnswer(3));
}



QuestionView::~QuestionView() {
  delete ui;
}
