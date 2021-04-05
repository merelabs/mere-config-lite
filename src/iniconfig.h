#ifndef INICONFIG_H
#define INICONFIG_H

#include "groupconfig.h"

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC IniConfig : public GroupConfig
{
    Q_OBJECT
public:
    explicit IniConfig(const std::string &path, QObject *parent = nullptr);

    std::vector<std::string> sections() const;
    std::map<std::string, std::string> get(const std::string &section, int *set = nullptr) const;
    std::string get(const std::string &section, const std::string &property, int *set = nullptr) const;

    std::map<std::string, std::map<std::string, std::string>> properties() const;

//    bool isGroup(const std::string &line) const override;
//    std::string group(const std::string &line) const override;

private:
    void load();

signals:

private:
    std::map<std::string, std::map<std::string, std::string>> m_config;
};

}
}

#endif // INICONFIG_H
