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
    emit m_storageManager->boxintroductionChanged();
}

void ConfigCenter::loadconfig_BlogCards(const QJsonObject &data)
{
    //-----BlogCards--------
    //aniadiendo structs
    const QJsonArray titles = data["BlogCards"].toObject()["Title"].toArray();
    const QJsonArray photolinks = data["BlogCards"].toObject()["BackgroundPhoto_link"].toArray();
    const QJsonArray links = data["BlogCards"].toObject()["Link"].toArray();
    const QJsonArray descriptions = data["BlogCards"].toObject()["Description"].toArray();

    for (int x = 0; x < titles.count(); ++x) {
        QString title = titles[x].toString();
        QString link = links[x].toString();
        QString photolink = photolinks[x].toString();
        QString description = descriptions[x].toString();

        m_storageManager->blogcardmodel()->addThings(photolink,title,description,link);
    }
    emit m_storageManager->blogcardmodelChanged();
}

void ConfigCenter::loadconfig_TechSkills(const QJsonObject &data)
{
    //-----TechSkills Coding--------
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

void ConfigCenter::loadconfig_TechSkills3dArt(const QJsonObject &data)
{
    //-----TechSkills3dArt--------
    //aniadiendo structs
    const QJsonArray titles = data["TechSkills3dArt"].toObject()["Project_Title"].toArray();
    const QJsonArray photolinks = data["TechSkills3dArt"].toObject()["Project_BackgroundPhoto_link"].toArray();
    const QJsonArray links = data["TechSkills3dArt"].toObject()["Project_Link"].toArray();

    for (int x = 0; x < titles.count(); ++x) {
        QString title = titles[x].toString();
        QString photolink = photolinks[x].toString();
        QString link = links[x].toString();
        m_storageManager->techskills3dartmodel()->addThings(photolink,title,link);
    }
    emit m_storageManager->techskills3dartmodelChanged();
}

void ConfigCenter::loadconfig_TechSkills3dGraphics(const QJsonObject &data)
{
    //-----TechSkills3dGraphics--------
    //aniadiendo structs
    const QJsonArray titles = data["TechSkills3dGraphics"].toObject()["Project_Title"].toArray();
    const QJsonArray photolinks = data["TechSkills3dGraphics"].toObject()["Project_BackgroundPhoto_link"].toArray();
    const QJsonArray links = data["TechSkills3dGraphics"].toObject()["Project_Link"].toArray();

    for (int x = 0; x < titles.count(); ++x) {
        QString title = titles[x].toString();
        QString photolink = photolinks[x].toString();
        QString link = links[x].toString();
        m_storageManager->techskills3dgraphics()->addThings(photolink,title,link);
    }
    emit m_storageManager->techskills3dgraphicsChanged();
}

void ConfigCenter::loadconfig_TechSkillsUE(const QJsonObject &data)
{
    //-----TechSkillsUE--------
    //aniadiendo structs
    const QJsonArray titles = data["TechSkillsUE"].toObject()["Project_Title"].toArray();
    const QJsonArray photolinks = data["TechSkillsUE"].toObject()["Project_BackgroundPhoto_link"].toArray();
    const QJsonArray links = data["TechSkillsUE"].toObject()["Project_Link"].toArray();

    for (int x = 0; x < titles.count(); ++x) {
        QString title = titles[x].toString();
        QString photolink = photolinks[x].toString();
        QString link = links[x].toString();
        m_storageManager->techskillsUEmodel()->addThings(photolink,title,link);
    }
    emit m_storageManager->techskillsUEmodelChanged();
}

void ConfigCenter::setOnline(bool isOnline)
{

    if(isOnline){
        connect(m_networkManager,&NetworkLayer::dataReceived,
                this,&ConfigCenter::onDataReceived);
        connect(m_networkManager,&NetworkLayer::errorOccurred,
                this, &ConfigCenter::onDataReceivednt);

        const QUrl contentUrl("https://raw.githubusercontent.com/GizzlyFacu/GizWeb/refs/heads/main/remote/configuracion.json");
        m_networkManager->makeGetRequest(contentUrl);
    }
    else {
        m_jsonParsing.writeJson();
        const QJsonObject dataJson = m_jsonParsing.readJson("configuracionLocal.json");
        qDebug()<<"data local: \n"<<dataJson.length()<<"\n";
        loadconfig_BoxIntroduction(dataJson);
        loadconfig_BlogCards(dataJson);
        loadconfig_TechSkills(dataJson);
        loadconfig_TechSkills3dArt(dataJson);
        loadconfig_TechSkills3dGraphics(dataJson);
        loadconfig_TechSkillsUE(dataJson);

    }
}

void ConfigCenter::onDataReceived(const QByteArray &jsonData)
{
    const QJsonObject dataJson = QJsonDocument::fromJson(jsonData).object();
    qDebug()<<"data recibida: \n"<<jsonData.toStdString()<<"\n";
    loadconfig_BoxIntroduction(dataJson);
    loadconfig_BlogCards(dataJson);
    loadconfig_TechSkills(dataJson);
    loadconfig_TechSkills3dArt(dataJson);
    loadconfig_TechSkills3dGraphics(dataJson);
    loadconfig_TechSkillsUE(dataJson);
}

void ConfigCenter::onDataReceivednt(const QUrl &url)
{
    //qWarning()<<"error transmitido desde qnetworlayout /n: "<<url.toString();
}
