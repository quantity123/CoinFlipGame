#include "qlevelconfig.h"

QLevelConfig::QLevelConfig(QObject *parent)
    : QObject(parent)
    , mColCount(gColCount)
    , mRowCount(gRowCount)
{
    QLevelConfigArray v;
    QVector<uint> v1;

    int array1[gRowCount][gColCount] = {{1, 1, 1, 1},
                                        {1, 1, 0, 1},
                                        {1, 0, 0, 0},
                                        {1, 1, 0, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array1[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(1, v);

    int array2[gRowCount][gColCount] = {{1, 0, 1, 1},
                                        {0, 0, 1, 1},
                                        {1, 1, 0, 0},
                                        {1, 1, 0, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array2[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(2, v);

    int array3[gRowCount][gColCount] = {{0, 0, 0, 0},
                                        {0, 1, 1, 0},
                                        {0, 1, 1, 0},
                                        {0, 0, 0, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array3[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(3, v);

    int array4[gRowCount][gColCount] = {{0, 1, 1, 1},
                                        {1, 0, 0, 1},
                                        {1, 0, 1, 1},
                                        {1, 1, 1, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array4[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(4, v);

    int array5[gRowCount][gColCount] = {{1, 0, 0, 1},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {1, 0, 0, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array5[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(5, v);

    int array6[gRowCount][gColCount] = {{1, 0, 0, 1},
                                        {0, 1, 1, 0},
                                        {0, 1, 1, 0},
                                        {1, 0, 0, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array6[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(6, v);

    int array7[gRowCount][gColCount] = {{0, 1, 1, 1},
                                        {1, 0, 1, 1},
                                        {1, 1, 0, 1},
                                        {1, 1, 1, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array7[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(7, v);

    int array8[gRowCount][gColCount] = {{0, 1, 0, 1},
                                        {1, 0, 0, 0},
                                        {0, 0, 0, 1},
                                        {1, 0, 1, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array8[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(8, v);

    int array9[gRowCount][gColCount] = {{1, 0, 1, 0},
                                        {1, 0, 1, 0},
                                        {0, 0, 1, 0},
                                        {1, 0, 0, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array9[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(9, v);

    int array10[gRowCount][gColCount] = {{1, 0, 1, 1},
                                         {1, 1, 0, 0},
                                         {0, 0, 1, 1},
                                         {1, 1, 0, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array10[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(10, v);

    int array11[gRowCount][gColCount] = {{0, 1, 1, 0},
                                         {1, 0, 0, 1},
                                         {1, 0, 0, 1},
                                         {0, 1, 1, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array11[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(11, v);

    int array12[gRowCount][gColCount] = {{0, 1, 1, 0},
                                         {0, 0, 0, 0},
                                         {1, 1, 1, 1},
                                         {0, 0, 0, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array12[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(12, v);

    int array13[gRowCount][gColCount] = {{0, 1, 1, 0},
                                         {0, 0, 0, 0},
                                         {0, 0, 0, 0},
                                         {0, 1, 1, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array13[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(13, v);

    int array14[gRowCount][gColCount] = {{1, 0, 1, 1},
                                         {0, 1, 0, 1},
                                         {1, 0, 1, 0},
                                         {1, 1, 0, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array14[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(14, v);

    int array15[gRowCount][gColCount] = {{0, 1, 0, 1},
                                         {1, 0, 0, 0},
                                         {1, 0, 0, 0},
                                         {0, 1, 0, 1}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array15[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(15, v);

    int array16[gRowCount][gColCount] = {{0, 1, 1, 0},
                                         {1, 1, 1, 1},
                                         {1, 1, 1, 1},
                                         {0, 1, 1, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array16[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(16, v);

    int array17[gRowCount][gColCount] = {{0, 1, 1, 1},
                                         {0, 1, 0, 0},
                                         {0, 0, 1, 0},
                                         {1, 1, 1, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array17[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(17, v);

    int array18[gRowCount][gColCount] = {{0, 0, 0, 1},
                                         {0, 0, 1, 0},
                                         {0, 1, 0, 0},
                                         {1, 0, 0, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array18[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(18, v);

    int array19[gRowCount][gColCount] = {{0, 1, 0, 0},
                                         {0, 1, 1, 0},
                                         {0, 0, 1, 1},
                                         {0, 0, 0, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array19[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(19, v);

    int array20[gRowCount][gColCount] = {{0, 0, 0, 0},
                                         {0, 0, 0, 0},
                                         {0, 0, 0, 0},
                                         {0, 0, 0, 0}};
    v.clear();
    for(uint i=0; i<mRowCount; i++)
    {
        v1.clear();
        for(uint j=0; j<mColCount; j++)
        {
            v1.push_back(array20[i][j]);
        }
        v.push_back(v1);
    }
    mLevelConfigArrayMap.insert(20, v);
}

uint QLevelConfig::levelCount() const
{
    return mLevelConfigArrayMap.count();
}

const uint& QLevelConfig::rowCount() const
{
    return mRowCount;
}

uint QLevelConfig::colCount() const
{
    return mColCount;
}

const QLevelConfig::QLevelConfigArray
QLevelConfig::levelConfigArray(const uchar &aLevel) const
{
    return mLevelConfigArrayMap.value(aLevel);
}
