#ifndef MERE_CONFIG_PARSER_CKPARSER_H
#define MERE_CONFIG_PARSER_CKPARSER_H

#include "crossparser.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class CKParser : public CrossParser
{
public:
    explicit CKParser(const Spec::BaseEx &spec);

    virtual Group* parse() const override;

    virtual Group* parse(const std::string &name) const override;

    virtual Property* parse(const std::string &name, const std::string &key) const override;

    virtual std::vector<Mere::Config::Property *> properties() const override;
    virtual std::vector<Mere::Config::Group *> groups() const override;

private:
    Group *parent(Group *node, const std::string &parent) const;

private:
    const Spec::BaseEx &m_spec;
};

}
}
}
#endif // MERE_CONFIG_PARSER_CKPARSER_H
