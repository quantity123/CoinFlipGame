#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mWidth(320)
    , mHeight(588)
    , mWidget(this)
    , mVBoxLayout(this)
    , mMenuBar(this)
    , mLevelConfig(this)
    , mBackBtnMovePoint(mWidth-77, mHeight-57)
    , mStartScene(this)
    , mChooseLevelScene(this)
    , mPlayScene(this)
{
    this->setFixedSize(mWidth, mHeight);
//    QDesktopWidget *desktop = QApplication::desktop();
//    move((desktop->width()-this->width())*0.5, (desktop->height()-this->height())*0.5);   //ubuntu需要设置主窗口在桌面中间位置
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setCentralWidget(&mWidget);

    mWidget.setLayout(&mVBoxLayout);

    mVBoxLayout.addWidget(&mMenuBar);
    mVBoxLayout.addWidget(&mStartScene);
    mVBoxLayout.addWidget(&mChooseLevelScene);
    mVBoxLayout.addWidget(&mPlayScene);
    mVBoxLayout.setMargin(0);

    //设置菜单和退出
    this->setMenuBar(&mMenuBar);
    QMenu *startMenu = mMenuBar.addMenu("菜单");
    QAction *exitAction = startMenu->addAction("退出");
    auto onActionExit = [&]()
    {
        this->close();
    };
    connect(exitAction, &QAction::triggered, onActionExit);

    //设置准备开始游戏场景的宽和高
    mStartScene.setFixedWindowSize(mWidth, mHeight);

    mChooseLevelScene.setFixedWindowSize(mWidth, mHeight);
    //获取游戏一共有多少个关卡并创建关卡
    uint levelCount = mLevelConfig.levelCount();
    mChooseLevelScene.createLevel(levelCount);
    mChooseLevelScene.setBackBtnMovePoint(mBackBtnMovePoint);

    mPlayScene.setFixedWindowSize(mWidth, mHeight);
    //获取行和列数量并创建硬币阵列
    uint rowCount = mLevelConfig.rowCount();
    uint colCount = mLevelConfig.colCount();
    mPlayScene.buildCoinBtnRowArray(rowCount, colCount);
    mPlayScene.setBackBtnMovePoint(mBackBtnMovePoint);

    //显示准备开始游戏场景
    setScene(MainWindow::SceneType::stStartScene);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setScene(SceneType aSceneType)
{
    switch (aSceneType)
    {
    case stStartScene:
        mStartScene.show();
        this->setWindowTitle("准备开始游戏");
        break;
    case stChooseLevelScene:
        mChooseLevelScene.show();
        this->setWindowTitle("选择游戏关卡");
        break;
    case stPalyScene:
        mPlayScene.show();
        this->setWindowTitle("游戏中");
        break;
    default:
        this->setWindowTitle("错误的场景类型！");
        break;
    }
}

void MainWindow::setPlayLevel(const uchar &aLevel)
{
    QLevelConfig::QLevelConfigArray levelConfigArray = mLevelConfig.levelConfigArray(aLevel);
    QString sLevel = QString("%1").arg(aLevel);
    mPlayScene.setPlayLevel(sLevel, levelConfigArray);
}
