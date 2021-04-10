#include "listtuple.h"

ListTuple::ListTuple(QObject *parent) : QObject(parent)
{

}

void ListTuple::append(const QVariantList &pList){
    mList.append(pList);
}

void ListTuple::pushBack(const QVariantList &pList){
    mList.push_back(pList);
}

void ListTuple::pushFront(const QVariantList &pList){
    mList.push_front(pList);
}

void ListTuple::clear(){
    mList.clear();
}

void ListTuple::remove(const QVariantList &pList){
    int index = mList.indexOf(pList);
    mList.removeAt(index);
}

void ListTuple::remove(const int &index){
    mList.removeAt(index);
}

QVariant ListTuple::getData(const int &row, const int &column) const{
    return mList[row].at(column);
}

QVariantList ListTuple::getRowData(const int &row) const {
    return mList.at(row);
}
