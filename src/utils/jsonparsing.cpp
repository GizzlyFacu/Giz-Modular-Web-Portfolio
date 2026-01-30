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
    blogCards["BackgroundPhoto_link"] =QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/Blogcard%20Card%202%20BigBand%20WalkCycle.gif",
                                                  "https://gizzlyfacu.github.io/GizWeb/remote/Blogcard%20Card%201%20Speedmodeling.gif"};
    blogCards["Link"] =QJsonArray{"https://x.com/GizzlyStation/status/1654655148310896640",
                                  "https://www.linkedin.com/posts/facugizzly_blender-blender3d-activity-7330409512694181889-52LA"};
    blogCards["Title"] = QJsonArray{"Big Band Walk Cycle",
                                    "Gm_flatgrass SpeedWork"};
    blogCards["Description"] =QJsonArray{"Final 3D Art Project: Blender, Substance Painter and Marvelous Designer",
                                         "Blender Geometry Nodes + Procedural Textures, PH and Luminar"};
    root["BlogCards"] = blogCards;

    // TechSkills Coding
    QJsonObject techSkills;
    techSkills["Project_BackgroundPhoto_link"] = QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Coding%20Project%201.jpg"};
    techSkills["Project_Title"] = QJsonArray{"Giz Modular Web Portfolio"};
    techSkills["Project_Link"] = QJsonArray{"https://github.com/GizzlyFacu/Giz-Modular-Web-Portfolio"};
    root["TechSkills"] = techSkills;
    // TechSkills 3DArt
    QJsonObject techSkills3dart;
    techSkills3dart["Project_BackgroundPhoto_link"] = QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%203DArt%20Project%203%20ArchViz.jpg",
                                                                 "https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%203DArt%20Project%201%20Band.jpg",
                                                                 "https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%203DArt%20Project%202%20Weapon.jpg"};
    techSkills3dart["Project_Title"] = QJsonArray{"ArchViz #1",
                                                  "Skullgirls: Big Band",
                                                  "TF2: Loose Cannon"};
    techSkills3dart["Project_Link"] = QJsonArray{"https://www.artstation.com/artwork/NG1mLN",
                                                 "https://www.artstation.com/artwork/g0PYo8",
                                                 "https://www.artstation.com/artwork/18YOJo"};
    root["TechSkills3dArt"] = techSkills3dart;
    // TechSkills 3DGraphics
    QJsonObject techSkills3dgraphics;
    techSkills3dgraphics["Project_BackgroundPhoto_link"] = QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20Project1.png"};
    techSkills3dgraphics["Project_Title"] = QJsonArray{"OpenGl VST Knob"};
    techSkills3dgraphics["Project_Link"] = QJsonArray{"https://github.com/GizzlyFacu/PluginKnob"};
    root["TechSkills3dGraphics"] = techSkills3dgraphics;
    // TechSkills UE
    QJsonObject techSkillsUE;
    techSkillsUE["Project_BackgroundPhoto_link"] = QJsonArray{"https://gizzlyfacu.github.io/GizWeb/remote/TechSkills%20UE%20Project%201.jpg"};
    techSkillsUE["Project_Title"] = QJsonArray{"Prototype: Bark Master"};
    techSkillsUE["Project_Link"] = QJsonArray{"https://gizzlystation.itch.io/"};
    root["TechSkillsUE"] = techSkillsUE;
    return root;
}

QJsonObject JsonParsing::convertFromQByteArray(const QByteArray &content)
{
    QJsonDocument contentDoc=QJsonDocument::fromJson(content);
    QJsonObject obj(contentDoc.object());
    return obj;
}
