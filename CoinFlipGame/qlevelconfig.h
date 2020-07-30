#ifndef QGAMECONFIG_H
#define QGAMECONFIG_H

#include <QObject>
#include <QMap>

class QLevelConfig : public QObject
{
    Q_OBJECT
public:
    using QLevelConfigArray = QVector<QVector<uint>>;
    explicit QLevelConfig(QObject *parent = nullptr);
    uint levelCount() const;
    const uint& rowCount() const;
    uint colCount() const;
    const QLevelConfigArray levelConfigArray(const uchar &aLevel) const;
signals:
private:
    static const uint gRowCount = 4;
    static const uint gColCount = 4;
    uint mColCount;
    const uint mRowCount;
    QMap<uint, QLevelConfigArray> mLevelConfigArrayMap;
};

#endif // QGAMECONFIG_H
