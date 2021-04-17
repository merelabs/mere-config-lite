#ifndef TESTGKPARSER_H
#define TESTGKPARSER_H

#include <QtTest>

class TestGKParser : public QObject
{
    Q_OBJECT

public:
    TestGKParser(){};
    ~TestGKParser(){};

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_strict_on();
    void test_strict_off();
    void test_get_groups();
    void test_get_group();
    void test_get_group_property();

private:
    std::string m_file1;
    std::string m_file2;
};


#endif // TESTGKPARSER_H
