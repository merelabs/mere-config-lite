#ifndef MERE_CONFIG_DOCUMENT_H
#define MERE_CONFIG_DOCUMENT_H

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

    RootGroup* root() const;
    void root(RootGroup *root);

    Group* group(const std::string &path) const;
    Property* property(const std::string &path) const;

private:
    Group* traverse(const std::string &path) const;
    Group* traverse(const Group *group, const std::string &path) const;

private:
    std::string m_name;
    std::string m_type;
    std::string m_path;

    RootGroup *m_root;
};

}
}
#endif // MERE_CONFIG_DOCUMENT_H
