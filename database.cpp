#include "database.h"
#include "QMessageBox"

//建立一个数据库连接
DataBase::DataBase()
{

}

DataBase::DataBase(QString databaseName)
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QSQLITE");
    //db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(".//" + databaseName);
    if( !db.open())
    {
        qDebug() << "无法建立数据库连接";
    }
}

//bool DataBase::createConnection(QString databaseName)
//{
//    //以后就可以用"sqlite1"与数据库进行连接了
//    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName(".//MSP_Database.db");
//    if( !db.open())
//    {
//        qDebug() << "无法建立数据库连接";
//        return false;
//    }
//    return true;
//}


//向数据库中插入记录
bool DataBase::insert(QString key, QString keyfrom)
{
   // QSqlDatabase db = QSqlDatabase::database("sqlite"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into youdaoAPI values(?, ?)");
    query.bindValue(0,key);
    query.bindValue(1,keyfrom);
    bool success=query.exec();
    if(!success)
    {
        //QMessageBox::information(this,"Error","Unsucceed to insert!");
        QSqlError lastError = query.lastError();
        qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
        return false;
    }
    return true;
}

//查询所有信息
bool DataBase::queryAll(QString tableName)
{
    //QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.exec("select * from " + tableName);
    QSqlRecord rec = query.record();
    qDebug() << QObject::tr("youdaoAPI表字段数：" ) << rec.count();

    while(query.next())
    {
        for(int index = 0; index < rec.count(); index++)
            qDebug() << query.value(index) << " ";
    }
    return true;
}

//根据ID删除记录
bool DataBase::deleteById(int rowid, QString tableName)
{
    //QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
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

void DataBase::closeDatabase()
{
    db.close();
}

//根据ID更新记录 单词拼错
//bool DataBase::updateById(int id)
//{
//    //QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
//    QSqlQuery query(db);
//    query.prepare(QString("update automobil set attribute=?,type=?,"
//                             "kind=?, nation=?,"
//                             "carnumber=?, elevaltor=?,"
//                             "distance=?, oil=?,"
//                             "temperature=? where id=%1").arg(id));

//     query.bindValue(0,"四轮");
//     query.bindValue(1,"轿车");
//     query.bindValue(2,"富康");
//     query.bindValue(3,rand()%100);
//     query.bindValue(4,rand()%10000);
//     query.bindValue(5,rand()%300);
//     query.bindValue(6,rand()%200000);
//     query.bindValue(7,rand()%52);
//     query.bindValue(8,rand()%100);

//     bool success=query.exec();
//     if(!success)
//     {
//          QSqlError lastError = query.lastError();
//          qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
//     }
//    return true;
//}

