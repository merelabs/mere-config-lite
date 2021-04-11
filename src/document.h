#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "global.h"
#include "rootgroup.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC Document
{
public:
    ~Document() = default;
    Document() = default;

    explicit Document(const std::string &name);

    Document(const Document &that) = default;
    Document& operator=(const Document &that) = default;

    Document(Document &&that) = default;
    Document& operator=(Document &&that) = default;

    std::string name() const;
    void name(const std::string &name);

    RootGroup root() const;
    void root(const RootGroup &root);

//    Group group() const;
//    Property property() const;

private:
    std::string m_name;
    std::string m_type;
    std::string m_path;

    std::vector<Property> m_properties;
    std::vector<Group> m_groups;

    RootGroup   m_root;
};

}
}
#endif // DOCUMENT_H
