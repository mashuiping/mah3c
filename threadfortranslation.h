#ifndef THREADFORTRANSLATION_H
#define THREADFORTRANSLATION_H

#include "QObject"
#include "QThread"
class threadForTranslation:public QThread
{
    Q_OBJECT
public:
    threadForTranslation();
signals:
    void stringChangedInTranslationThread(int);
    void getSizeInTranslationThread();
protected:
    void run();

};

#endif // THREADFORTRANSLATION_H
