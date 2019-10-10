#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>


class Database
{
public:
    Database();
    QString* getQuestion(int id);
};

#endif // DATABASE_H
