#ifndef TESTINIPARSER_H
#define TESTINIPARSER_H

#include <QtTest>

class TestIniParser : public QObject
{
    Q_OBJECT

public:
    TestIniParser(){};
    ~TestIniParser(){};

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_strict_on();
    void test_strict_off();
    void test_section_number_strict();
    void test_group_property_number();
    void test_group_subgroup_number();
    void test_group_property_value();

private:
    std::string m_file1;
    std::string m_file2;
    std::string m_file3;
};


#endif // TESTINIPARSER_H
