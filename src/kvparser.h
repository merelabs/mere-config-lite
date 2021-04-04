#ifndef KVPARSER_H
#define KVPARSER_H

#include "kvconfig.h"
#include "parser.h"
#include "property.h"

#include <string>

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC KVParser : public Parser
{
    Q_OBJECT
public:
    explicit KVParser(const KVConfig &config, QObject *parent = nullptr);

    virtual std::vector<Property> parse() const;
    virtual std::string parse(const std::string &key, int *set = nullptr) const;

protected:
    virtual std::string key(const std::string &line) const;
    virtual std::string value(const std::string &line) const;

signals:

};

}
}

#endif // KVPARSER_H
