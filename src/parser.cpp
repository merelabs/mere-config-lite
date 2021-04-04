#include "parser.h"
#include "mere/utils/stringutils.h"

#include <fstream>
#include <iostream>

Mere::Config::Parser::Parser(const Config &config, QObject *parent)
    : QObject(parent),
      m_config(config)
{
}

const Mere::Config::Config& Mere::Config::Parser::config() const
{
    return m_config;
}

bool Mere::Config::Parser::strict() const
{
    return m_strict;
}

void Mere::Config::Parser::strict(bool strict)
{
    m_strict = strict;
}

bool Mere::Config::Parser::isComment(const std::string &line) const
{
    return m_config.isCommnet(line);
}

std::vector<std::string> Mere::Config::Parser::parse() const
{
    std::string path = this->config().path();

    std::ifstream file(path);
    if (!file.good()) return {};

    std::vector<std::string> lines;

    std::string line;
    while (next(file, line))
        lines.push_back(line);

    return lines;
}

std::string Mere::Config::Parser::parse(const std::string &match, int *set) const
{
    std::string path = this->config().path();

    std::ifstream file(path);
    if (!file.good()) return {};

    std::string line;
    while (next(file, line))
    {
        if(line.find(match) == 0)
            break;
    }

    if (set) *set = !line.empty();

    return line;
}

bool Mere::Config::Parser::next(std::ifstream &file, std::string &line) const
{
    while(std::getline(file, line))
    {
        Mere::Utils::StringUtils::trim(line);

        if (line.empty()) continue;
        if (this->isComment(line)) continue;
        break;
    }

    return static_cast<bool>(file);
}

std::string Mere::Config::Parser::key(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(0, pos);
}

std::string Mere::Config::Parser::value(const std::string &line) const
{
    auto pos = line.find("=");
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(pos + 1);
}
