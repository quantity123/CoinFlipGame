#ifndef QCHOOSELEVELBTN_H
#define QCHOOSELEVELBTN_H

#include <QLabel>
#include "qstartandbackpushbtn.h"

class QChooseLevelBtn : public QStartAndBackPushBtn
{
    Q_OBJECT
public:
//    explicit QChooseLevelBtn(QWidget *parent = nullptr);
    QChooseLevelBtn(QString aNormalPixmap, QString aPressPixmap="");
    void setLevelBtnParent(QWidget *aParent);
    void setCoordinatePoint(const int &aX, const int &aY);
    void setLevelText(const int &aLevel);
signals:

private:
    QLabel mLevelNum;
};

#endif // QCHOOSELEVELBTN_H
