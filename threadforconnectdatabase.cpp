#include "threadforconnectdatabase.h"
#include "msp_paperassistant.h"
#include "QMessageBox"
threadForConnectDatabase::threadForConnectDatabase()
{

}

void threadForConnectDatabase::run()
{

    qDebug() << "this is thread for database";
    if(isDirectlyTransltion){
        isDirectlyTransltion = false;
        emit stringChanged();
    }
    qDebug() << "hewr------------------------";
    dataGeter * datageter = new dataGeter;
    connect(datageter,SIGNAL(getSize()),this,SLOT(finishedGetsizeFromDataGeter()));
    connect(datageter,SIGNAL(oneStep(int)),this,SLOT(oneStepFromDataGeter(int)));
    //dataGeter datageter;
    qDebug() << "isCET4--------------------" <<isCET4;
    qDebug() << "isCET6---------------------" << isCET6;
    if(isCET4+isCET6){


        beforeTranslateText = datageter->getNotInData(beforeTranslateText);
        emit stringChanged();
    }

}

void threadForConnectDatabase::finishedGetsizeFromDataGeter()
{
    emit finishedGetsizeFromThread();
}

void threadForConnectDatabase::oneStepFromDataGeter(int i)
{
    emit oneStepFromThread(i);
}



