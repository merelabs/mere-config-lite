#include "testparser.h"

#include "../src/parser/parser.h"
#include "../src/parser/config.h"

#include <fstream>

void TestParser::initTestCase()
{
    m_file1 = std::tmpnam(nullptr);

    std::ofstream file1(m_file1);
    file1 << "\n";
    file1 << "#this is a commnet" << "\n";
    file1 << "name=parser" << "\n";
    file1.close();

    m_file2 = std::tmpnam(nullptr);

    std::ofstream file2(m_file2);
    file2 << "\n";
    file2 << "#this is a commnet" << "\n";
    file2 << "name=parser" << "\n";
    file2 << "#this is aother comment line" << "\n";
    file2 << "note=checking to grab two valid lines" << "\n";
    file2 << "\n";
    file2.close();
}

void TestParser::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
}

void TestParser::test_config_lines()
{
    Mere::Config::Parser::Config config(m_file1);
    Mere::Config::Parser::Parser parser1(config);

    std::vector<std::string> lines = parser1.parse();
    QVERIFY(lines.size() == 1);

    config.path(m_file2);
    Mere::Config::Parser::Parser parser2(config);

    lines = parser2.parse();
    QVERIFY(lines.size() == 2);
}
