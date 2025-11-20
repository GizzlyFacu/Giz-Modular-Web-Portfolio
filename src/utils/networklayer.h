#ifndef NETWORKLAYER_H
#define NETWORKLAYER_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QSharedPointer>
#include <QUrl>
class NetworkLayer : public QObject
{
    Q_OBJECT
public:
    explicit NetworkLayer(QObject *parent = nullptr);
public slots:
    void sayA(){qDebug()<<"a";}
    void makeGetRequest(const QUrl &url);
private slots:
    void onReplyFinished(QNetworkReply *reply);
signals:
    void dataReceived(const QByteArray &data);
    void errorOccurred(const QUrl &error);

private:
    QNetworkAccessManager *m_manager=nullptr;
};

#endif // NETWORKLAYER_H
