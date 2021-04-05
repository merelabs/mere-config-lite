#ifndef TESTGROUPPARSER_H
#define TESTGROUPPARSER_H

#include <QtTest>

class TestGroupParser : public QObject
{
    Q_OBJECT
public:
    ~TestGroupParser(){};
    TestGroupParser(){};

    void initTestCase();
    void cleanupTestCase();

private:
    std::string m_file1;
};

#endif // TESTGROUPPARSER_H
