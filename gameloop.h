#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <mainwindow.h>
#include <QObject>
#include <question.h>

class GameLoop : public QObject
{
    Q_OBJECT

public:
    GameLoop(MainWindow *mainWindow);
    void init();

private:
    MainWindow* mainWindow;
    int round = 0;
    void gameloop(int round,bool lost = false);
    void gameEnd(bool lost);
    void askQuestion(int round);
    virtual ~GameLoop();


public slots:
    void startButtonPress();
    void success(bool status);

};

#endif // GAMELOOP_H
