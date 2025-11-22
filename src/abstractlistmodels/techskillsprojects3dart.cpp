#include "techskillsprojects3dart.h"

TechSkillsProjects3dArt::TechSkillsProjects3dArt(QObject *parent)
    : QAbstractListModel{parent}
{
    m_listTechSkillsB.reserve(50);
}
int TechSkillsProjects3dArt::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listTechSkillsB.length();
}

QVariant TechSkillsProjects3dArt::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row()>=0 && index.row()<m_listTechSkillsB.length()){
        QSharedPointer<TechSkillsB> TechSkillsBResult=m_listTechSkillsB[index.row()];
        switch ((Roles)role) {
        case titleRole:
            return TechSkillsBResult->m_Title;
            break;
        case photolinkRole:
            return TechSkillsBResult->m_photoLink;
            break;
        case LinkRole:
            return TechSkillsBResult->m_Link;
            break;
        }
    }
    return{};
}

QHash<int, QByteArray> TechSkillsProjects3dArt::roleNames() const
{

    QHash<int,QByteArray> result;
    result[titleRole]="title";
    result[photolinkRole]="photoLink";
    result[LinkRole]="link";
    return result;
}

void TechSkillsProjects3dArt::addThings(const QString Photolink,const QString Title, const QString Link)
{

    beginInsertRows(QModelIndex(),m_listTechSkillsB.length(),m_listTechSkillsB.length());
    m_listTechSkillsB << QSharedPointer<TechSkillsB>::create(Photolink,Title,Link);
    endInsertRows();
}
