/* After compiling TESTU01 and adding the libraries to your paths,
 * compile this program with
 * cc -O3 speedxoshiro128plusplus.c xoshiro128plusplus.c \
 *     -o speedxoshiro128plusplus -ltestu01 -lprobdist -lmylib -lm
 * then run it using ./speedxoshiro128plusplus.c
 */

//#include "unif01.h"
//#include "ulec.h"

#include "TestU01/suite.h"

//uint32_t xoshiro128plusplus (void);

#if defined(BUILD_MONOLITHIC)
#define main chaos_testU01_example_speedxoshiro128plusplus_main
#endif

int main (void)
{
	unif01_Gen *gen;

	gen = unif01_CreateExternGenBits("xoshiro128plusplus", xoshiro128plusplus);
	unif01_TimerSumGenWr (gen, 100000000, FALSE);
	ulec_DeleteGen (gen);

	return 0;
}
