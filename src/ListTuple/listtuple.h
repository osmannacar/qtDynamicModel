#ifndef LISTTUPLE_H
#define LISTTUPLE_H

#include <QObject>
#include <QList>
#include <QVariantList>

class ListTuple : public QObject
{
    Q_OBJECT
public:
    explicit ListTuple(QObject *parent = nullptr);
public slots:
    void append(const QVariantList &pList);
    void pushBack(const QVariantList &pList);
    void pushFront(const QVariantList &pList);
    void clear();
    void remove(const QVariantList &pList);
    void remove(const int &index);
    QVariant getData(const int &row, const int &column) const;
    QVariantList getRowData(const int &row) const;
private:
    QList<QVariantList> mList;
};

#endif // LISTTUPLE_H
