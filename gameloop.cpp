#include "gameloop.h"
#include "QObject"
#include "stdint.h"
#include "iostream"

GameLoop::GameLoop(MainWindow *mainWindow) : QObject() {
    this->mainWindow = mainWindow;
}


void GameLoop::init() {

}

void GameLoop::askQuestion(int round) {
    Question q = Question("Wie alt bin ich?","22","21","40","20",4,round);
    mainWindow->getQuestionView()->setQuestion(&q);
}

void GameLoop::gameloop(int round,bool lost) {

    if (lost) {
      gameEnd(lost);
    }else if (round > 14) {
      gameEnd(lost);
    }
    else {
       askQuestion(round);
    }
}


void GameLoop::gameEnd(bool lost) {
    round = 0;
    mainWindow->getEndMsg()->setVisible(true);
    mainWindow->getQuestionView()->setVisible(false);
    mainWindow->getStartButton()->setVisible(true);
    if (lost) {
         mainWindow->getEndMsg()->setText("You suck man");
    } else {
         mainWindow->getEndMsg()->setText("okay");
    }
}

void GameLoop::success(bool status) {
    round++;

    gameloop(round,!status);
}


void GameLoop::startButtonPress() {
    mainWindow->getStartButton()->setVisible(false);
    mainWindow->getQuestionView()->setVisible(true);
    mainWindow->getEndMsg()->setVisible(false);
    gameloop(0,false);
}

GameLoop::~GameLoop() {

}
