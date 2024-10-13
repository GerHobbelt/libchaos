//#include "unif01.h"
//#include "usoft.h"
//#include "scatter.h"

#include "TestU01/suite.h"

static int Proj[] = { 1, 3 };
static long LacI[] = { 1, 2, 6};
static double Lower[] = { 0.0, 0.0, 0.0 };
static double Upper[] = { 0.0001, 0.5, 1.0 };

#include <chaos/monolithic_examples.h>

#if defined(BUILD_MONOLITHIC)
#define main chaos_testU01_example_scat2_main
#endif

int main (void)
{
   unif01_Gen *gen;

   gen = usoft_CreateVisualBasic (12345);
   scatter_PlotUnif1 (gen, 10000000, 3, FALSE, Proj, Lower, Upper,
		      scatter_latex, 8, TRUE, LacI, "bone");
   usoft_DeleteGen (gen);
   return 0;
}
