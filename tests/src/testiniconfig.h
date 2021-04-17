#ifndef TESTINICONFIG_H
#define TESTINICONFIG_H

#include <QtTest>

class TestIniConfig : public QObject
{
    Q_OBJECT
public:
    ~TestIniConfig(){};
    TestIniConfig(){};

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_syntax();
    void test_get();
//    void test_set();
//    void test_read();
//    void test_getKeys();
//    void test_getValue();
//    void test_getProperty();
//    void test_getProperties();

//    void test_getAllKeys();
//    void test_getKeysOfGroup();
//    void test_getAllKeysOfGroup();

//    void test_getGroup();
//    void test_getGroups();
//    void test_getAllGroups();
//    void test_getGroupsOfGroup();
//    void test_getAllGroupsOfGroup();
//    void test_getValueOfGroup();

//    void test_getPropertyOfGroup();
//    void test_getAllProperties();
//    void test_getPropertiesOfGroup();
//    void test_getAllPropertiesOfGroup();

//    void test_readGroup();
//    void test_readPropertyOfGroup();


//    void test_setProperty();
//    void test_setValue();

//    void test_readProperties();
//    void test_readProperty();

private:
    std::string m_file0;
    std::string m_file1;
    std::string m_file2;
    std::string m_file3;
};

#endif // TESTINICONFIG_H
