#ifndef QCHOOSELEVELSCENE_H
#define QCHOOSELEVELSCENE_H

#include <QWidget>
#include "qstartandbackpushbtn.h"
#include <QSound>

class QChooseLevelScene : public QWidget
{
    Q_OBJECT
public:
    explicit QChooseLevelScene(QWidget *parent = nullptr);
    void setFixedWindowSize(const int &aWidth, const int &aHeight);
    void createLevel(uint aLevelCount);
    void setBackBtnMovePoint(const QPoint &aPoint);
signals:
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap mChooseLevelSceneBackground;
    QPixmap mGameTitle;
    QSound mChooseLevelBtnClickSound;
    QStartAndBackPushBtn mBackStartSceneBtn;
    QSound mBackStartSceneBtnClickSound;
    QWidget *mMainWindow;
};

#endif // QCHOOSELEVELSCENE_H
