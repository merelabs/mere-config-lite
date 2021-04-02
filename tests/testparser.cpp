#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "mere/config/config.h"
#include "mere/config/parser.h"

class TestParser : public QObject
{
    Q_OBJECT

public:
    TestParser();
    ~TestParser();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_comment();
};

TestParser::TestParser()
{

}

TestParser::~TestParser()
{

}

void TestParser::initTestCase()
{

}

void TestParser::cleanupTestCase()
{

}

void TestParser::test_comment()
{
    }

//QTEST_MAIN(TestParser)

#include "testparser.moc"
