#ifndef BLOGCARDMODEL_H
#define BLOGCARDMODEL_H

#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>


struct BlogCardM{
    QString photoLink;
    QString title;
    QString description;
    QString link;
public:
    BlogCardM(QString PhotoLink="qrc:/images/assets/imagesLocal/loader.jpg",
              QString Title="null",
              QString Description="null",
              QString Link="null"){
        photoLink=PhotoLink;
        title=Title;
        description=Description;
        link=Link;
    }
};

class BlogCardModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit BlogCardModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;

    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
    enum Roles{
        photolinkRole=Qt::UserRole+1,
        linkRole,
        titleRole,
        descriptionRole
    };
    void addThings(const QString Photolink,const QString Title, const QString Description, const QString Link);
private:
    QList<QSharedPointer<BlogCardM>> m_listBlogCardM;
signals:
};

#endif // BLOGCARDMODEL_H
