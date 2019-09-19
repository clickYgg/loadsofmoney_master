#include "question.h"

#include <string.h>

using namespace std;

Question::Question(string question,string answer1,string answer2, string answer3,string answer4,int solution, int difficulty) {
    answers->push_back(answer1);
    answers->push_back(answer2);
    answers->push_back(answer3);
    answers->push_back(answer4);
    this->question = question;
    this->difficulty = difficulty;
    this->solution = solution;
}

string Question::getAnswer(int i) {
   return answers->at(i);
}

string Question::getQuestion() {
    return question.c_str();
}

int Question::getSolution() {
    return solution;
}

Question::~Question() {

}
