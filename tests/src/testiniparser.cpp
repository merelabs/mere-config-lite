#include "testiniparser.h"

#include "mere/config/iniconfig.h"
#include "mere/config/iniparser.h"
#include "mere/config/property.h"
#include "mere/config/exception.h"

#include <fstream>

void TestIniParser::initTestCase()
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
}

void TestIniParser::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
}

void TestIniParser::test_strict_on()
{
    const Mere::Config::IniConfig config(m_file1);
    Mere::Config::IniParser parser(config);
    parser.strict(true);

    QVERIFY_EXCEPTION_THROWN(parser.parse(), std::exception);
}

void TestIniParser::test_strict_off()
{
    const Mere::Config::IniConfig config(m_file1);

    Mere::Config::IniParser parser(config);
    parser.strict(false);

    std::vector<Mere::Config::Group> groups = parser.parse();
    QVERIFY(groups.size() == 0);
}

void TestIniParser::test_section_number_strict()
{
    const Mere::Config::IniConfig config(m_file2);
    Mere::Config::IniParser parser(config);

    std::vector<Mere::Config::Group> groups = parser.parse();
    QVERIFY(groups.size() == 3);
}

void TestIniParser::test_section_property_number()
{
    const Mere::Config::IniConfig config(m_file2);
    Mere::Config::IniParser parser(config);

    QVERIFY(parser.parse("group1").size() == 1);
    QVERIFY(parser.parse("group2").size() == 2);
    QVERIFY(parser.parse("group3").size() == 3);
}

void TestIniParser::test_section_property_value()
{
    const Mere::Config::IniConfig config(m_file2);
    Mere::Config::IniParser parser(config);

    std::string value = parser.parse("group3", "site");
    QVERIFY(value.compare("any") == 0);
}
