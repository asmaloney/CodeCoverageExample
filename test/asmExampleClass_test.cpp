#include <QtTest/QtTest>

#include "asmTestSuite.h"

#include "asmExampleClass.h"


class TestExampleClass : public asmTestSuite
{
      Q_OBJECT

   private slots:
      void  test_addSomeStuff();
      void  test_addSomeStuffEmptyVector();
};

// test adding list of numbers
void  TestExampleClass::test_addSomeStuff()
{
   asmExampleClass   example;

   int   result = example.addSomeStuff( { 1, 32, 44, 51 } );

   QCOMPARE( result, 128 );
}

// test adding list of numbers with empty vector
void  TestExampleClass::test_addSomeStuffEmptyVector()
{
   asmExampleClass   example;

   int   result = example.addSomeStuff( {} );

   QCOMPARE( result, 0 );
}

static TestExampleClass  sInstance;

#include "asmExampleClass_test.moc"
