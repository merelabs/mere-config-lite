#include "document.h"

Mere::Config::Document::Document(const std::string &name)
    : m_name(name)
{

}

std::string Mere::Config::Document::name() const
{
    return m_name;
}

void Mere::Config::Document::name(const std::string &name)
{
    m_name = name;
}

Mere::Config::RootGroup* Mere::Config::Document::root() const
{
    return m_root;
}

void Mere::Config::Document::root(RootGroup *root)
{
    m_root = root;
}

Mere::Config::Group* Mere::Config::Document::group(const std::string &path) const
{
    return traverse(path);
}

Mere::Config::Property* Mere::Config::Document::property(const std::string &path) const
{

    Group *group;

    std::string key;

    auto pos = path.find_last_of("/");
    if(pos != std::string::npos)
    {
        key = path.substr(pos + 1);
        group = traverse(path.substr(0, pos));
   }
    else
    {
        key = path;
        group = (Group *)m_root;
    }

    return group->property(key);
}

Mere::Config::Group* Mere::Config::Document::traverse(const std::string &path) const
{
    return traverse(m_root, path);
}

Mere::Config::Group* Mere::Config::Document::traverse(const Group *group, const std::string &path) const
{
    //FIXME:: delimiter
    auto pos = path.find("/");
    if(pos != std::string::npos)
    {
        Group *grp = group->group(path.substr(0, pos));
        if (!grp) return nullptr;

        return traverse(grp, path.substr(pos + 1));
    }

    return group->group(path);
}
