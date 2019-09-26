#include "question.h"

#include <string.h>
#include <QStringList>
#include <QString>
using namespace std;

Question::Question(QString question,QString answer1,QString answer2, QString answer3,QString answer4,int solution, int difficulty) {
    answers->push_back(answer1);
    answers->push_back(answer2);
    answers->push_back(answer3);
    answers->push_back(answer4);
    this->question = question;
    this->difficulty = difficulty;
    this->solution = solution;
}

QString Question::getAnswer(int i) {
   return answers->at(i);
}

QString Question::getQuestion() {
    return question;
}

int Question::getSolution() {
    return solution;
}

Question::~Question() {
    answers->clear();
}
