
//#include "unif01.h"
//#include "ulcg.h"
//#include "sres.h"
//#include "swrite.h"
//#include "smarsa.h"

#include "TestU01/suite.h"

#if defined(BUILD_MONOLITHIC)
#define main chaos_testU01_example_birth2_main
#endif

int main (void)
{
   unif01_Gen *gen;
   sres_Poisson *res;
   swrite_Basic = FALSE;

   gen = ulcg_CreateLCG (2147483647, 397204094, 0, 12345);
   res = sres_CreatePoisson ();

   smarsa_BirthdaySpacings (gen, res, 1, 1000, 0, 10000, 2, 1);
   /* .... Examine or postprocess res */

   smarsa_BirthdaySpacings (gen, res, 1, 10000, 0, 1000000, 2, 1);
   /* .... Examine or postprocess res */

   sres_DeletePoisson (res);
   ulcg_DeleteGen (gen);
   return 0;
}
