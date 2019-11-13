#ifndef GAMELOOP_H
#define GAMELOOP_H

#include <mainwindow.h>
#include <QObject>

class GameLoop : public QObject
{
    Q_OBJECT

public:
    GameLoop(MainWindow *mainWindow);
    void init();

private:
    MainWindow* mainWindow;
    int round = 0;
    int gameloop(int round,bool lost = false);
    void gameEnd(bool lost);
    virtual ~GameLoop();


public slots:
    void startButtonPress();
    void success(bool status);

};

#endif // GAMELOOP_H
