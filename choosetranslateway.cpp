#include "choosetranslateway.h"
#include "ui_choosetranslateway.h"
#include "externalvar.h"
chooseTranslateWay::chooseTranslateWay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseTranslateWay)
{
    ui->setupUi(this);
    ui->CET6Button->setChecked(true);
}

chooseTranslateWay::~chooseTranslateWay()
{
    delete ui;
}


void chooseTranslateWay::on_okButton_clicked()
{
    isCET4 = ui->CET4Button->isChecked();
    isCET6 = ui->CET6Button->isChecked();
    isDirectlyTransltion = ui->directlyButton->isChecked();
    accept();
}

void chooseTranslateWay::on_Cancel_clicked()
{
    isCancel = true;
}

void chooseTranslateWay::on_chooseTranslateWay_destroyed()
{
    isCancel = true;
}
