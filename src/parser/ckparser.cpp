#include "ckparser.h"
#include "gkparser.h"
#include "kvparser.h"
#include "../exception.h"

#include <fstream>

Mere::Config::Parser::CKParser::CKParser(const Spec::BaseEx &spec)
    : CrossParser(spec),
      m_spec(spec)
{
}

Mere::Config::Group* Mere::Config::Parser::CKParser::parse() const
{
    std::ifstream file(config().path());
    if (!file.good()) return nullptr;
    file.close();

    Group *root = new Group();
    root->properties(properties());
    root->groups(groups());

    return root;
}

Mere::Config::Group* Mere::Config::Parser::CKParser::parse(const std::string &name) const
{
    GKParser parse(m_spec);
    return parse.parse(name);
}

Mere::Config::Property* Mere::Config::Parser::CKParser::parse(const std::string &name, const std::string &key) const
{
    GKParser parse(m_spec);
    return parse.parse(name, key);
}

std::vector<Mere::Config::Property *> Mere::Config::Parser::CKParser::properties() const
{
    Mere::Config::Spec::BaseEx config(m_spec);
    config.strict(Spec::Base::Strict::Soft);

    KVParser kvparser(config);
    return kvparser.parse();
}

std::vector<Mere::Config::Group *> Mere::Config::Parser::CKParser::groups() const
{
    Mere::Config::Spec::BaseEx config(m_spec);
    config.strict(Spec::Base::Strict::Soft);

    GKParser gkparser(config);
    return gkparser.parse();
}

Mere::Config::Group* Mere::Config::Parser::CKParser::parent(Group *node, const std::string &parent) const
{
    while (node && node->name().compare(parent))
        node = node->parent();

    return node;
}
