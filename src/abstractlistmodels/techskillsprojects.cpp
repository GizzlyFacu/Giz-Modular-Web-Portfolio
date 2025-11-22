#include "techskillsprojects.h"

TechSkillsProjects::TechSkillsProjects(QObject *parent)
    : QAbstractListModel{parent}
{
    m_listTechSkillsM.reserve(50);
}
int TechSkillsProjects::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listTechSkillsM.length();
}

QVariant TechSkillsProjects::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row()>=0 && index.row()<m_listTechSkillsM.length()){
        QSharedPointer<TechSkillsM> TechSkillsMResult=m_listTechSkillsM[index.row()];
        switch ((Roles)role) {
        case titleRole:
            return TechSkillsMResult->m_Title;
            break;
        case photolinkRole:
            return TechSkillsMResult->m_photoLink;
            break;
        case LinkRole:
            return TechSkillsMResult->m_Link;
            break;
        }
    }
    return{};
}

QHash<int, QByteArray> TechSkillsProjects::roleNames() const
{

    QHash<int,QByteArray> result;
    result[titleRole]="title";
    result[photolinkRole]="photoLink";
    result[LinkRole]="link";
    return result;
}

void TechSkillsProjects::addThings(const QString Photolink,const QString Title, const QString Link)
{

    beginInsertRows(QModelIndex(),m_listTechSkillsM.length(),m_listTechSkillsM.length());
    m_listTechSkillsM << QSharedPointer<TechSkillsM>::create(Photolink,Title,Link);
    endInsertRows();
}
