#include "qcoinbtnwithbackground.h"

QCoinBtnWithBackground::QCoinBtnWithBackground(QWidget *parent)
    : QObject(parent)
    , mBackground(parent)
    , mCoinBtn(parent)
{
    QPixmap pixmap(":/res/BoardNode.png");
    mBackground.setPixmap(pixmap);
    mBackground.setFixedSize(pixmap.width(), pixmap.height());
}

void QCoinBtnWithBackground::setColNum(const uint &aColNum)
{
    mColNum = aColNum;
}

const uint& QCoinBtnWithBackground::colNum() const
{
    return mColNum;
}

void QCoinBtnWithBackground::move(const uint &aX, const uint &aY)
{
    mBackground.move(aX-2, aY-4);
    mCoinBtn.move(aX, aY);
}

void QCoinBtnWithBackground::setLevelConfigEle(const uchar &levelConfigEle)
{
    mCoinBtn.setFlag(levelConfigEle);
}

const QCoinBtn* QCoinBtnWithBackground::coinBtn() const
{
    return &mCoinBtn;
}

void QCoinBtnWithBackground::changeFlag()
{
    mCoinBtn.changeFlag();
}

const uchar& QCoinBtnWithBackground::flag() const
{
    return mCoinBtn.flag();
}
