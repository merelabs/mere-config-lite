#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "mere/config/kvconfig.h"
#include "mere/config/kvparser.h"

class TestGroupParser : public QObject
{
    Q_OBJECT

public:
    TestGroupParser();
    ~TestGroupParser();

private slots:
    void initTestCase();
    void cleanupTestCase();
};

TestGroupParser::TestGroupParser()
{

}

TestGroupParser::~TestGroupParser()
{

}

void TestGroupParser::initTestCase()
{

}

void TestGroupParser::cleanupTestCase()
{

}


//QTEST_MAIN(TestGroupParser)
#include "testgroupparser.moc"
