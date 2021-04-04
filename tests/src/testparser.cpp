#include "testparser.h"

#include "mere/config/config.h"
#include "mere/config/parser.h"

#include <fstream>

void TestParser::initTestCase()
{
    m_path = std::tmpnam(nullptr);

    std::ofstream file(m_path);
    file << "\n";
    file << "#this is a commnet" << "\n";
    file << "name=parser" << "\n";
    file.close();
}

void TestParser::cleanupTestCase()
{
    remove(m_path.c_str());
}

void TestParser::test_line()
{
    const Mere::Config::Config config(m_path);
    Mere::Config::Parser parser(config);

    std::string line = parser.parse("name=");
    QVERIFY(!line.empty());
}

void TestParser::test_line_none()
{
    const Mere::Config::Config config(m_path);
    Mere::Config::Parser parser(config);

    std::string line = parser.parse("xname=");
    QVERIFY(line.empty());
}

void TestParser::test_lines()
{
    const Mere::Config::Config config(m_path);
    Mere::Config::Parser parser(config);

    std::vector<std::string> lines = parser.parse();
    QVERIFY(lines.size() == 1);
}
