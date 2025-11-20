#ifndef JSONPARSING_H
#define JSONPARSING_H

#include <QObject>
#include <QQmlEngine>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QFile>
class JsonParsing : public QObject
{
    Q_OBJECT
public:
    explicit JsonParsing(QObject *parent = nullptr);
    QJsonObject readJson(QString link);
    QJsonObject crearEstructuraJSON();
    QJsonObject convertFromQByteArray(const QByteArray &content);
    void sayA(){
        qDebug()<<"say AAAAA";
    }
public slots:
    void writeJson();
signals:
};

#endif // JSONPARSING_H
