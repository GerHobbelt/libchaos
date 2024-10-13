#ifndef TESTU01_H
#define TESTU01_H

//#include "bbattery.h"
//#include "fcho.h"
//#include "fcong.h"
//#include "ffam.h"
//#include "ffsr.h"
//#include "fknuth.h"
//#include "fmarsa.h"
//#include "fmultin.h"
//#include "fnpair.h"
//#include "fres.h"
//#include "fspectral.h"
//#include "fstring.h"
//#include "ftab.h"
//#include "fvaria.h"
//#include "fwalk.h"
//#include "scatter.h"
//#include "scomp.h"
//#include "sentrop.h"
//#include "sknuth.h"
//#include "smarsa.h"
//#include "smultin.h"
//#include "snpair.h"
//#include "sres.h"
//#include "sspacings.h"
//#include "sspectral.h"
//#include "sstring.h"
//#include "svaria.h"
//#include "swalk.h"
//#include "swrite.h"
//#include "uautomata.h"
//#include "ubrent.h"
//#include "ucarry.h"
//#include "ucrypto.h"
//#include "rijndael-alg-fst.h"
//#include "tu01_sha1.h"
//#include "ucubic.h"
//#include "udeng.h"
//#include "ufile.h"
//#include "ugfsr.h"
//#include "ugranger.h"
//#include "uinv.h"
//#include "uknuth.h"
//#include "ulcg.h"
//#include "ulec.h"
//#include "umarsa.h"
//#include "umrg.h"
//#include "unif01.h"
//#include "unumrec.h"
//#include "uquad.h"
//#include "usoft.h"
//#include "utaus.h"
//#include "utezuka.h"
//#include "utouzin.h"
//#include "uvaria.h"
//#include "uweyl.h"
//#include "uwu.h"
//#include "uxorshift.h"

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

#include "TestU01/types.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>


#if !defined(FALSE) || !defined(TRUE)
#define FALSE 0
#define TRUE 1
#endif


#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */




#define LEN 100

#define NDIM 200                  /* Dimension of extern arrays */

extern double bbattery_pVal[1 + NDIM];
extern char *bbattery_TestNames[1 + NDIM];
extern int bbattery_NTests;


void bbattery_SmallCrush (unif01_Gen * gen);
void bbattery_SmallCrushFile (char *filename);
void bbattery_RepeatSmallCrush(unif01_Gen *gen, int Rep[]);

void bbattery_Crush (unif01_Gen * gen);
void bbattery_RepeatCrush(unif01_Gen *gen, int Rep[]);
void bbattery_BigCrush(unif01_Gen *gen);
void bbattery_RepeatBigCrush(unif01_Gen *gen, int Rep[]);
void bbattery_Alphabit(unif01_Gen *gen, double nb, int r, int s);
void bbattery_AlphabitFile(char *filename, double nb);
void bbattery_RepeatAlphabit(unif01_Gen *gen, double nb, int r, int s, int Rep[]);
void bbattery_BlockAlphabit (unif01_Gen * gen, double n, int r, int s   );
void bbattery_RepeatBlockAlphabit (unif01_Gen * gen, double nb, int r, int s, int Rep[], int L);
void bbattery_BlockAlphabitFile (char *filename, double nb   );

void bbattery_Rabbit (unif01_Gen * gen, double nb);
void bbattery_RabbitFile (char *filename, double nb);
void bbattery_RepeatRabbit (unif01_Gen * gen, double nb, int Rep[]);
void bbattery_pseudoDIEHARD (unif01_Gen * gen);

void bbattery_FIPS_140_2 (unif01_Gen * gen);
void bbattery_FIPS_140_2File (char *filename);


extern int fcho_Resolution;


double fcho_Linear (double x);
double fcho_LinearInv (double x);
double fcho_2Pow (double x);
fcho_Cho * fcho_CreateSampleSize (double a, double b, double c, fcho_FuncType F, char *name);

void fcho_DeleteSampleSize (fcho_Cho *cho);
long fcho_ChooseParamL (fcho_Cho *cho, long min, long max, long i, long j);
int fcho_Chooses (int r, int s, int prec);
fcho_Cho2 * fcho_CreateCho2 (fcho_Cho *Chon, fcho_Cho *Chop2);
void fcho_DeleteCho2 (fcho_Cho2 *cho);

ffam_Fam *fcong_CreateLCG (char *filename, int i1, int i2, int istep);
void fcong_DeleteLCG (ffam_Fam * fam);
ffam_Fam *fcong_CreateLCGPow2 (char *filename, int i1, int i2, int istep);
void fcong_DeleteLCGPow2 (ffam_Fam * fam);
ffam_Fam *fcong_CreateMRG2 (char *filename, int i1, int i2, int istep);
void fcong_DeleteMRG2 (ffam_Fam * fam);
ffam_Fam *fcong_CreateMRG3 (char *filename, int i1, int i2, int istep);
void fcong_DeleteMRG3 (ffam_Fam * fam);
ffam_Fam *fcong_CreateCombL2 (char *filename, int i1, int i2, int istep);
void fcong_DeleteCombL2 (ffam_Fam * fam);
ffam_Fam *fcong_CreateCombWH2 (char *filename, int i1, int i2, int istep);
void fcong_DeleteCombWH2 (ffam_Fam * fam);
ffam_Fam *fcong_CreateInvImpl (char *filename, int i1, int i2, int istep);
void fcong_DeleteInvImpl (ffam_Fam * fam);
ffam_Fam *fcong_CreateInvImpl2a (char *filename, int i1, int i2, int istep);
void fcong_DeleteInvImpl2a (ffam_Fam * fam);
ffam_Fam *fcong_CreateInvImpl2b (char *filename, int i1, int i2, int istep);
void fcong_DeleteInvImpl2b (ffam_Fam * fam);
ffam_Fam *fcong_CreateInvExpl (char *filename, int i1, int i2, int istep);
void fcong_DeleteInvExpl (ffam_Fam * fam);
ffam_Fam *fcong_CreateInvExpl2a (char *filename, int i1, int i2, int istep);
void fcong_DeleteInvExpl2a (ffam_Fam * fam);
ffam_Fam *fcong_CreateInvExpl2b (char *filename, int i1, int i2, int istep);
void fcong_DeleteInvExpl2b (ffam_Fam * fam);
ffam_Fam *fcong_CreateInvMRG2 (char *filename, int i1, int i2, int istep);
void fcong_DeleteInvMRG2 (ffam_Fam * fam);
ffam_Fam *fcong_CreateCubic1 (char *filename, int i1, int i2, int istep);
void fcong_DeleteCubic1 (ffam_Fam * fam);
ffam_Fam *fcong_CreateCombCubic2 (char *filename, int i1, int i2, int istep);
void fcong_DeleteCombCubic2 (ffam_Fam * fam);
ffam_Fam *fcong_CreateCombCubLCG (char *filename, int i1, int i2, int istep);
void fcong_DeleteCombCubLCG (ffam_Fam * fam);

ffam_Fam * ffam_CreateFam (int Ng, char *name);
void ffam_DeleteFam (ffam_Fam *fam);
void ffam_PrintFam (ffam_Fam *fam);
void ffam_ReallocFam (ffam_Fam * fam, int Ng);

FILE *ffam_OpenFile (char *filename, char *deffile);
ffam_Fam * ffam_CreateSingle (unif01_Gen *gen, int prec, int i1, int i2);
void ffam_DeleteSingle (ffam_Fam *fam);

ffam_Fam * ffsr_CreateLFSR1 (char *fname, int i1, int i2, int istep);
void ffsr_DeleteLFSR1 (ffam_Fam * fam);
ffam_Fam * ffsr_CreateLFSR2 (char *fname, int i1, int i2, int istep);
void ffsr_DeleteLFSR2 (ffam_Fam * fam);
ffam_Fam * ffsr_CreateLFSR3 (char *fname, int i1, int i2, int istep);
void ffsr_DeleteLFSR3 (ffam_Fam * fam);
ffam_Fam * ffsr_CreateTausLCG2 (char *fname, int i1, int i2, int istep);
void ffsr_DeleteTausLCG2 (ffam_Fam * fam);

void rsrfft (double *x, int m);
void rstage (int n, int n2, int n4, double *x1, double *x2, double *x3, double *x4);
void rbitrev (double *x, int m);

void rsrfft (double *x, int m);
void rstage (int n, int n2, int n4, double *x1, double *x2, double *x3, double *x4);
void rbitrev (double *x, int m);



extern long fknuth_Maxn;


fknuth_Res1 * fknuth_CreateRes1 (void);
void fknuth_DeleteRes1 (fknuth_Res1 *res);
void fknuth_Gap1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                 long N, int r, double Alpha, double Beta,                 int Nr, int j1, int j2, int jstep);
void fknuth_SimpPoker1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                       long N, int r, int d, int k,                       int Nr, int j1, int j2, int jstep);

void fknuth_CouponCollector1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                             long N, int r, int d,                             int Nr, int j1, int j2, int jstep);
void fknuth_Run1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                long N, int r, lebool Up, lebool Indep,                 int Nr, int j1, int j2, int jstep);
void fknuth_MaxOft1 (ffam_Fam *fam, fknuth_Res1 *res, fcho_Cho *cho,                    long N, int r, int d, int t,                    int Nr, int j1, int j2, int jstep);
void fknuth_Serial1 (void);
void fknuth_SerialSparse1 (void);
void fknuth_Collision1 (void);
void fknuth_Permutation1 (void);
void fknuth_CollisionPermut1 (void);



