
//#include "unif01.h"
//#include "ulcg.h"
//#include "smarsa.h"
//#include <stddef.h>

#include "TestU01/suite.h"

#if defined(BUILD_MONOLITHIC)
#define main chaos_testU01_example_birth1_main
#endif

int main (void)
{
   unif01_Gen *gen;
   gen = ulcg_CreateLCG (2147483647, 397204094, 0, 12345);
   smarsa_BirthdaySpacings (gen, NULL, 1, 1000, 0, 10000, 2, 1);
   smarsa_BirthdaySpacings (gen, NULL, 1, 10000, 0, 1000000, 2, 1);
   ulcg_DeleteGen (gen);
   return 0;
}
