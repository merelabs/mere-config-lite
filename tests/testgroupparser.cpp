#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class TestGroupParser : public QObject
{
    Q_OBJECT

public:
    TestGroupParser();
    ~TestGroupParser();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
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

void TestGroupParser::test_case1()
{

}

//QTEST_MAIN(TestGroupParser)
#include "testgroupparser.moc"
