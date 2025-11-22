#ifndef TECHSKILLSPROJECTS3DART_H
#define TECHSKILLSPROJECTS3DART_H

#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>


struct TechSkillsB{
    QString m_photoLink;
    QString m_Title;
    QString m_Link;
public:
    TechSkillsB(QString PhotoLink="qrc:/images/assets/imagesLocal/loader.jpg",
               QString Title="TechSkills3DART Title",
               QString Link="TechSkills3DART Link")
    {
        m_photoLink=PhotoLink;
        m_Title=Title;
        m_Link=Link;
    }
};

class TechSkillsProjects3dArt: public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit TechSkillsProjects3dArt(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;

    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
    enum Roles{
        photolinkRole=Qt::UserRole+10,
        titleRole,
        LinkRole
    };
    void addThings(const QString Photolink,const QString Title, const QString Link);
private:
    QList<QSharedPointer<TechSkillsB>> m_listTechSkillsB;
signals:
};

#endif // TECHSKILLSPROJECTS3DART_H
