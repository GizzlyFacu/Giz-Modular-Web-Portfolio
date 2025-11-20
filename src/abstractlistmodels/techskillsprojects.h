#ifndef TECHSKILLSPROJECTS_H
#define TECHSKILLSPROJECTS_H

#include <QObject>
#include <QQmlEngine>
#include <QAbstractListModel>


struct TechSkillsM{
    QString m_photoLink;
    QString m_Title;
    QString m_Link;
public:
    TechSkillsM(QString PhotoLink="TechSkills Background Link",
               QString Title="TechSkills Title",
               QString Link="TechSkills Link")
    {
        m_photoLink=PhotoLink;
        m_Title=Title;
        m_Link=Link;
    }
};

class TechSkillsProjects : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit TechSkillsProjects(QObject *parent = nullptr);

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
    QList<QSharedPointer<TechSkillsM>> m_listTechSkillsM;
signals:
};

#endif // TECHSKILLSPROJECTS_H
