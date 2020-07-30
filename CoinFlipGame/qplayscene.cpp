#include "qplayscene.h"
#include <QPainter>
#include "mainwindow.h"

QPlayScene::QPlayScene(QWidget *parent)
    : QWidget(parent)
    , mPlaySceneBackground(":/res/PlayLevelSceneBg.png")
    , mGameTitle(":/res/Title.png")
    , mIsWin(false)
    , mWinLabel(this)
    , mWinSound(":/res/LevelWinSound.wav", this)
    , mWinLabelAnimation(this)
    , mIsCoinFlipping(false)
    , mIsCoinFlippingTimer(this)
    , mCoinFlipSound(":/res/ConFlipSound.wav", this)
    , mCoinBtnRowArray(this)
    , mLevelInfo(this)
    , mBackChooseLevelSceneBtn(":/res/BackButton.png", ":/res/BackButtonSelected.png")
    , mBackChooseLevelSceneBtnClickSound(":/res/BackButtonSound.wav", this)
    , mMainWindow(parent)
{
    this->hide();

    //设置游戏标题图标比例大小
    mGameTitle = mGameTitle.scaled(mGameTitle.width()*0.5, mGameTitle.height()*0.5);

    //设置动画对象是哪个目标
    mWinLabelAnimation.setTargetObject(&mWinLabel);
    //设置动画属性类型
    mWinLabelAnimation.setPropertyName("geometry");
    //设置动画播放时间
    mWinLabelAnimation.setDuration(2000);
    //设置动画缓缓移动曲线
    mWinLabelAnimation.setEasingCurve(QEasingCurve::OutBounce);

    auto onIsFlippingTimer = [=]()
    {
        mIsCoinFlippingTimer.stop();
        //检查游戏是否胜利并设置标记
        mIsWin = mCoinBtnRowArray.checkIsWin();
        if (mIsWin)
        {
            //游戏胜利音效
            mWinSound.play();
            //执行胜利图片动画
            mWinLabelAnimation.start();
        }
        mIsCoinFlipping = false;
    };
    connect(&mIsCoinFlippingTimer, &QTimer::timeout, onIsFlippingTimer);

    //设置当前关卡的字体和位置与大小
    QFont font;
    font.setFamily("正楷");
    font.setPointSize(20);
    mLevelInfo.setFont(font);
    mLevelInfo.setFixedSize(150, 40);
    mLevelInfo.setText("Level:0");

    //设置返回按钮
    mBackChooseLevelSceneBtn.setParent(this);
    auto onBackChooseLevelBtnClicked = [&]()
    {
        mBackChooseLevelSceneBtnClickSound.play();
        dynamic_cast<MainWindow *>(mMainWindow)->setScene(MainWindow::SceneType::stChooseLevelScene);
        this->hide();
    };
    connect(&mBackChooseLevelSceneBtn, &QStartAndBackPushBtn::clicked, onBackChooseLevelBtnClicked);
}

void QPlayScene::setFixedWindowSize(const int &aWidth, const int &aHeight)
{
    this->setFixedSize(aWidth, aHeight);

    QPixmap winPixmap;
    winPixmap.load(":/res/LevelCompletedDialogBg.png");
    mWinLabel.setPixmap(winPixmap);
    mWinLabel.setFixedSize(winPixmap.width(), winPixmap.height());

    mLevelInfo.move(5, aHeight-60);
}

void QPlayScene::buildCoinBtnRowArray(uint &aRowCount, uint &aColCount)
{
    mCoinBtnRowArray.buildCoinBtnRowArray(this, aRowCount, aColCount);
}

void QPlayScene::setBackBtnMovePoint(const QPoint &aPoint)
{
    mBackChooseLevelSceneBtn.move(aPoint.x(), aPoint.y());
}

void QPlayScene::setPlayLevel(const QString &aLevel, const QLevelConfig::QLevelConfigArray &levelConfigArray)
{
    mLevelInfo.setText("Level:" + aLevel);

    mWinLabel.move((this->width()-mWinLabel.width())*0.5, -mWinLabel.height());

    //设置动画起始位置
    mWinLabelAnimation.setStartValue(QRect(mWinLabel.x(), mWinLabel.y(), mWinLabel.width(), mWinLabel.height()));
    //设置动画结束位置
    mWinLabelAnimation.setEndValue(QRect(mWinLabel.x(), mWinLabel.y()+185, mWinLabel.width(), mWinLabel.height()));

    mCoinBtnRowArray.setPlayLevel(levelConfigArray);

    mIsWin = false;
}

const bool& QPlayScene::isWin() const
{
    return mIsWin;
}

const bool& QPlayScene::isCoinFlipping() const
{
    return mIsCoinFlipping;
}

void QPlayScene::setCoinFlipping()
{
    mCoinFlipSound.play();  //翻转硬币音效
    mIsCoinFlipping = true;
    mIsCoinFlippingTimer.start(30*8+500+30*8);   //两个30*8是翻一个币的时间和其它四个币时间,500是翻其它四个币延迟500
}

void QPlayScene::changeCoinUpperLowerLeftRightFlag(const uint &aRowNum, const uint &aColNum)
{
    mCoinBtnRowArray.changeCoinUpperLowerLeftRightFlag(aRowNum, aColNum);
}

void QPlayScene::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), mPlaySceneBackground);
    painter.drawPixmap(15, 40, mGameTitle);
}
