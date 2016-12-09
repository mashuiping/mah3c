#include "choosevacabularyfordatabase.h"
#include "ui_choosevacabularyfordatabase.h"
#include "externalvar.h"
chooseVacabularyForDatabase::chooseVacabularyForDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseVacabularyForDatabase)
{
    ui->setupUi(this);
    ui->CET4Radio->setChecked(true);
}

chooseVacabularyForDatabase::~chooseVacabularyForDatabase()
{
    delete ui;
}

void chooseVacabularyForDatabase::on_okButton_clicked()
{
    isCET4Database = ui->CET4Radio->isChecked();
    isCET6Database = ui->CET6Radio->isChecked();
    accept();
}

