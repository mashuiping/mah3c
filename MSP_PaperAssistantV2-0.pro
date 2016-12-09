#-------------------------------------------------
#
# Project created by QtCreator 2016-10-30T11:35:38
#
#-------------------------------------------------

QT       += core gui
QT  += sql
QT += network
QT += core xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MSP_PaperAssistantV2-0
TEMPLATE = app


SOURCES += main.cpp\
        msp_paperassistant.cpp \
    database.cpp \
    translator.cpp \
    datageter.cpp \
    externalvar.cpp \
    downloder.cpp \
    databaseforcet.cpp \
    databaseforapi.cpp \
    choosevocabulary.cpp \
    api.cpp \
    addapi.cpp \
    updatedatabase.cpp \
    choosevacabularyfordatabase.cpp \
    addvocabulary.cpp \
    threadforconnectdatabase.cpp \
    threadfortranslation.cpp \
    choosetranslateway.cpp \
    choosevocabularytoadd.cpp

HEADERS  += msp_paperassistant.h \
    database.h \
    translator.h \
    datageter.h \
    externalvar.h \
    downloder.h \
    databaseforcet.h \
    databaseforapi.h \
    choosevocabulary.h \
    api.h \
    addapi.h \
    updatedatabase.h \
    choosevacabularyfordatabase.h \
    addvocabulary.h \
    threadforconnectdatabase.h \
    threadfortranslation.h \
    choosetranslateway.h \
    choosevocabularytoadd.h


unix|win32: LIBS += -L$$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug/ -lcurl

INCLUDEPATH += $$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug
DEPENDPATH += $$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug/curl.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug/libcurl.a

unix|win32: LIBS += -L$$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug/ -lcurldll

INCLUDEPATH += $$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug
DEPENDPATH += $$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug/curldll.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../build-MSP_PaperAssistantV2-0-Desktop_Qt_5_7_0_MinGW_32bit-Debug/libcurldll.a

FORMS += \
    choosevocabulary.ui \
    msp_paperassistant.ui \
    api.ui \
    addapi.ui \
    updatedatabase.ui \
    choosevacabularyfordatabase.ui \
    addvocabulary.ui \
    choosetranslateway.ui \
    choosevocabularytoadd.ui
