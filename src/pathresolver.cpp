#include "pathresolver.h"
#include "homespec.h"

#include <fstream>
#include <vector>

std::string Mere::Config::PathResolver::resolve(const std::string &path, const std::string &type)
{
    if (path.front() == '/')
        return path;

    std::vector<std::string> homes = HomeSpec::homes();
    for(std::string &home : homes)
    {
        if(std::ifstream(home.append(path)).good())
            return home;
    }

    return "";
}
