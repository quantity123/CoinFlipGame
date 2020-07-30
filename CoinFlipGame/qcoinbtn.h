#ifndef QCOINBTN_H
#define QCOINBTN_H

#include <QPushButton>
#include <QTimer>

class QCoinBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit QCoinBtn(QWidget *parent = nullptr);
    void setFlag(const uchar &aFlag);
    const uchar& flag() const;
    //翻转硬币并改变标志
    void changeFlag();
signals:
private:
    uchar mFlag;  //金币正反标志
    QTimer mTimer1;  //正面翻反面定时器
    QTimer mTimer2;  //反面翻正面定时器
    uint mMax;
    uint mMin;
};

#endif // QCOINBTN_H
