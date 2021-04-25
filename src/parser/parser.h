#ifndef MERE_CONFIG_PARSER_PARSER_H
#define MERE_CONFIG_PARSER_PARSER_H

#include "../global.h"
#include "../spec/base.h"
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
    explicit Parser(const Spec::Base &spec);
    const Spec::Base &config() const;

protected:
    Spec::Base::Strict strict() const;
    bool isComment(const std::string &line) const;

    // move to next valid line
    // valid line means, not a commnet or not an empty line
    virtual bool next(std::ifstream &file, std::string &line) const;

    // move to previous valid line
    virtual bool prev(std::ifstream &file, std::string &line) const;

    // move to line that starts with privided string
    virtual bool seek(std::ifstream &file, std::string &line) const;

    // move to the stream position
    virtual bool seek(std::ifstream &file, std::streampos &position) const;

private:
    enum class Direction
    {
        Backword = -1,
        Forward  = 1
    };

    bool getline(std::ifstream &file, std::string &line, Direction direction = Direction::Forward) const;

private:
    const Spec::Base &m_spec;
};
}
}
}

#endif // MERE_CONFIG_PARSER_PARSER_H
