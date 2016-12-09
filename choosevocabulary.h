#ifndef CHOOSEVOCABULARY_H
#define CHOOSEVOCABULARY_H

#include <QDialog>

namespace Ui {
class ChooseVocabulary;
}

class ChooseVocabulary : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseVocabulary(QWidget *parent = 0);
    ~ChooseVocabulary();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::ChooseVocabulary *ui;
};

#endif // CHOOSEVOCABULARY_H
