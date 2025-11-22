#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <QObject>
#include <QQmlEngine>
#include "abstractlistmodels/blogcardmodel.h"
#include "abstractlistmodels/techskillsprojects.h"
#include "abstractlistmodels/techskillsprojects3dart.h"
#include "abstractlistmodels/techskillsprojects3dgraphics.h"
#include "abstractlistmodels/techskillsprojectsUE.h"
struct BoxIntroduction{
    Q_GADGET
    Q_PROPERTY(QString PhotoLink MEMBER m_PhotoLink)
public:
    QString m_PhotoLink;
    BoxIntroduction(QString PhotoLink = "qrc:/images/assets/imagesLocal/yo.jpeg"){
        m_PhotoLink=PhotoLink;
    }
};
class StorageManager : public QObject
{
    Q_OBJECT
public:
    explicit StorageManager(QObject *parent = nullptr);
    Q_PROPERTY(BoxIntroduction boxintroduction READ boxintroduction NOTIFY boxintroductionChanged FINAL)
    Q_PROPERTY(TechSkillsProjects* techskillsmodel READ techskillsmodel WRITE setTechskillsmodel NOTIFY techskillsmodelChanged FINAL)
    Q_PROPERTY(BlogCardModel* blogcardmodel READ blogcardmodel WRITE setblogcardmodel NOTIFY blogcardmodelChanged FINAL)
    Q_PROPERTY(TechSkillsProjects3dArt* techskills3dartmodel READ techskills3dartmodel WRITE setTechskills3dartmodel NOTIFY techskills3dartmodelChanged FINAL)
    Q_PROPERTY(TechSkillsProjects3dGraphics* techskills3dgraphics READ techskills3dgraphics WRITE setTechskills3dgraphics NOTIFY techskills3dgraphicsChanged FINAL)
    Q_PROPERTY(TechSkillsProjectsUE* techskillsUEmodel READ techskillsUEmodel WRITE setTechskillsUEmodel NOTIFY techskillsUEmodelChanged FINAL)
    BoxIntroduction boxintroduction() const;
    BlogCardModel *blogcardmodel() const;
    TechSkillsProjects *techskillsmodel() const;
    TechSkillsProjects3dArt *techskills3dartmodel() const;
    TechSkillsProjects3dGraphics *techskills3dgraphics() const;
    TechSkillsProjectsUE *techskillsUEmodel() const;
    void setBoxintroduction(const BoxIntroduction &newBoxintroduction);
    void setblogcardmodel(BlogCardModel *newblogcardmodel);
    void setTechskillsmodel(TechSkillsProjects *newTechskillsmodel);
    void setTechskills3dartmodel(TechSkillsProjects3dArt *newTechskills3dartmodel);   
    void setTechskills3dgraphics(TechSkillsProjects3dGraphics *newTechskills3dgraphics);
    void setTechskillsUEmodel(TechSkillsProjectsUE *newTechskillsUEmodel);

public slots:

private:

    BoxIntroduction m_boxintroduction;
    BlogCardModel *m_blogcardmodel = new BlogCardModel(this);
    TechSkillsProjects *m_techskillsmodel = new TechSkillsProjects(this);
    TechSkillsProjects3dArt *m_techskills3dartmodel = new TechSkillsProjects3dArt(this);
    TechSkillsProjects3dGraphics *m_techskills3dgraphics = new TechSkillsProjects3dGraphics(this);
    TechSkillsProjectsUE *m_techskillsUEmodel = new TechSkillsProjectsUE(this);

signals:
    void boxintroductionChanged();
    void blogcardmodelChanged();
    void techskillsmodelChanged();
    void techskills3dartmodelChanged();
    void techskills3dgraphicsChanged();
    void techskillsUEmodelChanged();
};

#endif // STORAGEMANAGER_H
