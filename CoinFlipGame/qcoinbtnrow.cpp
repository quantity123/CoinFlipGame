#include "qcoinbtnrow.h"
#include "qplayscene.h"

QCoinBtnRow::QCoinBtnRow(QObject *parent)
    : QObject(parent)
{
}

void QCoinBtnRow::buildCoinBtnRow(QWidget *aParent, const uint &aRowNum, const uint &aColCount)
{
    for (uint i=0; i<aColCount; ++i)
    {
        QCoinBtnWithBackground *coinBtnWithBackground = new QCoinBtnWithBackground(aParent);
        coinBtnWithBackground->setColNum(i);
        uint x = 59+i*50;
        uint y = 204+aRowNum*50;
        coinBtnWithBackground->move(x, y);
        mCoinBtnWithBackgroundList.append(coinBtnWithBackground);
        //点击硬币触发翻转
        auto onCoinBtnWithBackgroundClicked = [=]()
        {
            const bool &win = dynamic_cast<QPlayScene*>(aParent)->isWin();
            const bool &flipping = dynamic_cast<QPlayScene*>(aParent)->isCoinFlipping();
            if (!win && !flipping)
            {
                dynamic_cast<QPlayScene*>(aParent)->setCoinFlipping();
                coinBtnWithBackground->changeFlag();
                auto onChangeCoinUpperLowerLeftRightFlag = [=]()
                {
                    dynamic_cast<QPlayScene*>(aParent)->changeCoinUpperLowerLeftRightFlag(aRowNum, i);
                };
                QTimer::singleShot(500, onChangeCoinUpperLowerLeftRightFlag);
            }
        };
        connect(coinBtnWithBackground->coinBtn(), &QCoinBtn::clicked, onCoinBtnWithBackgroundClicked);
    }
}

void QCoinBtnRow::setPlayLevel(const QVector<uint> &aLevelConfigRow)
{
    QList<QCoinBtnWithBackground*>::const_iterator ci;
    for (ci=mCoinBtnWithBackgroundList.cbegin(); ci!=mCoinBtnWithBackgroundList.cend(); ++ci)
    {
        QCoinBtnWithBackground *coinBtnWithBackground = static_cast<QCoinBtnWithBackground*>(*ci);
        const uint &colnum = coinBtnWithBackground->colNum();
        const uint &levelConfigEle = aLevelConfigRow.at(colnum);
        coinBtnWithBackground->setLevelConfigEle(levelConfigEle);
    }
}

void QCoinBtnRow::setRowNum(const uint& aRowNum)
{
    mRowNum = aRowNum;
}

const uint& QCoinBtnRow::rowNum() const
{
    return mRowNum;
}

void QCoinBtnRow::changeFlag(const uint &aColCount)
{
    QList<QCoinBtnWithBackground*>::const_iterator ci;
    for (ci=mCoinBtnWithBackgroundList.cbegin(); ci!=mCoinBtnWithBackgroundList.cend(); ++ci)
    {
        QCoinBtnWithBackground *coinBtnWithBackground = static_cast<QCoinBtnWithBackground*>(*ci);
        const uint &colnum = coinBtnWithBackground->colNum();
        if (colnum == aColCount)
        {
            coinBtnWithBackground->changeFlag();
            break;
        }
    }
}

void QCoinBtnRow::changePreviouAndNextFlag(const uint &aColCount)
{
    QList<QCoinBtnWithBackground*>::const_iterator ci;
    for (ci=mCoinBtnWithBackgroundList.cbegin(); ci!=mCoinBtnWithBackgroundList.cend(); ++ci)
    {
        QCoinBtnWithBackground *coinBtnWithBackground = static_cast<QCoinBtnWithBackground*>(*ci);
        const uint &colnum = coinBtnWithBackground->colNum();
        if (colnum == aColCount)
        {
            QList<QCoinBtnWithBackground*>::const_iterator tmpCi;
            QCoinBtnWithBackground *tmpCoinBtnWithBackground;
            tmpCi = ci - 1; //获取前一个
            if (tmpCi >= mCoinBtnWithBackgroundList.cbegin())
            {
                tmpCoinBtnWithBackground = static_cast<QCoinBtnWithBackground*>(*tmpCi);
                tmpCoinBtnWithBackground->changeFlag();
            }
            tmpCi = ci + 1; //获取后一个
            if (tmpCi < mCoinBtnWithBackgroundList.cend())
            {
                tmpCoinBtnWithBackground = static_cast<QCoinBtnWithBackground*>(*tmpCi);
                tmpCoinBtnWithBackground->changeFlag();
            }
            break;
        }
    }
}

bool QCoinBtnRow::checkIsWin()
{
    QList<QCoinBtnWithBackground*>::const_iterator ci;
    for (ci=mCoinBtnWithBackgroundList.cbegin(); ci!=mCoinBtnWithBackgroundList.cend(); ++ci)
    {
        QCoinBtnWithBackground *coinBtnWithBackground = static_cast<QCoinBtnWithBackground*>(*ci);
        if (coinBtnWithBackground->flag() == 0)
            return false;
    }
    return true;
}
