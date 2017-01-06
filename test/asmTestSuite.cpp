#include "asmTestSuite.h"

QVector<QObject*> asmTestSuite::mSuites;

asmTestSuite::asmTestSuite()
{
   mSuites.push_back( this );
}
