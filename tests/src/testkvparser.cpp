#include "testkvparser.h"

#include "mere/config/kvconfig.h"
#include "mere/config/kvparser.h"
#include "mere/config/property.h"
#include "mere/config/exception.h"

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
    const Mere::Config::KVConfig config(m_file2);

    Mere::Config::KVParser parser(config);
    parser.strict(true);

    QVERIFY_EXCEPTION_THROWN(parser.parse(), std::exception);
}

void TestKVParser::test_strict_off()
{
    const Mere::Config::KVConfig config(m_file2);

    Mere::Config::KVParser parser(config);
    parser.strict(false);

    std::vector<Mere::Config::Property> properties = parser.parse();
    QVERIFY(properties.size() == 0);
}

void TestKVParser::test_property_number()
{
    const Mere::Config::KVConfig config(m_file1);

    Mere::Config::KVParser parser(config);

    std::vector<Mere::Config::Property> properties = parser.parse();
    QVERIFY(properties.size() == 1);
}

void TestKVParser::test_property_value()
{
    const Mere::Config::KVConfig config(m_file1);
    Mere::Config::KVParser parser(config);

    std::string value = parser.parse("name");
    QVERIFY(value.compare("parser") == 0);
}
