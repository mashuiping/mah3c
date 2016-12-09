#include "addvocabulary.h"
#include "ui_addvocabulary.h"
#include "QRegExp"
#include "databaseforcet.h"
#include "externalvar.h"
#include "choosevocabularytoadd.h"
addVocabulary::addVocabulary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addVocabulary)
{
    ui->setupUi(this);
}

addVocabulary::~addVocabulary()
{
    delete ui;
}

void addVocabulary::on_checkBox_accepted()
{
    chooseVocabularyToAdd choosevocabularytoddd;
    choosevocabularytoddd.exec();
    if(isCancel){
        isCancel = false;
        return;
    }
    QString addWordStr = ui->addWord->toPlainText();
    addWordStr = addWordStr.replace(QRegExp("[^a-zA-Z]")," ").replace(QRegExp("\\s+")," ").trimmed();
    qDebug() << addWordStr;
    QStringList addWordList = addWordStr.split(" ");
    databaseForCET databaseforcet("MSP_Database.db");
    QString tableName;
    if(isCET4Database) tableName = "CET4";
    else               tableName = "CET6";
    int addWordListSize = addWordList.size();
    for(int i = 0; i < addWordListSize; i++){
        qDebug() << databaseforcet.insert(tableName,addWordList.at(i));
    }
}