extern long fmarsa_Maxn;
extern long fmarsa_MaxL;



fmarsa_Res2 * fmarsa_CreateRes2 (void   );
void fmarsa_DeleteRes2 (fmarsa_Res2 *res   );
void fmarsa_MatrixR1 (ffam_Fam * fam, fres_Cont * res, fcho_Cho2 * cho,   long N, long n, int r, int s, int L, int Nr, int j1, int j2, int jstep   );
fcho_Cho *fmarsa_CreateBirthEC (long N, int t, double EC   );
void fmarsa_DeleteBirthEC (fcho_Cho * cho   );
void fmarsa_BirthdayS1 (ffam_Fam * fam, fres_Poisson * res, fcho_Cho2 * cho,   long N, int r, int t, int p, int Nr, int j1, int j2, int jstep   );
void fmarsa_SerialOver1 (void   );
void fmarsa_CollisionOver1 (void   );
void fmarsa_GCD1 (ffam_Fam *fam, fmarsa_Res2 *res, fcho_Cho *cho,   long N, int r, int s, int Nr, int j1, int j2, int jstep   );




extern long fmultin_Maxn;




fmultin_Res *fmultin_CreateRes (smultin_Param * par   );
void fmultin_DeleteRes (fmultin_Res * res   );
void fmultin_DeleteEC (fcho_Cho * cho   );
fcho_Cho *fmultin_CreateEC_DT (long N, int t, double EC   );
fcho_Cho * fmultin_CreateEC_2HT (long N, int t, double EC   );
fcho_Cho * fmultin_CreateEC_2L (long N, double EC   );
fcho_Cho * fmultin_CreateEC_T (long N, double EC   );
void fmultin_DeleteDens (fcho_Cho * cho   );
fcho_Cho *fmultin_CreateDens_DT (int t, double R   );
fcho_Cho * fmultin_CreateDens_2HT (int t, double R   );
fcho_Cho * fmultin_CreateDens_2L (double R   );
fcho_Cho * fmultin_CreateDens_T (double R   );
void fmultin_DeletePer (fcho_Cho * cho   );
fcho_Cho *fmultin_CreatePer_DT (int t, double R   );
fcho_Cho * fmultin_CreatePer_2HT (int t, double R   );
fcho_Cho * fmultin_CreatePer_2L (double R   );
fcho_Cho * fmultin_CreatePer_T (double R   );

void fmultin_Serial1 (ffam_Fam *fam, smultin_Param *spar,   fmultin_Res *res, fcho_Cho2 *cho, long N, int r, int t,   lebool Sparse, int Nr, int j1, int j2, int jstep   );
void fmultin_SerialOver1 (ffam_Fam *fam, smultin_Param *spar,   fmultin_Res *res, fcho_Cho2 *cho, long N, int r, int t,   lebool Sparse, int Nr, int j1, int j2, int jstep   );
void fmultin_SerialBits1 (ffam_Fam *fam, smultin_Param *spar,   fmultin_Res *res, fcho_Cho2 *cho, long N, int r, int s, lebool Sparse,   int Nr, int j1, int j2, int jstep   );
void fmultin_SerialBitsOver1 (ffam_Fam *fam, smultin_Param *spar,   fmultin_Res *res, fcho_Cho2 *cho, long N, int r, int s, lebool Sparse,   int Nr, int j1, int j2, int jstep   );
void fmultin_Permut1 (ffam_Fam *fam, smultin_Param *spar,   fmultin_Res *res, fcho_Cho2 *cho, long N, int r,   lebool Sparse, int Nr, int j1, int j2, int jstep   );




extern long fnpair_Maxn;




fnpair_Res1 *fnpair_CreateRes1 (void   );
void fnpair_DeleteRes1 (fnpair_Res1 * res   );
fcho_Cho *fnpair_CreateM1 (int maxm   );
void fnpair_DeleteM1 (fcho_Cho * cho   );
void fnpair_ClosePairs1 (ffam_Fam * fam, fnpair_Res1 * res, fcho_Cho2 * cho,   long N, int r, int t, int p, int m, int Nr, int j1, int j2, int jstep   );
void fnpair_Bickel1 (ffam_Fam * fam, fnpair_Res1 * res, fcho_Cho * cho,   long N, int r, int t, int p, lebool Torus,   int Nr, int j1, int j2, int jstep   );
void fnpair_BitMatch1 (ffam_Fam * fam, fnpair_Res1 * res, fcho_Cho * cho,   long N, int r, int t, int Nr, int j1, int j2, int jstep   );

void fres_InitCont (ffam_Fam *fam, fres_Cont *res, int N,   int Nr, int f1, int f2, int fstep, char *nam   );
fres_Cont * fres_CreateCont (void   );
void fres_DeleteCont (fres_Cont *res   );
void fres_PrintCont (fres_Cont *res   );
void fres_FillTableEntryC (fres_Cont *fres, gofw_TestArray pval,   int N, int i, int j   );
void fres_InitDisc (ffam_Fam *fam, fres_Disc *res,   int Nr, int f1, int f2, int fstep, char *nam   );
fres_Disc * fres_CreateDisc (void   );
void fres_DeleteDisc (fres_Disc *res   );
void fres_PrintDisc (fres_Disc *res, lebool LR   );
void fres_FillTableEntryD (fres_Disc *fres,   double pLeft, double pRight, double pVal2, int i, int j   );
void fres_InitPoisson (ffam_Fam *fam, fres_Poisson *res,   int Nr, int f1, int f2, int fstep, char *nam   );
fres_Poisson * fres_CreatePoisson (void   );
void fres_DeletePoisson (fres_Poisson *res   );
void fres_PrintPoisson (fres_Poisson *res, lebool LR, lebool Ratio   );
void fres_FillTableEntryPoisson (fres_Poisson *fres, double Exp, double Obs,   double pLeft, double pRight, double pVal2, int i, int j   );





extern long fspectral_Maxn;



void fspectral_Fourier3 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                         int k, int r, int s,                         int Nr, int j1, int j2, int jstep   );




extern long fstring_Maxn;
extern long fstring_MaxL;



fstring_Res1 * fstring_CreateRes1 (void   );
void fstring_DeleteRes1 (fstring_Res1 *res   );
fstring_Res2 * fstring_CreateRes2 (void   );
void fstring_DeleteRes2 (fstring_Res2 *res   );
void fstring_Period1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,   long N, int r, int s,   int Nr, int j1, int j2, int jstep   );
void fstring_Run1 (ffam_Fam *fam, fstring_Res2 *res, fcho_Cho *cho,   long N, int r, int s,   int Nr, int j1, int j2, int jstep   );
void fstring_AutoCor1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,   long N, int r, int s, int d,   int Nr, int j1, int j2, int jstep   );
void fstring_LongHead1 (ffam_Fam *fam, fstring_Res1 *res, fcho_Cho2 *cho,   long N, long n, int r, int s, long L,   int Nr, int j1, int j2, int jstep   );
void fstring_HamWeight2 (ffam_Fam *fam, fres_Cont *res, fcho_Cho2 *cho,   long N, long n, int r, int s, long L,   int Nr, int j1, int j2, int jstep   );
void fstring_HamWeight1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho2 *cho,   long N, long n, int r, int s, long L,   int Nr, int j1, int j2, int jstep   );
void fstring_HamCorr1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho2 *cho,   long N, long n, int r, int s, long L,   int Nr, int j1, int j2, int jstep   );
void fstring_HamIndep1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho2 *cho,   long N, long n, int r, int s, long L,   int Nr, int j1, int j2, int jstep   );




extern ftab_StyleType ftab_Style;
extern double ftab_Suspectp;
extern int ftab_SuspectLog2p;



void ftab_SetDesc(ftab_Table* T, char* Desc);
ftab_Table *ftab_CreateTable (int Nr, int j1, int j2, int jstep,   char *Desc, ftab_FormType Form, int Ns   );
void ftab_DeleteTable (ftab_Table * T   );
void ftab_InitMatrix (ftab_Table * T, double x   );
void ftab_MakeTables (ffam_Fam *fam, void *res, void *cho, void *par,   ftab_CalcType Calc, int Nr, int f1, int f2, int fstep   );
void ftab_PrintTable (ftab_Table * T   );
void ftab_PrintTable2 (ftab_Table * T1, ftab_Table * T2, lebool Flag   );




extern long fvaria_MaxN;
extern long fvaria_Maxn;
extern long fvaria_Maxk;
extern long fvaria_MaxK;




void fvaria_SampleMean1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                         long n, int r,                         int Nr, int j1, int j2, int jstep   );
void fvaria_SampleCorr1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                         long N, int r, int k,                         int Nr, int j1, int j2, int jstep   );
void fvaria_SampleProd1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                         long N, int r, int t,                         int Nr, int j1, int j2, int jstep   );
void fvaria_SumLogs1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                      long N, int r,                      int Nr, int j1, int j2, int jstep   );
void fvaria_SumCollector1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                           long N, int r, double g,                           int Nr, int j1, int j2, int jstep   );
void fvaria_Appearance1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho *cho,                         long N, int r, int s, int L,                         int Nr, int j1, int j2, int jstep   );
void fvaria_WeightDistrib1 (ffam_Fam *fam, fres_Cont *res, fcho_Cho2 *cho,                            long N, long n, int r, long k,                            double alpha, double beta,                            int Nr, int j1, int j2, int jstep   );





