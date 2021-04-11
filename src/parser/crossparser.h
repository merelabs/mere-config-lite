#ifndef MIXPARSER_H
#define MIXPARSER_H

#include "crossconfig.h"
#include "parser.h"
#include "../rootgroup.h"

namespace Mere
{
namespace Config
{
namespace Parser
{

class CrossParser : public Parser
{
public:
    CrossParser(const CrossConfig &config);

    virtual RootGroup parse() const = 0;
};

}
}
}

#endif // MIXPARSER_H
