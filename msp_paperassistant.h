#ifndef MSP_PAPERASSISTANT_H
#define MSP_PAPERASSISTANT_H


#include <QMainWindow>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QNetworkReply>
#include <qDebug>
#include <QtXml/QDomDocument>
#include "database.h"
#include "datageter.h"
#include "externalvar.h"
#include "QNetworkAccessManager"
#include "downloder.h"
#include "translator.h"
#include "choosevocabulary.h"
#include "QFileDialog"
#include "QClipboard"
#include "QMessageBox"
#include "api.h"
#include "updatedatabase.h"
#include "QThread"
#include "QProcess"
#include "threadforconnectdatabase.h"
#include "threadfortranslation.h"
#include "QProgressDialog"
#include "datageter.h"
#include "QObject"
#include "choosetranslateway.h"
namespace Ui {
class MSP_PaperAssistant;
}

class MSP_PaperAssistant : public QMainWindow
{
    Q_OBJECT

public:
    explicit MSP_PaperAssistant(QWidget *parent = 0);

    void restart();
    void startRequest(QUrl url);
    ~MSP_PaperAssistant();


private:
    threadForConnectDatabase * threadforconnectdatabase;
    threadForTranslation *threadfortranslation;
    QProgressDialog *progressdialogforconnectdatabase;
    QProgressDialog *progressdialogfortranslation;
    Ui::MSP_PaperAssistant *ui;

private slots:

    void on_translateButton_clicked();
    void on_clearButton_clicked();
    void on_copyButton_clicked();
    void on_apiButton_clicked();
    void on_chooseButton_clicked();
    void on_updateButton_clicked();
    void on_helpButton_clicked();
    //void on_beforeTranslateText_textChanged();


    void on_restartButton_clicked();

public slots:
    void quitThreadForDatabase();
    void setProgressSize();
    void updataProgress(int);
    void setProgressSizeForTranslation();
    void updataProgressForTranslation(int);
    void quitThreadForTranslation();
};

#endif // MSP_PAPERASSISTANT_H
