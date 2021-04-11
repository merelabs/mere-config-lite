#include "testiniconfig.h"
#include "mere/config/iniconfig.h"

#include <fstream>

void TestIniConfig::initTestCase()
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
    file2 << "[group1]" << "\n";
    file2 << "name=kvparser" << "\n";
    file2 << "note=a key value pair" << "\n";
    file2 << "[group3]" << "\n";
    file2 << "note=a gropped key value pair" << "\n";
    file2 << "site=any" << "\n";
    file2.close();
}

void TestIniConfig::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
}

void TestIniConfig::test_section_count()
{
    const Mere::Config::IniConfig config1(m_file1);

    QVERIFY(config1.sections().size() == 0);

    const Mere::Config::IniConfig config2(m_file2);
    qDebug() << ">>>>>>>>>>" << config2.sections().size();
    QVERIFY(config2.sections().size() == 2);
}

void TestIniConfig::test_propery_count()
{
//    const Mere::Config::IniConfig config1(m_file1);
//    QVERIFY(config1.properties().size() == 0);

//    const Mere::Config::IniConfig config2(m_file2);
//    QVERIFY(config2.properties().size() == 6);
}

void TestIniConfig::test_propery_value()
{
//    const Mere::Config::IniConfig config1(m_file1);

//    QVERIFY(config1.property("name").compare("parser") == 0);

//    const Mere::Config::IniConfig config2(m_file2);
//    QVERIFY(config2.property("group3.site").compare("any") == 0);
}
