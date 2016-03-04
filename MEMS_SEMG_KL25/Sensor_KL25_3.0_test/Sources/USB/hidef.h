/******************************************************/
/**
* @file hidef.h
* Machine/compiler dependent declarations.
*/
/*----------------------------------------------------
   Copyright (c) Freescale DevTech
               All rights reserved
                  Do not modify!
 *****************************************************/

#ifndef _H_HIDEF_
#define _H_HIDEF_

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(__CWCC__)||defined(__GNUC__))
#pragma gcc_extensions on

/**** Version for ColFire V1 */
#include <stddef.h>
#include "types.h"

#define EnableInterrupts asm ("CPSIE  i")
  /*!< Macro to enable all interrupts. */

#define DisableInterrupts asm ("CPSID  i")
  /*!< Macro to disable all interrupts. */
#elif defined(__IAR_SYSTEMS_ICC__)
#include <intrinsics.h>

#define EnableInterrupts  __enable_interrupt();
#define DisableInterrupts __disable_interrupt();
#endif

#ifdef __cplusplus
 }
#endif

#endif

/*****************************************************/
/* end hidef.h */
