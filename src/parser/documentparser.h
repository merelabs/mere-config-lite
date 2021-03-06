#ifndef MERE_CONFIG_PARSER_DOCUMENTPARSER_H
#define MERE_CONFIG_PARSER_DOCUMENTPARSER_H


#include "../spec/document.h"
#include "groupparser.h"
#include "../document.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class DocumentParser : public Parser
{
public:
    DocumentParser(const Spec::Document &spec);

    virtual Document* parse() const = 0;
    virtual Group* parse(const std::string &group) const = 0;
    virtual Property* parse(const std::string &group, const std::string &property) const = 0;
};

}
}
}

#endif // MERE_CONFIG_PARSER_DOCUMENTPARSER_H
