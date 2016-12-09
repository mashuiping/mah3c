#include "mythread.h"
#include "downloder.h"
#include "externalvar.h"
#include "datageter.h"
#include "choosevacabularyfordatabase.h"
#include "choosevocabulary.h"
myThread::myThread()
{

}

void myThread::runConnectDatabase()
{
    dataGeter datageter;
    while(isChooseFile){
        if(isCET4+isCET6){
            beforeTranslateText = datageter.getNotInData(beforeTranslateText);
            break;
        }
            else{
            ChooseVocabulary choosevocabulary;
            choosevocabulary.exec();
        }
    }
    isChooseFile = false;
    stopped = true;
}

bool myThread::isConnectDatabaseStop()
{
    return stopped;
}

void myThread::runTranslation()
{
    downloder myDownloder;
    translator mytranslator;
    for(int i = 0; i < beforeTranslateSize; i++){
        afterTranslateText = mytranslator.translate(myDownloder.downlode(urlList.at(i).toStdString()));
        emit stringChanged(str);
    }

}

