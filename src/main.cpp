#include <QApplication>
#include <QSize>
#include "controller.h"
#include <QScreen>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
    QApplication app(argc, argv);

    QSize tSize(1000,480);

    Controller c;
    c.setMinimumSize(tSize);
    c.setColor(Qt::black);
    c.show();

    return app.exec();
}
