#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenuBar>
#include "qlevelconfig.h"
#include "qstartscene.h"
#include "qchooselevelscene.h"
#include "qplayscene.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum SceneType
    {
        stStartScene
        , stChooseLevelScene
        , stPalyScene
    };
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setScene(SceneType aSceneType);
    void setPlayLevel(const uchar &aLevel);
private:
    uint mWidth;
    uint mHeight;
    QWidget mWidget;
    QVBoxLayout mVBoxLayout;
    QMenuBar mMenuBar;
    QLevelConfig mLevelConfig;
    QPoint mBackBtnMovePoint;
    QStartScene mStartScene;    //准备开始场景
    QChooseLevelScene mChooseLevelScene;    //选择游戏关卡场景
    QPlayScene mPlayScene;  //游戏中场景
};
#endif // MAINWINDOW_H
