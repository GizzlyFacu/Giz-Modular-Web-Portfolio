#include "techskillsprojectsUE.h"

TechSkillsProjectsUE::TechSkillsProjectsUE(QObject *parent)
    : QAbstractListModel{parent}
{
    m_listTechSkillsE.reserve(50);
}
int TechSkillsProjectsUE::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listTechSkillsE.length();
}

QVariant TechSkillsProjectsUE::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row()>=0 && index.row()<m_listTechSkillsE.length()){
        QSharedPointer<TechSkillsE> TechSkillsEResult=m_listTechSkillsE[index.row()];
        switch ((Roles)role) {
        case titleRole:
            return TechSkillsEResult->m_Title;
            break;
        case photolinkRole:
            return TechSkillsEResult->m_photoLink;
            break;
        case LinkRole:
            return TechSkillsEResult->m_Link;
            break;
        }
    }
    return{};
}

QHash<int, QByteArray> TechSkillsProjectsUE::roleNames() const
{

    QHash<int,QByteArray> result;
    result[titleRole]="title";
    result[photolinkRole]="photoLink";
    result[LinkRole]="link";
    return result;
}

void TechSkillsProjectsUE::addThings(const QString Photolink,const QString Title, const QString Link)
{

    beginInsertRows(QModelIndex(),m_listTechSkillsE.length(),m_listTechSkillsE.length());
    m_listTechSkillsE << QSharedPointer<TechSkillsE>::create(Photolink,Title,Link);
    endInsertRows();
}
