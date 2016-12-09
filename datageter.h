#ifndef DATAGETER_H
#define DATAGETER_H
#include "QObject"
#include <QStringList>
class dataGeter : public QObject
{
    Q_OBJECT
public:
    dataGeter();
    QStringList getData(QString);
    QString getFileData(QString);
    QString getNotInData(QString);      

signals:
    void getSize();
    void oneStep(int);

};

#endif // DATAGETER_H
