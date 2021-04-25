#include "dotparser.h"
#include "../exception.h"
#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::Parser::DotParser::DotParser(const Spec::Base &spec)
    : KVParser(spec),
      m_spec(spec)
{

}
