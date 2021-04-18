#include "lineparser.h"

#include <fstream>

Mere::Config::Parser::LineParser::LineParser(const Spec::Base &spec)
    : Parser(spec)
{

}

std::vector<std::string> Mere::Config::Parser::LineParser::parseLines() const
{
    std::ifstream file(config().path());
    if (!file.good()) return {};

    std::vector<std::string> lines;

    std::string line;
    while (Parser::next(file, line))
        lines.push_back(line);

    return lines;
}

std::string Mere::Config::Parser::LineParser::parseLine(const std::string &match, int *set) const
{
    std::ifstream file(config().path());
    if (!file.good()) return {};

    std::string seek(match);
    bool result = this->seek(file, seek);

    if (set) *set = result;

    return seek;
}

std::string Mere::Config::Parser::LineParser::key(const std::string &line) const
{
    auto pos = line.find(config().property()->delimiter());
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(0, pos);
}

std::string Mere::Config::Parser::LineParser::value(const std::string &line) const
{
    auto pos = line.find(config().property()->delimiter());
    if (pos == 0 || pos == std::string::npos) return "";

    return line.substr(pos + 1);
}
