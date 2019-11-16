#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <iostream>
#include <question.h>
#include <questionview.h>
#include <gameloop.h>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow mainWindow;
    mainWindow.show();

    GameLoop *g = new GameLoop(&mainWindow);
    QObject::connect(mainWindow.getStartButton(), SIGNAL (released()), g, SLOT (startButtonPress()));

    QObject::connect(mainWindow.getQuestionView(), &QuestionView::success, g, &GameLoop::success);

    g->init();
    return a.exec();
}
