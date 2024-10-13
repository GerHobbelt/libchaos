#ifndef TESTU01_TYPES_H
#define TESTU01_TYPES_H

/*************************************************************************\
 *
 * Package:        TestU01
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

#ifndef _FILE_OFFSET_BITS 
#define _FILE_OFFSET_BITS 64
#endif

#include <stdint.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <stdlib.h>

#ifndef USE_LONGLONG
#define USE_LONGLONG   1

typedef int64_t		   longlong;
typedef uint64_t		ulonglong;
#endif

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

typedef int  lebool;

typedef struct {
	void* state;
	void* param;
	char* name;
	double (*GetU01) (void* param, void* state);
	unsigned long (*GetBits) (void* param, void* state);
	void (*Write) (void* state);
} unif01_Gen;

typedef double (*fcho_FuncType) (double);

typedef struct {
	void* param;
	double (*Choose) (void* param, long, long);
	void (*Write) (void* param, long, long);
	char* name;
} fcho_Cho;

typedef struct {
	fcho_Cho* Chon;
	fcho_Cho* Chop2;
} fcho_Cho2;

typedef struct {
	unif01_Gen** Gen;
	int* LSize;
	int* Resol;
	int Ng;
	char* name;
} ffam_Fam;

typedef enum {
	ftab_NotInit,              /* Uninitialized */
	ftab_pVal1,                /* One-sided p-value */
	ftab_pVal2,                /* Two-sided p-value */
	ftab_pLog10,               /* Logarithm of p-value in base 10 */
	ftab_pLog2,                /* Logarithm of p-value in base 2 */
	ftab_Integer,              /* Integer number */
	ftab_Real,                 /* Real number */
	ftab_String                /* String */
} ftab_FormType;

typedef struct {
	double** Mat;
	int* LSize;
	int Nr, Nc;
	int j1, j2, jstep;
	ftab_FormType Form;
	char* Desc;
	char** Strings;
	int Ns;
} ftab_Table;

typedef enum {
	gofw_KSP,                      /* Kolmogorov-Smirnov+        */
	gofw_KSM,                      /* Kolmogorov-Smirnov-        */
	gofw_KS,                       /* Kolmogorov-Smirnov         */
	gofw_AD,                       /* Anderson-Darling           */
	gofw_CM,                       /* Cramer-vonMises            */
	gofw_WG,                       /* Watson G                   */
	gofw_WU,                       /* Watson U                   */
	gofw_Mean,                     /* Mean                       */
	gofw_Var,                      /* Variance                   */
	gofw_Cor,                      /* Correlation                */
	gofw_Sum,                      /* Sum                        */
	gofw_NTestTypes                /* Total number of test types */
} gofw_TestType;

typedef unsigned long bitset_BitSet;

typedef struct {
	ftab_Table* PVal[gofw_NTestTypes];
	bitset_BitSet Active;
	char* name;
} fres_Cont;

typedef struct {
	fres_Cont* Chi;
	fres_Cont* AD;
} fknuth_Res1;

typedef struct {
	fres_Cont* GCD;
	fres_Cont* NumIter;
} fmarsa_Res2;

typedef struct {
	ftab_Table* Exp;
	ftab_Table* Obs;
	ftab_Table* PLeft;
	ftab_Table* PRight;
	ftab_Table* PVal2;
	char* name;
} fres_Poisson;

#define smultin_MAX_DELTA  8
#define smultin_MAXB  10

#ifdef USE_LONGLONG
typedef ulonglong smultin_CellType;
#else
typedef double smultin_CellType;
#endif

typedef smultin_CellType(*smultin_GenerCellType) (unif01_Gen*, int, int,	long);

typedef struct {

	int NbDelta;
	double ValDelta[smultin_MAX_DELTA];
			smultin_GenerCellType GenerCell;
		int bmax;
} smultin_Param;

typedef struct {
	smultin_Param* Par;
	fres_Cont* PowDiv[smultin_MAX_DELTA];
	fres_Poisson* Coll;
	fres_Poisson* Empty;
	fres_Poisson* Balls[1 + smultin_MAXB];
	ftab_Table* COApprox;
} fmultin_Res;

enum snpair_StatType {
	snpair_NP,
	snpair_NPS,
	snpair_NPPR,
	snpair_mNP,
	snpair_mNP1,
	snpair_mNP1S,
	snpair_mNP2,
	snpair_mNP2S,
	snpair_NJumps,
	snpair_BB,
	snpair_BM,
	snpair_StatType_N
};

#define snpair_MAXM 512

typedef struct {
	ftab_Table* PVal[snpair_StatType_N];
} fnpair_Res1;

typedef struct {
	ftab_Table* PLeft;
	ftab_Table* PRight;
	ftab_Table* PVal2;
	char* name;
} fres_Disc;

