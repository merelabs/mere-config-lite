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
    void test_section_property_number();
    void test_section_property_value();

private:
    std::string m_file1;
    std::string m_file2;
};


#endif // TESTINIPARSER_H
