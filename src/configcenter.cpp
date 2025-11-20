#include "configcenter.h"
#include <QJsonObject>
#include <QJsonDocument>

void ConfigCenter::loadconfig_BoxIntroduction(const QJsonObject &data)
{
    //-----BoxIntroduction--------
    BoxIntroduction newBoxIntroduction(
        data["BoxIntroduction"].toObject()["Photo_link"].toString()
        );
    m_storageManager->setBoxintroduction(newBoxIntroduction);
}

void ConfigCenter::loadconfig_BlogCards(const QJsonObject &data)
{
    //-----BlogCards--------
    //aniadiendo structs
    const QJsonArray titles = data["BlogCards"].toObject()["Title"].toArray();
    const QJsonArray photolinks = data["BlogCards"].toObject()["BackgroundPhoto_link"].toArray();
    const QJsonArray descriptions = data["BlogCards"].toObject()["Description"].toArray();

    for (int x = 0; x < titles.count(); ++x) {
        QString title = titles[x].toString();
        QString photolink = photolinks[x].toString();
        QString description = descriptions[x].toString();
        m_storageManager->blogcardmodel()->addThings(photolink,title,description);
    }
    emit m_storageManager->blogcardmodelChanged();
}

void ConfigCenter::loadconfig_TechSkills(const QJsonObject &data)
{
    //-----BlogCards--------
    //aniadiendo structs
    const QJsonArray titles = data["TechSkills"].toObject()["Project_Title"].toArray();
    const QJsonArray photolinks = data["TechSkills"].toObject()["Project_BackgroundPhoto_link"].toArray();
    const QJsonArray links = data["TechSkills"].toObject()["Project_Link"].toArray();

    for (int x = 0; x < titles.count(); ++x) {
        QString title = titles[x].toString();
        QString photolink = photolinks[x].toString();
        QString link = links[x].toString();
        m_storageManager->techskillsmodel()->addThings(photolink,title,link);
    }
    emit m_storageManager->techskillsmodelChanged();
}

void ConfigCenter::onDataReceived(const QByteArray &jsonData)
{
    const QJsonObject dataJson = QJsonDocument::fromJson(jsonData).object();
    qDebug()<<"data recibida: /n"<<jsonData.toStdString()<<"/n";
    loadconfig_BoxIntroduction(dataJson);
    loadconfig_BlogCards(dataJson);
    loadconfig_TechSkills(dataJson);
}

void ConfigCenter::onDataReceivednt(const QUrl &url)
{
    //qWarning()<<"error transmitido desde qnetworlayout /n: "<<url.toString();
}
