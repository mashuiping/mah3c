#include "datageter.h"
#include "ui_msp_paperassistant.h"
#include "msp_paperassistant.h"
#include "externalvar.h"
#include "QRegExp"
#include "database.h"
#include "databaseforapi.h"
#include "databaseforcet.h"
dataGeter::dataGeter()
{

}

QStringList dataGeter::getData(QString dataStr)
{
    QStringList dataList = dataStr.replace(QRegExp("[^a-zA-Z]")," ").replace(QRegExp("\\s+"), " ").trimmed().split(" ");
    QStringList urlList;
    for(int i = 0; i < dataList.size(); i++){
        urlList.append("http://fanyi.youdao.com/openapi.do?keyfrom="+keyfrom+"&key="+key+"&type=data&doctype=xml&version=1.1&q="+dataList.at(i));
    }

    return urlList;
}

QString dataGeter::getFileData(QString filename)
{
    QFile readFile(filename);
    if(!readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        cout <<"Can't open the file!"<<endl;
    }
    QString fileData;
    while(!readFile.atEnd()) {
        fileData.append(readFile.readLine()+"\n");
    }
    fileData = fileData.replace(QRegExp("[^a-zA-Z]")," ").replace(QRegExp("\\s+"), " ").trimmed();
    return fileData;
}

QString dataGeter::getNotInData(QString dataStr)
{
    QStringList dataList = dataStr.replace(QRegExp("[^a-zA-Z]")," ").replace(QRegExp("\\s+"), " ").trimmed().split(" ");
    QString notInData;
    databaseForCET databaseforcet("MSP_Database.db");
    beforeTranslateSize = dataList.size();
    emit getSize();
    if(isCET4) tableName = "CET4";
    else tableName = "CET6";
    qDebug() << "tableName" << tableName;
    for(int i = 0 ; i < beforeTranslateSize; i++){
        emit oneStep(i);
        if(dataList.at(i).size() > 3){
            if(!databaseforcet.queryOne(tableName,dataList.at(i)))
                if(!notInData.contains(dataList.at(i))){
                    notInData.append(dataList.at(i)+"\n");
                    
                }
        }

    }
    databaseforcet.closeDatabase();
    return notInData;
}






