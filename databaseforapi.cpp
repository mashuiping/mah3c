#include "databaseforapi.h"
#include "QMap"
#include "externalvar.h"
#include "QString"
databaseForAPI::databaseForAPI(QString databaseName)
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        dbForAPI = QSqlDatabase::database("qt_sql_default_connection");
    else
        dbForAPI = QSqlDatabase::addDatabase("QSQLITE");
    //dbForAPI = QSqlDatabase::addDatabase("QSQLITE");
    dbForAPI.setDatabaseName(".//" + databaseName);
    if( !dbForAPI.open())
    {
        qDebug() << "无法建立数据库连接";
    }

}
QMap<int,QString> databaseForAPI::queryAllAPI(QString tableName)
{
    QMap<int,QString> apiData;

    //QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(dbForAPI);
    query.exec("select * from " + tableName);
    //QSqlRecord rec = query.record();
    //qDebug() << QObject::tr("youdaoAPI表字段数：" ) << rec.count();

    while(query.next())
    {
        apiSize++;
        //for(int index = 0; index < rec.count(); index++){
        apiData.insert(apiSize,"key: " + query.value(0).toString()+" keyfrom: " +query.value(1).toString());
        //qDebug() << query.value(index) << " ";
    }
    return apiData;
}

void databaseForAPI::closeDatabase()
{
    dbForAPI.close();
}

