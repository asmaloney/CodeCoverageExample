#include <QtTest/QtTest>

#include "asmTestSuite.h"


int main( int argc, char** argv )
{
   QCoreApplication  app( argc, argv );

   int   failedSuitesCount = 0;

   QVector<QObject*>::iterator iter;

   for ( iter = asmTestSuite::mSuites.begin(); iter != asmTestSuite::mSuites.end(); ++iter )
   {
      int result = QTest::qExec( *iter );

      if ( result != 0 )
      {
         failedSuitesCount++;
      }
   }

   return failedSuitesCount;
}
