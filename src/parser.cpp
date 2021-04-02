#include "parser.h"
#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::Parser::Parser(const Config &config, QObject *parent)
    : QObject(parent),
      m_config(config)
{

}

const Mere::Config::Config& Mere::Config::Parser::config() const
{
    return m_config;
}

bool Mere::Config::Parser::isComment(const std::string &line) const
{
    return m_config.isCommnet(line);
}
