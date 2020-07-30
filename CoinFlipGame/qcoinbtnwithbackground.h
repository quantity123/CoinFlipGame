#ifndef QCOINBTNWITHBACKGROUND_H
#define QCOINBTNWITHBACKGROUND_H

#include <QWidget>
#include <QLabel>
#include "qcoinbtn.h"

class QCoinBtnWithBackground : public QObject
{
    Q_OBJECT
public:
    explicit QCoinBtnWithBackground(QWidget *parent = nullptr);
    void setColNum(const uint &aColNum);
    const uint& colNum() const;
    void move(const uint &aX, const uint &aY);
    void setLevelConfigEle(const uchar &levelConfigEle);
    const QCoinBtn* coinBtn() const;
    void changeFlag();
    const uchar& flag() const;
signals:
private:
    QLabel mBackground; //底部背景方框(mBackground比mCoinBtn先创建所以是mCoinBtn的背景)
    QCoinBtn mCoinBtn;  //硬币按钮
    uint mColNum;
};

#endif // QCOINBTNWITHBACKGROUND_H
