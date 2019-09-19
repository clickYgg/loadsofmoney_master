#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <QStringList>
using namespace std;


class Question {
    Q_OBJECT
public:
    Question(string question,string answer1,string answer2, string answer3,string answer4,int solution, int difficulty);
    string getAnswer(int i);
    string getQuestion();
    int getSolution();
    ~Question();
private:
    string question = "What is my name?";
    QStringList *answers = new QStringList;
    int solution = 3;
    int difficulty = 0;
};

#endif // QUESTION_H
