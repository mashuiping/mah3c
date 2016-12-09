#ifndef DATABASEFORAPI_H
#define DATABASEFORAPI_H

#include "database.h"
#include "QMap"
#include "QString"
class databaseForAPI : public DataBase
{
public:
    databaseForAPI(QString);
    QMap<int,QString> queryAllAPI(QString);
    void closeDatabase();
private:
    QSqlDatabase dbForAPI;

};

#endif // DATABASEFORAPI_H
