#include "testgroupparser.h"

#include "../src/parser/groupparser.h"

#include <fstream>

void TestGroupParser::initTestCase()
{
    m_file1 = std::tmpnam(nullptr);

    std::ofstream file(m_file1);
    file << "\n";
    file << "#this is a commnet" << "\n";
    file << "name=parser" << "\n";
    file.close();
}

void TestGroupParser::cleanupTestCase()
{
    remove(m_file1.c_str());
}
