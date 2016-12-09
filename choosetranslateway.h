#ifndef CHOOSETRANSLATEWAY_H
#define CHOOSETRANSLATEWAY_H

#include <QDialog>

namespace Ui {
class chooseTranslateWay;
}

class chooseTranslateWay : public QDialog
{
    Q_OBJECT

public:
    explicit chooseTranslateWay(QWidget *parent = 0);
    ~chooseTranslateWay();

private slots:


    void on_okButton_clicked();

    void on_Cancel_clicked();

    void on_chooseTranslateWay_destroyed();

private:
    Ui::chooseTranslateWay *ui;
};

#endif // CHOOSETRANSLATEWAY_H
