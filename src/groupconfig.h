#ifndef GROUPCONFIG_H
#define GROUPCONFIG_H

#include "config.h"
#include "group.h"

#include <QObject>

namespace Mere
{
namespace Config
{

class MERE_CONFIG_LIB_SPEC GroupConfig : public Config
{
    Q_OBJECT
public:
    virtual ~GroupConfig();
    explicit GroupConfig(const std::string &path, QObject *parent = 0);
    explicit GroupConfig(const std::string &path, const std::string &type, QObject *parent = 0);

    Group group(const std::string &name, int *set = nullptr) const;
    void group(const Group &group);

    std::vector<Group> groups() const;
    void groups(const std::vector<Group> &groups);

    virtual bool isGroup(const std::string &line) const = 0;

signals:

private:
    std::vector<Group> m_groups;
};

}
}
#endif // GROUPCONFIG_H
