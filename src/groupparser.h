#ifndef GROUPPARSER_H
#define GROUPPARSER_H

#include "groupconfig.h"
#include "parser.h"
#include "group.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC GroupParser : public Parser
{
    Q_OBJECT
public:
    explicit GroupParser(const GroupConfig &config, QObject *parent = nullptr);

signals:

};

}
}

#endif // GROUPPARSER_H
