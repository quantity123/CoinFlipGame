#include "qcoinbtnrowarray.h"
#include <QList>

QCoinBtnRowArray::QCoinBtnRowArray(QObject *parent)
    : QObject(parent)
{
}

void QCoinBtnRowArray::buildCoinBtnRowArray(QWidget *aParent, uint &aRowCount, uint &aColCount)
{
    for (uint i=0; i<aRowCount; ++i)
    {
        QCoinBtnRow *coinBtnRow = new QCoinBtnRow(this);
        coinBtnRow->setRowNum(i);
        coinBtnRow->buildCoinBtnRow(aParent, i, aColCount);
        mCoinBtnRowList.append(coinBtnRow);
    }
}

void QCoinBtnRowArray::setPlayLevel(const QLevelConfig::QLevelConfigArray &levelConfigArray)
{
    QList<QCoinBtnRow*>::const_iterator ci;
    for (ci=mCoinBtnRowList.cbegin(); ci!=mCoinBtnRowList.cend(); ++ci)
    {
        QCoinBtnRow *coinBtnRow = static_cast<QCoinBtnRow*>(*ci);
        const uint &rowNum = coinBtnRow->rowNum();
        QVector<uint> levelConfigRow = levelConfigArray.at(rowNum);
        coinBtnRow->setPlayLevel(levelConfigRow);
    }
}

void QCoinBtnRowArray::changeCoinUpperLowerLeftRightFlag(const uint &aRowNum, const uint &aColNum)
{
    QList<QCoinBtnRow*>::const_iterator ci;
    for (ci=mCoinBtnRowList.cbegin(); ci!=mCoinBtnRowList.cend(); ++ci)
    {
        QCoinBtnRow *coinBtnCurrRow = static_cast<QCoinBtnRow*>(*ci);
        const uint &rowNum = coinBtnCurrRow->rowNum();
        if (rowNum == aRowNum)
        {
            coinBtnCurrRow->changePreviouAndNextFlag(aColNum);
            QList<QCoinBtnRow*>::const_iterator tmpCi;
            QCoinBtnRow *tmpCoinBtnRow = nullptr;
            tmpCi = ci - 1; //获取上一行
            if (tmpCi >= mCoinBtnRowList.cbegin())
            {
                tmpCoinBtnRow = static_cast<QCoinBtnRow*>(*tmpCi);
                tmpCoinBtnRow->changeFlag(aColNum);
            }
            tmpCi = ci + 1; //获取下一行
            if (tmpCi < mCoinBtnRowList.cend())
            {
                tmpCoinBtnRow = static_cast<QCoinBtnRow*>(*tmpCi);
                tmpCoinBtnRow->changeFlag(aColNum);
            }
            break;
        }
    }
}

bool QCoinBtnRowArray::checkIsWin()
{
    QList<QCoinBtnRow*>::const_iterator ci;
    for (ci=mCoinBtnRowList.cbegin(); ci!=mCoinBtnRowList.cend(); ++ci)
    {
        QCoinBtnRow *coinBtnRow = static_cast<QCoinBtnRow*>(*ci);
        if (!coinBtnRow->checkIsWin())
            return false;
    }
    return true;
}
