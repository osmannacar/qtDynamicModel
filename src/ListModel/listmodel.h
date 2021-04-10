#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>
#include "alistmodeldata.h"
#include <unordered_map>

class ListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ListModel(QObject *parent = 0);
    ~ListModel();

    void addModelData(const int &key, AListModelData *modelData);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void clear();
    Q_INVOKABLE bool updateData(const int &key, const int &dataType, const QVariant data);
    bool remove(const int &key);

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    std::unordered_map<int, AListModelData*> mModelDatas;
};

#endif // LISTMODEL_H
