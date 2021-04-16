#ifndef MERE_CONFIG_PARSER_CROSSPARSER_H
#define MERE_CONFIG_PARSER_CROSSPARSER_H

#include "parser.h"
#include "../spec/baseex.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC CrossParser : public Parser
{
public:
    explicit CrossParser(const Spec::BaseEx &spec);
};

}
}
}

#endif // MERE_CONFIG_PARSER_CROSSPARSER_H
