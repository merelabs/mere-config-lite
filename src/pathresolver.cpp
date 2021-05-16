#include "pathresolver.h"
#include "homespec.h"

#include "mere/utils/pathutils.h"

std::string Mere::Config::PathResolver::resolve(const std::string &path, const std::string &type)
{
    Q_UNUSED(type)

    int resolved;
    std::string realpath = Mere::Utils::PathUtils::resolve(path, &resolved);
    if (resolved) return realpath;

    std::vector<std::string> homes = HomeSpec::homes();
    for(std::string &home : homes)
    {
        if(Mere::Utils::PathUtils::exists(home.append(path)))
            return home;
    }

    return "";
}
