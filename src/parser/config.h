#ifndef MERE_CONFIG_PARSER_CONFIG_H
#define MERE_CONFIG_PARSER_CONFIG_H

#include "../global.h"
#include <string>

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC Config
{
public:
    virtual ~Config();
    explicit Config(const std::string &path);

    std::string path() const;
    void path(const std::string &path);

    bool strict() const;
    void strict(bool strict);

    std::string comment() const;
    void comment(const std::string &commnet);
    bool isComment(const std::string &line) const;

private:
    std::string m_path;

    bool m_strict;
    std::string m_comment;
};

}
}
}


#endif // MERE_CONFIG_PARSER_CONFIG_H
