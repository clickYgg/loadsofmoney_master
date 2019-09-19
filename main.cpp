#include "mainwindow.h"
#include <QApplication>
#include <string>
#include "question.h"

using namespace std;

class questionClass {

    public:
    string question = "What is my name?";
    string answer1 = "Magnets";
    string answer2 = "Borbarad";
    string answer3 = "Heisenberg";
    string answer4 = "Bitch";
    int solution = 3;
    int difficulty = 0;
};

class gameState {

    public: // Access specifier

    int Round = 0;

    void advance()
    {
        Round++;
    }
    void fail()
    {
        Round = -1;
    }
    void reset()
    {
        Round = 0;
    }
};

bool check(int choice) {

    questionClass questionObj;

    if (choice == questionObj.solution) {
        return true;
    }
    else {
        return false;
    }
}

int askQuestion {};

int gameLoop(int currentRound) {

    gameState roundTicker;
    currentRound = roundTicker.Round;

    if (currentRound < 0) {
        return 0; // game lost
    }
    if (currentRound >= 15) {
        return 1; // game won
    }
    else
    {
        // askQuestion(currentRound);
        return gameLoop(currentRound);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    gameLoop(0);

    return a.exec();
}
