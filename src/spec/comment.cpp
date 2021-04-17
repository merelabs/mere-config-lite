#include "comment.h"

Mere::Config::Spec::Comment::Comment()
    : Comment("^#.*")
{

}

Mere::Config::Spec::Comment::Comment(const std::string &pattern)
    : Domain(pattern)
{

}

bool Mere::Config::Spec::Comment::isComment(const std::string &line) const
{
    return valid(line);
}


