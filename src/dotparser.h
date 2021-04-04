#ifndef DOTPARSER_H
#define DOTPARSER_H

#include "dotconfig.h"
#include "groupparser.h"

namespace Mere
{
namespace Config
{

class DotParser : public GroupParser
{
    Q_OBJECT
public:
    explicit DotParser(const DotConfig &config, QObject *parent = nullptr);

    std::vector<Property> parse() const;

protected:
    bool isGroup(const std::string &line) const override;
    std::string group(const std::string &line) const override;

signals:

private:
    const DotConfig &m_config;
};

}
}
#endif // DOTPARSER_H
