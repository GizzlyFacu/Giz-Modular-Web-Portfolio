#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <QObject>
#include <QQmlEngine>
#include "abstractlistmodels/blogcardmodel.h"
#include "abstractlistmodels/techskillsprojects.h"

struct BoxIntroduction{
    Q_GADGET
    Q_PROPERTY(QString PhotoLink MEMBER m_PhotoLink)
public:
    QString m_PhotoLink;
    BoxIntroduction(QString PhotoLink = "BoxIntroduction PhotoLink"){
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

    BoxIntroduction boxintroduction() const;
    BlogCardModel *blogcardmodel() const;
    TechSkillsProjects *techskillsmodel() const;

    void setBoxintroduction(const BoxIntroduction &newBoxintroduction);
    void setblogcardmodel(BlogCardModel *newblogcardmodel);
    void setTechskillsmodel(TechSkillsProjects *newTechskillsmodel);

public slots:

private:

    BoxIntroduction m_boxintroduction;
    BlogCardModel *m_blogcardmodel = new BlogCardModel(this);
    TechSkillsProjects *m_techskillsmodel = new TechSkillsProjects(this);

signals:
    void boxintroductionChanged();
    void blogcardmodelChanged();
    void techskillsmodelChanged();
};

#endif // STORAGEMANAGER_H
