#ifndef DOTPARSER_H
#define DOTPARSER_H

#include "groupconfig.h"
#include "groupparser.h"

namespace Mere
{
namespace Config
{

class DotParser : public GroupParser
{
    Q_OBJECT
public:
    explicit DotParser(const GroupConfig &config, QObject *parent = nullptr);

signals:

};

}
}
#endif // DOTPARSER_H
