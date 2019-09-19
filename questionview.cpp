#include "questionview.h"
#include "ui_questionview.h"

#include <string.h>

using namespace std;

QuestionView::QuestionView(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::QuestionView)
{
  ui->setupUi(this);

}

void setQuestion() {

}


QuestionView::~QuestionView() {
  delete ui;
}
