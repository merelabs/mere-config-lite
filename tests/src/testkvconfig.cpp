#include "testkvconfig.h"

#include "../src/kvconfig.h"

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
    Mere::Config::KVConfig config1(m_file1);
    config1.load();

    QVERIFY(config1.getProperties().size() == 1);

    Mere::Config::KVConfig config2(m_file2);
    config2.load();

    QVERIFY(config2.getProperties().size() == 6);
}

void TestKVConfig::test_propery_value()
{
    Mere::Config::KVConfig config1(m_file1);
    config1.load();

    QVERIFY(config1.getProperty("name")->value().compare("parser") == 0);

    Mere::Config::KVConfig config2(m_file2);
    config2.load();
    QVERIFY(config2.getProperty("group3.site")->value().compare("any") == 0);
}
