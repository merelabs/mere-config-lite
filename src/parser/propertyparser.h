#ifndef MERE_CONFIG_PARSER_PROPERTYPARSER_H
#define MERE_CONFIG_PARSER_PROPERTYPARSER_H

#include "parser.h"
#include "propertyconfig.h"
#include "../property.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class MERE_CONFIG_LIB_SPEC PropertyParser : public Parser
{
public:
    explicit PropertyParser(const PropertyConfig &config);

    virtual std::vector<Property> parse() const = 0;
    virtual Property parse(const std::string &key, int *set = nullptr) const = 0;

protected:
    // move to next valid property
    bool next(std::ifstream &file, std::string &line) const;

private:
    const PropertyConfig &m_config;

};

}
}
}

#endif // MERE_CONFIG_PARSER_PROPERTYPARSER_H