extern long fwalk_Maxn;
extern long fwalk_MaxL;
extern double fwalk_MinMu;




fwalk_Res1 *fwalk_CreateRes1 (void   );
void fwalk_DeleteRes1 (fwalk_Res1 * res   );
void fwalk_RWalk1 (ffam_Fam * fam, fwalk_Res1 * res, fcho_Cho2 * cho,   long N, long n, int r, int s, long L, int Nr, int j1, int j2, int jstep   );
void fwalk_VarGeoP1 (ffam_Fam * fam, fres_Cont * res, fcho_Cho2 * cho,   long N, long n, int r, double Mu, int Nr, int j1, int j2, int jstep   );
void fwalk_VarGeoN1 (ffam_Fam * fam, fres_Cont * res, fcho_Cho2 * cho,   long N, long n, int r, double Mu, int Nr, int j1, int j2, int jstep   );




int rijndaelKeySetupEnc(uint32_t rk[/*4*(Nr + 1)*/], const uint8_t cipherKey[], int keyBits   );
int rijndaelKeySetupDec(uint32_t rk[/*4*(Nr + 1)*/], const uint8_t cipherKey[], int keyBits   );
void rijndaelEncrypt(const uint32_t rk[/*4*(Nr + 1)*/], int Nr, const uint8_t pt[16], uint8_t ct[16]   );
void rijndaelDecrypt(const uint32_t rk[/*4*(Nr + 1)*/], int Nr, const uint8_t ct[16], uint8_t pt[16]   );

#ifdef INTERMEDIATE_VALUE_KAT
void rijndaelEncryptRound(const uint32_t rk[/*4*(Nr + 1)*/], int Nr, uint8_t block[16], int rounds   );
void rijndaelDecryptRound(const uint32_t rk[/*4*(Nr + 1)*/], int Nr, uint8_t block[16], int rounds   );
#endif /* INTERMEDIATE_VALUE_KAT */




extern long scatter_N;
extern int scatter_t;
extern lebool scatter_Over;
extern int scatter_x;
extern int scatter_y;
extern double scatter_L [scatter_MAXDIM + 1];
extern double scatter_H [scatter_MAXDIM + 1];
extern lebool scatter_Lacunary;
extern long scatter_LacI [scatter_MAXDIM + 1];
extern double scatter_Width;
extern double scatter_Height;
extern scatter_OutputType scatter_Output;
extern long scatter_Nkept;




void scatter_PlotUnif (unif01_Gen *gen, char *Nin   );
void scatter_PlotUnifInterac (unif01_Gen *gen   );
void scatter_PlotUnif1 (unif01_Gen * gen, long N, int Dim, lebool Over,   int Proj[2], double Lower[], double Upper[], scatter_OutputType Output,  int Prec, lebool Lac, long LacI[], char *Name   );

scomp_Res * scomp_CreateRes (void   );
void scomp_DeleteRes (scomp_Res *res   );
void scomp_LinearComp (unif01_Gen *gen, scomp_Res *res,                       long N, long n, int r, int s   );
void scomp_LempelZiv (unif01_Gen *gen, sres_Basic *res,   long N, int t, int r, int s   );

sentrop_Res * sentrop_CreateRes (void   );
void sentrop_DeleteRes (sentrop_Res *res   );
void sentrop_EntropyDiscOver (unif01_Gen * gen, sentrop_Res * res,   long N, long n, int r, int s, int L   );
void sentrop_EntropyDiscOver2 (unif01_Gen * gen, sentrop_Res * res,   long N, long n, int r, int s, int L   );
void sentrop_EntropyDisc (unif01_Gen * gen, sentrop_Res * res,   long N, long n, int r, int s, int L   );
void sentrop_EntropyDM (unif01_Gen * gen, sres_Basic * res,   long N, long n, int r, long m   );
void sentrop_EntropyDMCirc (unif01_Gen * gen, sres_Basic * res,   long N, long n, int r, long m   );

sknuth_Res1 * sknuth_CreateRes1 (void   );
void sknuth_DeleteRes1 (sknuth_Res1 *res   );
sknuth_Res2 * sknuth_CreateRes2 (void   );
void sknuth_DeleteRes2 (sknuth_Res2 *res   );
void sknuth_Serial (unif01_Gen *gen, sres_Chi2 *res,                    long N, long n, int r, long d, int t   );
void sknuth_SerialSparse (unif01_Gen *gen, sres_Chi2 *res,                          long N, long n, int r, long d, int t   );
void sknuth_Gap (unif01_Gen *gen, sres_Chi2 *res,                 long N, long n, int r, double Alpha, double Beta   );
void sknuth_SimpPoker (unif01_Gen *gen, sres_Chi2 *res,                       long N, long n, int r, int d, int k   );
void sknuth_CouponCollector (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, int d   );
void sknuth_Permutation (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, int t   );
void sknuth_Run (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, lebool Up   );
void sknuth_RunIndep (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, lebool Up   );
void sknuth_MaxOft (unif01_Gen * gen, sknuth_Res1 * res,   long N, long n, int r, int d, int t   );
void sknuth_Collision (unif01_Gen * gen, sknuth_Res2 * res,   long N, long n, int r, long d, int t   );
void sknuth_CollisionPermut (unif01_Gen * gen, sknuth_Res2 * res,   long N, long n, int r, int t   );




#ifdef USE_LONGLONG
extern double smarsa_Maxk;   /* 2^64 */
#else
extern double smarsa_Maxk;        /* 2^53 */
#endif




smarsa_Res * smarsa_CreateRes (void   );
void smarsa_DeleteRes (smarsa_Res *res   );
smarsa_Res2 *smarsa_CreateRes2 (void   );
void smarsa_DeleteRes2 (smarsa_Res2 *res   );
void smarsa_SerialOver (unif01_Gen *gen, sres_Basic *res,   long N, long n, int r, long d, int t   );
void smarsa_CollisionOver (unif01_Gen *gen, smarsa_Res *res,   long N, long n, int r, long d, int t   );
void smarsa_Opso (unif01_Gen * gen, smarsa_Res * res, long N, int r, int p   );
void smarsa_BirthdaySpacings (unif01_Gen *gen, sres_Poisson *res,   long N, long n, int r, long d, int t, int Order   );
void smarsa_CAT (unif01_Gen *gen, sres_Poisson *res,   long N, long n, int r, long d, int t, long S[]   );
void smarsa_CATBits (unif01_Gen *gen, sres_Poisson *res,   long N, long n, int r, int s, int L, unsigned long Key   );

#if 0
void smarsa_MatrixRank (unif01_Gen *gen, sres_Chi2 *res,   long N, long n, int r, int s, int l, int k   );
#endif

void smarsa_MatrixRank (unif01_Gen *gen, sres_Chi2 *res,   long N, long n, int r, int s, int l, int k   );
void smarsa_Savir2 (unif01_Gen *gen, sres_Chi2 *res,   long N, long n, int r, long m, int t   );
void smarsa_GCD (unif01_Gen *gen, smarsa_Res2 *res,                 long N, long n, int r, int s   );



extern smultin_Envir smultin_env;
extern smultin_Param smultin_ParamDefault;




smultin_Param *smultin_CreateParam (int NbDelta, double ValDelta[],   smultin_GenerCellType GenerCell, int bmax   );
void smultin_DeleteParam (smultin_Param *par   );
smultin_Res * smultin_CreateRes (smultin_Param *par   );
void smultin_DeleteRes (smultin_Res * res   );
double smultin_MNTermeKhi2 (double junk, double NbEsp, long j   );
double smultin_MNTermePowDiv (double Delta, double NbEsp, long j   );
double smultin_MNTermeLogLikhood (double junk, double NbEsp, long j   );
double smultin_MNTermeColl (double junk1, double junk2, long j   );
void smultin_MultinomMuSigma (   long n,                      double k,                    double Theta1,               double Theta2,               smultin_MNTermeType F,       double *Mu,                  double *Sigma                   );
void smultin_PowDivMomCorChi (   double Delta,   long n,                      double k,                    double *MuC,                 double *SigmaC                  );
void smultin_PowDivMom (   double Delta,                 long n,                       double k,                     double NbExp,                 double *Mu,                   double *Sigma                    );
smultin_CellType smultin_GenerCellSerial (unif01_Gen *gen,    int r, int t, long d   );
smultin_CellType smultin_GenerCellSerial2 (unif01_Gen *gen,   int r, int t, long d   );
smultin_CellType smultin_GenerCellPermut (unif01_Gen *gen,   int r, int t, long junk   );
smultin_CellType smultin_GenerCellMax (unif01_Gen *gen,   int r, int t, long junk   );
smultin_CellType smultin_GenerCellSerialBits (unif01_Gen * gen,   int r, int s, long L   );
fmass_INFO smultin_CreateCollisions (long n, smultin_CellType k   );
void smultin_DeleteCollisions (fmass_INFO W   );
double smultin_CollisionsTerm (fmass_INFO W, long s   );
double smultin_FDistCollisions (fmass_INFO W, long s   );
double smultin_FBarCollisions (fmass_INFO W, long s   );
static void InitPowDiv (   smultin_Param *par,   smultin_Res *res,   long N,                      lebool Sparse,   long n,                       smultin_CellType z               );
void smultin_Multinomial (unif01_Gen * gen, smultin_Param * par,   smultin_Res * res, long N, long n, int r, long d, int t, lebool Sparse   );
void smultin_MultinomialOver (unif01_Gen * gen, smultin_Param * par,   smultin_Res * res, long N, long n, int r, long d, int t, lebool Sparse   );
void smultin_MultinomialBits (unif01_Gen *gen, smultin_Param *par,   smultin_Res *res, long N, long n, int r, int s, int L, lebool Sparse   );
void smultin_MultinomialBitsOver (unif01_Gen * gen, smultin_Param * par,   smultin_Res * res, long N, long n, int r, int s, int L, lebool Sparse   );




