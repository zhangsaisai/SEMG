/* ###################################################################
 **     THIS COMPONENT MODULE IS GENERATED BY USER
 **     Filename    : LPF.c
 **     Project     : semg_mkl15z128vlh4
 **     Processor   : MKL15Z128VLH4
 **     Component   :
 **     Version     :
 **     Datasheet   :
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2014-Dec 5, 2014, 10:35:33 AM, # CodeGen: 1
 **     Author	    : Dong
 **     Abstract    :
 **
 **     Settings    :
 **
 **     Contents    :
 **
 **     Mail      	: pzdongdong@163.com
 **
 **     Revision    : No.  Name        Data/Time        Content
 ** ###################################################################*/
/*!
 * @file LPF.c
 * @version 01.00
 * @brief
 *		This file contains low pass filter functions.
 */
/*!
 *  @addtogroup LPF Low Pass Filter
 *      This file contains low pass filter functions.
 *  @{
 */

/* {Default RTOS Adapter} No RTOS includes */
#include "PE_Types.h"

#define NTAPS 18
static const double h[NTAPS] =
{
  0.00290781,
 -0.00404687,
  0.00260812,
  0.0092086,
 -0.0334543,
  0.0541612,
 -0.0351558,
 -0.08053674,
  0.58430797,
  0.58430797,
 -0.08053674,
 -0.0351558,
  0.0541612,
 -0.0334543,
  0.0092086,
  0.00260812,
 -0.00404687,
  0.00290781
};

/*
 * ===================================================================
 *     Method      : Clear ()
 */
/*!
 *     @brief
 *          Zeroize a FIR delay line.
 *     @param[in]
 *          ntaps       - The number of taps in the filter.
 *     @param[in, out]
 *          z           - The FIR delay line array.
 *     @return
 *          void
 */
/* ===================================================================*/
void Clear(int ntaps, double z[])
{
    for(int i = 0; i < ntaps; i++)
    {
        z[i] = 0;
    }
}

/*
 * ===================================================================
 *     Method      : FirBasic ()
 */
/*!
 *     @brief
 *         	The basic fir LPF. Store input sample, calculate output
 *         	sample, move delay line.
 *     @param[in]
 *         	input       - The input sample.
 *     @param[in]
 *          ntaps       - The number of taps in the filter.
 *     @param[in]
 *          h           - The coefficients of LPF.
 *     @param[out]
 *          z           - The FIR delay line array.
 *     @return
 *         	accum
 */
/* ===================================================================*/
double FirBasic(double input, int ntaps, const double h[], double z[])
{
    double accum;

    z[0] = input;
    accum = 0;
    for(int i = 0; i < ntaps; i++)
    {
        accum += h[i] * z[i];
    }

    for(int i = ntaps - 2; i >= 0; i--)
    {
        z[i + 1] = z[i];
    }

    return accum;
}

/*!
 * @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Dong
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */

