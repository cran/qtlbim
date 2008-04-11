
// QTLBIM - QTL Bayesian Interval Mapping
// Defining all the global variables used in the code
// This should only be a temporary file, a stepping stone in the process of moving away from global variables
//********************************************************************

#ifndef GLOBAL_VARS_H
#define GLOBAL_VARS_H


//***************************************************************************************
/// @defgroup qbPheno Variables that should reside in the qp.pheno structure
/// @{

/// 1: normal data; 2: binary data; 3:ordinal data
extern int CATEGORY;
/// @warning No documentation available
extern double *CENSOR_LO;
/// @warning No documentation available
extern double *CENSOR_HI;
/// Categories # for binary or ordinal data
extern int CN;
/// threshold values for ordinal traits
extern double *CUTPOINT;
/// random effects #
extern int NRANCOVA;
/// fixed effects #
extern int NFIXCOVA;
/// random effect #
extern int *NRAN;
/// random covariates
extern double **COEF_RAN;
/// fixed covariates
extern double **COEF_FIX;
/// number of individuals
extern int NS;
/// number of individuals
/// @note This variable has to be removed and consumed by NS. There is no current need for two
extern int NS1;
/// ordinal or binary phenotype
extern int *W;
/// phenotypic data
extern double *Y;

/// @}



//***************************************************************************************
/// @defgroup qbGeno Variables that should reside in the qb.geno structure
///@{

/// max number of grids
extern int CHL;
/// QTL number at each chromosome
extern int *CHRQTL;
/// cross type 0:RILs, 1:BC, 2:F2
extern int CROSS;
/// QTL genotypes
extern int **GENO;
/// grid points
extern double **GRID;
/// number of genotypes
extern int NG;
/// number of grids at each chromosome
extern int *NGRID;
/// number of chromosomes
extern int NLG;
// genotype probabilities for each individual at each grid
extern double ****QPROB;
/// total number of grids
extern int TNGRID;

///@}



//***************************************************************************************
/// @defgroup qbModel Variables that should reside in the qb.model structure
/// @note NC0 and multiple which have been listed in the variable classification excel file are not in this header!
/// @note NC is listed as an internal variable. What is it doing in a header? Or is my understanding of 'internal' flawed? - Ram
/// @{

/// see Chipman's paper
extern double *C;
/// max QTL # at each chromosome
extern int *CHR_NQTL;
/// see Chipman's paper
extern int DEPENDENCE;
/// distance between flanking two genes
extern double *DQQ;
/// expected number of all QTL
extern int E_NQTL;
/// expected number of main-effect QTL
extern int E_NQTL_MAIN;
/// 1:include environmental factors-need to fix this
extern int ENV_FACTOR;
/// 1: epistatic model; 0: non-epistatic model;
extern int EPISTASIS;
/// 1: include g by e interactions
extern int GBYE;
/// indicating which fixed covariates are treated in g-by-e
extern int *GBYE_FIX_INDEX;
/// 1: groupedly update all main effects or epistatic effects
extern int GROUP;
/// the number of main effects at one QTL
extern int NC;
/// max QTL #
extern int NQTL;
/// prior for main effect indicator
extern double W_MAIN;
/// prior for epistatic effect indicator
extern double W_EPISTASIS;
/// prior for g by e indicator
extern double W_GBYE;

/// @}



//***************************************************************************************
/// @defgroup qbMCMC Variables that should reside in the qb.mcmc structure
/// @{

/// 1: Gibbs scaning all effects; 0: Kohn's M-H method for MCMC algorithm
extern int GIBBS;
/// Burnin
extern int NBURNIN;
/// Number of iterations
extern int NITER;
/// Thinning value
extern int NTHIN;
/// the pseudo-random number generator
extern int SEED;
/// 1: update QTL genotypes; 0: doesn't update QTL genotype
extern int UPDATEGENO;
/// 1: update QTL positions; 0: doesn't update QTL positions
extern int UPDATEPOS;
/// Verbose
extern int VERBOSE;

///@}



//***************************************************************************************
/// @defgroup qbOp Variables that should reside in the qp.op structure
/// @{


/// coefficients of QTL main effects
extern double ***COEF;
/// QTL position indicators, position is GRID[QCHR[L]][QLOC[L]]
extern int *QLOC;
/// chromosomes that QTL locate
extern int *QCHR;

    /// @defgroup qbOpCovariate Variables in qb.op.covariate
    /// @{
    /// effects of fixed covariates
    extern double  *FIX;
    /// effects of random covariates
    extern double  **RAN;
    /// variances of random covariates
    extern double  *VRAN;
    /// interactions of QTL main effects and fixed covariates
    extern double ***GBYE_FIX;
    /// @}

    /// @defgroup qbOpIterdiag Variables in qb.op.iterdiag
    /// @{
    /// overall mean
    extern double AMU;
    /// QTL indicators
    extern int *GAMMA;
    /// residual variance
    extern double *VE;
    /// @}

    /// @defgroup qbOpMainloci Variables in qb.op.mainloci
    /// @{
    /// main effects
    extern double  **MAIN;
    /// main effects indicators
    extern int *GAMMA_MAIN;
    /// prior variance of main effects
    extern double  **VMAIN;
    /// prior variance of main effects
    extern double  *VMAIN1;
    /// @}

    /// @defgroup qbOpPairloci Variables in qb.op.pairloci
    /// @{
    /// epistatic effects
    extern double ****EPISTATIC;
    /// epistatic effects indicators
    extern int **GAMMA_EPISTASIS;
    /// prior variance of epistatic effects
    extern double ****VEPISTASIS;
    /// prior variance of epistatic effects
    extern double **VEPISTASIS1;
    /// @}

    /// @defgroup qbOpGbyE Variables in qb.op.gbye
    /// @{
    /// g-by-e indicators
    extern double  **GAMMA_GBYE;
    /// prior variance of g-by-e effects
    extern double ***V_GBYE_FIX;
    /// prior variance of g-by-e effects
    extern double **V_GBYE_FIX1;
    /// @}

/// @}



// these are global parameters, which values have been generated by the previous steps
//*****************************************************************************************
/// these parameters are passed from R function bmq.mcmc
//********************************************************************************
/// 1: standardized phenotype; 0: original phenotype
/// @warning deprecated
extern int SPH;
//********************************************************************************
/// for binary and ordinal traits
//********************************************************************************
/// parameters used in prior specification
//*********************************************************************************
/// genetic model parameters
//*********************************************************************************
/// QTL positions, genetic effects indicators
//**********************************************************************************
// environmental covariate parameters
//***********************************************************************************
/// genotypic valyes
extern double *GVALUE;
extern double PDD1, PDD2;
extern double *PD1, *PD2;
extern int IBD;
extern double  *X;
//*************************************************************************************************************
extern char iterfile[100];
extern char pairfile[100];
extern char mainfile[100];
extern char gbyefile[100];
extern char covfile[100];
extern char devfile[100];
//******************************************************************


#endif // GLOBAL_VARS_H
