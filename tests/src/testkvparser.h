#ifndef TESTKVPARSER_H
#define TESTKVPARSER_H

#include <QtTest>

class TestKVParser : public QObject
{
    Q_OBJECT

public:
    TestKVParser(){};
    ~TestKVParser(){};

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_strict_on();
    void test_strict_off();
    void test_property_number();
    void test_property_value();

private:
    std::string m_file1;
    std::string m_file2;
};


#endif // TESTKVPARSER_H
