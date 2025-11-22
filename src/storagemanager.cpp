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

TechSkillsProjects3dArt *StorageManager::techskills3dartmodel() const
{
    return m_techskills3dartmodel;
}

void StorageManager::setTechskills3dartmodel(TechSkillsProjects3dArt *newTechskills3dartmodel)
{
    if (m_techskills3dartmodel == newTechskills3dartmodel)
        return;
    m_techskills3dartmodel = newTechskills3dartmodel;
    emit techskills3dartmodelChanged();
}

TechSkillsProjects3dGraphics *StorageManager::techskills3dgraphics() const
{
    return m_techskills3dgraphics;
}

void StorageManager::setTechskills3dgraphics(TechSkillsProjects3dGraphics *newTechskills3dgraphics)
{
    if (m_techskills3dgraphics == newTechskills3dgraphics)
        return;
    m_techskills3dgraphics = newTechskills3dgraphics;
    emit techskills3dgraphicsChanged();
}

TechSkillsProjectsUE *StorageManager::techskillsUEmodel() const
{
    return m_techskillsUEmodel;
}

void StorageManager::setTechskillsUEmodel(TechSkillsProjectsUE *newTechskillsUEmodel)
{
    if (m_techskillsUEmodel == newTechskillsUEmodel)
        return;
    m_techskillsUEmodel = newTechskillsUEmodel;
    emit techskillsUEmodelChanged();
}
