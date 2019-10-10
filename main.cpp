#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <iostream>
#include <database.h>


using namespace std;

class questionClass {

    public:
    string q = "What is my name?";
    string a1 = "Magnets";
    string a2 = "Borbarad";
    string a3 = "Heisenberg";
    string a4 = "Bitch";
    int solution = 3;
    int difficulty = 0;
};

int askQuestion(int round) {

    questionClass qObj;
    int choice;

    cout << "ROUND: " << round << endl;
    cout << "QUESTION: " << qObj.q << endl;
    cout << "ANSWER 1. "+qObj.a1 << endl;
    cout << "ANSWER 2. "+qObj.a2 << endl;
    cout << "ANSWER 3. "+qObj.a3 << endl;
    cout << "ANSWER 4. "+qObj.a4 << endl;

    cin >> choice;

    if (choice == qObj.solution) {
        round++;
        cout << "you are goddamnn right!" << endl;
        return round;
    }
    else {
        // game over
        round = -1;
        return round;
    }
}

int gameloop(int round) {

    string input;

    if (round < 0) {
        cout << "game over" << endl;
        cout << "do you want to start over? y/n" << endl;
        cin >> input;

        if (input == "y") {
            round = 1;
            cout << "starting a new game..." << endl;
            return gameloop(askQuestion(round));
        }
        else {
            cout << "goodbye looser!" << endl;
            return 0;
        }
    }
    if (round > 14) {
        cout << "you've won! Congratulations!";
        return 1;
    }
    else {
       return gameloop(askQuestion(round));
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database *db = new Database();
    *db->getQuestion(0);

    /*

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    gameloop(0);
    */
    return a.exec();
}
