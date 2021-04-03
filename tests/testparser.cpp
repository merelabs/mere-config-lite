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
    void test_line();
    void test_line_none();
    void test_lines();
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

void TestParser::test_line()
{
    std::string base(QDir::currentPath().toStdString());
    const Mere::Config::Config config(base.append("/data/config/kv/4-properties.conf"));
    Mere::Config::Parser parser(config);

    std::string line = parser.parse("name=");
    assert(!line.empty());
}

void TestParser::test_line_none()
{
    std::string base(QDir::currentPath().toStdString());
    const Mere::Config::Config config(base.append("/data/config/kv/4-properties.conf"));
    Mere::Config::Parser parser(config);

    std::string line = parser.parse("xname=");
    assert(line.empty());
}

void TestParser::test_lines()
{
    std::string base(QDir::currentPath().toStdString());
    const Mere::Config::Config config(base.append("/data/config/kv/4-properties.conf"));
    Mere::Config::Parser parser(config);

    std::vector<std::string> lines = parser.parse();
    assert(lines.size() == 4);
}

QTEST_MAIN(TestParser)

#include "testparser.moc"
