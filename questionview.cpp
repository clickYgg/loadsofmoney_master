#include "questionview.h"
#include "ui_questionview.h"
#include <string.h>
#include <iostream>


using namespace std;

QuestionView::QuestionView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QuestionView) {
  ui->setupUi(this);
  cout << "test";
  connect(ui->pushButton, SIGNAL (released()),this, SLOT (buttonClicked1()));
  connect(ui->pushButton_2, SIGNAL (released()),this, SLOT (buttonClicked2();));
  connect(ui->pushButton_3, SIGNAL (released()),this, SLOT (buttonClicked3()));
  connect(ui->pushButton_4, SIGNAL (released()),this, SLOT (buttonClicked4()));

}

void QuestionView::buttonClicked1() {
    if (goodOne == 1) {
         emit success(true);
    } else {
         emit success(false);
    }
}

void QuestionView::buttonClicked2() {
    if (goodOne == 2) {
        emit success(true);
    } else {
        emit success(false);
    }
}

void QuestionView::buttonClicked3() {
    if (goodOne == 3) {
         emit success(true);
    } else {
         emit success(false);
    }
}

void QuestionView::buttonClicked4() {
    if (goodOne == 4) {
         emit success(true);
    } else {
         emit success(false);
    }
}

void QuestionView::setQuestion(Question *question) {
    ui->questionLabel->setText(question->getQuestion());
    ui->pushButton->setText(question->getAnswer(0));
    ui->pushButton_2->setText(question->getAnswer(1));
    ui->pushButton_3->setText(question->getAnswer(2));
    ui->pushButton_4->setText(question->getAnswer(3));

    goodOne = question->getSolution()+1;

}


QuestionView::~QuestionView() {
  delete ui;
}
