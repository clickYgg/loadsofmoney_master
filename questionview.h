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
    Q_OBJECT
public:
    QuestionView(QWidget *parent = 0);
    void setQuestion(Question *question);
    ~QuestionView();
private:
    int goodOne = 0;
    Ui::QuestionView *ui;
signals:
    void success(bool status);
private slots:
    void buttonClicked1();
    void buttonClicked2();
    void buttonClicked3();
    void buttonClicked4();
};

#endif // QUESTIONVIEW_H
