#include "choosevocabulary.h"
#include "ui_choosevocabulary.h"
#include "externalvar.h"

ChooseVocabulary::ChooseVocabulary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseVocabulary)
{
    ui->setupUi(this);
    //ui->buttonBox->setDisabled(true);
}

ChooseVocabulary::~ChooseVocabulary()
{
    delete ui;
}

void ChooseVocabulary::on_buttonBox_accepted()
{
    isCET4 = ui->CET4->isChecked();
    isCET6 = ui->CET6->isChecked();
    //qDebug() << isCET4;
}
