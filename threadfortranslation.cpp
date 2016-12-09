#include "threadfortranslation.h"
#include "downloder.h"
#include "externalvar.h"
#include "datageter.h"
#include "choosevacabularyfordatabase.h"
#include "choosevocabulary.h"
#include "QMessageBox"
threadForTranslation::threadForTranslation()
{

}

void threadForTranslation::run()
{
    dataGeter datageter;
    QStringList urlList = datageter.getData(beforeTranslateText);
    beforeTranslateSize = urlList.size();
    emit getSizeInTranslationThread();
    downloder myDownloder;
    translator mytranslator;
    for(int i = 0; i < beforeTranslateSize; i++){
        afterTranslateText = mytranslator.translate(myDownloder.downlode(urlList.at(i).toStdString()));
        emit stringChangedInTranslationThread(i);
    }
}
