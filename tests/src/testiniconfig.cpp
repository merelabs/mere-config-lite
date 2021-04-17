#include "testiniconfig.h"
#include "../src/iniconfig.h"

#include <fstream>

void TestIniConfig::initTestCase()
{
    m_file0 = std::tmpnam(nullptr);

    std::ofstream file0(m_file0);
    file0 << "\n";
    file0 << "#this is a commnet" << "\n";
    file0 << "nameparser" << "\n";
    file0.close();

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

    m_file3 = std::tmpnam(nullptr);

    std::ofstream file3(m_file3);
    file3 << "\n";
    file3 << "#this is a commnet" << "\n";
    file3 << "type=lib" << "\n";
    file3 << "name=config-lite" << "\n";
    file3 << "note=a simple flexible configuration library" << "\n";
    file3 << "[api]" << "\n";
    file3 << "count=4" << "\n";
    file3 << "[api/get]" << "\n";
    file3 << "count=14" << "\n";
    file3 << "[api/set]" << "\n";
    file3 << "count=7" << "\n";
    file3 << "api0=set property" << "\n";
    file3 << "api1=set property of a group" << "\n";
    file3 << "[api/read]" << "\n";
    file3 << "count=12" << "\n";
    file3 << "[api/write]" << "\n";
    file3 << "count=0" << "\n";
    file3 << "[api/write/document]" << "\n";
    file3 << "[group1 name with space]" << "\n";
    file3 << "name=kvparser" << "\n";
    file3 << "note=a key value pair" << "\n";
    file3 << "[group3]" << "\n";
    file3 << "note=a gropped key value pair for group3" << "\n";
    file3 << "site=any" << "\n";
    file3 << "[group3/sub group of group 3]" << "\n";
    file3 << "note=a gropped key value pair" << "\n";
    file3 << "site=any" << "\n";
    file3 << "[group3/sub group of group 3/second leyer subgroup]" << "\n";
    file3 << "note=a gropped key value pair" << "\n";
    file3 << "site=any" << "\n";
    file3.close();
}

void TestIniConfig::cleanupTestCase()
{
    remove(m_file0.c_str());
    remove(m_file1.c_str());
    remove(m_file2.c_str());
    remove(m_file3.c_str());
}

void TestIniConfig::test_syntax()
{
//    Mere::Config::IniConfig config0(m_file0);
//    config0.load();
}

void TestIniConfig::test_get()
{
    Mere::Config::IniConfig config(m_file3);
    config.load();

//    QVERIFY(config.get("type").compare("lib") == 0);
//    QVERIFY(std::stoi(config.get("api/count")) == 4);
//    QVERIFY(std::stoi(config.get("api/get/count")) == 14);
}

//void TestIniConfig::test_set()
//{
//    Mere::Config::IniConfig config(m_file3);

////     test before loading
////    config.set("age", "45");
////    QVERIFY(config.get("age").compare("45") == 0);


//    config.load();

//    config.set("age", "45");
//    QVERIFY(config.get("age").compare("45") == 0);

//    config.set("api/get/count", "5");
//    QVERIFY(std::stoi(config.get("api/get/count")) == 5);

//    config.set("api/get/age", "5");
//    QVERIFY(std::stoi(config.get("api/get/age")) == 5);
//}


//void TestIniConfig::test_read()
//{
//    Mere::Config::IniConfig config(m_file3);

//    int set = 0;
//    QVERIFY(config.read("type", &set).compare("lib") == 0);
//    QVERIFY(set == 1);

//    QVERIFY(config.read("mising-property", &set).empty());
//    QVERIFY(set == 0);

//    QVERIFY(std::stoi(config.read("api/get/count")) == 14);
//}

//void TestIniConfig::test_getKeys()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<std::string> keys = config.getKeys();

//    QVERIFY(keys.size() == 3);
//    QVERIFY(keys.at(0).compare("type") == 0);
//}

//void TestIniConfig::test_getValue()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    int set;
//    QVERIFY(config.getValue("type", &set).compare("lib") == 0);
//    QVERIFY(set == 1);

//    QVERIFY(config.getValue("missing", &set).empty());
//    QVERIFY(set == 0);
//}

//void TestIniConfig::test_getProperty()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    Mere::Config::Property* property = config.getProperty("type");
//    QVERIFY(property != nullptr);
//    QVERIFY(property->value().compare("lib") == 0);

//    property = config.getProperty("api/count");
//    QVERIFY(property != nullptr);
//    QVERIFY(std::stoi(property->value()) == 4);

//    property = config.getProperty("api/get/count");
//    QVERIFY(property != nullptr);
//    QVERIFY(std::stoi(property->value()) == 14);

