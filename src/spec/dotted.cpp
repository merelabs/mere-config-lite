#include "dotted.h"

Mere::Config::Spec::Dotted::~Dotted()
{
}

Mere::Config::Spec::Dotted::Dotted(const std::string &path)
    : Base(path)
{
    property()->pattern("^\\\w+(\\\.\\\w)+=.*$");
}
