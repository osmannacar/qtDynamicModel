#include "listmodel.h"
#include <QDebug>

ListModel::ListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

ListModel::~ListModel()
{
    mModelDatas.erase(mModelDatas.begin(), mModelDatas.end());
}

void ListModel::addModelData(const int &key, AListModelData *modelData)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mModelDatas.insert({key, modelData});
    endInsertRows();
}

int ListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return (int)mModelDatas.size();
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= mModelDatas.size())
        return QVariant();

    auto iter = std::next(mModelDatas.begin(), index.row());
    const AListModelData *modelData = iter->second;
    return modelData->data(role);
}

void ListModel::clear()
{
    beginResetModel();
    mModelDatas.clear();
    endResetModel();
}

bool ListModel::updateData(const int &key, const int &dataType, const QVariant data)
{
    int indexOfKey = std::distance(mModelDatas.begin(), mModelDatas.find(key));
    if(indexOfKey < 0){
        qDebug() << "ListModel::updateData out of index";
        return false;
    }
    mModelDatas[key]->update(dataType, data);
    emit dataChanged(index(indexOfKey), index(indexOfKey));
    return true;
}

bool ListModel::remove(const int &key)
{
    int indexOfKey = std::distance(mModelDatas.begin(), mModelDatas.find(key));
    if(indexOfKey < 0){
        qDebug() << "ListModel::remove out of index";
        return false;
    }
    beginRemoveRows(QModelIndex(), indexOfKey, indexOfKey);
    mModelDatas.erase(key);
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> ListModel::roleNames() const
{
    if(mModelDatas.size() == 0){
        return QHash<int, QByteArray>();
    }
    return mModelDatas.begin()->second->roles();
}
