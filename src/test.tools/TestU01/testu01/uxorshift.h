/*  uxorshift.h  for ANSI C */

#ifndef TESTU01_UXORSHIFT_H
#define TESTU01_UXORSHIFT_H
 
//#include "gdef.h"
//#include "unif01.h"

#include "TestU01/types.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */


unif01_Gen* uxorshift_CreateXorshift32 (int a, int b, int c, unsigned int x);



#ifdef USE_LONGLONG
  unif01_Gen* uxorshift_CreateXorshift64 (int a, int b, int c, ulonglong x);
#endif



unif01_Gen * uxorshift_CreateXorshiftC (int a, int b, int c, int r,                                        unsigned int X[]);



unif01_Gen * uxorshift_CreateXorshiftD (int r, int a[], unsigned int X[]);



unif01_Gen* uxorshift_CreateXorshift7 (unsigned int S[8]);



unif01_Gen* uxorshift_CreateXorshift13 (unsigned int S[8]);


void uxorshift_DeleteXorshiftC (unif01_Gen * gen);



void uxorshift_DeleteXorshiftD (unif01_Gen * gen);



void uxorshift_DeleteGen (unif01_Gen * gen);
 

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif

