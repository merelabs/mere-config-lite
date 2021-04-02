#include "groupconfig.h"

Mere::Config::GroupConfig::~GroupConfig()
{

}

Mere::Config::GroupConfig::GroupConfig(const std::string &path, QObject *parent)
    : GroupConfig(path, ".conf", parent)
{
}

Mere::Config::GroupConfig::GroupConfig(const std::string &path, const std::string &type, QObject *parent)
    : Config(path, type, parent)
{
}

Mere::Config::Group Mere::Config::GroupConfig::group(const std::string &name, int *set) const
{
    auto pos = std::find_if(m_groups.begin(), m_groups.end(), [&](const Group &group) -> bool{
        return group.name().compare(name) == 0;
    });

    if (pos == m_groups.end())
    {
        if (set) *set = 0;
        return Group();
    }

    if (set) *set = 1;

    return *pos;
}

void Mere::Config::GroupConfig::group(const Group &group)
{
    m_groups.push_back(group);
}

std::vector<Mere::Config::Group> Mere::Config::GroupConfig::groups() const
{
    return m_groups;
}

void Mere::Config::GroupConfig::groups(const std::vector<Group> &groups)
{
    m_groups.clear();
    m_groups.insert(m_groups.end(), groups.begin(), groups.end());
}
