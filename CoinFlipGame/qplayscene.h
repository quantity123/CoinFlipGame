#ifndef QPLAYSCENE_H
#define QPLAYSCENE_H

#include <QWidget>
#include "qstartandbackpushbtn.h"
#include <QSound>
#include <QLabel>
#include "qcoinbtnrowarray.h"
#include <QTimer>

class QLevelConfig;

class QPlayScene : public QWidget
{
    Q_OBJECT
public:
    explicit QPlayScene(QWidget *parent = nullptr);
    void setFixedWindowSize(const int &aWidth, const int &aHeight);
    void buildCoinBtnRowArray(uint &aRowCount, uint &aColCount);
    void setBackBtnMovePoint(const QPoint &aPoint);
    void setPlayLevel(const QString &aLevel, const QLevelConfig::QLevelConfigArray &levelConfigArray);
    const bool& isWin() const;
    const bool& isCoinFlipping() const;
    void setCoinFlipping();
    void changeCoinUpperLowerLeftRightFlag(const uint &aRowNum, const uint &aColNum);
signals:
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QPixmap mPlaySceneBackground;
    QPixmap mGameTitle;
    bool mIsWin;
    QLabel mWinLabel;   //胜利显示的图片
    QSound mWinSound;
    QPropertyAnimation mWinLabelAnimation;  //胜利时候的动画
    bool mIsCoinFlipping;
    QTimer mIsCoinFlippingTimer;
    QSound mCoinFlipSound;
    QCoinBtnRowArray mCoinBtnRowArray;
    QLabel mLevelInfo;
    QStartAndBackPushBtn mBackChooseLevelSceneBtn;
    QSound mBackChooseLevelSceneBtnClickSound;
    QWidget *mMainWindow;
};

#endif // QPLAYSCENE_H
