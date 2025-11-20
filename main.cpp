#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "src/utils/jsonparsing.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    JsonParsing pepe;
    pepe.sayA();
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("GizWebPluginLab2", "Main");

    return app.exec();
}
