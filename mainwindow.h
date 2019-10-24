#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myaddressbookmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_an_Address_Book_triggered();

    void on_actionExit_triggered();

    void on_tableView_clicked(const QModelIndex &index);

    void on_onePushButton_clicked();

    void on_twoPushButton_clicked();

    void on_threePushButton_clicked();

    void on_fourPushButton_clicked();

    void on_fivePushButton_clicked();

    void on_sixPushButton_clicked();

    void on_sevenPushButton_clicked();

    void on_rightPushButton_clicked();

    void on_ninePushButton_clicked();

    void on_starPushButton_clicked();

    void on_zeroPushButton_clicked();

    void on_poundPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_callPushButton_clicked();

private:
    Ui::MainWindow *ui;
    MyAddressBookModel *myModel;
};

#endif // MAINWINDOW_H
