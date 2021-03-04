#include "homespec.h"

#include <iostream>
#include <vector>

//static
std::string Mere::Config::HomeSpec::local()
{
    return "/usr/local/etc/";
}

//static
std::string Mere::Config::HomeSpec::system()
{
    return "/etc/";
}

//static
std::vector<std::string> Mere::Config::HomeSpec::homes()
{
    return std::vector<std::string>({local(), system()});
}