struct fmass_INFO_T {
	double* cdf;                    /* cumulative probabilities */
	double* pdf;                    /* probability terms or mass distribution */
	double* paramR;                 /* real parameters of the distribution */
	long* paramI;                   /* integer parameters of the distribution */
	long smin;                      /* pdf[s] = 0 for s < smin */
	long smax;                      /* pdf[s] = 0 for s > smax */
	long smed;                      /* cdf[s] = F(s) for s <= smed, and
																		 cdf[s] = bar_F(s) for s > smed */
};

typedef struct fmass_INFO_T* fmass_INFO;

typedef struct {
	unsigned long microsec;
	unsigned long second;
} chrono_Chrono;

typedef enum {
	chrono_sec,
	chrono_min,
	chrono_hours,
	chrono_days,
	chrono_hms
} chrono_TimeFormat;

typedef enum {
	tables_Plain,
	tables_Mathematica,
	tables_Matlab
} tables_StyleType;

typedef double (*wdist_CFUNC) (double[], double);

typedef double (*wdist_DFUNC) (fmass_INFO, long);

typedef enum {
	gofw_Gnuplot,
	gofw_Mathematica
} gofw_GraphType;

typedef double gofw_TestArray[gofw_NTestTypes];

typedef struct {
	double* V;
	long Dim;
	long NObs;
	char* Desc;
} statcoll_Collector;

typedef struct {
	fres_Cont* BLen;
	fres_Disc* GLen;
} fstring_Res1;

typedef struct {
	fres_Cont* NBits;
	fres_Cont* NRuns;
} fstring_Res2;

typedef enum {
	ftab_Plain,                /* To print tables in plain text */
	ftab_Latex                 /* To print tables in Latex format */
} ftab_StyleType;

typedef void (*ftab_CalcType) (ffam_Fam* fam, void* res, void* cho,	void* par, int LSize, int j,	int irow, int icol);

typedef struct {
	fres_Cont* H;
	fres_Cont* M;
	fres_Cont* J;
	fres_Cont* R;
	fres_Cont* C;
} fwalk_Res1;

#define scatter_MAXDIM 64

typedef enum {
	scatter_latex,                 /* Latex format */
	scatter_gnu_ps,                /* gnuplot format for Postscript file */
	scatter_gnu_term               /* Interactive gnuplot format */
} scatter_OutputType;

typedef struct {
	statcoll_Collector* sVal1, * pVal1;
		gofw_TestArray sVal2, pVal2;
		char* name;
} sres_Basic;

typedef struct {
	double* NbExp;
	long* Count;
	long* Loc;
	long jmin;
	long jmax;
		long degFree;
		statcoll_Collector * sVal1, * pVal1;
		gofw_TestArray sVal2, pVal2;
		char* name;
} sres_Chi2;

typedef struct {
	sres_Basic* JumpNum;
	sres_Chi2* JumpSize;
	sres_Chi2* LinComp;
} scomp_Res;

typedef struct {
	long* Count;
		long jmin;
	long jmax;
		sres_Basic* Bas;
} sentrop_Res;

typedef struct {
	sres_Chi2* Chi;
	sres_Basic* Bas;
} sknuth_Res1;

typedef struct {
	double Lambda, Mu;
		statcoll_Collector* sVal1;
		double sVal2;
		double pLeft, pRight, pVal2;
		char* name;
} sres_Poisson;

typedef struct {
	sres_Poisson* Pois;
	sres_Basic* Bas;
} sknuth_Res2;

typedef struct {
	sres_Basic* Bas;
	sres_Poisson* Pois;
} smarsa_Res;

typedef struct {
	sres_Chi2* GCD;
	sres_Chi2* NumIter;
} smarsa_Res2;

typedef enum {
	smultin_CollNotInit,           /* Not initialized */
	smultin_CollExact,             /* Exact distribution */
	smultin_CollNormal,            /* Normal approximation */
	smultin_CollPoissonSparse,     /* Poisson approximation: sparse case */
	smultin_CollPoissonDense       /* Poisson approximation: dense case */
} smultin_CollApproxType;

typedef struct {
	lebool Hashing;
		smultin_CellType NbCellsTotal;
		lebool Over;
		smultin_CollApproxType CollApprox;
		double Mu[smultin_MAX_DELTA];
	double Sigma[smultin_MAX_DELTA];
		double EsEmpty;
		long CountSize;
	long Count1Size;
	long* Count;
	long* Count1;
	smultin_CellType* Cell;
	smultin_CellType* Cell1;
		long NbSize;
	long Nb1Size;
	smultin_CellType* Nb;
	smultin_CellType* Nb1;
		smultin_CellType NbCells[smultin_MAXB + 1];
	double EsCells[smultin_MAXB + 1];
	smultin_CellType WbCells[smultin_MAXB + 1];
		double NbCollisions;
		statcoll_Collector* Collector[smultin_MAX_DELTA];
			gofw_TestArray sVal2[smultin_MAX_DELTA];
	gofw_TestArray pVal2[smultin_MAX_DELTA];
			double pCollLeft, pCollRight;
		double pColl;
		double pEmpty;
		double pWb[smultin_MAXB + 1];
		int NbDeltaOld;
		double* TabFj[smultin_MAX_DELTA];
		int nLimit;
		lebool flagTab;
} smultin_Res;

