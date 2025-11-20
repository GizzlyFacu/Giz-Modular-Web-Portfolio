#include "storagemanager.h"

StorageManager::StorageManager(QObject *parent)
    : QObject{parent}
{
}

BoxIntroduction StorageManager::boxintroduction() const
{
    return m_boxintroduction;
}

void StorageManager::setBoxintroduction(const BoxIntroduction &newBoxintroduction)
{
    m_boxintroduction = newBoxintroduction;
}


BlogCardModel *StorageManager::blogcardmodel() const
{
    return m_blogcardmodel;
}

void StorageManager::setblogcardmodel(BlogCardModel *newblogcardmodel)
{
    if (m_blogcardmodel == newblogcardmodel)
        return;
    m_blogcardmodel = newblogcardmodel;
    emit blogcardmodelChanged();
}

TechSkillsProjects *StorageManager::techskillsmodel() const
{
    return m_techskillsmodel;
}

void StorageManager::setTechskillsmodel(TechSkillsProjects *newTechskillsmodel)
{
    if (m_techskillsmodel == newTechskillsmodel)
        return;
    m_techskillsmodel = newTechskillsmodel;
    emit techskillsmodelChanged();
}
