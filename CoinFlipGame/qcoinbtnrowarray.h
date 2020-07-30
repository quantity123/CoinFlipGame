#ifndef QCOINBTNROWARRAY_H
#define QCOINBTNROWARRAY_H

#include <QObject>
#include "qcoinbtnrow.h"
#include "qlevelconfig.h"

class QCoinBtnRowArray : public QObject
{
    Q_OBJECT
public:
    explicit QCoinBtnRowArray(QObject *parent = nullptr);
    void buildCoinBtnRowArray(QWidget *aParent, uint &aRowCount, uint &aColCount);
    void setPlayLevel(const QLevelConfig::QLevelConfigArray &levelConfigArray);
    void changeCoinUpperLowerLeftRightFlag(const uint &aRowNum, const uint &aColNum);
    bool checkIsWin();
signals:
private:
    QList<QCoinBtnRow*> mCoinBtnRowList;
};

#endif // QCOINBTNROWARRAY_H
