#ifndef ASMTESTSUITE_H
#define ASMTESTSUITE_H

#include <QObject>
#include <QVector>
#include <QtTest/QtTest>


class asmTestSuite : public QObject
{
      Q_OBJECT

   public:
      explicit asmTestSuite();

      static QVector<QObject*> mSuites;
};

#endif
