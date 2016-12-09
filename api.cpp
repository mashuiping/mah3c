#include "api.h"
#include "ui_api.h"
#include "externalvar.h"
#include "databaseforapi.h"
#include "QMap"
#include "QMessageBox"
#include "addapi.h"



api::api(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::api)
{
    ui->setupUi(this);
    ui->key->setText(key);
    ui->keyfrom->setText(keyfrom);
    refreshListView();
    ui->remove->setDisabled(true);
}

api::~api()
{
    delete ui;
}

void api::on_apiListView_doubleClicked(const QModelIndex &index)
{
    QMessageBox::information(this,"clicked","You have choose the following API: \n" + ui->apiListView->currentItem()->text());
    QStringList clickedStrList = ui->apiListView->currentItem()->text().split(" ");
    key = clickedStrList.at(3);
    keyfrom = clickedStrList.at(5);
    accept();
}

void api::on_addButton_clicked()
{
    addAPI addapi;
    addapi.exec();
    refreshListView();
}

void api::on_remove_clicked()
{
    DataBase database("MSP_Database.db");
    QStringList clickedStrList = ui->apiListView->currentItem()->text().split(" ");
    qDebug() << clickedStrList.at(1);
    database.deleteById(clickedStrList.at(1).toInt() ,"youdaoAPI");
    database.closeDatabase();
    refreshListView();

}

void api::on_okButton_clicked()
{
    accept();
}

void api::on_apiListView_clicked(const QModelIndex &index)
{
    ui->remove->setDisabled(false);
}
void api::refreshListView(){
    ui->apiListView->clear();
    databaseForAPI databaseforapi("MSP_Database.db");
    QMap<int,QString> apiMap = databaseforapi.queryAllAPI("youdaoAPI");
    //databaseforapi.queryAll("youdaoAPI");
    for(int i = 1; i <= apiSize; i++){
        ui->apiListView->addItem("ID: "+ QString::number(i,10) +" "+ apiMap[i]);
    }
    apiSize = 0;
    databaseforapi.closeDatabase();
}
