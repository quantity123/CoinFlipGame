#ifndef QCOINFLIPPUSHBUTTON_H
#define QCOINFLIPPUSHBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>

class QStartAndBackPushBtn : public QPushButton
{
    Q_OBJECT
public:
//    explicit QCoinFlipPushButton(QWidget *parent = nullptr, QString aNormalPixmap="", QString aPressPixmap="");
    QStartAndBackPushBtn(QString aNormalPixmap, QString aPressPixmap="");
    void zoom(bool aIsDown);   //动画开始按钮按下弹跳
signals:
protected:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
private:
    QPropertyAnimation mStartBtnClickAnimation; //是对象，不是指针
    QString mNormalPixmap;
    QString mPressPixmap;
};

#endif // QCOINFLIPPUSHBUTTON_H
