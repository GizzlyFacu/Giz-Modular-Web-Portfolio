#include "techskillsprojects3dgraphics.h"

TechSkillsProjects3dGraphics::TechSkillsProjects3dGraphics(QObject *parent)
    : QAbstractListModel{parent}
{
    m_listTechSkillsC.reserve(50);
}
int TechSkillsProjects3dGraphics::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listTechSkillsC.length();
}

QVariant TechSkillsProjects3dGraphics::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row()>=0 && index.row()<m_listTechSkillsC.length()){
        QSharedPointer<TechSkillsC> TechSkillsCResult=m_listTechSkillsC[index.row()];
        switch ((Roles)role) {
        case titleRole:
            return TechSkillsCResult->m_Title;
            break;
        case photolinkRole:
            return TechSkillsCResult->m_photoLink;
            break;
        case LinkRole:
            return TechSkillsCResult->m_Link;
            break;
        }
    }
    return{};
}

QHash<int, QByteArray> TechSkillsProjects3dGraphics::roleNames() const
{

    QHash<int,QByteArray> result;
    result[titleRole]="title";
    result[photolinkRole]="photoLink";
    result[LinkRole]="link";
    return result;
}

void TechSkillsProjects3dGraphics::addThings(const QString Photolink,const QString Title, const QString Link)
{

    beginInsertRows(QModelIndex(),m_listTechSkillsC.length(),m_listTechSkillsC.length());
    m_listTechSkillsC << QSharedPointer<TechSkillsC>::create(Photolink,Title,Link);
    endInsertRows();
}
