#ifndef TESTU01_PROBDIST_H
#define TESTU01_PROSDIST_H

/*************************************************************************\
 *
 * Package:        ProbDist
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

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

double fdist_belog(double);



extern const double fdist_XINF;
extern const double fdist_XBIG;
extern const double fdist_XBIGM;



double fbar_Unif(double x);
double fbar_Expon(double x);
double fbar_Weibull(double c, double x);
double fbar_Logistic(double x);
double fbar_Pareto(double c, double x);
double fbar_Normal1(double x);
double fbar_Normal2(double x);

#ifdef HAVE_ERF
double fbar_Normal3(double x);
#endif

double fbar_BiNormal1 (double x, double y, double rho, int ndig   );
double fbar_BiNormal2 (double x, double y, double rho   );
double fbar_LogNormal (double mu, double sigma, double x   );
double fbar_JohnsonSB (double alpha, double beta, double a, double b,   double x   );
double fbar_JohnsonSU (double alpha, double beta, double x   );
double fbar_AndersonDarling (long N, double X   );
double fbar_ChiSquare1 (long N, double x   );
double fbar_ChiSquare2 (long n, int d, double x   );
double fbar_Gamma (double alpha, int d, double x   );
double fbar_KSPlus (long N, double x   );
double fbar_KS1 (long n, double x   );
double fbar_CramerMises (long N, double x   );
double fbar_WatsonG (long N, double x   );
double fbar_WatsonU (long N, double x   );
double fbar_Scan (long N, double d, long m   );
double fbar_Geometric (double p, long n   );
double fbar_Poisson1 (double lam, long s   );
double fbar_Poisson2 (fmass_INFO W, long s   );
double fbar_Binomial2 (fmass_INFO W, long s   );
double fbar_NegaBin2 (fmass_INFO W, long s   );

double fdist_belog (double);
void fdist_CalcB4 (double, double *, double *, double *, double *);
double fdist_belog (double x   );
double fdist_Unif (double x   );
double fdist_Expon (double x   );
double fdist_Weibull (double c, double x   );
double fdist_ExtremeValue (double x   );
double fdist_Logistic (double x   );
double fdist_Pareto (double c, double x   );
double fdist_Normal1 (double x   );
double fdist_Normal2 (double x   );

#ifdef HAVE_ERF
double fdist_Normal3 (double x   );
#endif

double fdist_Normal4 (double x   );
double fdist_BiNormal1 (double x, double y, double rho, int ndig   );
double fdist_BiNormal2 (double dh, double dk, double rho   );
double fdist_LogNormal (double mu, double sigma, double x   );
double fdist_JohnsonSB (double alpha, double beta, double a, double b,   double x   );
double fdist_JohnsonSU (double alpha, double beta, double x   );
double fdist_ChiSquare1 (long N, double x   );
double fdist_ChiSquare2 (long n, int d, double x   );
double fdist_Student1 (long n, double x   );
double fdist_Student2 (long n, int d, double x   );
double fdist_Gamma (double alpha, int d, double x   );
double fdist_Beta (double p, double q, int d, double x   );
void fdist_CalcB4 (double alpha, double *pB, double *plogB, double *pC,                   double *plogC   );
double fdist_BetaSymmetric (double alpha, double x   );
double fdist_KS2 (long N0, double x   );
double fdist_KS1 (long n, double x   );
double fdist_KSPlus (long N, double x   );
double fdist_KSPlusJumpOne (long N, double a, double x   );

#if 0
void fdist_FindJumps (fdist_FUNC_JUMPS * H, int Detail   );
void fdist_FreeJumps (fdist_FUNC_JUMPS * H   );
double fdist_KSMinusJumpsMany (fdist_FUNC_JUMPS * H, double dMoins   );
double fdist_KSPlusJumpsMany (fdist_FUNC_JUMPS * H, double dPlus   );
#endif

double fdist_CramerMises (long N, double x   );
double fdist_WatsonU (long N, double x   );
double fdist_WatsonG (long n, double X   );
double fdist_AndersonDarling (long N, double x   );
double fdist_AndersonDarling2 (long N, double x   );
double fdist_Geometric (double p, long s   );
double fdist_Poisson1 (double lam, long s   );
double fdist_Poisson2 (fmass_INFO W, long s   );
double fdist_Binomial1 (long n, double p, long s   );
double fdist_Binomial2 (fmass_INFO W, long s   );
double fdist_NegaBin1 (long n, double p, long s   );
double fdist_NegaBin2 (fmass_INFO W, long s   );
double fdist_Scan (long N, double d, long m   );

double fdist_belog(double);
void fdist_CalcB4 (double, double *, double *, double *, double *);




extern const double fdist_XINF;
extern const double fdist_XBIG;
extern const double fdist_XBIGM;




double finv_Expon (double u   );
double finv_Weibull (double c, double u   );
double finv_ExtremeValue (double u   );
double finv_Logistic (double u   );
double finv_Pareto (double c, double u   );
double finv_Normal3 (double y   );
double finv_Normal1 (double x   );
double finv_Normal2 (double u   );
double finv_LogNormal (double mu, double sigma, double u   );
double finv_JohnsonSB (double alpha, double beta, double a, double b,                       double u   );
double finv_JohnsonSU (double alpha, double beta, double u   );
double finv_ChiSquare1 (long k, double u   );
double finv_ChiSquare2 (long k, double u   );
double finv_Student (long k, double u   );
double finv_BetaSymmetric (double alpha, double u   );
long finv_Geometric (double p, double u   );
double finv_GenericC (wdist_CFUNC F, double par[], double U, int prec,                      int Detail   );
long finv_GenericD1 (fmass_INFO W, double u   );




extern double fmass_Epsilon;
extern double fmass_MaxLambdaPoisson;
extern double fmass_MaxnBinomial;
extern double fmass_MaxnNegaBin;




double fmass_PoissonTerm1 (double lam, long s   );
fmass_INFO fmass_CreatePoisson (double lam   );
double fmass_PoissonTerm2 (fmass_INFO W, long s   );
void fmass_DeletePoisson (fmass_INFO W   );
double fmass_BinomialTerm1 (long n, double p, double q, long s   );
double fmass_BinomialTerm4 (long n, double p, double p2, long s   );
double fmass_BinomialTerm3 (long n, double p, long s   );
fmass_INFO fmass_CreateBinomial (long n, double p, double q   );
double fmass_BinomialTerm2 (fmass_INFO W, long s   );
void fmass_DeleteBinomial (fmass_INFO W   );
double fmass_NegaBinTerm1 (long n, double p, long s   );
fmass_INFO fmass_CreateNegaBin (long n, double p   );
double fmass_NegaBinTerm2 (fmass_INFO W, long s   );
void fmass_DeleteNegaBin (fmass_INFO W   );




extern double gofs_MinExpected;
extern double gofs_EpsilonAD;





void gofs_ContUnifTransform (double V[], long N, wdist_CFUNC F,                             double par[], double U[]   );
void gofs_DiscUnifTransform (double V[], long N, wdist_DFUNC F,                             fmass_INFO W, double U[]   );
void gofs_DiffD (double U[], double D[], long N1, long N2,                  double a, double b   );

#ifdef USE_LONGLONG
void gofs_DiffLL (longlong U[], longlong D[], long N1, long N2,                  longlong a, longlong b   );
void gofs_DiffULL (ulonglong U[], ulonglong D[], long N1, long N2,                   ulonglong a, ulonglong b   );
#endif

void gofs_DiffL (long U[], long D[], long N1, long N2, long a, long b   );
void gofs_IterateSpacings (double V[], double S[], long N   );
void gofs_PowerRatios (double U[], long N   );
void gofs_MergeClasses (double NbExp[], long Loc[],                        long *smin, long *smax, long *NbClasses   );
void gofs_WriteClasses (double NbExp[], long Loc[],                         long smin, long smax, long NbClasses   );
double gofs_Chi2 (double NbExp[], long Count[], long smin, long smax   );
double gofs_Chi2Equal (double NbExp, long Count[], long smin, long smax   );
long gofs_Scan (double U[], long N, double d   );
double gofs_CramerMises (double U[], long N   );
double gofs_WatsonG (double U[], long N   );
double gofs_WatsonU (double U[], long N   );
double gofs_AndersonDarling (double V[], long N   );
void gofs_KSJumpOne (double U[], long N, double a, double *DP, double *DM   );
void gofs_KS (double U[], long N, double *DP, double *DM, double *D   );

#if 0
void gofs_KSJumpsMany (double X[], int N, wdist_CFUNC F, double W[],                       double *DP, double *DM, int Detail   );
#endif



extern gofw_GraphType gofw_GraphSoft;
extern double gofw_Suspectp;
extern double gofw_Epsilonp;
extern double gofw_Epsilonp1;
extern char *gofw_TestNames[gofw_NTestTypes];
extern bitset_BitSet gofw_ActiveTests;




void gofw_GraphDistUnif (FILE * f, double U[], long N, char Desc[]   );
void gofw_GraphFunc (FILE *f, wdist_CFUNC F, double par[], double a,                     double b, int M, int mono, char Desc[]   );
double gofw_pDisc (double pLeft, double pRight   );
void gofw_Writep0 (double p   );
void gofw_Writep1 (double p   );
void gofw_Writep2 (double x, double p   );
void gofw_WriteKS0 (long N, double DP, double DM, double D   );
void gofw_WriteKS1 (double V[], long N, wdist_CFUNC F, double par[]   );
void gofw_WriteKSJumpOne0 (long N, double a, double DP   );
void gofw_WriteKSJumpOne1 (double V[], long N, wdist_CFUNC F, double par[],                           double a   );

#if 0
void gofw_KSJumpsMany0 (double DP, double DM, fdist_FUNC_JUMPS * H   );
void gofw_KSJumpsMany2 (statcoll_Collector *S, fdist_FUNC_JUMPS *H,                        int Detail   );
#endif

void gofw_InitTestArray (gofw_TestArray A, double x   );
void gofw_Tests0 (double U[], long N, gofw_TestArray sVal   );
void gofw_Tests1 (double V[], long N, wdist_CFUNC F, double par[],                  gofw_TestArray sVal   );
void gofw_ActiveTests0 (double U[], long N,                         gofw_TestArray sVal, gofw_TestArray pVal   );
void gofw_ActiveTests1 (double V[], long N, wdist_CFUNC F, double par[],                        gofw_TestArray sVal, gofw_TestArray pVal   );
void gofw_ActiveTests2 (double V[], double U[], long N, wdist_CFUNC F,   double par[], gofw_TestArray sVal, gofw_TestArray pVal   );
void gofw_WriteActiveTests0 (long N, gofw_TestArray sVal,                             gofw_TestArray pVal   );
void gofw_WriteActiveTests1 (double V[], long N, wdist_CFUNC F, double par[]   );
void gofw_WriteActiveTests2 (long N, gofw_TestArray sVal,   gofw_TestArray pVal, char S[]   );
void gofw_IterSpacingsTests0 (double U[], long N, int k,   lebool printval, lebool graph, FILE * f   );
void gofw_IterPowRatioTests0 (double U[], long N, int k,   lebool printval, lebool graph, FILE * f   );

void statcoll_SetDesc (statcoll_Collector * S, const char name[]   );
statcoll_Collector *statcoll_Create (long N, const char name[]   );
statcoll_Collector *statcoll_Delete (statcoll_Collector * S   );
void statcoll_Init (statcoll_Collector * S, long N   );
void statcoll_AddObs (statcoll_Collector * S, double x   );
void statcoll_Write (statcoll_Collector * S, int k, int p1, int p2, int p3   );
double statcoll_Average (statcoll_Collector * S   );
double statcoll_Variance (statcoll_Collector * S   );
double statcoll_AutoCovar (statcoll_Collector * S, int k   );
double statcoll_Covar (statcoll_Collector * S1, statcoll_Collector * S2   );

double wdist_Normal (double Junk[], double x   );
double wdist_ChiSquare (double W[], double x   );
double wdist_Unif (double Junk[], double x   );

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
