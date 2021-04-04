#ifndef MERE_CONFIG_PARSER_H
#define MERE_CONFIG_PARSER_H

#include "global.h"
#include "config.h"
#include <istream>
#include <QObject>

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(const Config &config, QObject *parent = nullptr);
    const Config& config() const;

    bool strict() const;
    void strict(bool strict);

    std::vector<std::string> parse() const;
    std::string parse(const std::string &match, int *set = nullptr) const;

protected:
    bool isComment(const std::string &line) const;
    bool next(std::ifstream &file, std::string &line) const;

    std::string key(const std::string &line) const;
    std::string value(const std::string &line) const;

signals:

private:
    bool m_strict;
    const Config &m_config;
};
}
}

#endif // MERE_CONFIG_PARSER_H
