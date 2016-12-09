#ifndef UPDATEDATABASE_H
#define UPDATEDATABASE_H

#include <QDialog>

namespace Ui {
class updateDatabase;
}

class updateDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit updateDatabase(QWidget *parent = 0);
    void refreshListView();
    ~updateDatabase();

private slots:

    void on_CET4orCET6Button_clicked();

    void on_addDataButton_clicked();

    void on_removeDataButton_clicked();

    void on_databaseListView_clicked(const QModelIndex &index);

private:
    Ui::updateDatabase *ui;
};

#endif // UPDATEDATABASE_H
