#include "testdotparser.h"

#include "mere/config/dotconfig.h"
#include "mere/config/dotparser.h"

#include <fstream>

void TestDotParser::initTestCase()
{
    m_file1 = std::tmpnam(nullptr);

    std::ofstream file(m_file1);
    file << "\n";
    file << "#this is a commnet" << "\n";
    file << "name=parser" << "\n";
    file.close();

    m_file2 = std::tmpnam(nullptr);

    std::ofstream file2(m_file2);
    file2 << "\n";
    file2 << "#this is a commnet" << "\n";
    file2 << "group1.name=parser" << "\n";
    file2 << "group2.name=kvparser" << "\n";
    file2 << "group2.note=a key value pair" << "\n";
    file2 << "group3.name=iniparser" << "\n";
    file2 << "group3.note=a gropped key value pair" << "\n";
    file2 << "group3.site=any" << "\n";
    file2.close();
}

void TestDotParser::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
}

void TestDotParser::test_strict_on()
{
    const Mere::Config::DotConfig config(m_file1);
    Mere::Config::DotParser parser(config);
    parser.strict(true);

    QVERIFY_EXCEPTION_THROWN(parser.parse(), std::exception);
}

void TestDotParser::test_strict_off()
{
    const Mere::Config::DotConfig config(m_file1);

    Mere::Config::DotParser parser(config);
    parser.strict(false);

    std::vector<Mere::Config::Property> properties = parser.parse();
    QVERIFY(properties.size() == 0);
}
