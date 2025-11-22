#ifndef TECHSKILLSPROJECTS3DGRAPHICS_H
#define TECHSKILLSPROJECTS3DGRAPHICS_H

#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>


struct TechSkillsC{
    QString m_photoLink;
    QString m_Title;
    QString m_Link;
public:
    TechSkillsC(QString PhotoLink="qrc:/images/assets/imagesLocal/loader.jpg",
               QString Title="TechSkills Title",
               QString Link="TechSkills Link")
    {
        m_photoLink=PhotoLink;
        m_Title=Title;
        m_Link=Link;
    }
};

class TechSkillsProjects3dGraphics : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit TechSkillsProjects3dGraphics(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;

    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
    enum Roles{
        photolinkRole=Qt::UserRole+4,
        titleRole,
        LinkRole
    };
    void addThings(const QString Photolink,const QString Title, const QString Link);
private:
    QList<QSharedPointer<TechSkillsC>> m_listTechSkillsC;
signals:
};

#endif // TECHSKILLSPROJECTS3DGRAPHICS_H
