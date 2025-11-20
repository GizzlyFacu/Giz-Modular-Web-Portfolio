#include "jsonparsing.h"
#include <QDebug>
JsonParsing::JsonParsing(QObject *parent)
    : QObject{parent}
{
}

QJsonObject JsonParsing::readJson(QString link)
{
    QFile file(link);
    QJsonObject obj;
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        obj = doc.object();
        file.close();
    }
    else {
        return QJsonObject();
    }
    return obj;
}

void JsonParsing::writeJson()
{
    QJsonObject estructura = crearEstructuraJSON();
    QJsonDocument doc(estructura);

    QFile file("configuracion.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }
    else {
        qDebug()<<"error al abrir el archivo";
    }
}

QJsonObject JsonParsing::crearEstructuraJSON()
{
    QJsonObject root;

    // BoxIntroduction
    QJsonObject boxIntroduction;
    boxIntroduction["Photo_link"] = "link.com";
    root["BoxIntroduction"] = boxIntroduction;

    // BlogCards
    QJsonObject blogCards;
    blogCards["BackgroundPhoto_link"] =QJsonArray{"Link1", "Link2", "Link3"};
    blogCards["Title"] = QJsonArray{"Titulo1", "Titulo2", "Titulo3"};
    blogCards["Description"] =QJsonArray{"Description1", "Description2", "Description3"};
    root["BlogCards"] = blogCards;

    // TechSkills
    QJsonObject techSkills;
    techSkills["Project_BackgroundPhoto_link"] = QJsonArray{"PhotoLink1", "PhotoLink2", "PhotoLink3"};
    techSkills["Project_Title"] = QJsonArray{"Titulo1", "Titulo2", "Titulo3"};
    techSkills["Project_Link"] = QJsonArray{"Link1", "Link2", "Link3"};
    root["TechSkills"] = techSkills;

    return root;
}

QJsonObject JsonParsing::convertFromQByteArray(const QByteArray &content)
{
    QJsonDocument contentDoc=QJsonDocument::fromJson(content);
    QJsonObject obj(contentDoc.object());
    return obj;
}
