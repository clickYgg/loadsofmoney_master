#include "questionview.h"
#include "ui_questionview.h"
#include <string.h>
#include <iostream>
#include <QFont>


using namespace std;

QuestionView::QuestionView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QuestionView) {
  ui->setupUi(this);
  QFont font(":/font/open-sans.ttf");
  font.setPointSize(14);
  ui->questionLabel->setFont(font);
  ui->a_button->setFont(font);
  ui->b_button->setFont(font);
  ui->c_button->setFont(font);
  ui->d_button->setFont(font);

  connect(ui->a_button, SIGNAL (released()),this, SLOT (buttonClicked1()));
  connect(ui->b_button, SIGNAL (released()),this, SLOT (buttonClicked2()));
  connect(ui->c_button, SIGNAL (released()),this, SLOT (buttonClicked3()));
  connect(ui->d_button, SIGNAL (released()),this, SLOT (buttonClicked4()));

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
    ui->a_button->setText(question->getAnswer(0));
    ui->b_button->setText(question->getAnswer(1));
    ui->c_button->setText(question->getAnswer(2));
    ui->d_button->setText(question->getAnswer(3));

    goodOne = question->getSolution();
}


QuestionView::~QuestionView() {
  delete ui;
}
