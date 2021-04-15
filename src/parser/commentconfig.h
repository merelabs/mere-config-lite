#ifndef COMMENTCONFIG_H
#define COMMENTCONFIG_H

#include "../global.h"
#include <string>

namespace Mere
{
namespace Config
{
namespace Parser
{

class MERE_CONFIG_LIB_SPEC CommentConfig
{
public:
    CommentConfig();
    explicit CommentConfig(const std::string &pattern);

    std::string pattern() const;
    void pattern(const std::string &pattern);

    bool isComment(const std::string &line) const;

private:
    std::string m_pattern;
};

}
}
}
#endif // COMMENTCONFIG_H
