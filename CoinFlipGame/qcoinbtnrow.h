#ifndef QCOINBTNROW_H
#define QCOINBTNROW_H

#include <QObject>
#include "qcoinbtnwithbackground.h"
#include "qlevelconfig.h"

class QCoinBtnRow : public QObject
{
    Q_OBJECT
public:
    explicit QCoinBtnRow(QObject *parent = nullptr);
    void buildCoinBtnRow(QWidget *aParent, const uint &aRowNum, const uint &aColCount);
    void setPlayLevel(const QVector<uint> &aLevelConfigRow);
    void setRowNum(const uint &aRowNum);
    const uint& rowNum() const;
    void changeFlag(const uint &aColCount);
    void changePreviouAndNextFlag(const uint &aColCount);
    bool checkIsWin();
signals:
private:
    QList<QCoinBtnWithBackground*> mCoinBtnWithBackgroundList;
    uint mRowNum;
};

#endif // QCOINBTNROW_H
