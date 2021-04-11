#ifndef TESTKVCONFIG_H
#define TESTKVCONFIG_H

#include <QtTest>

class TestKVConfig : public QObject
{
    Q_OBJECT
public:
    ~TestKVConfig(){};
    TestKVConfig(){};

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_propery_count();
    void test_propery_value();

private:
    std::string m_file1;
    std::string m_file2;
};

#endif // TESTKVCONFIG_H
