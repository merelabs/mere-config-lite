#ifndef MKPARSER_H
#define MKPARSER_H

#include "crossconfig.h"
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
    explicit CKParser(const CrossConfig &config);

    RootGroup parse() const;

private:
    const CrossConfig &m_config;
};

}
}
}
#endif // MKPARSER_H