//    property = config.getProperty("missing");
//    QVERIFY(property == nullptr);
//}

//void TestIniConfig::test_getProperties()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<Mere::Config::Property *> properties = config.getProperties();
//    QVERIFY(properties.size() == 3);
//    QVERIFY(properties.at(0)->name().compare("type") == 0);
//    QVERIFY(properties.at(0)->value().compare("lib") == 0);
//}

//void TestIniConfig::test_setProperty()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    int size = config.getProperties().size();

//    Mere::Config::Property property("abc", "def");
//    config.setProperty(&property);

//    std::vector<Mere::Config::Property *> properties = config.getProperties();
//    QVERIFY(properties.size() == size + 1);

//    Mere::Config::Property property1("abc", "def");
//    config.setProperty(&property1);
//    QVERIFY(properties.size() == size + 1);
//}

//void TestIniConfig::test_setValue()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    int size = config.getProperties().size();

//    config.setValue("abc", "def");
//    std::vector<Mere::Config::Property *> properties = config.getProperties();
//    QVERIFY(properties.size() == size + 1);

//    config.setValue("abc", "def");
//    QVERIFY(properties.size() == size + 1);
//}

//void TestIniConfig::test_readProperties()
//{
//    Mere::Config::IniConfig config(m_file3);

//    std::vector<Mere::Config::Property *> properties = config.readProperties();
//    QVERIFY(properties.size() == 3);
//}

//void TestIniConfig::test_readProperty()
//{
//    Mere::Config::IniConfig config(m_file3);

//    Mere::Config::Property *property = config.readProperty("type");
//    QVERIFY(property->value().compare("lib") == 0);
//}

//void TestIniConfig::test_getAllKeys()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<std::string> keys = config.getAllKeys();

//    QVERIFY(keys.size() == 18);
//    QVERIFY(keys.at(4).compare("api/get/count") == 0);
//}

//void TestIniConfig::test_getKeysOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<std::string> keys = config.getKeys("api");

//    QVERIFY(keys.size() == 1);
//    QVERIFY(keys.at(0).compare("count") == 0);
//}

//void TestIniConfig::test_getAllKeysOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<std::string> keys = config.getAllKeys("api");

//    QVERIFY(keys.at(1).compare("api/get/count") == 0);
//}

//void TestIniConfig::test_getGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    Mere::Config::Group *group = config.getGroup("api");
//    QVERIFY(group->name().compare("api") == 0);
//}

//void TestIniConfig::test_getGroups()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<Mere::Config::Group *> groups = config.getGroups();
//    QVERIFY(groups.size() == 3);
//}

//void TestIniConfig::test_getAllGroups()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<Mere::Config::Group *> groups = config.getAllGroups();
//    QVERIFY(groups.size() == 8);
//}

//void TestIniConfig::test_getGroupsOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<Mere::Config::Group *> groups = config.getGroups("api");
//    QVERIFY(groups.size() == 4);
//}

//void TestIniConfig::test_getAllGroupsOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<Mere::Config::Group *> groups = config.getAllGroups("api");
//    QVERIFY(groups.size() == 5);
//}

//void TestIniConfig::test_getValueOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::string value = config.getValue("api", "count");
//    QVERIFY(std::stoi(value) == 4);

//    Mere::Config::Group *group = config.getGroup("api");
//    value = config.getValue(group, "count");
//    QVERIFY(std::stoi(value) == 4);
//}

//void TestIniConfig::test_getPropertyOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    Mere::Config::Property *property = config.getProperty("api", "count");
//    QVERIFY(std::stoi(property->value()) == 4);
//}

//void TestIniConfig::test_getAllProperties()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<Mere::Config::Property *> properties = config.getAllProperties();
//    QVERIFY(properties.size() == 18);
//}

//void TestIniConfig::test_getPropertiesOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<Mere::Config::Property *> properties = config.getProperties("api");
//    QVERIFY(properties.size() == 1);
//}

//void TestIniConfig::test_getAllPropertiesOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    std::vector<Mere::Config::Property *> properties = config.getAllProperties("api");
//    QVERIFY(properties.size() == 7);
//}

//void TestIniConfig::test_readGroup()
//{
//    Mere::Config::IniConfig config(m_file3);
//    config.load();

//    Mere::Config::Group *group = config.readGroup("api");
//    QVERIFY(group->name().compare("api") == 0);
//}

//void TestIniConfig::test_readPropertyOfGroup()
//{
//    Mere::Config::IniConfig config(m_file3);

//    Mere::Config::Property *property = config.readProperty("api", "count");
//    QVERIFY(std::stoi(property->value()) == 4);
//}
