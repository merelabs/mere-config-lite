#ifndef MERE_CONFIG_PARSER_GROUPPARSER_H
#define MERE_CONFIG_PARSER_GROUPPARSER_H

#include "../spec/baseex.h"
#include "parser.h"
#include "../group.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC GroupParser : public Parser
{
public:
    explicit GroupParser(const Spec::BaseEx &spec);

    virtual std::vector<Group *> parse() const = 0;
    virtual Group* parse(const std::string &name) const = 0;
    virtual Property* parse(const std::string &group, const std::string &property) const = 0;

protected:
    // move to next valid group
    bool next(std::ifstream &file, std::string &line) const;

private:
    const Spec::BaseEx &m_spec;
};

}
}
}

#endif // MERE_CONFIG_PARSER_GROUPPARSER_H
