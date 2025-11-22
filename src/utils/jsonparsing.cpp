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
        qWarning()<<"error el leer el .json, el archivo ya esta abrido.";
        return QJsonObject();
    }
    return obj;
}

void JsonParsing::writeJson()
{
    QJsonObject estructura = crearEstructuraJSON();
    QJsonDocument doc(estructura);

    QFile file("configuracionLocal.json");
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
    boxIntroduction["Photo_link"] = "https://gizzlyfacu.github.io/GizWeb/remote/BoxIntroduction%20Photo.jpeg";
    root["BoxIntroduction"] = boxIntroduction;

    // BlogCards
    QJsonObject blogCards;
    blogCards["BackgroundPhoto_link"] =QJsonArray{"https://raw.githubusercontent.com/GizzlyFacu/GizWeb/refs/heads/main/remote/BlogCard%20Photo%201.jpg", "https://gizzlyfacu.github.io/GizWeb/remote/BlogCard%20Photo%202.jpg"};
    blogCards["Title"] = QJsonArray{"Archviz Exterior #1", "Terrarian Yoyo"};
    blogCards["Description"] =QJsonArray{"First Archviz Render, Inspired by the Heydar Aliyev Cultural Center", "Made with Blender & Substance Painter"};
    root["BlogCards"] = blogCards;

    // TechSkills Coding
    QJsonObject techSkills;
    techSkills["Project_BackgroundPhoto_link"] = QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project1.png", "https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project2.png"};
    techSkills["Project_Title"] = QJsonArray{"OpenGl VST Knob", "VaultTones"};
    techSkills["Project_Link"] = QJsonArray{"https://github.com/GizzlyFacu/PluginKnob", "https://github.com/GizzlyFacu/GizzlyVaultTones"};
    root["TechSkills"] = techSkills;
    // TechSkills 3DArt
    QJsonObject techSkills3dart;
    techSkills3dart["Project_BackgroundPhoto_link"] = QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project1.png", "https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project2.png"};
    techSkills3dart["Project_Title"] = QJsonArray{"OpenGl VST Knob 2", "VaultTones 2"};
    techSkills3dart["Project_Link"] = QJsonArray{"https://github.com/GizzlyFacu/PluginKnob", "https://github.com/GizzlyFacu/GizzlyVaultTones"};
    root["TechSkills3dArt"] = techSkills3dart;
    // TechSkills 3DGraphics
    QJsonObject techSkills3dgraphics;
    techSkills3dgraphics["Project_BackgroundPhoto_link"] = QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project1.png", "https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project2.png"};
    techSkills3dgraphics["Project_Title"] = QJsonArray{"OpenGl VST Knob 3", "VaultTones 3"};
    techSkills3dgraphics["Project_Link"] = QJsonArray{"https://github.com/GizzlyFacu/PluginKnob", "https://github.com/GizzlyFacu/GizzlyVaultTones"};
    root["TechSkills3dGraphics"] = techSkills3dgraphics;
    // TechSkills UE
    QJsonObject techSkillsUE;
    techSkillsUE["Project_BackgroundPhoto_link"] = QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project1.png", "https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project2.png"};
    techSkillsUE["Project_Title"] = QJsonArray{"OpenGl VST Knob 4", "VaultTones 4"};
    techSkillsUE["Project_Link"] = QJsonArray{"https://github.com/GizzlyFacu/PluginKnob", "https://github.com/GizzlyFacu/GizzlyVaultTones"};
    root["TechSkillsUE"] = techSkillsUE;
    return root;
}

QJsonObject JsonParsing::convertFromQByteArray(const QByteArray &content)
{
    QJsonDocument contentDoc=QJsonDocument::fromJson(content);
    QJsonObject obj(contentDoc.object());
    return obj;
}