extern snpair_Envir snpair_env;
extern long snpair_MaxNumPoints;
extern lebool snpair_TimeBB;
extern lebool snpair_mNP2S_Flag;




void snpair_QuickSort (snpair_PointType A[], long l, long r, int c   );
void snpair_DistanceCP (snpair_Res * res, snpair_PointType P1,   snpair_PointType P2   );
void snpair_DistanceBB (snpair_Res * res, snpair_PointType P1,   snpair_PointType P2   );
void snpair_VerifPairs0 (snpair_Res * res, snpair_PointType A[], long r,   long s, int junk1, int junk2   );
void snpair_VerifPairs1 (snpair_Res * res, snpair_PointType A[], long r,   long s, int np, int c   );
void snpair_MiniProc0 (snpair_Res * res, snpair_PointType T[], long r,   long s, long u, long v, int junk1, int junk2   );
void snpair_MiniProc1 (snpair_Res * res, snpair_PointType T[], long r,   long s, long u, long v, int np, int c   );
void snpair_CheckBoundary (snpair_Res * res, long r, long s, long u, long v,   int nr, int nrb, int np, int c   );
void snpair_FindClosePairs (snpair_Res * res, long r, long s,   int nr, int np, int c   );


snpair_Res *snpair_CreateRes (void   );
void snpair_DeleteRes (snpair_Res * res   );
void snpair_WriteDataCP (unif01_Gen * gen, char *TestName,   long N, long n, int r, int t, int p, int m, lebool Torus   );
void snpair_WriteResultsCP (unif01_Gen * gen, chrono_Chrono * Timer,   snpair_Res * res, long N, long m   );
void snpair_ClosePairs (unif01_Gen * gen, snpair_Res * res,   long N, long n, int r, int k, int p, int m   );

#if 0
void snpair_ReTestY (long N, long n, int m, double tt0, double tt1   );
#endif

void snpair_WriteDataBB (unif01_Gen * gen, char *TestName,   long N, long n, int r, int k, int p, lebool Torus, int L1, int L2   );
void snpair_WriteResultsBB (unif01_Gen * gen, chrono_Chrono * Timer,   snpair_Res * res, long N   );
void snpair_BickelBreiman (unif01_Gen * gen, snpair_Res * res,   long N, long n, int r, int k, int p, lebool Torus   );
void snpair_DistanceCPBitM (snpair_Res * res, snpair_PointType P1,   snpair_PointType P2   );
void snpair_ClosePairsBitMatch (unif01_Gen * gen, snpair_Res * res,   long N, long n, int r, int k   );

void sres_InitChi2 (sres_Chi2 *res, long N, long jmax, char *nam   );
sres_Chi2 *sres_CreateChi2 (void   );
void sres_DeleteChi2 (sres_Chi2 * res   );
void sres_GetChi2SumStat (sres_Chi2 *res   );
void sres_InitBasic (sres_Basic *res, long N, char *nam   );
sres_Basic *sres_CreateBasic (void   );
void sres_DeleteBasic (sres_Basic * res   );
void sres_GetNormalSumStat (sres_Basic *res   );
void sres_InitPoisson (sres_Poisson *res, long N, double Lambda, char *nam   );
sres_Poisson * sres_CreatePoisson (void   );
void sres_DeletePoisson (sres_Poisson *res   );
void sres_InitDisc (sres_Disc *res, long N, char *nam   );
sres_Disc * sres_CreateDisc (void   );
void sres_DeleteDisc (sres_Disc *res   );

void sspacings_DeleteRes (sspacings_Res *res   );
void sspacings_SumLogsSpacings (unif01_Gen * gen, sspacings_Res * res,   long N, long n, int r, int m   );
void sspacings_SumSquaresSpacings (unif01_Gen * gen, sspacings_Res * res,   long N, long n, int r, int m   );
void sspacings_ScanSpacings (unif01_Gen * gen, sspacings_Res * res,   long N, long n, int r, double d   );
void sspacings_AllSpacings (unif01_Gen * gen, sspacings_Res * res,   long N, long n0, int r, int M0, int M1, int D, int LgEps   );
void sspacings_AllSpacings2 (unif01_Gen * gen, sspacings_Res * res,   long N, long n0, int r, int M0, int M1, int D, int LgEps   );

sspectral_Res * sspectral_CreateRes (void   );
void sspectral_DeleteRes (sspectral_Res *res   );
void sspectral_Fourier1 (unif01_Gen *gen, sspectral_Res *res,   long N, int t, int r, int s   );
void sspectral_Fourier3 (unif01_Gen *gen, sspectral_Res *res,   long N, int t, int r, int s   );
void sspectral_Fourier2 (unif01_Gen *gen, sspectral_Res *res,   long N, int t, int r, int s   );




extern lebool sstring_CorrFlag;
extern lebool sstring_Counters;




sstring_Res3 * sstring_CreateRes3 (void   );
void sstring_DeleteRes3 (sstring_Res3 *res   );
sstring_Res2 * sstring_CreateRes2 (void   );
void sstring_DeleteRes2 (sstring_Res2 *res   );
sstring_Res * sstring_CreateRes (void   );
void sstring_DeleteRes (sstring_Res *res   );
void sstring_PeriodsInStrings (unif01_Gen *gen, sres_Chi2 *res,   long N, long n, int r, int s   );
void sstring_LongestHeadRun (unif01_Gen *gen, sstring_Res2 *res,   long N, long n, int r, int s, long L   );
void sstring_HammingWeight2 (unif01_Gen * gen, sres_Basic * res,   long N, long n, int r, int s, long L   );
void sstring_HammingWeight (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, int s, long L   );

#if 0
void sstring_Run0 (unif01_Gen * gen, sres_Basic * res,   long N, long n, int r, int s   );
#endif

void sstring_Run (unif01_Gen * gen, sstring_Res3 *res,   long N, long n, int r, int s   );
void sstring_AutoCor (unif01_Gen * gen, sres_Basic * res,   long N, long n, int r, int s, int d   );
void sstring_HammingCorr (unif01_Gen * gen, sstring_Res * res,   long N, long n, int r, int s, int L   );
void sstring_HammingIndep (unif01_Gen * gen, sstring_Res * res,   long N, long n, int r, int s, int L, int d   );



extern lebool svaria_Timer;




void svaria_SampleMean (unif01_Gen * gen, sres_Basic * res,   long N, long n, int r   );
void svaria_SampleCorr (unif01_Gen * gen, sres_Basic * res,   long N, long n, int r, int k   );
void svaria_SampleProd (unif01_Gen * gen, sres_Basic * res,   long N, long n, int r, int t   );
void svaria_SumLogs (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r   );
void svaria_WeightDistrib (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, long k, double Alpha, double Beta   );
void svaria_CollisionArgMax (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, long k, long m   );
void svaria_SumCollector (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, double g   );
void svaria_AppearanceSpacings (unif01_Gen * gen, sres_Basic * res,   long N, long Q, long K, int r, int s, int L   );

swalk_Res * swalk_CreateRes (void   );
void swalk_DeleteRes (swalk_Res *res   );
void swalk_RandomWalk1 (unif01_Gen *gen, swalk_Res *res,   long N, long n, int r, int s, long L0, long L1   );
void swalk_RandomWalk1a (unif01_Gen *gen, swalk_Res *res,   long N, long n, int r, int s, int t, long L, bitset_BitSet maskc   );
void swalk_VarGeoP (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, double Mu   );
void swalk_VarGeoN (unif01_Gen * gen, sres_Chi2 * res,   long N, long n, int r, double Mu   );




extern lebool swrite_Basic;
extern lebool swrite_Parameters;
extern lebool swrite_Collectors;
extern lebool swrite_Counters;
extern lebool swrite_Classes;
extern lebool swrite_Others;
extern lebool swrite_Host;
extern char swrite_ExperimentName[LEN + 1];




void swrite_SetExperimentName (char Name[]   );
void swrite_Head (unif01_Gen *gen, char *TestName, long N, long n, int r   );
void swrite_Final (unif01_Gen *gen, chrono_Chrono *Timer   );
void swrite_AddStrChi (char S[], int len, long d   );
void swrite_NormalSumTest (long N, sres_Basic *res   );
void swrite_Chi2SumTest (long N, sres_Chi2 *res   );
void swrite_Chi2SumTestb (long N, double sval, double pval, long degFree   );



typedef enum {
	ucrypto_OFB,                 /* Output Feedback mode */
	ucrypto_CTR,                 /* Counter mode */
	ucrypto_KTR                  /* Key counter mode */
} ucrypto_Mode;

typedef struct
{
	uint32_t state[5];
	uint32_t count[2];
	unsigned char buffer[64];
} SHA1_CTX;



