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
        //aca se cargan los datos:
        //true: descarga de github
        //false: escribe y lee desde local
        setOnline(false);
    }
    void loadconfig_BoxIntroduction(const QJsonObject &data);
    void loadconfig_BlogCards(const QJsonObject &data);
    void loadconfig_TechSkills(const QJsonObject &data);
    void loadconfig_TechSkills3dArt(const QJsonObject &data);
    void loadconfig_TechSkills3dGraphics(const QJsonObject &data);
    void loadconfig_TechSkillsUE(const QJsonObject &data);
    void setOnline(bool isOnline);
public slots:
    void sayA(){qDebug()<<"aaa";}
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