typedef double (*smultin_MNTermeType) (double, double, long);

typedef struct {
	double Maxk;
		double SeuilHash;
		double HashLoad;
		double SeuilEColl;
		double SeuilCOverDense;
		double SeuilCOverNorSup;
		double SeuilCOverNorInf;
		double SeuilCOverSparse;
} smultin_Envir;

typedef struct {
	int Seuil1;        /* Recursion threshold for snpair_FindClosePairs */
	int Seuil2;        /* Recursion threshold for snpair_CheckBoundary  */
	int Seuil3;        /* L1 = 1 + (lg (n/Seuil3)) / sqrt(t) */
	int Seuil4;        /* L2 = 1 + (lg (n/Seuil4)) / sqrt(t) */
} snpair_Envir;

typedef double* snpair_PointType;

typedef snpair_PointType* snpair_PointTableType;

typedef struct snpair_Res snpair_Res;

typedef void (*snpair_DistanceType) (snpair_Res* res, snpair_PointType,	snpair_PointType);

typedef void (*snpair_VerifPairsType) (snpair_Res* res, snpair_PointType[],	long, long, int, int);

typedef void (*snpair_MiniProcType) (snpair_Res* res, snpair_PointType[],	long, long, long, long, int, int);

#define snpair_MAXREC 12

struct snpair_Res {
	long n;
		lebool CleanFlag;               /* If TRUE, free all memory */
	void* work;
		snpair_PointTableType Points[1 + snpair_MAXREC];
		int NumClose;
		double* CloseDist;
		snpair_DistanceType   Distance;
	snpair_VerifPairsType VerifPairs;
	snpair_MiniProcType   MiniProc;
		statcoll_Collector* Yn;
	statcoll_Collector* Y;
	statcoll_Collector* U;
	statcoll_Collector* V;
	statcoll_Collector* S;
	statcoll_Collector* TheWn;
	statcoll_Collector* TheWni;
	statcoll_Collector* ThepValAD;
	statcoll_Collector* BitMax;
		double sVal[snpair_StatType_N];
	double pVal[snpair_StatType_N];
};

typedef struct {
	statcoll_Collector* sVal1;
		double sVal2;
		double pLeft, pRight, pVal2;
		char* name;
} sres_Disc;

typedef struct {
	sres_Basic** LogCEMu;
	sres_Basic** LogCAMu;
	sres_Basic** SquareCEMu;
	sres_Basic** SquareCAMu;
			double* LogCESig_sVal, * LogCESig_pVal;
		double* LogCASig_sVal, * LogCASig_pVal;
		double* SquareCESig_sVal, * SquareCESig_pVal;
		double* SquareCASig_sVal, * SquareCASig_pVal;
			int imax;
			char* name;
			statcoll_Collector** Collectors;
		int smax, step;
} sspacings_Res;

typedef struct {
	sres_Basic* Bas;
		double* Coef;
		long jmin, jmax;
} sspectral_Res;

typedef struct {
	sres_Basic* NBits;
	sres_Chi2* NRuns;
	long* Count0;
	long* Count1;
} sstring_Res3;

typedef struct {
	sres_Chi2* Chi;
	sres_Disc* Disc;
} sstring_Res2;

#define sstring_MAXD 8

typedef struct {
	int L;
			tables_StyleType Style;
			long** Counters;
			double** ZCounters;
			int d;
				long XD[sstring_MAXD + 1][2];
				sres_Basic * Block[sstring_MAXD + 1];
					sres_Basic* Bas;
} sstring_Res;

typedef struct {
	long L0, L1, L;
			sres_Chi2** H;
	sres_Chi2** M;
	sres_Chi2** J;
	sres_Chi2** R;
	sres_Chi2** C;
		long imax;
		char* name;
		void* work;
} swalk_Res;

typedef struct {
	unif01_Gen* gen;
	long n;
	double time;
	double mean;
	lebool fU01;
} unif01_TimerRec;

typedef struct {
	unif01_Gen* gen1;
	unif01_Gen* gen2;
} unif01_Comb2_Param;

#define vectorsF2_WL      32

#define unif01_MASK32  0xffffffffUL
#define unif01_NORM32  4294967296.0
#define unif01_INV32   2.328306436538696289e-10




#define util_Max(x,y) (((x) > (y)) ? (x) : (y))
#define util_Min(x,y) (((x) < (y)) ? (x) : (y))

#define util_Warning(Cond,S) do { \
   if (Cond) { \
      printf ("*********  WARNING "); \
      printf ("in file  %s  on line  %d\n", __FILE__, __LINE__); \
      printf ("*********  %s\n", S); } \
   } while (0)

#define util_Error(S) do { \
   printf ("\n\n******************************************\n"); \
   printf ("ERROR in file %s   on line  %d\n\n", __FILE__, __LINE__); \
   printf ("%s\n******************************************\n\n", S); \
   exit (EXIT_FAILURE); \
   } while (0)

#define util_Assert(Cond,S) if (!(Cond)) util_Error(S)

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