#ifdef VERBOSE                    /* SAK */
#include <stdio.h>

void SHAPrintContext (SHA1_CTX * context, char *msg   );
#endif

void SHA1Init (SHA1_CTX * context   );
void SHA1Update (SHA1_CTX * context, const unsigned char data[], uint32_t len   );
void SHA1Final (unsigned char digest[20], SHA1_CTX * context   );

unif01_Gen * uautomata_CreateCA1 (int N, int S[ ], int r, int F[ ],                                   int k, int ts, int cs, int rot   );
unif01_Gen * uautomata_CreateCA90mp (int m, int S[]   );
void uautomata_DeleteGen (unif01_Gen *gen   );
void uautomata_DeleteCA90mp (unif01_Gen *gen   );

unif01_Gen * ubrent_CreateXor4096s (unsigned int seed   );
void ubrent_DeleteXor4096s (unif01_Gen *gen   );
unif01_Gen * ubrent_CreateXorgen32 (int r, int s, int a, int b, int c, int d,                                    lebool hasWeyl, unsigned int seed   );
void ubrent_DeleteXorgen32 (unif01_Gen *gen   );

#ifdef USE_LONGLONG
unif01_Gen * ubrent_CreateXor4096l (ulonglong seed   );
void ubrent_DeleteXor4096l (unif01_Gen *gen   );
unif01_Gen * ubrent_CreateXorgen64 (int r, int s, int a, int b, int c, int d,                                    lebool hasWeyl, ulonglong seed   );
void ubrent_DeleteXorgen64 (unif01_Gen *gen   );
unif01_Gen * ubrent_CreateXor4096d (ulonglong seed   );
void ubrent_DeleteXor4096d (unif01_Gen *gen   );
#endif

unif01_Gen * ubrent_CreateXor4096i (unsigned long seed   );
void ubrent_DeleteXor4096i (unif01_Gen *gen   );
unif01_Gen * ubrent_CreateXor4096r (unsigned long seed   );
void ubrent_DeleteXor4096r (unif01_Gen *gen   );

unif01_Gen *ucarry_CreateAWC (unsigned int r, unsigned int s,   unsigned long c, unsigned long m, unsigned long S[]   );
void ucarry_DeleteAWC (unif01_Gen * gen   );
unif01_Gen *ucarry_CreateSWB (unsigned int r, unsigned int s,   unsigned long c, unsigned long m, unsigned long S[]   );
void ucarry_DeleteSWB (unif01_Gen * gen   );
unif01_Gen *ucarry_CreateRanlux (unsigned int Lux, long s   );
void ucarry_DeleteRanlux (unif01_Gen * gen   );

#ifdef USE_LONGLONG
unif01_Gen *ucarry_CreateMWC (unsigned int r, unsigned long c,   unsigned int w, unsigned long A[], unsigned long S[]   );
void ucarry_DeleteMWC (unif01_Gen * gen   );
#endif  /* USE_LONGLONG */

unif01_Gen *ucarry_CreateMWCFloat (unsigned int r, unsigned long c,   unsigned int w, unsigned long A[], unsigned long S[]   );
void ucarry_DeleteMWCFloat (unif01_Gen * gen   );

#ifdef USE_LONGLONG
unif01_Gen *ucarry_CreateMWCfix8r4 (unsigned long c, unsigned long S[]   );
unif01_Gen *ucarry_CreateMWCfix8r8 (unsigned long c, unsigned long S[]   );
#endif                            /* USE_LONGLONG */

unif01_Gen *ucarry_CreateMWCfixCouture (unsigned int c, unsigned int S[]   );
void ucarry_DeleteMWCfixCouture (unif01_Gen *gen   );
unif01_Gen *ucarry_CreateSWC (unsigned int r, unsigned int h,   unsigned int c, unsigned int w, unsigned int A[], unsigned int S[]   );
void ucarry_DeleteSWC (unif01_Gen * gen   );
unif01_Gen *ucarry_CreateMWC1616 (unsigned int a, unsigned int b,   unsigned int x, unsigned int y   );
void ucarry_DeleteGen (unif01_Gen *gen   );

unif01_Gen * ucrypto_CreateAES (unsigned char *Key, int KeyLen,   unsigned char *Seed, ucrypto_Mode mode, int r, int s   );
void ucrypto_DeleteAES (unif01_Gen * gen   );
unif01_Gen * ucrypto_CreateSHA1 (unsigned char *Seed, int len, ucrypto_Mode mode,    int r, int s   );
void ucrypto_DeleteSHA1 (unif01_Gen * gen   );






#if 0
extern randctx *ctx;
extern word     flag;
#endif




unif01_Gen * ucrypto_CreateISAAC (int flag, unsigned int A[]   );
void ucrypto_DeleteISAAC (unif01_Gen *gen   );

unif01_Gen *ucubic_CreateCubic (long m, long a, long b, long c, long d,   long s   );
unif01_Gen *ucubic_CreateCubicFloat (long m, long a, long b, long c, long d,   long s   );
unif01_Gen *ucubic_CreateCubic1 (long m, long a, long s   );
unif01_Gen *ucubic_CreateCubic1Float (long m, long a, long s   );
unif01_Gen *ucubic_CreateCombCubic2 (long m1, long m2, long a1, long a2,   long s1, long s2   );
unif01_Gen *ucubic_CreateCubicOut (long m, long a, long c, long s   );
unif01_Gen *ucubic_CreateCubicOutFloat (long m, long a, long c, long s   );
void ucubic_DeleteGen (unif01_Gen * gen   );

unif01_Gen *udeng_CreateDX02a (unsigned long m, unsigned long b, int k,   unsigned long S[]   );
unif01_Gen *udeng_CreateDL00a (unsigned long m, unsigned long b, int k,   unsigned long S[]   );
void udeng_DeleteGen (unif01_Gen * gen   );

unif01_Gen * ufile_CreateReadText (char *A, long dim   );
void ufile_DeleteReadText (unif01_Gen *gen   );
void ufile_InitReadText (void   );
unif01_Gen * ufile_CreateReadBin (char *A, long dim   );
void ufile_DeleteReadBin (unif01_Gen *gen   );
void ufile_InitReadBin (void   );
void ufile_Gen2Bin (unif01_Gen *gen, char *fname, double nbits,   int r, int s   );

unif01_Gen *ugfsr_CreateGFSR3 (unsigned int k, unsigned int r,   unsigned int l, unsigned long S[]   );
unif01_Gen * ugfsr_CreateRipley90 (long s   );
unif01_Gen * ugfsr_CreateToot73 (unsigned long S[]   );
unif01_Gen *ugfsr_CreateFushimi90 (int s   );
unif01_Gen *ugfsr_CreateFushimi (int k, int r, int s   );
unif01_Gen *ugfsr_CreateKirk81 (long s   );
unif01_Gen *ugfsr_CreateTGFSR (unsigned int k, unsigned int r,   unsigned int l, unsigned long Av, unsigned long S[]   );
unif01_Gen *ugfsr_CreateT800 (unsigned long S[]   );
unif01_Gen *ugfsr_CreateTGFSR2 (unsigned int k, unsigned int r,   unsigned int l, unsigned int s, unsigned int t, unsigned long Av,   unsigned long Bv, unsigned long Cv, unsigned long S[]   );
unif01_Gen *ugfsr_CreateTT400 (unsigned long S[]   );
unif01_Gen *ugfsr_CreateTT403 (unsigned long S[]   );
unif01_Gen *ugfsr_CreateTT775 (unsigned long S[]   );
unif01_Gen *ugfsr_CreateTT800 (unsigned long S[]   );
unif01_Gen *ugfsr_CreateTT800M94 (unsigned long S[]   );
unif01_Gen *ugfsr_CreateTT800M96 (unsigned long S[]   );
unif01_Gen *ugfsr_CreateMT19937_02 (unsigned long seed,   unsigned long Key[], int len   );
unif01_Gen *ugfsr_CreateMT19937_98 (unsigned long seed   );
unif01_Gen *ugfsr_CreateGFSR5 (unsigned int k, unsigned int r1,   unsigned int r2, unsigned int r3, unsigned int l, unsigned long S[]   );
unif01_Gen *ugfsr_CreateZiff98 (unsigned long S[]   );
void ugfsr_DeleteGFSR5 (unif01_Gen *gen   );
void ugfsr_DeleteGen (unif01_Gen *gen   );

unif01_Gen * ugranger_CreateCombLCGInvExpl (   long m1, long a1, long c1, long s1, long m2, long a2, long c2   );
void ugranger_DeleteCombLCGInvExpl (unif01_Gen *gen   );

#ifdef USE_GMP
unif01_Gen * ugranger_CreateCombBigLCGInvExpl (   char * m1, char * a1, char * c1, char * s1, long m2, long a2, long c2   );
void ugranger_DeleteCombBigLCGInvExpl (unif01_Gen *gen   );
#endif

unif01_Gen * ugranger_CreateCombLCGCub (   long m1, long a1, long c1, long s1, long m2, long a2, long s2   );
void ugranger_DeleteCombLCGCub (unif01_Gen *gen   );
unif01_Gen * ugranger_CreateCombBigLCGCub (   char * m1, char * a1, char * c1, char * s1, long m2, long a2, long s2   );
void ugranger_DeleteCombBigLCGCub (unif01_Gen *gen   );
unif01_Gen * ugranger_CreateCombTausBigLCG (   unsigned int k1, unsigned int q1, unsigned int s1, unsigned int SS1,   unsigned int k2, unsigned int q2, unsigned int s2, unsigned int SS2,   char * m, char * a, char * c, char * SS3   );
 void ugranger_DeleteCombTausBigLCG (unif01_Gen *gen   );
