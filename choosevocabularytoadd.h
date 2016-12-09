#ifndef CHOOSEVOCABULARYTOADD_H
#define CHOOSEVOCABULARYTOADD_H

#include <QDialog>

namespace Ui {
class chooseVocabularyToAdd;
}

class chooseVocabularyToAdd : public QDialog
{
    Q_OBJECT

public:
    explicit chooseVocabularyToAdd(QWidget *parent = 0);
    ~chooseVocabularyToAdd();

private slots:
    void on_OK_clicked();

    void on_chooseVocabularyToAdd_destroyed();

private:
    Ui::chooseVocabularyToAdd *ui;
};

#endif // CHOOSEVOCABULARYTOADD_H
