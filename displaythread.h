#ifndef DISPLAYTHREAD_H
#define DISPLAYTHREAD_H

#include <QObject>
#include <QThread>
class displayThread : public QThread
{
public:
    displayThread();
    void stop();
protected:
    void display();
private:
    volatile bool stopped;
};

#endif // DISPLAYTHREAD_H
