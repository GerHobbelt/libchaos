//#include "gdef.h"
//#include "swrite.h"
//#include "bbattery.h"

#include "TestU01/suite.h"

#if defined(BUILD_MONOLITHIC)
#define main chaos_testU01_example_bat2_main
#endif

int main (void)
{
   swrite_Basic = FALSE;
   bbattery_RabbitFile ("vax.bin", 1048576);
   return 0;
}
