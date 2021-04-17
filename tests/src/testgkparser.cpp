#include "testgkparser.h"

#include "../src/spec/base.h"
#include "../src/parser/gkparser.h"

#include <fstream>

void TestGKParser::initTestCase()
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
    file2 << "[group1]" << "\n";
    file2 << "prop1=parser" << "\n";
    file2 << "[group2]" << "\n";
    file2.close();
}

void TestGKParser::cleanupTestCase()
{
    remove(m_file1.c_str());
    remove(m_file2.c_str());
}

void TestGKParser::test_strict_on()
{
    Mere::Config::Spec::BaseEx config(m_file1);
    config.strict(true);

    Mere::Config::Parser::GKParser parser(config);
    QVERIFY_EXCEPTION_THROWN(parser.parse(), std::exception);
}

void TestGKParser::test_strict_off()
{
    Mere::Config::Spec::BaseEx config(m_file1);
    Mere::Config::Parser::GKParser parser(config);

    QVERIFY(parser.parse().size() == 0);
}

void TestGKParser::test_get_groups()
{
    Mere::Config::Spec::BaseEx config(m_file2);
    Mere::Config::Parser::GKParser parser(config);

    QVERIFY(parser.parse().size() == 2);
}

void TestGKParser::test_get_group()
{
    Mere::Config::Spec::BaseEx config(m_file2);
    Mere::Config::Parser::GKParser parser(config);

    Mere::Config::Group *group = parser.parse("group1");
    QVERIFY(group != nullptr);

    QVERIFY(group->properties().size() == 1);
}

void TestGKParser::test_get_group_property()
{
    Mere::Config::Spec::BaseEx config(m_file2);
    Mere::Config::Parser::GKParser parser(config);

    Mere::Config::Property *property = parser.parse("group1", "prop1");
    QVERIFY(property);
    QVERIFY(property->value().compare("parser") == 0);
}
