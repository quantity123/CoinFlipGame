#include "qchooselevelscene.h"
#include <QPainter>
#include "mainwindow.h"
#include "qchooselevelbtn.h"

QChooseLevelScene::QChooseLevelScene(QWidget *parent)
    : QWidget(parent)
    , mChooseLevelSceneBackground(":/res/OtherSceneBg.png")
    , mGameTitle(":/res/Title.png")
    , mChooseLevelBtnClickSound(":/res/TapButtonSound.wav", this)
    , mBackStartSceneBtn(":/res/BackButton.png", ":/res/BackButtonSelected.png")
    , mBackStartSceneBtnClickSound(":/res/BackButtonSound.wav", this)
    , mMainWindow(parent)
{
    this->hide();

    mBackStartSceneBtn.setParent(this);
    auto onBackMainSeneBtnClicked = [&]()
    {
        mBackStartSceneBtnClickSound.play();
        dynamic_cast<MainWindow *>(mMainWindow)->setScene(MainWindow::SceneType::stStartScene);
        this->hide();
    };
    connect(&mBackStartSceneBtn, &QStartAndBackPushBtn::clicked, onBackMainSeneBtnClicked);
}

void QChooseLevelScene::setFixedWindowSize(const int &aWidth, const int &aHeight)
{
    this->setFixedSize(aWidth, aHeight);
}

void QChooseLevelScene::createLevel(uint aLevelCount)
{
    for (uint i=0; i<aLevelCount; ++i)
    {
        QChooseLevelBtn *levelBtn = new QChooseLevelBtn(":/res/LevelIcon.png");
        levelBtn->setLevelBtnParent(this);
        levelBtn->setCoordinatePoint(20+i%4*75, 160+i/4*75);
        uint level;
        level = i + 1;
        levelBtn->setLevelText(level);
        auto onChooseLevelBtnClicked = [=]()
        {
            mChooseLevelBtnClickSound.play();   //选中一关卡音效
            dynamic_cast<MainWindow *>(mMainWindow)->setPlayLevel(level);
            dynamic_cast<MainWindow *>(mMainWindow)->setScene(MainWindow::SceneType::stPalyScene);
            this->hide();
        };
        connect(levelBtn, &QChooseLevelBtn::clicked, onChooseLevelBtnClicked);
    }
}

void QChooseLevelScene::setBackBtnMovePoint(const QPoint &aPoint)
{
    mBackStartSceneBtn.move(aPoint.x(), aPoint.y());
}

void QChooseLevelScene::paintEvent(QPaintEvent */*event*/)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), mChooseLevelSceneBackground);
    painter.drawPixmap((this->width()-mGameTitle.width())*0.5, 40, mGameTitle); //把标题左右居中
}
