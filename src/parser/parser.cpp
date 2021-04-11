#include "parser.h"
#include "mere/utils/stringutils.h"

#include <fstream>
#include <iostream>

Mere::Config::Parser::Parser::Parser(const Config &config)
    : m_config(config)
{
}

const Mere::Config::Parser::Config& Mere::Config::Parser::Parser::config() const
{
    return m_config;
}

bool Mere::Config::Parser::Parser::strict() const
{
    return m_config.strict();
}

bool Mere::Config::Parser::Parser::isComment(const std::string &line) const
{
    return m_config.isComment(line);
}

std::vector<std::string> Mere::Config::Parser::Parser::parse() const
{
    std::string path = m_config.path();

    std::ifstream file(path);
    if (!file.good()) return {};

    std::vector<std::string> lines;

    std::string line;
    while (next(file, line))
        lines.push_back(line);

    return lines;
}

std::string Mere::Config::Parser::Parser::parse(const std::string &match, int *set) const
{
    std::string path = this->config().path();

    std::ifstream file(path);
    if (!file.good()) return {};

    std::string seek(match);
    bool result = this->seek(file, seek);

    if (set) *set = result;

    return seek;
}

bool Mere::Config::Parser::Parser::next(std::ifstream &file, std::string &line) const
{
    while(std::getline(file, line))
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
        if (seek.compare(line) == 0)
            break;
    }

    return static_cast<bool>(file);
}

std::string Mere::Config::Parser::Parser::key(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(0, pos);
}

std::string Mere::Config::Parser::Parser::value(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(pos + 1);
}