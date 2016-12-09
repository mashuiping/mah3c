#include "choosevocabularytoadd.h"
#include "ui_choosevocabularytoadd.h"
#include "externalvar.h"
#include "choosevocabularytoadd.h"
chooseVocabularyToAdd::chooseVocabularyToAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseVocabularyToAdd)
{
    ui->setupUi(this);
}

chooseVocabularyToAdd::~chooseVocabularyToAdd()
{
    delete ui;
}

void chooseVocabularyToAdd::on_OK_clicked()
{
    isCET4 = ui->CET4Radio->isChecked();
    isCET6 =ui->CET6Radio->isChecked();
}

void chooseVocabularyToAdd::on_chooseVocabularyToAdd_destroyed()
{
    isCancel = true;
}
