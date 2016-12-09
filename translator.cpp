#include "translator.h"
#include "externalvar.h"
#include "QDomDocument"
#include "QDebug"
translator::translator()
{


}

QString translator::translate(QString toTranslateText)
{
    QString translatedText;
    QDomDocument doc;
    doc.setContent(toTranslateText);
    QDomNodeList errorCode =  doc.elementsByTagName("errorCode");
    if(errorCode.at(0).toElement().text() != "0"){
        qDebug() << "API error";
        return "";
    }
    QDomNodeList phoneticList = doc.elementsByTagName("phonetic");
    QDomNodeList queryList = doc.elementsByTagName("query") ;
    QString phonetic = phoneticList.at(0).toElement().text();
    translatedText.append(queryList.at(0).toElement().text() + " ["+ phonetic +"]\n" );

//    if(!phoneticList.size()){
//        qDebug() << "No a valid word";
//        translatedText.append("No a valid word");
//        return translatedText;
//    }



    QDomNodeList explains = doc.elementsByTagName("explains");
    QDomNode explainsNode = explains.at(0).firstChild();
    while(explainsNode.isElement()){
        translatedText.append(explainsNode.toElement().text()+"\n");
        explainsNode = explainsNode.nextSibling();
    }
    return translatedText;
}
