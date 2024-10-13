#ifndef TESTU01_MY16807_H
#define TESTU01_MY16807_H

//#include "unif01.h"

#include "TestU01/types.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

unif01_Gen *CreateMy16807 (int s);

void DeleteMy16807 (unif01_Gen * gen);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
