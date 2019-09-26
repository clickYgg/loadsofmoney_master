#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <question.h>
#include <questionview.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QuestionView* getQuestionView();
    ~MainWindow();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
