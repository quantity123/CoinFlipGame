#ifndef QSTARTSCENE_H
#define QSTARTSCENE_H

#include <QWidget>
#include "qstartandbackpushbtn.h"
#include <QSound>

class QStartScene : public QWidget
{
    Q_OBJECT
public:
    explicit QStartScene(QWidget *parent = nullptr);
    void setFixedWindowSize(const int &aWidth, const int &aHeight);
signals:
protected:
    //绘图事件
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap mStartSceneBackground;
    QPixmap mGameTitle;
    QStartAndBackPushBtn mStartButton;
    QSound mPressStartButtonSound;
    QWidget *mMainWindow;
};

#endif // QSTARTSCENE_H