unif01_Gen * ugranger_CreateCombTausLCG21xor (   unsigned int k1, unsigned int q1, unsigned int s1, unsigned int SS1,   unsigned int k2, unsigned int q2, unsigned int s2, unsigned int SS2,   long m, long a, long c, long SS3   );
void ugranger_DeleteCombTausLCG21xor (unif01_Gen *gen   );
unif01_Gen * ugranger_CreateCombTausCub21xor (   unsigned int k1, unsigned int q1, unsigned int s1, unsigned int SS1,   unsigned int k2, unsigned int q2, unsigned int s2, unsigned int SS2,   long m, long a, long SS3   );
 void ugranger_DeleteCombTausCub21xor (unif01_Gen *gen   );
unif01_Gen * ugranger_CreateCombTausInvExpl21xor (   unsigned int k1, unsigned int q1, unsigned int s1, unsigned int SS1,   unsigned int k2, unsigned int q2, unsigned int s2, unsigned int SS2,   long m, long a, long c   );
void ugranger_DeleteCombTausInvExpl21xor (unif01_Gen *gen   );

unif01_Gen *uinv_CreateInvImpl (long m, long a1, long a2, long z0   );
unif01_Gen *uinv_CreateInvImpl2a (int e, unsigned long a1, unsigned long a2,   unsigned long z0   );
unif01_Gen *uinv_CreateInvImpl2b (int e, unsigned long a1, unsigned long a2,   unsigned long z0   );
unif01_Gen *uinv_CreateInvExpl (long m, long a, long c   );
unif01_Gen *uinv_CreateInvExpl2a (int e, long a, long c   );
unif01_Gen *uinv_CreateInvExpl2b (int e, long a, long c   );
unif01_Gen *uinv_CreateInvMRG (long m, int k, long A[], long S[]   );
void uinv_DeleteInvMRG (unif01_Gen * gen   );
unif01_Gen *uinv_CreateInvMRGFloat (long m, int k, long A[], long S[]   );
void uinv_DeleteInvMRGFloat (unif01_Gen * gen   );
void uinv_DeleteGen (unif01_Gen *gen   );



#if 0
extern long ran_x1[KK];                    /* the generator state */

extern long ran_arr_buf1[QUALITY];
extern long ran_arr_sentinel1;
extern long *ran_arr_ptr1;
#endif



//long ran_arr_cycle1(   );
unif01_Gen *uknuth_CreateRan_array1 (long s, long A[]   );



#if 0
extern double ran_u1[KK];           /* the generator state */

extern double ranf_arr_buf1[QUALITY];
extern double ranf_arr_sentinel1;
extern double *ranf_arr_ptr1;
#endif



//double ranf_arr_cycle1(   );
unif01_Gen * uknuth_CreateRanf_array1 (long s, double B[]   );



#if 0
extern long ran_x[KK];                    /* the generator state */
#endif



void ran_array(long aa[],int n   );



#if 0
extern long ran_arr_buf[QUALITY];
extern long ran_arr_sentinel;
extern long *ran_arr_ptr;
#endif




//long ran_arr_cycle(   );
void ran_start(long seed   );
unif01_Gen *uknuth_CreateRan_array2 (long s, long A[]   );



#if 0
extern double ran_u[KK];
#endif


void ranf_array(double aa[], int n   );



#if 0
extern double ranf_arr_buf[QUALITY];
extern double ranf_arr_sentinel;
extern double *ranf_arr_ptr;
#endif



//double ranf_arr_cycle(   );
void ranf_start(long seed   );
unif01_Gen * uknuth_CreateRanf_array2 (long s, double B[]   );
void uknuth_DeleteRan_array1 (unif01_Gen * gen   );
void uknuth_DeleteRanf_array1 (unif01_Gen * gen   );
void uknuth_DeleteRan_array2 (unif01_Gen * gen   );
void uknuth_DeleteRanf_array2 (unif01_Gen * gen   );

unif01_Gen *ulcg_CreateLCG (long m, long a, long c, long s   );

#ifdef USE_GMP
unif01_Gen *ulcg_CreateBigLCG (char *m, char *a, char *c, char *s   );
void ulcg_DeleteBigLCG (unif01_Gen * gen   );
#endif

unif01_Gen *ulcg_CreateLCGFloat (long m, long a, long c, long s   );

#ifdef USE_GMP
unif01_Gen *ulcg_CreateBigPow2LCG (long e, char *a, char *c, char *s   );
void ulcg_DeleteBigPow2LCG (unif01_Gen * gen   );
#endif

unif01_Gen *ulcg_CreatePow2LCG (int e, long a, long c, long s   );
unif01_Gen *ulcg_CreateLCG2e31 (long a, long c, long s   );
unif01_Gen *ulcg_CreateLCG2e32 (unsigned long a, unsigned long c,   unsigned long s   );
unif01_Gen *ulcg_CreateLCGPayne (long a, long c, long s   );
unif01_Gen *ulcg_CreateLCG2e31m1HD (long a, long s   );

#ifdef USE_LONGLONG
unif01_Gen *ulcg_CreateLCG2e48L (ulonglong a, ulonglong c, ulonglong s   );
unif01_Gen *ulcg_CreatePow2LCGL (int e, ulonglong a, ulonglong c, ulonglong s   );
#endif

unif01_Gen *ulcg_CreateLCGWu2 (long m, char o1, unsigned int q, char o2,   unsigned int r, long s   );
unif01_Gen *ulcg_CreateCombLEC2 (long m1, long m2, long a1, long a2,   long c1, long c2, long s1, long s2   );
unif01_Gen *ulcg_CreateCombLEC2Float (long m1, long m2, long a1, long a2,   long c1, long c2, long s1, long s2   );
unif01_Gen *ulcg_CreateCombLEC3 (long m1, long m2, long m3, long a1,   long a2, long a3, long c1, long c2, long c3, long s1, long s2, long s3   );
unif01_Gen *ulcg_CreateCombWH2 (long m1, long m2, long a1, long a2,   long c1, long c2, long s1, long s2   );
unif01_Gen *ulcg_CreateCombWH2Float (long m1, long m2, long a1, long a2,   long c1, long c2, long s1, long s2   );
unif01_Gen *ulcg_CreateCombWH3 (long m1, long m2, long m3, long a1,   long a2, long a3, long c1, long c2, long c3, long s1, long s2, long s3   );
void ulcg_DeleteGen (unif01_Gen * gen   );

unif01_Gen * ulec_CreateCombLec88 (long S1, long S2   );
unif01_Gen * ulec_CreateCombLec88Float (long S1, long S2   );
unif01_Gen * ulec_CreateCLCG4 (long S1, long S2, long S3, long S4   );
unif01_Gen * ulec_CreateCLCG4Float (long S1, long S2, long S3, long S4   );
unif01_Gen * ulec_CreateMRG93 (long S1, long S2, long S3, long S4, long S5   );
unif01_Gen *ulec_CreateCombMRG96 (long S11, long S12, long S13,   long S21, long S22, long S23   );
unif01_Gen *ulec_CreateCombMRG96Float (long S11, long S12, long S13,   long S21, long S22, long S23   );
unif01_Gen *ulec_CreateCombMRG96D (long S11, long S12, long S13,   long S21, long S22, long S23   );
unif01_Gen *ulec_CreateCombMRG96FloatD (long S11, long S12, long S13,   long S21, long S22, long S23   );
unif01_Gen *ulec_CreateMRG32k3aL (long x10, long x11, long x12,   long x20, long x21, long x22   );
unif01_Gen *ulec_CreateMRG32k3a (double x10, double x11, double x12,   double x20, double x21, double x22   );
unif01_Gen *ulec_CreateMRG32k3b (double x10, double x11, double x12,   double x20, double x21, double x22   );
unif01_Gen *ulec_CreateMRG32k5a (double x10, double x11, double x12,   double x13, double x14, double x20, double x21, double x22,   double x23, double x24   );
unif01_Gen *ulec_CreateMRG32k5b (double x10, double x11, double x12,   double x13, double x14, double x20, double x21, double x22,   double x23, double x24   );

#ifdef USE_LONGLONG
unif01_Gen *ulec_CreateMRG63k3a (longlong s10, longlong s11, longlong s12,   longlong s20, longlong s21, longlong s22   );
unif01_Gen *ulec_CreateMRG63k3b (longlong s10, longlong s11, longlong s12,   longlong s20, longlong s21, longlong s22   );
#endif                            /* USE_LONGLONG */

unif01_Gen *ulec_Createlfsr88 (unsigned int us1, unsigned int us2,   unsigned int us3   );
unif01_Gen *ulec_Createlfsr113 (unsigned int us1, unsigned int us2,   unsigned int us3, unsigned int us4   );

#ifdef USE_LONGLONG
unif01_Gen *ulec_Createlfsr258 (ulonglong us1, ulonglong us2,   ulonglong us3, ulonglong us4, ulonglong us5   );
#endif                            /* USE_LONGLONG */

