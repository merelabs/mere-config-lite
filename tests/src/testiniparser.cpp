#include "testiniparser.h"

#include "../src/parser/documentconfig.h"
#include "../src/parser/iniparser.h"

#include <fstream>

void TestIniParser::initTestCase()
{
    m_file1 = std::tmpnam(nullptr);

    std::ofstream file1(m_file1);
    file1 << "\n";
    file1 << "#this is a commnet" << "\n";
    file1 << "nameparser" << "\n";
    file1.close();

    m_file2 = std::tmpnam(nullptr);

    std::ofstream file2(m_file2);
    file2 << "\n";
    file2 << "#this is a commnet" << "\n";
    file2 << "[group1]" << "\n";
    file2 << "name=parser" << "\n";
    file2 << "[group2]" << "\n";
    file2 << "name=kvparser" << "\n";
    file2 << "note=a key value pair" << "\n";
    file2 << "[group3]" << "\n";
    file2 << "name=iniparser" << "\n";
    file2 << "note=a gropped key value pair" << "\n";
    file2 << "site=any" << "\n";
    file2.close();

    m_file3 = std::tmpnam(nullptr);

    std::ofstream file3(m_file3);
    file3 << "\n";
    file3 << "#this is a commnet" << "\n";
    file3 << "[group1]" << "\n";
    file3 << "name=parser" << "\n";
    file3 << "[group2]" << "\n";
    file3 << "name=kvparser" << "\n";
    file3 << "note=a key value pair" << "\n";
    file3 << "[group2/subgroup21]" << "\n";
    file3 << "Xname=kvparser" << "\n";
    file3 << "Xnote=a key value pair" << "\n";
    file3 << "[group3]" << "\n";
    file3 << "name=iniparser" << "\n";
    file3 << "note=a gropped key value pair" << "\n";
    file2 << "site=any" << "\n";
    file3 << "[group3/subgroup31]" << "\n";
    file3.close();
}

void TestIniParser::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
    remove(m_file3.c_str());
}

void TestIniParser::test_strict_on()
{
    Mere::Config::Parser::DocumentConfig config(m_file1);
    config.strict(true);

    Mere::Config::Parser::IniParser parser(config);
    QVERIFY_EXCEPTION_THROWN(parser.parse(), std::exception);
}

void TestIniParser::test_strict_off()
{
    Mere::Config::Parser::DocumentConfig config(m_file1);
    config.strict(false);

    Mere::Config::Parser::IniParser parser(config);
    Mere::Config::Document document = parser.parse();
}

void TestIniParser::test_section_number_strict()
{
    Mere::Config::Parser::DocumentConfig config2(m_file2);
    config2.strict(true);

    Mere::Config::Parser::IniParser parser2(config2);

    Mere::Config::Document document2 = parser2.parse();
    QVERIFY(document2.root().groups().size() == 3);

    Mere::Config::Parser::DocumentConfig config3(m_file3);
    config3.strict(true);

    Mere::Config::Parser::IniParser parser3(config3);

    Mere::Config::Document document3 = parser3.parse();
    QVERIFY(document3.root().groups().size() == 3);
}

void TestIniParser::test_section_property_number()
{
    Mere::Config::Parser::DocumentConfig config2(m_file2);
    config2.strict(true);

    Mere::Config::Parser::IniParser parser2(config2);

    QVERIFY(parser2.parse("group1").properties().size() == 1);
    QVERIFY(parser2.parse("group2").properties().size() == 2);
    QVERIFY(parser2.parse("group3").properties().size() == 3);
}

void TestIniParser::test_section_section_number()
{    
    Mere::Config::Parser::DocumentConfig config3(m_file3);
    config3.strict(true);

    Mere::Config::Parser::IniParser parser3(config3);

    QVERIFY(parser3.parse("group1").groups().size() == 0);
    QVERIFY(parser3.parse("group2").groups().size() == 1);
    QVERIFY(parser3.parse("group3").groups().size() == 1);
}

void TestIniParser::test_section_property_value()
{
    Mere::Config::Parser::DocumentConfig config2(m_file2);
    config2.strict(true);

    Mere::Config::Parser::IniParser parser2(config2);

    QVERIFY(parser2.parse("group2", "name").value().compare("kvparser") == 0);
}
