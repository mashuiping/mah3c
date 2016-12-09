#ifndef EXTERNALVAR_H
#define EXTERNALVAR_H
#include <QString>
#include <translator.h>
#include <string>
#include <iostream>
#include "database.h"
#include "databaseforapi.h"
#include "databaseforcet.h"

using namespace std;

extern QString key;
extern QString keyfrom;
extern bool isCET4;
extern bool isCET6;

extern int beforeTranslateSize;
extern int afterTranslateSize;
extern QString beforeTranslateText;
extern QString  afterTranslateText;
extern QString tableName;
//extern QStringList afterTranslateList;
extern QString translateWord;
extern QString phonetic;
extern string url;
extern int apiSize;
extern bool isCET4Database;
extern bool isCET6Database;
extern QString tableNameForDatabase;
extern bool isDirectlyTransltion;
extern bool isCancel;
//extern DataBase database;
//extern databaseForAPI databaseforapi;
//extern databaseForCET databaseforcet;
//extern translator myTranslator;
//extern int APIId;
#endif // EXTERNALVAR_H
