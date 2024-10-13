#ifndef TESTU01_EXAMPLES_H
#define TESTU01_EXAMPLES_H

#include "TestU01/types.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#if defined(BUILD_MONOLITHIC)
int chaos_testU01_example_bat1_main (void);
int chaos_testU01_example_bat2_main (void);
int chaos_testU01_example_bat3_main (void);
int chaos_testU01_example_birth1_main (void);
int chaos_testU01_example_birth2_main (void);
int chaos_testU01_example_ex1_main (void);
int chaos_testU01_example_ex3_main (void);
int chaos_testU01_example_ex4_main (void);
int chaos_testU01_example_ex7_main (void);
int chaos_testU01_example_fbirth_main (void);
int chaos_testU01_example_fcoll_main (void);
int chaos_testU01_example_scat_main (void);
int chaos_testU01_example_scat2_main (void);
int chaos_testU01_example_speedpcg32_main (void);
int chaos_testU01_example_speedxoshiro128plusplus_main (void);
int chaos_testU01_example_testpcg32_main (void);
int chaos_testU01_example_testxoshiro128plusplus_main (void);
#endif

double MRG32k3a (void);
uint32_t pcg32_random_r (void);
uint32_t xoshiro128plusplus (void);
unif01_Gen *CreateMy16807 (int s);
unsigned int xorshift (void);
void DeleteMy16807 (unif01_Gen * gen);

int chaos_testU01_tcode_tool_main(int argc, const char** argv);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
