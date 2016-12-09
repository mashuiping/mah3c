#include "updatedatabase.h"
#include "ui_updatedatabase.h"
#include "externalvar.h"
#include "databaseforcet.h"
#include "choosevacabularyfordatabase.h"
#include "databaseforcet.h"
#include "addvocabulary.h"
updateDatabase::updateDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateDatabase)
{
    ui->setupUi(this);
    ui->removeDataButton->setEnabled(false);
}

void updateDatabase::refreshListView()
{
    if(isCET4Database) tableNameForDatabase = "CET4";
    else               tableNameForDatabase = "CET6";
    qDebug() << tableName;
    databaseForCET databaseforcet("MSP_Database.db");
    QStringList databaseList = databaseforcet.queryAllCET(tableNameForDatabase);
    databaseforcet.closeDatabase();
    int databaseSize = databaseList.size();
    for(int i = 1 ; i <= databaseSize; i++){
         ui->databaseListView->addItem( QString::number(i,10) + " " +  databaseList.at(i-1) );
    }
}

updateDatabase::~updateDatabase()
{
    delete ui;
}


void updateDatabase::on_CET4orCET6Button_clicked()
{
    chooseVacabularyForDatabase choosevacabularyvordatabase;
    choosevacabularyvordatabase.exec();
    refreshListView();

}

void updateDatabase::on_addDataButton_clicked()
{
    addVocabulary addvocabulary;
    addvocabulary.exec();
}

void updateDatabase::on_removeDataButton_clicked()
{
    DataBase database("MSP_Database.db");
    QStringList clickedStrList = ui->databaseListView->currentItem()->text().split(" ");
    qDebug() << "cli" << clickedStrList.at(0).toInt();
    qDebug() << "table" << tableNameForDatabase;
    database.deleteById(clickedStrList.at(0).toInt() ,tableNameForDatabase);
    database.closeDatabase();
    refreshListView();
}

void updateDatabase::on_databaseListView_clicked(const QModelIndex &index)
{
    ui->removeDataButton->setDisabled(false);

}
