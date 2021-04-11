#include "dotparser.h"
#include "../exception.h"
#include "mere/utils/stringutils.h"

#include <fstream>

Mere::Config::Parser::DotParser::DotParser(const DotConfig &config)
    : KVParser(config),
      m_config(config)
{

}
