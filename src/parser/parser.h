#ifndef MERE_CONFIG_PARSER_PARSER_H
#define MERE_CONFIG_PARSER_PARSER_H

#include "../global.h"
#include "config.h"
#include <istream>

namespace Mere
{
namespace Config
{

namespace Parser
{

class MERE_CONFIG_LIB_SPEC Parser
{
public:
    explicit Parser(const Config &config);
    const Config &config() const;

    std::vector<std::string> parse() const;
    std::string parse(const std::string &match, int *set = nullptr) const;

protected:
    bool strict() const;
    bool isComment(const std::string &line) const;

    // move to next valid line
    // valid line means, not a commnet or empty line
    virtual bool next(std::ifstream &file, std::string &line) const;

    // move to line that starts with privided string
    bool seek(std::ifstream &file, std::string &line) const;

    // it shoild not know about key/value
    std::string key(const std::string &line) const;
    std::string value(const std::string &line) const;

private:
    const Config &m_config;
};
}
}
}

#endif // MERE_CONFIG_PARSER_PARSER_H
