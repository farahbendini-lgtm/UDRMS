#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Backend backend;

    QQmlApplicationEngine engine;


    engine.rootContext()->setContextProperty("backend", &backend);

    engine.load(QUrl::fromLocalFile("C:/Users/thinkPad/OneDrive/Documents/project/Main.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}