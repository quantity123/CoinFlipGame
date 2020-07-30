#include "qcoinbtn.h"

QCoinBtn::QCoinBtn(QWidget *parent)
    : QPushButton(parent)
    , mFlag(1)
    , mTimer1(this)
    , mTimer2(this)
    , mMax(8)
    , mMin(1)
{
    QPixmap pixmap;
    pixmap.load(":/res/Coin0001.png");
    this->setFixedSize(pixmap.width(), pixmap.height());
    this->setIcon(QIcon(pixmap));
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    this->setStyleSheet("QPushButton{border:0px;}");

    auto onTimer1_Out = [&]()
    {
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1").arg(this->mMin++);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setIcon(QIcon(pixmap));
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        this->setStyleSheet("QPushButton{border:0px;}");
        if (mMin > mMax)
        {
            mTimer1.stop();
            mMin = 1;
        }
    };
    connect(&mTimer1, &QTimer::timeout, onTimer1_Out);

    auto onTimer2_Out = [&]()
    {
        QPixmap pixmap;
        QString str = QString(":/res/Coin000%1").arg(this->mMax--);
        pixmap.load(str);
        this->setFixedSize(pixmap.width(), pixmap.height());
        this->setIcon(QIcon(pixmap));
        this->setIconSize(QSize(pixmap.width(), pixmap.height()));
        this->setStyleSheet("QPushButton{border:0px;}");
        if (mMax < mMin)
        {
            mTimer2.stop();
            mMax = 8;
        }
    };
    connect(&mTimer2, &QTimer::timeout, onTimer2_Out);
}

void QCoinBtn::setFlag(const uchar &aFlag)
{
    mFlag = aFlag;
    QString iconPath;
    if (mFlag == 1)
    {
        iconPath = ":/res/Coin0001.png";
    }
    else
    {
        iconPath = ":/res/Coin0008.png";
    }
    QPixmap pixmap;
    pixmap.load(iconPath);
    this->setFixedSize(pixmap.width(), pixmap.height());
    this->setIcon(QIcon(pixmap));
    this->setIconSize(QSize(pixmap.width(), pixmap.height()));
    this->setStyleSheet("QPushButton{border:0px;}");
}

const uchar& QCoinBtn::flag() const
{
    return mFlag;
}

void QCoinBtn::changeFlag()
{
    if (this->mFlag == 1)
    {
        mTimer1.start(30);
        this->mFlag = 0;
    }
    else
    {
        mTimer2.start(30);
        this->mFlag = 1;
    }
}
