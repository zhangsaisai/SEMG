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
#include "LPF.h"
#include "Macros.h"

/* The coefficients of the lpf. */
static const int32 H[NTAPS] = {
        -25,     46,    -50,     20,     53,   -142,    182,    -98,   -127,
        402,   -536,    342,    221,   -942,   1384,  -1061,   -298,   2545,
      -5089,   7102,  24912,   7102,  -5089,   2545,   -298,  -1061,   1384,
       -942,    221,    342,   -536,    402,   -127,    -98,    182,   -142,
         53,     20,    -50,     46,    -25
};

/*
 * ===================================================================
 *     Method      : EvenFirLPF ()
 */
/*!
 *     @brief
 *          The fir LPF, Hamming window. The order must be even.
 *          fs = 1000 Hz, fc = 380 Hz.
 *     @param[in]
 *          e               - The data to be filtered.
 *     @param[in]
 *          fq              - The filter buffer queue, a struct including queue pointers etc.
 *     @return
 *          short
 */
/* ===================================================================*/
inline int16 EvenFirLPF(register int16 const * const e, register TFilterBufferQueuePtr const fq)
{
    register int32 const * head = fq->head;
    register int32 const * tail = fq->tail;
    register int32 const * const leftEdge = fq->leftEdge;
    register int32 const * const rightEdge = fq->rightEdge;
    register int32 result = 0;
    register int32 const * const H_p = H;

    *fq->tail = (int32)*e;

    register uint32 i = 0;

    for(; head != tail; i++)
    {
        result += (*head + *tail) * (*(H_p + i));
        head++;
        tail--;
        head = (head <= rightEdge) ? head : leftEdge;
        tail = (tail >= leftEdge) ? tail : rightEdge;
    }
    result += *head * (*(H_p + i));


    fq->head++;
    fq->head = (fq->head <= rightEdge) ? fq->head : leftEdge;

    fq->tail++;
    fq->tail = (fq->tail <= rightEdge) ? fq->tail : leftEdge;

    return result >> 15;
}

/*
 * ===================================================================
 *     Method      : FirLPF40 ()
 */
/*!
 *     @brief
 *          The fir LPF, Hamming window.
 *          40th order, fs = 1000 Hz, fc = 380 Hz.
 *     @param[in]
 *          e           - The data to be filtered.
 *     @param[in]
 *          buffer      - The filter buffer.
 *     @return
 *          int
 */
/* ===================================================================*/
inline int32 FirLPF40(int16 const * const e, int16 * const buffer)
{
    register int16 *p = buffer;
    register long result = 0;

    *(p + 40) = *(p + 39);
    *(p + 39) = *(p + 38);
    *(p + 38) = *(p + 37);
    *(p + 37) = *(p + 36);
    *(p + 36) = *(p + 35);
    *(p + 35) = *(p + 34);
    *(p + 34) = *(p + 33);
    *(p + 33) = *(p + 32);
    *(p + 32) = *(p + 31);
    *(p + 31) = *(p + 30);
    *(p + 30) = *(p + 29);
    *(p + 29) = *(p + 28);
    *(p + 28) = *(p + 27);
    *(p + 27) = *(p + 26);
    *(p + 26) = *(p + 25);
    *(p + 25) = *(p + 24);
    *(p + 24) = *(p + 23);
    *(p + 23) = *(p + 22);
    *(p + 22) = *(p + 21);
    *(p + 21) = *(p + 20);
    *(p + 20) = *(p + 19);
    *(p + 19) = *(p + 18);
    *(p + 18) = *(p + 17);
    *(p + 17) = *(p + 16);
    *(p + 16) = *(p + 15);
    *(p + 15) = *(p + 14);
    *(p + 14) = *(p + 13);
    *(p + 13) = *(p + 12);
    *(p + 12) = *(p + 11);
    *(p + 11) = *(p + 10);
    *(p + 10) = *(p + 9);
    *(p + 9) = *(p + 8);
    *(p + 8) = *(p + 7);
    *(p + 7) = *(p + 6);
    *(p + 6) = *(p + 5);
    *(p + 5) = *(p + 4);
    *(p + 4) = *(p + 3);
    *(p + 3) = *(p + 2);
    *(p + 2) = *(p + 1);
    *(p + 1) = *p;
    *p = *e;


    /* Coefficients
    -25,     46,    -50,     20,     53,   -142,    182,    -98,   -127,
    402,   -536,    342,    221,   -942,   1384,  -1061,   -298,   2545,
  -5089,   7102,  24912,   7102,  -5089,   2545,   -298,  -1061,   1384,
   -942,    221,    342,   -536,    402,   -127,    -98,    182,   -142,
     53,     20,    -50,     46,    -25
     */
    result = (*(p + 40) + (*p)) * -25
           + (*(p + 39) + (*(p + 1))) * 46
           + (*(p + 38) + (*(p + 2))) * -50
           + (*(p + 37) + (*(p + 3))) * 20
           + (*(p + 36) + (*(p + 4))) * 53
           + (*(p + 35) + (*(p + 5))) * -142
           + (*(p + 34) + (*(p + 6))) * 182
           + (*(p + 33) + (*(p + 7))) * -98
           + (*(p + 32) + (*(p + 8))) * -127
           + (*(p + 31) + (*(p + 9))) * 402
           + (*(p + 30) + (*(p + 10))) * -536
           + (*(p + 29) + (*(p + 11))) * 342
           + (*(p + 28) + (*(p + 12))) * 221
           + (*(p + 27) + (*(p + 13))) * -942
           + (*(p + 26) + (*(p + 14))) * 1384
           + (*(p + 25) + (*(p + 15))) * -1061
           + (*(p + 24) + (*(p + 16))) * -298
           + (*(p + 23) + (*(p + 17))) * 2545
           + (*(p + 22) + (*(p + 18))) * -5089
           + (*(p + 21) + (*(p + 19))) * 7102
           + (*(p + 20)) * 24912;
    /*result = (*(p + 40) + (*p)) * (*H)
           + (*(p + 39) + (*(p + 1))) * (*(H + 1))
           + (*(p + 38) + (*(p + 2))) * (*(H + 2))
           + (*(p + 37) + (*(p + 3))) * (*(H + 3))
           + (*(p + 36) + (*(p + 4))) * (*(H + 4))
           + (*(p + 35) + (*(p + 5))) * (*(H + 5))
           + (*(p + 34) + (*(p + 6))) * (*(H + 6))
           + (*(p + 33) + (*(p + 7))) * (*(H + 7))
           + (*(p + 32) + (*(p + 8))) * (*(H + 8))
           + (*(p + 31) + (*(p + 9))) * (*(H + 9))
           + (*(p + 30) + (*(p + 10))) * (*(H + 10))
           + (*(p + 29) + (*(p + 11))) * (*(H + 11))
           + (*(p + 28) + (*(p + 12))) * (*(H + 12))
           + (*(p + 27) + (*(p + 13))) * (*(H + 13))
           + (*(p + 26) + (*(p + 14))) * (*(H + 14))
           + (*(p + 25) + (*(p + 15))) * (*(H + 15))
           + (*(p + 24) + (*(p + 16))) * (*(H + 16))
           + (*(p + 23) + (*(p + 17))) * (*(H + 17))
           + (*(p + 22) + (*(p + 18))) * (*(H + 18))
           + (*(p + 21) + (*(p + 19))) * (*(H + 19))
           + (*(p + 20)) * (*(H + 20));*/

    return result >> 15;
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


