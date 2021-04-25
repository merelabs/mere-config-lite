#ifndef TESTPARSER_H
#define TESTPARSER_H

#include <QtTest>

class TestParser : public QObject
{
    Q_OBJECT
public:
    TestParser(){};
    ~TestParser(){};

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_next();
    void test_prev();
    void test_config_lines();

private:
    std::string m_file1;
    std::string m_file2;

};

#endif // TESTPARSER_H
