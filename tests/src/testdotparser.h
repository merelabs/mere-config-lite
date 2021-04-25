#ifndef TESTDOTPARSER_H
#define TESTDOTPARSER_H

#include <QtTest>

class TestDotParser : public QObject
{
    Q_OBJECT
public:
    ~TestDotParser(){};
    TestDotParser(){};

    void initTestCase();
    void cleanupTestCase();

    void test_strict_on();
    void test_strict_off();

private:
    std::string m_file1;
    std::string m_file2;
};

#endif // TESTDOTPARSER_H
