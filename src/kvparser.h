#ifndef KVPARSER_H
#define KVPARSER_H

#include "kvconfig.h"
#include "parser.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC KVParser : public Parser
{
    Q_OBJECT
public:
    explicit KVParser(const KVConfig &config, QObject *parent = nullptr);

    std::string key(const std::string &line) const;
    std::string value(const std::string &line) const;

    std::map<std::string, std::string> parse() const;
    std::string parse(const std::string &key, int *set = nullptr) const;

signals:

};

}
}

#endif // KVPARSER_H
