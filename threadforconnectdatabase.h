#ifndef THREADFORCONNECTDATABASE_H
#define THREADFORCONNECTDATABASE_H
#include "mythread.h"
#include "downloder.h"
#include "externalvar.h"
#include "datageter.h"
#include "choosevacabularyfordatabase.h"
#include "choosevocabulary.h"
#include "QThread"

class threadForConnectDatabase : public QThread
{
    Q_OBJECT
public:
    threadForConnectDatabase();
protected:
    void run();
signals:
    void stringChanged();
    void finishedGetsizeFromThread();
    void oneStepFromThread(int);
public slots:
    void finishedGetsizeFromDataGeter();
    void oneStepFromDataGeter(int);
private:
};

#endif // THREADFORCONNECTDATABASE_H
