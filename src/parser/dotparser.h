#ifndef MERE_CONFIG_PARSER_DOTPARSER_H
#define MERE_CONFIG_PARSER_DOTPARSER_H

#include "dotconfig.h"
#include "kvparser.h"
#include "../property.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class MERE_CONFIG_LIB_SPEC DotParser : public KVParser
{
public:
    explicit DotParser(const DotConfig &config);

private:
    const DotConfig &m_config;};

}
}

}
#endif // MERE_CONFIG_PARSER_DOTPARSER_H
