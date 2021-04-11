#ifndef MERE_CONFIG_PARSER_INIPARSER_H
#define MERE_CONFIG_PARSER_INIPARSER_H

#include "documentconfig.h"
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
    explicit IniParser(const DocumentConfig &config);

    Document parse() const override;
    Group parse(const std::string &name, int *set = nullptr) const override;
    Property parse(const std::string &group, const std::string &property, int *set = nullptr) const override;

protected:
    bool isGroup(const std::string &line) const;
    bool isSubGroup(const std::string &line) const;
    std::string group(const std::string &line) const;
    std::string subgroup(const std::string &group) const;
    std::string parent(const std::string &group) const;
    std::string base(const std::string &group) const;

signals:

private:
    const GroupConfig &m_config;
};

}
}
}

#endif // MERE_CONFIG_PARSER_INIPARSER_H
