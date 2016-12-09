#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include "QString"
#include "QThread"
class translator : public QThread
{
public:
    translator();
    QString translate(QString);
};

#endif // TRANSLATOR_H
