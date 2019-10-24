#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myModel(new MyAddressBookModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(myModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_an_Address_Book_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Address Book"), "",
                                                    tr("Address Book (*.csv)::All Files (*)"));
    std::cout  << fileName.toStdString() << std::endl;

    myModel->openFile(fileName);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->numberDisplay->setText(myModel->getPhoneNumber(index.row()));
}

void MainWindow::on_onePushButton_clicked()
{
    myModel->printNum("1");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}
void MainWindow::on_twoPushButton_clicked()
{
    myModel->printNum("2");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_threePushButton_clicked()
{
    myModel->printNum("3");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_fourPushButton_clicked()
{
    myModel->printNum("4");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_fivePushButton_clicked()
{
    myModel->printNum("5");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_sixPushButton_clicked()
{
    myModel->printNum("6");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_sevenPushButton_clicked()
{
    myModel->printNum("7");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_rightPushButton_clicked()
{
    myModel->printNum("8");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_ninePushButton_clicked()
{
    myModel->printNum("9");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_starPushButton_clicked()
{
    myModel->printNum("*");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_zeroPushButton_clicked()
{
    myModel->printNum("0");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_poundPushButton_clicked()
{
    myModel->printNum("#");
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_deletePushButton_clicked()
{
    myModel->deleteNum();
    QString phoneNum = myModel->showNum();
    ui->numberDisplay->setText(phoneNum);
}

void MainWindow::on_callPushButton_clicked()
{
    QString phoneNum = myModel->showNum();
    QString numLabel = ui->numberDisplay->text();
    if(numLabel != ""){
        QMessageBox msgBox;
        msgBox.setText("Calling " + numLabel + "...");
        msgBox.exec();
        myModel->reset();
        phoneNum = myModel->showNum();
        ui->numberDisplay->setText(phoneNum);
    }
}
