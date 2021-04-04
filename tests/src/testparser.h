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
    void test_line();
    void test_line_none();
    void test_lines();

private:
    std::string m_path;
};

#endif // TESTPARSER_H
