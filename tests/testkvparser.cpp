#include <QtTest>
#include <QCoreApplication>

// add necessary includes here
#include "mere/config/kvconfig.h"
#include "mere/config/kvparser.h"

class TestKVParser : public QObject
{
    Q_OBJECT

public:
    TestKVParser();
    ~TestKVParser();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_parseEmpty();
    void test_parseOnlyComment();
};

TestKVParser::TestKVParser()
{

}

TestKVParser::~TestKVParser()
{

}

void TestKVParser::initTestCase()
{

}

void TestKVParser::cleanupTestCase()
{

}

void TestKVParser::test_parseEmpty()
{
    const Mere::Config::KVConfig config(":/tests/res/config/kv/empty.conf");
    Mere::Config::KVParser parser(config);

    std::map<std::string, std::string> properties = parser.parse();
    assert(properties.size() == 0);
}

void TestKVParser::test_parseOnlyComment()
{
    const Mere::Config::KVConfig config(":/tests/res/config/kv/only-commnet.conf");
    Mere::Config::KVParser parser(config);

    std::map<std::string, std::string> properties = parser.parse();
    assert(properties.size() == 0);
}

QTEST_MAIN(TestKVParser)

#include "testkvparser.moc"
