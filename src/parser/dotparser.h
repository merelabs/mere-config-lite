#ifndef MERE_CONFIG_PARSER_DOTPARSER_H
#define MERE_CONFIG_PARSER_DOTPARSER_H

#include "../spec/base.h"
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
    explicit DotParser(const Spec::Base &spec);

private:
    const Spec::Base &m_spec;};

}
}

}
#endif // MERE_CONFIG_PARSER_DOTPARSER_H
