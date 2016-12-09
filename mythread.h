#ifndef MYTHREAD_H
#define MYTHREAD_H

#include "QThread"
#include "QObject"

class myThread:QThread
{
    Q_OBJECT
public:
    myThread();
    void runConnectDatabase();
    bool isConnectDatabaseStop();
    void runTranslation();
private:
    volatile bool stopped;
signals:
    void stringChanged(QString);
};

#endif // MYTHREAD_H
