#include "testparser.h"
#include "testkvparser.h"
#include "testiniparser.h"
#include "testkvconfig.h"
#include "testgroupparser.h"
#include "testiniconfig.h"
#include "testdotparser.h"

int main(int argc, char** argv)
{
    int status = 0;
    {
      TestParser test;
      status |= QTest::qExec(&test, argc, argv);
    }
    {
      TestKVParser test;
      status |= QTest::qExec(&test, argc, argv);
    }
   {
      TestKVConfig test;
      status |= QTest::qExec(&test, argc, argv);
   }
   {
      TestGroupParser test;
      status |= QTest::qExec(&test, argc, argv);
   }
    {
      TestIniParser test;
      status |= QTest::qExec(&test, argc, argv);
    }
    {
     TestIniConfig test;
     status |= QTest::qExec(&test, argc, argv);
    }
    {
      TestDotParser test;
      status |= QTest::qExec(&test, argc, argv);
    }
    return status;
}
