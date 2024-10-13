#ifndef TESTU01_LIB_H
#define TESTU01_LIB_H

/*************************************************************************\
 *
 * Package:        MyLib
 * Environment:    ANSI C
 *
 * Copyright (c) 2002 Pierre L'Ecuyer, DIRO, Université de Montréal.
 * e-mail: lecuyer@iro.umontreal.ca
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted without a fee for private, research,
 * academic, or other non-commercial purposes.
 * Any use of this software in a commercial environment requires a
 * written licence from the copyright owner.
 *
 * Any changes made to this package must be clearly identified as such.
 *
 * In scientific publications which used this software, a reference to it
 * would be appreciated.
 *
 * Redistributions of source code must retain this copyright notice
 * and the following disclaimer.
 *
 * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
\*************************************************************************/

#include "TestU01/types.h"

#include "../../mylib/num.h"

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

void  addstr_Long (char *to, const char *add, long n   );
void  addstr_Uint (char *to, const char *add, unsigned int n   );
void  addstr_Int (char *to, const char *add, int n   );
void  addstr_Ulong (char *to, const char *add, unsigned long n   );

#ifdef USE_LONGLONG
void  addstr_LONG (char *to, const char *add, longlong n   );
void  addstr_ULONG (char *to, const char *add, ulonglong n   );
#endif

void  addstr_Char (char *to, const char *add, char c   );
void  addstr_Double (char *to, const char *add, double x   );
void  addstr_Bool (char *to, const char *add, int b   );
void  addstr_ArrayLong (char *to, const char *add, int high, long val[]   );
void  addstr_ArrayUlong (char *to, const char *add,                          int high, unsigned long val[]   );
void  addstr_ArrayUint (char *to, const char *add, int high, 		        unsigned int val[]   );
void  addstr_ArrayInt (char *to, const char *add, int high, int val[]   );
void  addstr_ArrayDouble (char *to, const char *add,                          int high, double val[]   );




extern unsigned long bitset_maskUL[];
extern unsigned long bitset_MASK[];

#define bitset_TestBit(S, b)  ((S) & (bitset_maskUL[b]) ? 1 : 0)
#define bitset_SetBit(S, b) ((S) |= (bitset_maskUL[b]))
#define bitset_ClearBit(S, b) ((S) &= ~(bitset_maskUL[b]))




void bitset_WriteSet (char *desc, bitset_BitSet S, int n   );
bitset_BitSet bitset_Reverse (bitset_BitSet Z, int s   );

void chrono_Init (chrono_Chrono *C   );
chrono_Chrono * chrono_Create (void   );
void chrono_Delete (chrono_Chrono *C   );
double chrono_Val (chrono_Chrono *C, chrono_TimeFormat Unit   );
void chrono_Write (chrono_Chrono * C, chrono_TimeFormat Form   );

void gdef_GetHostName (char machine[], int n   );
void gdef_WriteHostName (void   );

void mystr_Delete (char S[], unsigned int index, unsigned int len   );
void mystr_Insert (char Res[], char Source[], unsigned int Pos   );
void mystr_ItemS (char R[], char S[], const char T[], unsigned int N   );
int mystr_Match (char Source[], char Pattern[]   );
void mystr_Slice (char R[], char S[], unsigned int P, unsigned int L   );
void mystr_Subst (char source[], char OldPattern[], char NewPattern[]   );
void mystr_Position (char Substring[], char Source[], unsigned int at,                     unsigned int *pos, int *found   );




extern double num_TwoExp[num_MaxTwoExp + 1];
extern double num_TENNEGPOW[];




int num_IsNumber (char S[]   );
void num_IntToStrBase (long k, long b, char S[]   );
void num_Uint2Uchar (unsigned char *output, unsigned int *input, int L   );
void num_WriteD (double x, int I, int J, int K   );
void num_WriteBits (unsigned long x, int k   );
long num_MultModL (long a, long s, long c, long m   );
double num_MultModD (double a, double s, double c, double m   );
long num_InvEuclid (long M, long x   );
unsigned long num_InvExpon (int E, unsigned long Z   );
long num_RoundL (double x   );
double num_RoundD (double x   );

double num2_Factorial (int n   );
double num2_LnFactorial (int n   );

#ifndef HAVE_LGAMMA
double num2_LnGamma (double x   );
#endif

double num2_Combination (int n, int s   );

#ifndef HAVE_LOG1P
double num2_log1p (double x   );
#endif

void num2_CalcMatStirling (double ***M, int m, int n   );
void num2_FreeMatStirling (double ***M, int m   );
double num2_VolumeSphere (double pLR, int k   );
double num2_EvalCheby (const double A[], int N, double x   );
double num2_BesselK025 (double x   );
double num2_Digamma (double x   );




extern tables_StyleType Style;




long **tables_CreateMatrixL (int N, int M   );
unsigned long **tables_CreateMatrixUL (int N, int M   );
double **tables_CreateMatrixD (int N, int M   );
void tables_DeleteMatrixL (long ***T   );
void tables_DeleteMatrixUL (unsigned long ***T   );
void tables_DeleteMatrixD (double ***T   );
void tables_CopyTabD (double T1[], double T2[], int n1, int n2   );
void tables_CopyTabL (long T1[], long T2[], int n1, int n2   );
void tables_QuickSortD (double T[], int l, int r   );
void tables_QuickSortL (long T[], int l, int r   );

#ifdef USE_LONGLONG
void tables_QuickSortLL (longlong T[], int l, int r   );
void tables_QuickSortULL (ulonglong T[], int l, int r   );
#endif

void tables_WriteTabL (long V[], int n1, int n2, int k, int p, char Desc[]   );
void tables_WriteTabD (double V[], int n1, int n2, int k, int p1,   int p2, int p3, char Desc[]   );

#ifdef USE_LONGLONG
void tables_WriteTabLL (longlong V[], int n1, int n2, int k, int p,    char Desc[]   );
void tables_WriteTabULL (ulonglong V[], int n1, int n2, int k, int p,    char Desc[]   );
#endif

void tables_WriteMatrixL (long **Mat, int i1, int i2, int j1, int j2,   int w, tables_StyleType style, char Nom[]   );
void tables_WriteMatrixD (double **Mat, int i1, int i2, int j1, int j2,   int w, int p, tables_StyleType style, char Nom[]   );
long tables_HashPrime (long n, double load   );

FILE *util_Fopen (const char *path, const char *mode   );
int util_Fclose (FILE * f   );
void *util_Malloc (size_t size   );
void *util_Calloc (size_t count, size_t esize   );
void *util_Realloc (void *ptr, size_t size   );
void *util_Free (void *p   );
void util_WriteBool (lebool b, int d   );
void util_ReadBool (char S[], lebool *x   );
int util_GetLine (FILE *infile, char *Line, char c   );

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
