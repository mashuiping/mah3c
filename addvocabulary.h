#ifndef ADDVOCABULARY_H
#define ADDVOCABULARY_H

#include <QDialog>

namespace Ui {
class addVocabulary;
}

class addVocabulary : public QDialog
{
    Q_OBJECT

public:
    explicit addVocabulary(QWidget *parent = 0);
    ~addVocabulary();

private slots:
    void on_checkBox_accepted();

private:
    Ui::addVocabulary *ui;
};

#endif // ADDVOCABULARY_H
