#include "controller.h"
#include <QQmlContext>
#include <QTimer>
#include "errormodeldata.h"
#include "Enums.h"

Controller::Controller(QWindow *parent) :
    QQuickView(parent)
  , mListModel(this)
{
    qmlRegisterType<Controller>();
    qmlRegisterType<ListModel>();
    qmlRegisterType<ListTuple>("oscar.qmltypes", 1, 0, "ListTuple");
    qmlRegisterType<Enums>("oscar.qmltypes", 1, 0, "Enums");

    rootContext()->setContextProperty("controller", this);

    setResizeMode(SizeRootObjectToView);

    mListModel.addModelData(5, new ErrorModelData("Uyari", "LRU1", "Gönlünde yer yoksa güzelim, Fark etmez ben ayakta da giderim."));
    mListModel.addModelData(1, new ErrorModelData("Kritik", "LRU2", "Saçma sapan konuşma laa"));
    mListModel.addModelData(2, new ErrorModelData("Çok kritik", "LRU3", "Az yede kendine internet al"));



    QTimer::singleShot(5000, this, [this](){
        mListModel.addModelData(0, new ErrorModelData("Uyari", "LRU7", "Ölüme gidelim dedin de mazot mu yok dedik."));
        qDebug() << "single shot add LRU7";
    });
    QTimer::singleShot(10000, this, [this](){
        mListModel.updateData(5, static_cast<int>(Enums::ErrorRoles::ImportanceRole), "Kritik");
        qDebug() << "single shot update LRU1 Kritik";
    });
    QTimer::singleShot(15000, this, [this](){
        mListModel.remove(1);
        qDebug() << "single shot delete LRU2";
    });

    setSource(QUrl(QStringLiteral("qrc:/ui/qml/main.qml")));
}

ListModel *Controller::model()
{
    return &mListModel;
}

void Controller::printListTuple(ListTuple *container)
{
    qDebug() << "first values of printListTuple:" << container->getRowData(1);
}

