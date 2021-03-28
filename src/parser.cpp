#include "parser.h"

#include <fstream>

Mere::Config::Parser::Parser(const std::string &path, QObject *parent)
    : QObject(parent),
      m_path(path)
{

}

std::map<std::string, std::string> Mere::Config::Parser::parse() const
{
    std::map<std::string, std::string> properties;

    // check for the file extension
    std::string ext(".conf");
    auto pos = m_path.find(ext);
    if (pos != m_path.length() - ext.length())
        return properties;

    std::ifstream file(m_path);

    // check for the file existance
    if (!file.good()) return properties;

    std::string line;
    while (std::getline(file, line))
    {
        trim(line);

        if (line.empty()) continue;
        if (this->comment(line)) continue;

        std::string key   = this->key(line);
        if(key.empty()) continue;

        std::string value = this->value(line);

        properties.insert({key, value});
    }

    return properties;
}

std::string Mere::Config::Parser::parse(const std::string &key, int *set) const
{
    std::string value;

    if (set) *set = 0;

    // check for the file extension
    std::string ext(".conf");
    auto pos = m_path.find(ext);
    if (pos != m_path.length() - ext.length())
        return value;

    std::ifstream file(m_path);

    // check for the file existance
    if (!file.good()) return value;

    std::string line;
    while (std::getline(file, line))
    {
        trim(line);

        if (line.empty()) continue;
        if (this->comment(line)) continue;

        std::string k   = this->key(line);
        if(k.empty()) continue;

        if (k != key) continue;

        value = this->value(line);
        if (set) *set = 1;
        break;
    }

    return value;
}

std::string& Mere::Config::Parser::trim(std::string &line) const
{
    // left
    uint count = 0;
    while(count < line.length() && line[count] == ' ') count++;
    if (count) line.erase(0, count);

    // right
    count = line.length() - 1;
    while(count != 0 && line[count] == ' ') count--;
    if (count != line.length() - 1) line.erase(count);

    return line;
}

bool Mere::Config::Parser::comment(const std::string &line) const
{
    auto pos = line.find("#");

    return pos == 0;
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
