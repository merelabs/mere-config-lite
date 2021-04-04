#include "testparser.h"
#include "testkvparser.h"
#include "testiniparser.h"

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
      TestIniParser test;
      status |= QTest::qExec(&test, argc, argv);
   }
   return status;
}
