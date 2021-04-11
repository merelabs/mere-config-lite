#include "testkvconfig.h"

#include "mere/config/kvconfig.h"

#include <fstream>

void TestKVConfig::initTestCase()
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

void TestKVConfig::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
}

void TestKVConfig::test_propery_count()
{
    const Mere::Config::KVConfig config1(m_file1);
    QVERIFY(config1.properties().size() == 1);

    const Mere::Config::KVConfig config2(m_file2);
    QVERIFY(config2.properties().size() == 6);
}

void TestKVConfig::test_propery_value()
{
    const Mere::Config::KVConfig config1(m_file1);

    QVERIFY(config1.property("name").compare("parser") == 0);

    const Mere::Config::KVConfig config2(m_file2);
    QVERIFY(config2.property("group3.site").compare("any") == 0);
}
