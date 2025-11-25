#include "blogcardmodel.h"

BlogCardModel::BlogCardModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_listBlogCardM.reserve(50);
}
int BlogCardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_listBlogCardM.length();
}

QVariant BlogCardModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row()>=0 && index.row()<m_listBlogCardM.length()){
        QSharedPointer<BlogCardM> BlogCardMResult=m_listBlogCardM[index.row()];
        switch ((Roles)role) {
        case titleRole:
            return BlogCardMResult->title;
            break;
        case photolinkRole:
            return BlogCardMResult->photoLink;
            break;
        case descriptionRole:
            return BlogCardMResult->description;
            break;
        case linkRole:
            return BlogCardMResult->link;
            break;
        }
    }
    return{};
}

QHash<int, QByteArray> BlogCardModel::roleNames() const
{

    QHash<int,QByteArray> result;
    result[titleRole]="title";
    result[photolinkRole]="photoLink";
    result[descriptionRole]="description";
    result[linkRole]="link";
    return result;
}

void BlogCardModel::addThings(const QString Photolink,const QString Title, const QString Description, const QString Link)
{

    beginInsertRows(QModelIndex(),m_listBlogCardM.length(),m_listBlogCardM.length());
    m_listBlogCardM << QSharedPointer<BlogCardM>::create(Photolink,Title,Description,Link);
    endInsertRows();
}
