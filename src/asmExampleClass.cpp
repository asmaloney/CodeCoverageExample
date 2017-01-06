#include <QDebug>

#include "asmExampleClass.h"

int asmExampleClass::addSomeStuff( const QVector<int> &inVec ) const
{
    if ( inVec.isEmpty() )
    {
        qInfo() << "I have nothing to add";
        return 0;
    }

    int sum = 0;

    for ( int num : inVec )
    {
        sum += num;
    }

    if ( sum == 42 )
    {
        qInfo() << "Of course it is";
    }

    return sum;
}
