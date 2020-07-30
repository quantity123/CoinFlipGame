#include "qchooselevelbtn.h"

QChooseLevelBtn::QChooseLevelBtn(QString aNormalPixmap, QString aPressPixmap)
    : QStartAndBackPushBtn(aNormalPixmap, aPressPixmap)
{
    mLevelNum.setFixedSize(this->width(), this->height());
    mLevelNum.setAlignment(Qt::AlignCenter);
    //设置label属性, 透过鼠标事件, 能触发按钮click信号不被label挡住
    mLevelNum.setAttribute(Qt::WA_TransparentForMouseEvents);
}

void QChooseLevelBtn::setLevelBtnParent(QWidget *aParent)
{
    this->setParent(aParent);
    mLevelNum.setParent(aParent);
}

void QChooseLevelBtn::setCoordinatePoint(const int &aX, const int &aY)
{
    this->move(aX, aY);
    mLevelNum.move(aX, aY);
}

void QChooseLevelBtn::setLevelText(const int &aLevel)
{
    mLevelNum.setNum(aLevel);
}
