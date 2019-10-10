#include "database.h"
#include <QtSql/QSqlDatabase>
#include <iostream>
#include <qcoreapplication.h>
#include <QSqlQuery>

using namespace std;

QSqlDatabase db;
QSqlQuery query;

//Abfragen
int answernr;
QString* question;

QString get_Question = "SELECT Frage FROM questions WHERE Q_ID=";
QString get_Answer = QString("SELECT ANSWER_%q  FROM questions WHERE Q_ID=").arg(answernr);
QString get_Loesung = "SELECT L�sung FROM questions WHERE Q_ID=";

QString* Database::getQuestion(int id)
{
    question=new QString[5];

    question[0]=query.exec(get_Question+id);
    answernr=1;
    question[1]=query.exec(get_Answer+id);
    answernr=2;
    question[2]=query.exec(get_Answer+id);
    answernr=3;
    question[3]=query.exec(get_Answer+id);
    answernr=4;
    question[4]=query.exec(get_Answer+id);
    question[5]=query.exec(get_Loesung+id);

    return question;
}

Database::Database()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("millionmilliondollarstyle");
    db.setUserName("localhost");
    db.setPassword("");
    db.open();
}
