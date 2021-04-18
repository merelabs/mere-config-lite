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

    virtual Group* parseGroup() const override;
    virtual Group* parseGroup(const std::string &name) const ;

    virtual Property* parseProperty(const std::string &key) const override;
    virtual Property* parseProperty(const std::string &name, const std::string &key) const ;

    virtual std::vector<Mere::Config::Property *> parseProperties() const override;
    virtual std::vector<Mere::Config::Group *> parseGroups() const override;

private:
    Group *parent(Group *node, const std::string &parent) const;

private:
    const Spec::BaseEx &m_spec;
};

}
}
}
#endif // CKPARSER_H
