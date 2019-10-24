#include "myaddressbookmodel.h"
#include <QFile>
#include <QMessageBox>
#include <iostream>
#include <QTextStream>

MyAddressBookModel::MyAddressBookModel(QObject *parent)
    :QAbstractTableModel (parent)
{

}

int MyAddressBookModel::rowCount(const QModelIndex &parent) const
{
    return firstNames.size();
}

int MyAddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant MyAddressBookModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole){
        switch(index.column()) {
        case 0: //first name
            return firstNames.at(index.row());
        case 1: //last name
            return lastNames.at(index.row());
        case 2: //last name
            return phoneNumbers.at(index.row());
        }
//        return QString("Rolw%1, Column%2")
//                .arg(index.row())
//                .arg(index.column());
    }
    return QVariant();
}

void MyAddressBookModel::openFile(QString filePath){

    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }
    QTextStream in(&file);

    for(int i = 0; !in.atEnd(); i++) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if(i == 0) continue;

        for(int j = 0; j < fields.length(); j++){
            std::cout << "[" << j << fields[j].toStdString();
        }
        std::cout << std::endl;

        firstNames.push_back(fields[0]);
        lastNames.push_back(fields[1]);
        phoneNumbers.push_back(fields[7]);
    }

    file.close();

    emit layoutChanged();

}

QString MyAddressBookModel::getPhoneNumber(int index)
{
    return phoneNumbers.at(index);
}

void MyAddressBookModel::printNum(QString newNum){
    if(number.length() == 3){
        number = number + "-";
    }
    if(number.length() == 7){
        number = number + "-";
    }
    if(number.length() < 12)
    {
        number += newNum;
    }
}

QString MyAddressBookModel::showNum(){
    return number;
}

QString MyAddressBookModel::deleteNum()
{
    if(number.mid(number.length() - 2,1) == "-"){
        number.chop(1);
    }
    number.chop(1);

    return number;
}

void MyAddressBookModel::reset()
{
    number = "";
}