unif01_Gen *ulec_CreateCombTausLCG11 (unsigned int k, unsigned int q,   unsigned int s, unsigned int Y1, long m, long a, long c, long Y2   );
void ulec_DeleteCombTausLCG11 (unif01_Gen *gen   );
unif01_Gen *ulec_CreateCombTausLCG21 (unsigned int k1, unsigned int q1,   unsigned int s1, unsigned int Y1, unsigned int k2, unsigned int q2,   unsigned int s2, unsigned int Y2, long m, long a, long c, long Y3   );
void ulec_DeleteCombTausLCG21 (unif01_Gen *gen   );
unif01_Gen * ulec_CreateMRG31k3p (long x10, long x11,   long x12, long x20, long x21, long x22   );
void ulec_DeleteGen (unif01_Gen *gen   );

unif01_Gen *umarsa_CreateKISS93 (unsigned int s1, unsigned int s2,   unsigned int s3   );
unif01_Gen *umarsa_CreateKISS96 (unsigned int x, unsigned int y,   unsigned int z1, unsigned int z2   );
unif01_Gen *umarsa_CreateKISS99 (unsigned int x, unsigned int y,   unsigned int I1, unsigned int I2   );
unif01_Gen *umarsa_CreateULTRA (unsigned int x, unsigned int y,   unsigned int z, unsigned int w   );
unif01_Gen *umarsa_CreateSupDup73 (unsigned int x, unsigned int y   );
unif01_Gen * umarsa_CreateSupDup96Add (unsigned int x0, unsigned int y0,                                       unsigned int c   );
unif01_Gen * umarsa_CreateSupDup96Xor (unsigned int x0, unsigned int y0,                                       unsigned int c   );

#ifdef USE_LONGLONG
unif01_Gen * umarsa_CreateSupDup64Add (ulonglong x, ulonglong y, ulonglong a,    ulonglong c, int s1, int s2, int s3   );
unif01_Gen * umarsa_CreateSupDup64Xor (ulonglong x, ulonglong y, ulonglong a,    ulonglong c, int s1, int s2, int s3   );
#endif

unif01_Gen *umarsa_CreateMarsa90a (int s1, int s2, int s3, int s4,   unsigned int s5   );
unif01_Gen *umarsa_CreateRANMAR (int s1, int s2, int s3, int s4   );

#ifdef USE_LONGLONG
unif01_Gen *umarsa_CreateMother0 (unsigned long s1, unsigned long s2,   unsigned long s3, unsigned long s4, unsigned long c   );
#endif

unif01_Gen *umarsa_CreateCombo (unsigned int x1, unsigned int x2,   unsigned int y1, unsigned int c   );
unif01_Gen *umarsa_CreateECG1 (unsigned int x1, unsigned int x2,   unsigned int x3   );
unif01_Gen *umarsa_CreateECG2 (unsigned int x1, unsigned int x2,   unsigned int x3   );
unif01_Gen *umarsa_CreateECG3 (unsigned int x1, unsigned int x2,   unsigned int x3   );
unif01_Gen *umarsa_CreateECG4 (unsigned int x1, unsigned int x2,   unsigned int x3   );
unif01_Gen *umarsa_CreateMWC97R (unsigned int I1, unsigned int I2   );
unif01_Gen *umarsa_Create4LFIB99 (unsigned int T[256]   );
unif01_Gen *umarsa_Create3SHR99 (unsigned int I1   );
unif01_Gen *umarsa_CreateSWB99 (unsigned int T[256], int b   );
void umarsa_DeleteGen (unif01_Gen *gen   );

unif01_Gen * umrg_CreateMRG (long m, int k, long A[], long S[]   );
void umrg_DeleteMRG (unif01_Gen * gen   );
unif01_Gen * umrg_CreateMRGFloat (long m, int k, long AA[], long SS[]   );
void umrg_DeleteMRGFloat (unif01_Gen * gen   );
unif01_Gen * umrg_CreateC2MRG (long m1, long m2, int k, long A1[], long A2[],   long S1[], long S2[]   );
void umrg_DeleteC2MRG (unif01_Gen *gen   );

#ifdef USE_GMP
unif01_Gen *umrg_CreateBigMRG (char *m, int k, char *A[], char *S[]   );
void umrg_DeleteBigMRG (unif01_Gen * gen   );
unif01_Gen *umrg_CreateBigC2MRG (char *m1, char *m2, int k,   char *A1[], char *A2[], char *S1[], char *S2[]   );
void umrg_DeleteBigC2MRG (unif01_Gen * gen   );
#endif

unif01_Gen * umrg_CreateLagFibFloat (int k, int r, char Op, int Lux,   unsigned long S[]   );
void umrg_DeleteLagFibFloat (unif01_Gen * gen   );
unif01_Gen * umrg_CreateLagFib (int t, int k, int r, char Op, int Lux,   unsigned long S[]   );
void umrg_DeleteLagFib (unif01_Gen * gen   );



extern lebool unif01_WrLongStateFlag;



void unif01_WriteNameGen (unif01_Gen *gen   );
void unif01_WriteState (unif01_Gen *gen   );
void unif01_WrLongStateDef (void   );
double unif01_StripD (unif01_Gen *gen, int r   );
long unif01_StripL (unif01_Gen *gen, int r, long d   );
unsigned long unif01_StripB (unif01_Gen *gen, int r, int s   );
unif01_Gen * unif01_CreateDummyGen (void   );
void unif01_DeleteDummyGen (unif01_Gen *gen   );
void unif01_DeleteGen (unif01_Gen *gen   );
unif01_Gen * unif01_CreateDoubleGen2 (unif01_Gen *gen, double v   );
unif01_Gen * unif01_CreateDoubleGen (unif01_Gen *gen, int s   );
void unif01_DeleteDoubleGen (unif01_Gen *gen   );
unif01_Gen * unif01_CreateLacGen (unif01_Gen *gen, int k, long I[]   );
void unif01_DeleteLacGen (unif01_Gen *gen   );
unif01_Gen * unif01_CreateBiasGen (unif01_Gen *gen, double a, double R   );
void unif01_DeleteBiasGen (unif01_Gen *gen   );
unif01_Gen * unif01_CreateLuxGen (unif01_Gen *gen, int k, int L   );
void unif01_DeleteLuxGen (unif01_Gen *gen   );
unif01_Gen * unif01_CreateTruncGen (unif01_Gen *gen, int b   );
void unif01_DeleteTruncGen (unif01_Gen *gen   );
unif01_Gen * unif01_CreateBitBlockGen (unif01_Gen *gen, int r, int s, int w   );
void unif01_DeleteBitBlockGen (unif01_Gen *gen   );
unif01_Gen * unif01_CreateCombAdd2 (unif01_Gen *g1, unif01_Gen *g2, char *Mess   );
unif01_Gen * unif01_CreateCombXor2 (unif01_Gen *g1, unif01_Gen *g2,   char *Mess   );
void unif01_DeleteCombGen (unif01_Gen *gen   );
unif01_Gen * unif01_CreateCombAdd3 (unif01_Gen *g1, unif01_Gen *g2,   unif01_Gen *g3, char *mess   );
unif01_Gen * unif01_CreateCombXor3 (unif01_Gen *g1, unif01_Gen *g2,   unif01_Gen *g3, char *mess   );
unif01_Gen * unif01_CreateParallelGen (int k, unif01_Gen *gen[], int L   );
void unif01_DeleteParallelGen (unif01_Gen *gen   );
unif01_Gen *unif01_CreateExternGen01 (char *name, double (*f_U01)(void)   );
void unif01_DeleteExternGen01 (unif01_Gen * gen   );
unif01_Gen *unif01_CreateExternGenBits (char *name,    unsigned int (*f_Bits)(void)   );
void unif01_DeleteExternGenBits (unif01_Gen * gen   );
unif01_Gen *unif01_CreateExternGenBitsL (char *name,    unsigned long (*f_Bits)(void)   );
void unif01_DeleteExternGenBitsL (unif01_Gen * gen   );
void unif01_TimerGen (unif01_Gen *gen, unif01_TimerRec * pt, long n,    lebool fU01   );
void unif01_TimerSumGen (unif01_Gen *gen, unif01_TimerRec * pt, long n,    lebool fU01   );
void unif01_WriteTimerRec (unif01_TimerRec *R   );
void unif01_TimerGenWr (unif01_Gen *gen, long n, lebool fU01   );
void unif01_TimerSumGenWr (unif01_Gen *gen, long n, lebool fU01   );

unif01_Gen * unumrec_CreateRan0 (long s   );
unif01_Gen * unumrec_CreateRan1 (long s   );
unif01_Gen * unumrec_CreateRan2 (long s   );
void unumrec_DeleteGen (unif01_Gen *gen   );

unif01_Gen * uquad_CreateQuadratic (long m, long a, long b, long c, long s   );
unif01_Gen *uquad_CreateQuadratic2 (int e, unsigned long a, unsigned long b,   unsigned long c, unsigned long s   );
void uquad_DeleteGen (unif01_Gen *gen   );

unif01_Gen * usoft_CreateSPlus (long s1, long s2   );

#ifdef HAVE_RANDOM
unif01_Gen * usoft_CreateUnixRandom (unsigned int s   );
void usoft_DeleteUnixRandom (unif01_Gen *gen   );
#endif                            /* HAVE_RANDOM */

