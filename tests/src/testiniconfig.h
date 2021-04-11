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
    void test_section_count();
    void test_propery_count();
    void test_propery_value();

private:
    std::string m_file1;
    std::string m_file2;

};

#endif // TESTINICONFIG_H
