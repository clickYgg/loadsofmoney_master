#include "gameloop.h"
#include "QObject"
#include "stdint.h"
#include "iostream"
#include <QTimer>
#include <QList>



GameLoop::GameLoop(MainWindow *mainWindow) : QObject() {
    this->mainWindow = mainWindow;
    questions.append(Question("Wie alt bin ich?","22","21","40","20",4,round));
    questions.append(Question("Test","etst","test","ste","tset",4,round));
}


void GameLoop::init() {

}

void GameLoop::askQuestion(int round) {
    mainWindow->getMonyCounter()->setIndex(round);
    Question q = questions.at(round);
    mainWindow->getQuestionView()->setQuestion(&q);
}

void GameLoop::gameloop(int round,bool lost) {
    if (lost) {
      gameEnd(lost);
    }else if (round > 14) {
      mainWindow->getMonyCounter()->setIndex(round);
      QTimer::singleShot(800,this,[this,lost]{ gameEnd(lost);});
    } else {
       askQuestion(round);
    }
}


void GameLoop::gameEnd(bool lost) {
    round = 0;
    if (lost) {
         mainWindow->getEndMsg()->setText("You suck man");
    } else {

         mainWindow->getEndMsg()->setText("okay");
    }
    mainWindow->setView(0);
    mainWindow->getMonyCounter()->clear();
}



void GameLoop::success(bool status) {
    round++;
    gameloop(round,!status);
}


void GameLoop::startButtonPress() {
    mainWindow->setView(1);
    mainWindow->getEndMsg()->setText("");
    gameloop(0,false);
}

GameLoop::~GameLoop() {

}
