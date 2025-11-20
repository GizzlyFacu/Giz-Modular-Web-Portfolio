#ifndef CONFIGCENTER_H
#define CONFIGCENTER_H

#include <QObject>
#include <QQmlEngine>
#include <QScopedPointer>
#include "utils/networklayer.h"
#include "utils/jsonparsing.h"
#include "storagemanager.h"


class ConfigCenter : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
public:
    explicit ConfigCenter(QObject *parent=nullptr, StorageManager *storage=nullptr){
        m_storageManager = storage;
        //esto es solo para desktop, ahora estoy usando qnetwork
        //m_jsonParsing.crearEstructuraJSON();
        //m_jsonParsing.writeJson();

        connect(m_networkManager,&NetworkLayer::dataReceived,
                this,&ConfigCenter::onDataReceived);
        connect(m_networkManager,&NetworkLayer::errorOccurred,
                this, &ConfigCenter::onDataReceivednt);

        const QUrl contentUrl("https://raw.githubusercontent.com/GizzlyFacu/WebAssemblyTest2/main/configuracion.json");
        m_networkManager->makeGetRequest(contentUrl);


    }
    void loadconfig_BoxIntroduction(const QJsonObject &data);
    void loadconfig_BlogCards(const QJsonObject &data);
    void loadconfig_TechSkills(const QJsonObject &data);
private:
    StorageManager *m_storageManager=nullptr;
    JsonParsing m_jsonParsing;
    NetworkLayer* m_networkManager=new NetworkLayer(this);
private slots:
    void onDataReceived(const QByteArray &jsonData);
    void onDataReceivednt(const QUrl &url);
signals:
};

#endif // CONFIGCENTER_H
