#ifndef ADDAPI_H
#define ADDAPI_H

#include <QDialog>

namespace Ui {
class addAPI;
}

class addAPI : public QDialog
{
    Q_OBJECT

public:
    explicit addAPI(QWidget *parent = 0);
    ~addAPI();

private slots:
    void on_okButton_clicked();

private:
    Ui::addAPI *ui;
};

#endif // ADDAPI_H
