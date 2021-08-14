#include "parser.h"
#include "mere/utils/stringutils.h"

#include <fstream>
#include <iostream>
#include <sstream>

Mere::Config::Parser::Parser::Parser(const Spec::Base &spec)
    : m_spec(spec)
{
}

const Mere::Config::Spec::Base& Mere::Config::Parser::Parser::config() const
{
    return m_spec;
}

Mere::Config::Spec::Strict Mere::Config::Parser::Parser::strict() const
{
    return m_spec.strict();
}

bool Mere::Config::Parser::Parser::isComment(const std::string &line) const
{
    return m_spec.isComment(line);
}

bool Mere::Config::Parser::Parser::next(std::ifstream &file, std::string &line) const
{
    while(getline(file, line, Direction::Forward))
    {
        Mere::Utils::StringUtils::trim(line);

        if (line.empty()) continue;
        if (isComment(line)) continue;
        break;
    }

    return static_cast<bool>(file);
}

bool Mere::Config::Parser::Parser::prev(std::ifstream &file, std::string &line) const
{
    while(getline(file, line, Direction::Backword))
    {
        Mere::Utils::StringUtils::trim(line);

        if (line.empty()) continue;
        if (isComment(line)) continue;
        break;
    }

    return static_cast<bool>(file);
}


bool Mere::Config::Parser::Parser::seek(std::ifstream &file, std::string &line) const
{
    std::string seek(line);

    while(next(file, line))
    {
        if (line.find(seek) == 0)
            break;
    }

    return static_cast<bool>(file);
}

bool Mere::Config::Parser::Parser::seek(std::ifstream &file, std::streampos &position) const
{
    if(!file.seekg(position))
        return false;

    return true;
}

bool Mere::Config::Parser::Parser::getline(std::ifstream &file, std::string &line, Direction direction) const
{
    if (direction == Direction::Forward)
    {
        std::getline(file, line);
    }
    else if (direction == Direction::Backword)
    {
        // ignore the part of current line and '\n' of last line
        // or goto end of previous line
        file.unget();
//        while (file.unget())
//        {
//            if (file.get() == '\n')
//            {
//                file.unget();
//                break;
//            }

//            file.unget();
//        }

        while (file.unget())
        {
            char c = (char)file.get();
            if (c == '\n') break;

            line.insert(line.begin(), c);

            file.unget();
        }
    }

    return static_cast<bool>(file);
}
