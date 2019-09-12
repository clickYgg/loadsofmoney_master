#ifndef QUESTIONVIEW_H
#define QUESTIONVIEW_H

#include <QWidget>
#include <string>

namespace Ui {
    class QuestionView;
}

class QuestionView : public QWidget
{
    Q_OBJECT
public:
    explicit QuestionView(QWidget *parent = nullptr, string question,string answer1,string answer2,string answer3,string answer4);
     ~QuestionView();

private:
    Ui::QuestionView *ui;

signals:

public slots:


};

#endif // QUESTIONVIEW_H
