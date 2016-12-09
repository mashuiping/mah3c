#ifndef CHOOSEVACABULARYFORDATABASE_H
#define CHOOSEVACABULARYFORDATABASE_H

#include <QDialog>

namespace Ui {
class chooseVacabularyForDatabase;
}

class chooseVacabularyForDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit chooseVacabularyForDatabase(QWidget *parent = 0);
    ~chooseVacabularyForDatabase();

private slots:
    void on_okButton_clicked();


private:
    Ui::chooseVacabularyForDatabase *ui;
};

#endif // CHOOSEVACABULARYFORDATABASE_H
