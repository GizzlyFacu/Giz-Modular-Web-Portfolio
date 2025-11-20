#include "networklayer.h"


NetworkLayer::NetworkLayer(QObject *parent)
    : QObject{parent}
{
    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished,
            this, &NetworkLayer::onReplyFinished);
}

void NetworkLayer::makeGetRequest(const QUrl &url)
{
    const QUrl requestUrl(url);

    if (!requestUrl.isValid()) {
        emit errorOccurred(url);
        return;
    }

    qDebug() << "Solicitando URL:" << url;

    // Realizar la solicitud GET
    m_manager->get(QNetworkRequest(requestUrl));
}

void NetworkLayer::onReplyFinished(QNetworkReply *reply)
{
    // Verificar si hubo error
    if (reply->error() != QNetworkReply::NoError) {
        QString errorString = "Error: " + reply->errorString();
        qWarning() << errorString;
        emit errorOccurred(errorString);
        reply->deleteLater();
        return;
    }

    // Leer los datos prohibidos
    QByteArray data = reply->readAll();
    // Emitir señal con los datos
    emit dataReceived(data);

    // Limpiar el reply
    reply->deleteLater();
}
