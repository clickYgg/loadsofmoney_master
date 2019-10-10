#include "mainwindow.h"
#include <QApplication>
#include <string>
#include <iostream>

#include <string>

using namespace std;



#include <string>
#include <question.h>
#include <questionview.h>
#include <QObject>

using namespace std;


class questionClass {

    public:
    QString q = "What is my name?";
    QString a1 = "Magnets";
    QString a2 = "Borbarad";
    QString a3 = "Heisenberg";
    QString a4 = "Bitch";
    int solution = 3;
    int difficulty = 0;
};

MainWindow w;



    int askQuestion(int round) {

        questionClass qObj;
        int choice;

        Question *question = new Question(qObj.q,qObj.a1,qObj.a2,qObj.a3,qObj.a4,qObj.solution,qObj.difficulty);
        QuestionView *questionView = w.getQuestionView();
        questionView->setQuestion(question);


//QObject::connect(questionView, SIGNAL (QuestionView::success()),&w, SLOT (Main::answerReceived()));

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


    int main(int argc, char *argv[]) {
        QApplication a(argc, argv);


        w.show();
         gameloop(0);

        return a.exec();
    }

