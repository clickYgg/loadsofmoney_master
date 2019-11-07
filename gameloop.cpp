#include "gameloop.h"
#include "QObject"

GameLoop::GameLoop(MainWindow *mainWindow) : QObject() {
    this->mainWindow = mainWindow;
}


void GameLoop::init() {
    QObject::connect(mainWindow.getStartButton(), SIGNAL (released()), this, SLOT (startButtonPress()));
    QObject::connect(mainWindow.getQuestionView(), SIGNAL (success(bool)), this, SLOT (success(bool)));
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
    mainWindow->getStartButton()->setVisible(false);
    mainWindow->getQuestionView()->setVisible(true);
    mainWindow->getEndMsg()->setVisible(false);
    gameloop(0,false);
}

GameLoop::~GameLoop() {

}
