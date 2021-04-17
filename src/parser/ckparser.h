#ifndef CKPARSER_H
#define CKPARSER_H

#include "crossparser.h"

namespace Mere
{
namespace Config
{

namespace Parser
{

class CKParser : public CrossParser
{
public:
    explicit CKParser(const Spec::BaseEx &spec);

    virtual Group* parse() const override;
    virtual Group*parse(const std::string &name) const ;
    virtual Property*parse(const std::string &name, const std::string &key) const ;

    virtual std::vector<Mere::Config::Property *> parseProperties() const override;
    virtual std::vector<Mere::Config::Group *> parseGroups() const override;

protected:
    std::string group(const std::string &line) const;
    std::string subgroup(const std::string &group) const;
    std::string parent(const std::string &group) const;
    std::string base(const std::string &group) const;

private:
    const Spec::BaseEx &m_spec;
};

}
}
}
#endif // CKPARSER_H
