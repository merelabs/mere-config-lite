#include "iniparser.h"
#include "ckparser.h"
#include "../property.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::IniParser::IniParser(const Spec::Document &spec)
    : DocumentParser(spec),
      m_spec(spec)
{
}

Mere::Config::Document* Mere::Config::Parser::IniParser::parse() const
{
    CKParser parse(m_spec);
    Group *group  = parse.parse();

    Document *document = new Document(m_spec.path());
    document->root((RootGroup*)group);

    return document;
}

Mere::Config::Group* Mere::Config::Parser::IniParser::parse(const std::string &name) const
{
    CKParser parse(m_spec);
    return parse.parse(name);
}

Mere::Config::Property* Mere::Config::Parser::IniParser::parse(const std::string &name, const std::string &key) const
{
    CKParser parse(m_spec);
    return parse.parse(name, key);
}

std::vector<Mere::Config::Property *> Mere::Config::Parser::IniParser::parseProperties() const
{
    CKParser parse(m_spec);

    return parse.properties();
}