#ifdef USE_LONGLONG
unif01_Gen * usoft_CreateJava48 (ulonglong s, int jflag   );
#endif                            /* USE_LONGLONG */

unif01_Gen * usoft_CreateExcel97 (double r   );
unif01_Gen * usoft_CreateExcel2003 (int x0, int y0, int z0   );
unif01_Gen * usoft_CreateVisualBasic (unsigned long s   );

#if defined(USE_GMP) && defined(USE_LONGLONG)
unif01_Gen * usoft_CreateMaple_9 (longlong s   );
void usoft_DeleteMaple_9 (unif01_Gen *gen   );
#endif

unif01_Gen * usoft_CreateMATLAB (int i, unsigned int j0, int b, double Z[]   );
void usoft_DeleteMATLAB (unif01_Gen *gen   );

#ifdef HAVE_MATHEMATICA
unif01_Gen *usoft_CreateMathematicaReal (int argc, char *argv[], long s   );
void usoft_DeleteMathematicaReal (unif01_Gen *gen   );
unif01_Gen *usoft_CreateMathematicaInteger (int argc, char *argv[], long s   );
void usoft_DeleteMathematicaInteger (unif01_Gen *gen   );
#endif

void usoft_DeleteGen (unif01_Gen *gen   );

unif01_Gen *utaus_CreateTaus (unsigned int k, unsigned int q, unsigned int s,   unsigned int Y   );
unif01_Gen *utaus_CreateTausJ (unsigned int k, unsigned int q,   unsigned int s, unsigned int j, unsigned int Y   );

#ifdef USE_LONGLONG
unif01_Gen * utaus_CreateLongTaus (unsigned int k, unsigned int q,                                   unsigned int s, ulonglong Y   );
#endif

unif01_Gen * utaus_CreateCombTaus2 (unsigned int k1, unsigned int k2,   unsigned int q1, unsigned int q2, unsigned int s1, unsigned int s2,   unsigned int Y1, unsigned int Y2   );
unif01_Gen * utaus_CreateCombTaus3 (unsigned int k1, unsigned int k2,   unsigned int k3, unsigned int q1, unsigned int q2, unsigned int q3,   unsigned int s1, unsigned int s2, unsigned int s3, unsigned int Y1,   unsigned int Y2, unsigned int Y3   );
unif01_Gen * utaus_CreateCombTaus3T (unsigned int k1, unsigned int k2,   unsigned int k3, unsigned int q1, unsigned int q2, unsigned int q3,   unsigned int s1, unsigned int s2, unsigned int s3, unsigned int Y1,   unsigned int Y2, unsigned int Y3   );
void utaus_DeleteGen (unif01_Gen *gen   );

unif01_Gen * utezuka_CreateTezLec91 (unsigned int Y1, unsigned int Y2   );
unif01_Gen *utezuka_CreateTez95 (unsigned int Y1, unsigned int Y2,   unsigned int Y3   );
unif01_Gen *utezuka_CreateTezMRG95 (unsigned int Y1[5], unsigned int Y2[7]   );
void utezuka_DeleteGen (unif01_Gen *gen   );

unif01_Gen * utouzin_CreateMRG00a (long s1, long s2, long s3, long s4,   long s5   );
unif01_Gen * utouzin_CreateMRG00b (long s1, long s2, long s3,   long s4, long s5, long s6   );
unif01_Gen * utouzin_CreateMRG00c (long s1, long s2, long s3,   long s4, long s5, long s6, long s7   );
unif01_Gen * utouzin_CreateMRG00d (long s1, long s2, long s3,   long s4, long s5, long s6, long s7, long s8   );
unif01_Gen * utouzin_CreateMRG00e (long s10, long s11, long s12,   long s20, long s21, long s22   );
unif01_Gen * utouzin_CreateMRG00f (long s10, long s11, long s12,   long s20, long s21, long s22   );
unif01_Gen * utouzin_CreateMRG00g (long s10, long s11, long s12,   long s20, long s21, long s22,   long s30, long s31, long s32   );
unif01_Gen * utouzin_CreateMRG00h (long s10, long s11, long s12,   long s13, long s20, long s21, long s22, long s23   );
void utouzin_DeleteGen (unif01_Gen * gen   );

unif01_Gen * uvaria_CreateACORN (int k, double S[]   );
void uvaria_DeleteACORN (unif01_Gen * gen   );
unif01_Gen * uvaria_CreateTindo (long b, long Delta, int l, int k   );
unif01_Gen * uvaria_CreateCSD (long v, long s   );

unif01_Gen * uvaria_CreateRanrotB (unsigned int s   );
void uvaria_DeleteRanrotB (unif01_Gen *gen   );
unif01_Gen * uvaria_CreateRey97 (double a1, double a2, double b2, long n0   );

unif01_Gen *uweyl_CreateWeyl (double Alpha, long n0   );
unif01_Gen *uweyl_CreateNWeyl (double Alpha, long n0   );
unif01_Gen *uweyl_CreateSNWeyl (long M, double Alpha, long n0   );
void uweyl_DeleteGen (unif01_Gen *gen   );

#ifdef USE_LONGLONG
unif01_Gen * uwu_CreateLCGWu61a (longlong s   );
unif01_Gen * uwu_CreateLCGWu61b (longlong s   );
#endif /* USE_LONGLONG */

void uwu_DeleteGen (unif01_Gen * gen   );

unif01_Gen *uxorshift_CreateXorshift32 (int a, int b, int c, unsigned int y   );

#ifdef USE_LONGLONG
unif01_Gen *uxorshift_CreateXorshift64 (int a, int b, int c, ulonglong y   );
#endif

unif01_Gen *uxorshift_CreateXorshiftC (int a, int b, int c, int N,              unsigned int S[]   );
void uxorshift_DeleteXorshiftC (unif01_Gen * gen   );

unif01_Gen *uxorshift_CreateXorshiftD (int N, int b[], unsigned int S[]   );
void uxorshift_DeleteXorshiftD (unif01_Gen * gen   );

unif01_Gen *uxorshift_CreateXorshift7 (unsigned int S[]   );
unif01_Gen *uxorshift_CreateXorshift13 (unsigned int S[]   );
void uxorshift_DeleteGen(unif01_Gen* gen);



#if 0
extern unsigned long MMC[WL];
#endif



typedef struct {
	int n;
	unsigned long* vect;
} BitVect;

typedef struct {
	BitVect** lignes;
	int nblignes;
	int t;
	int l;
} Matrix;

lebool InverseMatrix(Matrix* InvM, Matrix* M);
lebool Diag(Matrix* m, int kg, int t, int l, int* gr);
int CompleteElimination(Matrix* m, int nblignes, int l, int t);
int GaussianElimination(Matrix* m, int nblignes, int l, int t);
int SpecialGaussianElimination(Matrix* m, int nblignes, int l, int t, int* indices);
void MultMatrixByBV(BitVect* A, Matrix* M, BitVect* B);
int ValBitBV(BitVect* A, int noBit);
void PutBitBV(BitVect* A, int noBit, int valBit);
void PutBVToZero(BitVect* A);
void CopyBV(BitVect* A, BitVect* B);
void CopyBVPart(BitVect* A, BitVect* B, int l);
lebool CompareBV(BitVect* A, BitVect* B);
lebool BVisZero(BitVect* A);
void XORBV(BitVect* A, BitVect* B, BitVect* C);
void XOR2BV(BitVect* A, BitVect* B, BitVect* C, BitVect* D);
void ANDBV(BitVect* A, BitVect* B, BitVect* C);
void ANDBVMask(BitVect* A, BitVect* B, int t);
void ANDBVInvMask(BitVect* A, BitVect* B, int t);
void ANDBVSelf(BitVect* A, BitVect* B);
void XORBVSelf(BitVect* A, BitVect* B);
void BVLShift(BitVect* R, BitVect* A, int n);
void BVRShift(BitVect* R, BitVect* A, int n);
void BVLShiftSelf(BitVect* R, int n);
void BVLS1Self(BitVect* R);
void BVRShiftSelf(BitVect* R, int n);
void InverseBV(BitVect* A);
lebool VerifBitsCommuns(BitVect* ds1, BitVect* ds2);
void BVCanonic(BitVect* A, int l);
void Mask(BitVect* A, int l);
void InvMask(BitVect* A, int l);
void AllOnes(BitVect* A);
void AllocBV(BitVect* A, int l);
void FreeBV(BitVect* A);
void AllocMat(Matrix* m, int nblines, int l, int t);
void FreeMat(Matrix* m);
void CopyMat(Matrix* m, Matrix* ms, int nl, int t);
void CopyNTupleMat(Matrix* m, Matrix* ms, int nl, int* colonnes, int t);

void ExchangeVect(Matrix* m, int i, int j);
void TransposeMatrices(Matrix* T, Matrix* M, int mmax, int smax, int L);
void XorVect(Matrix* m, int r, int s, int min, int max);
void DispMat(Matrix* m, int t, int l, int kg, lebool mathematica);
void DispBitVect(BitVect* A, int l, int mathematica);
void MultMatrixByMatrix(Matrix* A, Matrix* B, Matrix* C);
void MatrixTwoPow(Matrix* A, Matrix* B, unsigned int e);

#ifdef USE_LONGLONG
void MatrixPow(Matrix* A, Matrix* B, longlong e);
#else
void MatrixPow(Matrix* A, Matrix* B, long e);
#endif

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif
