//#include "usoft.h"
//#include "unif01.h"
//#include "bbattery.h"

#include "TestU01/suite.h"

#if defined(BUILD_MONOLITHIC)
#define main chaos_testU01_example_bat3_main
#endif

int main (void)
{
   unif01_Gen *gen;
   int n = 1024*1024;

   /* Test the first n bits of binary file vax.bin */
   bbattery_AlphabitFile ("vax.bin", n);

   /* Test the Java random number generator */
   gen = usoft_CreateJava48 (1234567, 1);
   bbattery_Alphabit (gen, n, 0, 32);

   return 0;
}
