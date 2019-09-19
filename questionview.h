#ifndef QUESTIONVIEW_H
#define QUESTIONVIEW_H

#include <QWidget>
#include <string>
#include <question.h>

using namespace std;

namespace Ui {
    class QuestionView;
}

class QuestionView : public QWidget {

public:
    QuestionView(QWidget *parent = 0);
    void setQuestion(Question question);
    ~QuestionView();
private:
    Question question;
    Ui::QuestionView *ui;
    void answersClicked(int i);
signals:
    void success(bool status);


};

#endif // QUESTIONVIEW_H
