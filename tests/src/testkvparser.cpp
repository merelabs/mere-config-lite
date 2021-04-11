#include "testkvparser.h"

#include "../src/parser/config.h"
#include "../src/parser/kvparser.h"

#include <fstream>

void TestKVParser::initTestCase()
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
    file2 << "nameparser" << "\n";
    file2.close();
}

void TestKVParser::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
}

void TestKVParser::test_strict_on()
{
    Mere::Config::Parser::PropertyConfig config(m_file2);
    config.strict(true);

    Mere::Config::Parser::KVParser parser(config);
    QVERIFY_EXCEPTION_THROWN(parser.parse(), std::exception);
}

void TestKVParser::test_strict_off()
{
    Mere::Config::Parser::PropertyConfig config(m_file2);
    Mere::Config::Parser::KVParser parser(config);

    QVERIFY(parser.parse().size() == 0);
}

void TestKVParser::test_property_number()
{
    Mere::Config::Parser::PropertyConfig config(m_file1);
    config.strict(true);

    Mere::Config::Parser::KVParser parser(config);

    std::vector<Mere::Config::Property> properties = parser.parse();
    QVERIFY(properties.size() == 1);
}

void TestKVParser::test_property_value()
{
    Mere::Config::Parser::PropertyConfig config(m_file1);
    config.strict(true);

    Mere::Config::Parser::KVParser parser(config);
    Mere::Config::Property property = parser.parse("name");
    QVERIFY(property.value().compare("parser") == 0);
}
