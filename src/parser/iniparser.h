#ifndef MERE_CONFIG_PARSER_INIPARSER_H
#define MERE_CONFIG_PARSER_INIPARSER_H

#include "documentspec.h"
#include "documentparser.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC IniParser : public DocumentParser
{
public:
    explicit IniParser(const Spec::Document &spec);

    Document* parse() const override;
    Group *parse(const std::string &name) const override;
    Property* parse(const std::string &name, const std::string &key) const override;

private:
    const Spec::BaseEx &m_spec;
};

}
}
}

#endif // MERE_CONFIG_PARSER_INIPARSER_H
