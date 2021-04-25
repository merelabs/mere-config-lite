#ifndef MERE_CONFIG_PARSER_LINEPARSER_H
#define MERE_CONFIG_PARSER_LINEPARSER_H

#include "parser.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class MERE_CONFIG_LIB_SPEC LineParser : public Parser
{
public:
    explicit LineParser(const Spec::Base &spec);

    std::vector<std::string> parseLines() const;
    std::string parseLine(const std::string &match, int *set = nullptr) const;

protected:
    // it shoild not know about key/value
    std::string key(const std::string &line) const;
    std::string value(const std::string &line) const;
};

}
}
}

#endif // MERE_CONFIG_PARSER_LINEPARSER_H
