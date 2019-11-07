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

    g->init();
    return a.exec();
}
