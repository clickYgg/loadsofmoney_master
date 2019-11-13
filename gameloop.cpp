#include "gameloop.h"
#include "QObject"
#include "stdint.h"

GameLoop::GameLoop(MainWindow *mainWindow) : QObject() {

}


void GameLoop::init() {

}

int askQuestion(int round) {

    //questionClass qObj;
    //int choice;

//    cout << "ROUND: " << round << endl;
//    cout << "QUESTION: " << qObj.q << endl;
//    cout << "ANSWER 1. "+qObj.a1 << endl;
//    cout << "ANSWER 2. "+qObj.a2 << endl;
//    cout << "ANSWER 3. "+qObj.a3 << endl;
//    cout << "ANSWER 4. "+qObj.a4 << endl;

//    cin >> choice;

//    if (choice == qObj.solution) {
//        round++;
//        cout << "you are goddamnn right!" << endl;
//        return round;
//    }
//    else {
//        // game over
//        round = -1;
//        return round;
//    }
}

int GameLoop::gameloop(int round,bool lost) {

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
    mainWindow->getQuestionView()->setVisible(false);
    mainWindow->getStartButton()->setVisible(true);
    if (lost) {
         mainWindow->getEndMsg()->setText("You suck man");
    } else {
         mainWindow->getEndMsg()->setText("okay");
    }

}

void GameLoop::success(bool status) {
    gameloop(round,status);
}



void GameLoop::startButtonPress() {
    std::cout << "Hallo1" << std::endl;
    mainWindow->getStartButton()->setVisible(false);
    std::cout << "Hallo2" << std::endl;
    mainWindow->getQuestionView()->setVisible(true);
    std::cout << "Hallo3" << std::endl;
    mainWindow->getEndMsg()->setVisible(false);
    std::cout << "Hallo4" << std::endl;
    gameloop(0,false);
}

GameLoop::~GameLoop() {

}
