#ifndef QUESTIONVIEW_H
#define QUESTIONVIEW_H

#include <QWidget>
#include <string>

using namespace std;

namespace Ui {
    class QuestionView;
}

class QuestionView : public QWidget {
    Q_OBJECT
public:
    QuestionView(QWidget *parent = 0);
    ~QuestionView();
private:
    Ui::QuestionView *ui;
signals:

public slots:


};

#endif // QUESTIONVIEW_H
