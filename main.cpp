#include "msp_paperassistant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MSP_PaperAssistant w;
    w.show();

    return a.exec();
}
