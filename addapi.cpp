#include "addapi.h"
#include "ui_addapi.h"
#include "datageter.h"
#include "downloder.h"
#include "translator.h"
#include "QMessageBox"
#include "databaseforapi.h"
#include "externalvar.h"
addAPI::addAPI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAPI)
{
    ui->setupUi(this);
}

addAPI::~addAPI()
{
    delete ui;
}

void addAPI::on_okButton_clicked()
{

    QString tempKey = key;
    key = ui->keyEdit->text().trimmed();
    QString tempKeyfrom = keyfrom;
    keyfrom = ui->keyfromEdit->text().trimmed();
    dataGeter datageter;
    downloder mydownloder;
    translator mytranslator;
    //mytranslator.translate(myDownloder.downlode(urlList.at(i).toStdString())
    if(mytranslator.translate(mydownloder.downlode(datageter.getData("the").at(0).toStdString())) == ""){
        QMessageBox::information(this,"Error","The api key are didn't work");
        key = tempKey;
        keyfrom = tempKeyfrom;
        return ;
    }
    else
        QMessageBox::information(this,"Good News", "The api key add successful!");

    DataBase database("MSP_Database.db");
    database.insert(key,keyfrom);
    key = tempKey;
    keyfrom = tempKeyfrom;
    database.closeDatabase();
    accept();
}
