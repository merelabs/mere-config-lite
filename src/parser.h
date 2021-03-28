#ifndef MERE_CONFIG_PARSER_H
#define MERE_CONFIG_PARSER_H

#include <QObject>

namespace Mere
{
namespace Config
{

class Parser : public QObject
{
    Q_OBJECT
public:
    explicit Parser(const std::string &path, QObject *parent = nullptr);
    std::map<std::string, std::string> parse() const;
    std::string parse(const std::string &key, int *set = nullptr) const;

private:
    bool comment(const std::string &line) const;
    std::string key(const std::string &line) const;
    std::string value(const std::string &line) const;

signals:

private:
    const std::string &m_path;
};
}
}

#endif // MERE_CONFIG_PARSER_H
