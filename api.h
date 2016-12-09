#ifndef API_H
#define API_H

#include <QDialog>

namespace Ui {
class api;
}

class api : public QDialog
{
    Q_OBJECT

public:
    explicit api(QWidget *parent = 0);
    void refreshListView();
    ~api();

private slots:
    void on_apiListView_doubleClicked(const QModelIndex &index);

    void on_addButton_clicked();

    void on_remove_clicked();

    void on_okButton_clicked();

    void on_apiListView_clicked(const QModelIndex &index);

private:
    Ui::api *ui;
};

#endif // API_H
