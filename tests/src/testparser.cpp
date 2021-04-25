#include "testparser.h"

#include "../src/parser/parser.h"
#include "../src/spec/base.h"

#include <fstream>

class MyParser : public Mere::Config::Parser::Parser
{
public:
    MyParser(const Mere::Config::Spec::Base &spec)
        : Parser(spec),
          m_file(config().path())
    {
    }

    bool next(std::string &line)
    {
        return Parser::next(m_file, line);
    }

    bool prev(std::string &line)
    {
        return Parser::prev(m_file, line);
    }

private:
    std::ifstream m_file;
};

void TestParser::initTestCase()
{
    m_file1 = std::tmpnam(nullptr);

    std::ofstream file1(m_file1);
    file1 << "\n";
    file1 << "#this is a commnet" << "\n";
    file1 << "name=parser" << "\n";
    file1.close();

    m_file2 = std::tmpnam(nullptr);

    std::ofstream file2(m_file2);
    file2 << "\n";
    file2 << "#this is a commnet" << "\n";
    file2 << "name=parser" << "\n";
    file2 << "#this is aother comment line" << "\n";
    file2 << "note=checking to grab two valid lines" << "\n";
    file2 << "\n";
    file2.close();
}

void TestParser::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
}

void TestParser::test_next()
{
    Mere::Config::Spec::Base config(m_file1);
    MyParser parser1(config);

    std::string line;
    bool ok = parser1.next(line);
    QVERIFY(ok);
    QVERIFY(line.compare("name=parser") == 0);

    ok = parser1.next(line);
    QVERIFY(!ok);
}

void TestParser::test_prev()
{
    Mere::Config::Spec::Base config(m_file2);
    MyParser parser2(config);

    std::string nline;
    parser2.next(nline);

    std::string pline;
    parser2.prev(pline);
    QVERIFY(nline.compare(pline) == 0);
}

void TestParser::test_config_lines()
{
//    Mere::Config::Spec::Base config(m_file1);
//    Mere::Config::Parser::Parser parser1(config);

//    std::vector<std::string> lines = parser1.parse();
//    QVERIFY(lines.size() == 1);

//    config.path(m_file2);
//    Mere::Config::Parser::Parser parser2(config);

//    lines = parser2.parse();
//    QVERIFY(lines.size() == 2);
}
