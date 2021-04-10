#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QQuickView>
#include <QQuickWidget>
#include "ListModel/listmodel.h"
#include "ListTuple/listtuple.h"

class Controller : public QQuickView
{
    Q_OBJECT
public:
    explicit Controller(QWindow *parent = nullptr);

public slots:    
    ListModel* model();
    void printListTuple(ListTuple *container);

private:
    ListModel mListModel;
};

#endif // CONTROLLER_H
