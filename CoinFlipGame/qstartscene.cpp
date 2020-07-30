#include "qstartscene.h"
#include <QPainter>
#include "mainwindow.h"

QStartScene::QStartScene(QWidget *parent)
    : QWidget(parent)
    , mStartSceneBackground(":/res/PlayLevelSceneBg.png")
    , mGameTitle(":/res/Title.png")
    , mStartButton(":/res/MenuSceneStartButton.png")
    , mPressStartButtonSound(":/res/TapButtonSound.wav")
    , mMainWindow(parent)   //设置主窗口的变量指针
{
    this->hide();

    //设置游戏标题图标比例大小
    mGameTitle = mGameTitle.scaled(mGameTitle.width()*0.5, mGameTitle.height()*0.5);

    //设置开始游戏按钮
    mStartButton.setParent(this);
    auto onStartButtonClicked = [&]()
    {
        //mPressStartButtonSound->setLoops(10);    //设置循环播放10次，如果参数-1，无限循环
        mPressStartButtonSound.play();    //播放开始游戏按钮的音效
        mStartButton.zoom(true);
        mStartButton.zoom(false);
        auto onShowChooseScene = [&]()
        {
            dynamic_cast<MainWindow *>(mMainWindow)->setScene(MainWindow::SceneType::stChooseLevelScene);
            this->hide();
        };
        QTimer::singleShot(300, onShowChooseScene);
    };
    connect(&mStartButton, &QStartAndBackPushBtn::clicked, onStartButtonClicked);
}

void QStartScene::setFixedWindowSize(const int &aWidth, const int &aHeight)
{
    this->setFixedSize(aWidth, aHeight);
    mStartButton.move(aWidth*0.5-mStartButton.width()*0.5, aHeight*0.7);
}

void QStartScene::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), mStartSceneBackground);
    painter.drawPixmap(15, 40, mGameTitle);
}
