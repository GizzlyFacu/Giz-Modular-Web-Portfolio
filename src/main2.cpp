#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "storagemanager.h"
#include "configcenter.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    StorageManager* newStorageManager=new StorageManager(&app);
    qmlRegisterSingletonInstance("com.library",1,0,"StorageManager",newStorageManager);

    ConfigCenter* newConfigCenter=new ConfigCenter(&app,newStorageManager);
    qmlRegisterSingletonInstance("com.library",1,0,"ConfigCenter",newConfigCenter);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("PruebaJson", "Main");

    return app.exec();
}
