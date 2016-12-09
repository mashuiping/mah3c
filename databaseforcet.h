#ifndef DATABASEFORCET_H
#define DATABASEFORCET_H

#include "database.h"
#include "QString"
class databaseForCET : public DataBase
{
public:
    databaseForCET(QString);
    bool queryOne(QString,QString);
    bool insert(QString, QString);
    void closeDatabase();
    QStringList queryAllCET(QString);
    bool deleteById(int , QString );
private:
    QSqlDatabase dbForCET;
};

#endif // DATABASEFORCET_H
