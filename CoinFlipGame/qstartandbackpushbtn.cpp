#include "qstartandbackpushbtn.h"
#include <QDebug>

QStartAndBackPushBtn::QStartAndBackPushBtn(QString aNormalPixmap, QString aPressPixmap)
{
    mNormalPixmap = aNormalPixmap;
    mPressPixmap = aPressPixmap;
    QPixmap pixmap;
    bool loadRet = pixmap.load(mNormalPixmap);
    if (!loadRet)
    {
        qDebug() << aNormalPixmap + "图片加载失败！";
    }
    this->setFixedSize(pixmap.width(), pixmap.height());
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    this->setIcon(QIcon(pixmap));
    this->setStyleSheet("QPushButton{border:0px};");

    //设置动画对象是哪个目标
    mStartBtnClickAnimation.setTargetObject(this);
    //设置动画属性类型
    mStartBtnClickAnimation.setPropertyName("geometry");
    //设置动画播放时间
    mStartBtnClickAnimation.setDuration(150);
    //设置动画缓缓移动曲线
    mStartBtnClickAnimation.setEasingCurve(QEasingCurve::OutBounce);
}

void QStartAndBackPushBtn::zoom(bool aIsDown)
{
    if (aIsDown)
    {
        //设置起始位置
        mStartBtnClickAnimation.setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
        //设置结束位置
        mStartBtnClickAnimation.setEndValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
        //执行动画
        mStartBtnClickAnimation.start();
    }
    else
    {
        //设置起始位置
        mStartBtnClickAnimation.setStartValue(QRect(this->x(), this->y()+10, this->width(), this->height()));
        //设置结束位置
        mStartBtnClickAnimation.setEndValue(QRect(this->x(), this->y()-10, this->width(), this->height()));
        //执行动画
        mStartBtnClickAnimation.start();
    }
}

void QStartAndBackPushBtn::mousePressEvent(QMouseEvent *e)
{
    if (mPressPixmap != "")
    {
        QPixmap pixmap;
        bool loadRet = pixmap.load(mPressPixmap);
        if (!loadRet)
        {
            qDebug() << mPressPixmap + "图片加载失败！";
            return;
        }
        this->setIcon(QIcon(pixmap));
    }
    return QPushButton::mousePressEvent(e);
}

void QStartAndBackPushBtn::mouseReleaseEvent(QMouseEvent *e)
{
    if (mPressPixmap != "")
    {
        QPixmap pixmap;
        bool loadRet = pixmap.load(mNormalPixmap);
        if (!loadRet)
        {
            qDebug() << mNormalPixmap + "图片加载失败！";
            return;
        }
        this->setIcon(QIcon(pixmap));
    }
    return QPushButton::mouseReleaseEvent(e);
}
