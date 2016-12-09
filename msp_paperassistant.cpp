#include "msp_paperassistant.h"
#include "ui_msp_paperassistant.h"
MSP_PaperAssistant::MSP_PaperAssistant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MSP_PaperAssistant)
{
    ui->setupUi(this);

    key = "1271820284";
    keyfrom = "kmpDemo5";

}

void MSP_PaperAssistant::restart()
{
    qApp->quit();
    QProcess::startDetached(qApp->applicationFilePath(),QStringList());
}

MSP_PaperAssistant::~MSP_PaperAssistant()
{
    delete ui;
}



void MSP_PaperAssistant::on_translateButton_clicked()
{
    if(ui->beforeTranslateText->toPlainText().trimmed()==""){
        QMessageBox::information(this,"Warning","You nonthing you have input!");
        return ;
    }
    beforeTranslateText = ui->beforeTranslateText->toPlainText().toLower();
    chooseTranslateWay choosetranslateway;
    choosetranslateway.exec();
    if(isCancel){
        isCancel = false;
        return;
    }
    qDebug() << "-----------------------what";
    //************数据库连接对比过滤***************************//
    threadforconnectdatabase = new threadForConnectDatabase;
    connect(threadforconnectdatabase,&threadForConnectDatabase::stringChanged,this,&MSP_PaperAssistant::quitThreadForDatabase);
    connect(threadforconnectdatabase,SIGNAL(finishedGetsizeFromThread()),this,SLOT(setProgressSize()));
    connect(threadforconnectdatabase,SIGNAL(oneStepFromThread(int)),this,SLOT(updataProgress(int)));
    threadforconnectdatabase->start();
    //    while(1){
    //        if(threadforconnectdatabase.isStopped())
    //            break;
    //    }
    //    dataGeter datageter;
    //    while(isChooseFile){
    //        if(isCET4+isCET6){
    //            beforeTranslateText = QtConcurrent::run(datageter.getNotInData(beforeTranslateText));
    //            break;
    //        }
    //            else{
    //            ChooseVocabulary choosevocabulary;
    //            choosevocabulary.exec();
    //        }
    //    }
    //    isChooseFile = false;
    //****************************************************//


    //    qDebug() << urlList ;
    //    QMessageBox::information(this,"Warning","The number of the word to be translated is " + QString::number(urlList.size(),10));
    //    ui->afterTranslateText->clear();
    //    downloder myDownloder;
    //    translator mytranslator;

    //    for(int i = 0; i < urlList.size(); i++){
    //        ui->afterTranslateText->append(mytranslator.translate(myDownloder.downlode(urlList.at(i).toStdString())));
    //    }
    //    threadForTranslation threadfortranslation;
    //    threadfortranslation.run();
}

void MSP_PaperAssistant::on_clearButton_clicked()
{
    ui->afterTranslateText->clear();
    ui->beforeTranslateText->clear();
}

void MSP_PaperAssistant::on_copyButton_clicked()
{
    QClipboard * cb = QApplication::clipboard();   //获取系统剪贴板指针
    //QString originalText = clipboard->text();         //获取剪贴板上文本信息
    QString newText = ui->afterTranslateText->toPlainText();
    //qDebug() << newText;;
    cb->setText(newText);
}

void MSP_PaperAssistant::on_apiButton_clicked()
{
    api myapi;
    myapi.exec();

}

void MSP_PaperAssistant::on_chooseButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("select the txt"),"", tr("TXT(*.txt)"));
    if(filename == ""){
        QMessageBox::information(this,"Warning","Not file choosed");
        return;
    }

    dataGeter datageter;
    QString fileData = datageter.getFileData(filename);
    ui->beforeTranslateText->appendPlainText(fileData);
}

void MSP_PaperAssistant::on_updateButton_clicked()
{
    updateDatabase updatedatabase;
    updatedatabase.exec();
}

void MSP_PaperAssistant::on_helpButton_clicked()
{
    QProcess* process = new QProcess();
    QString notepadPath = "notepad.exe  Readme.txt";
    process->start(notepadPath);
}

void MSP_PaperAssistant::quitThreadForDatabase()
{
    ui->afterTranslateText->clear();
    dataGeter datageter;
    QStringList urlList = datageter.getData(beforeTranslateText);
    QMessageBox::information(this,"Warning","The number of the word to be translated is " + QString::number(urlList.size(),10));

    threadfortranslation = new threadForTranslation;
    connect(threadfortranslation,SIGNAL(getSizeInTranslationThread()),this,SLOT(setProgressSizeForTranslation()));
    connect(threadfortranslation,SIGNAL(stringChangedInTranslationThread(int)),this,SLOT(updataProgressForTranslation(int)));
    threadfortranslation->start();
    threadforconnectdatabase->quit();

}



void MSP_PaperAssistant::setProgressSize()
{
    //qDebug() << "setProgressSize----------------------------------------------------------------";
    progressdialogforconnectdatabase = new QProgressDialog(this);
    progressdialogforconnectdatabase->setLabelText(tr("Searching for the database!"));
    progressdialogforconnectdatabase->setModal(true);
    progressdialogforconnectdatabase->setRange(0,beforeTranslateSize);
    progressdialogforconnectdatabase->setCancelButton(false);
    progressdialogforconnectdatabase->show();

}

void MSP_PaperAssistant::updataProgress(int i)
{
    //qDebug() << "updataProgress-----------------------------------------------------------------";
    progressdialogforconnectdatabase->setValue(i+1);
}

void MSP_PaperAssistant::setProgressSizeForTranslation()
{
    progressdialogfortranslation = new QProgressDialog(this);
    progressdialogfortranslation->setLabelText(tr("Translating the words you input!"));
    progressdialogfortranslation->setModal(true);
    progressdialogfortranslation->setRange(0,beforeTranslateSize);
    progressdialogfortranslation->setCancelButtonText(tr("Cancel"));
    progressdialogfortranslation->show();
    connect(progressdialogfortranslation,SIGNAL(canceled()),this,SLOT(quitThreadForTranslation()));
}

void MSP_PaperAssistant::updataProgressForTranslation(int i)
{
    progressdialogfortranslation->setValue(i+1);
    ui->afterTranslateText->append(afterTranslateText);
}

void MSP_PaperAssistant::quitThreadForTranslation()
{
    restart();
}

void MSP_PaperAssistant::on_restartButton_clicked()
{
    restart();
}
