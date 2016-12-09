#ifndef DATABASE_H
#define DATABASE_H

#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>

class DataBase
{
public:
    DataBase();
    DataBase(QString);
    bool createConnection(QString);  //创建一个连接
    bool createTable(QString);       //创建数据库表
    bool insert(QString, QString);            //出入数据
    bool queryAll(QString);          //查询所有信息
    bool updateById(int);  //更新
    bool deleteById(int,QString);  //删除
    //bool sortById();          //排序
    void closeDatabase();
private:
    QSqlDatabase db;
};

#endif // DATABASE_H
