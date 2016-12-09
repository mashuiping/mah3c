#include "databaseforcet.h"
#include <iostream>
using namespace std;
databaseForCET::databaseForCET(QString databaseName)
{
    QSqlDatabase qdb;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        dbForCET = QSqlDatabase::database("qt_sql_default_connection");
    else
        dbForCET = QSqlDatabase::addDatabase("QSQLITE");
    //dbForCET = QSqlDatabase::addDatabase("QSQLITE");
    dbForCET.setDatabaseName(".//" + databaseName);
    if( !dbForCET.open())
    {
        qDebug() << "无法建立数据库连接";
    }

}

bool databaseForCET::queryOne(QString tableName, QString cetWord)
{
    QSqlQuery query(dbForCET);
    query.exec("select * from " + tableName);
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("youdaoAPI表字段数：" ) << rec.count();
    while(query.next())
    {
        for(int index = 0; index < rec.count(); index++)
            if(cetWord == query.value(index))
                return true;
            //qDebug() << query.value(index) << " ";
    }
    return false;
}
bool databaseForCET::insert(QString tableName, QString word)
{
    QSqlQuery query(dbForCET);
    query.prepare("insert into " + tableName + " values(?)");
    query.bindValue(0,word);
    bool success=query.exec();
    if(!success)
    {
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
        return false;
    }
    return true;
}

void databaseForCET::closeDatabase()
{
    dbForCET.close();
}

QStringList databaseForCET::queryAllCET(QString tableName)
{
    QStringList databaseList;
    QSqlQuery query(dbForCET);
    query.exec("select * from " + tableName);
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("youdaoAPI表字段数：" ) << rec.count();
    while(query.next())
    {
        //for(int index = 0; index < rec.count(); index++)
        databaseList.append(query.value(0).toString());
    }
    //qDebug() << databaseList;
    return databaseList;
}

bool databaseForCET::deleteById(int rowid, QString tableName)
{
    //QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(dbForCET);
    //query.prepare("delete from youdaoAPI where rowid = 7");
    query.prepare(QString("delete from " +tableName+ " where rowid = " + QString::number(rowid,10)));
    if(!query.exec())
    {
        qDebug() << "删除记录失败！";
        return false;
    }
    query.exec("update "+tableName+ " set rowid=rowid-1 where rowid>" + QString::number(rowid,10));
    return true;
}
