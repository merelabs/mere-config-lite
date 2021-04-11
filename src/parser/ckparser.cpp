#include "ckparser.h"
#include "../exception.h"

Mere::Config::Parser::CKParser::CKParser(const CrossConfig &config)
    : CrossParser(config),
      m_config(config)
{

}

Mere::Config::RootGroup Mere::Config::Parser::CKParser::parse() const
{
    RootGroup root;

    std::vector<Mere::Config::Group> groups;

    Group *groupPtr = &root;

    std::vector<std::string> lines = Parser::parse();
    for(const std::string &line : lines)
    {
        if (m_config.isGroup(line))
        {
            std::string name = m_config.group(line);
            // is sub group?
            if (m_config.isSubGroup(line))
            {
                std::string subgroup = m_config.subgroup(name);
                std::string parent   = m_config.parent(name);
                std::string base     = m_config.parent(name);

                if (groupPtr->name().compare(parent))
                {
                    if (strict()) throw Exception("malformed configuration");
                    continue;
                }

                Group group(subgroup);
                group.base(base);

                groupPtr->group(group);
                groupPtr = &groupPtr->groups().back();
            }
            else
            {
                Group group(name);
                groups.push_back(group);
                groupPtr = &groups.back();
            }

            continue;
        }

        if (!m_config.isProperty(line))
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        std::string key = this->key(line);
        if(key.empty())
        {
            if (strict()) throw Exception("malformed configuration");
            continue;
        }

        if (groupPtr)
            groupPtr->property(Property(key, this->value(line)));
    }

    return root;
}
