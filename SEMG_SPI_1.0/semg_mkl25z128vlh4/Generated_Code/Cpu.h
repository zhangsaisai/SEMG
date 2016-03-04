/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLH4
**     Component   : MKL25Z128LH4
**     Version     : Component 01.000, Driver 01.04, CPU db: 3.00.000
**     Datasheet   : KL25P80M48SF0RM, Rev.3, Sep 2012
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-08-08, 10:21, # CodeGen: 264
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         No public methods
**
**     (c) Freescale Semiconductor, Inc.
**     2004 All Rights Reserved
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.h
** @version 01.04
** @brief
**
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

#ifndef __Cpu_H
#define __Cpu_H

/* MODULE Cpu. */
/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* Active configuration define symbol */
#define PEcfg_FLASH 1U

/* Methods configuration constants - generated for all enabled component's methods */

/* Events configuration constants - generated for all enabled component's events */
#define Cpu_OnNMIINT_EVENT_ENABLED

#define CPU_BUS_CLK_HZ                  24000000U /* Initial value of the bus clock frequency in Hz */
#define CPU_CORE_CLK_HZ                 48000000U /* Initial value of the core/system clock frequency in Hz.  */

#define CPU_CLOCK_CONFIG_NUMBER         0x01U /* Specifies number of defined clock configurations. */

#define CPU_BUS_CLK_HZ_CLOCK_CONFIG0    24000000U /* Value of the bus clock frequency in the clock configuration 0 in Hz. */
#define CPU_CORE_CLK_HZ_CLOCK_CONFIG0   48000000U /* Value of the core/system clock frequency in the clock configuration 0 in Hz. */


#define CPU_XTAL_CLK_HZ                 8000000U /* Value of the external crystal or oscillator clock frequency in Hz */
#define CPU_INT_SLOW_CLK_HZ             32768U /* Value of the slow internal oscillator clock frequency in Hz  */
#define CPU_INT_FAST_CLK_HZ             4000000U /* Value of the fast internal oscillator clock frequency in Hz  */

#define CPU_FAMILY_Kinetis             /* Specification of the core type of the selected cpu */
#define CPU_DERIVATIVE_MKL25Z128LH4    /* Name of the selected cpu derivative */
#define CPU_PARTNUM_MKL25Z128VLH4      /* Part number of the selected cpu */
#define CPU_LITTLE_ENDIAN              /* The selected cpu uses little endian */

/* CPU frequencies in clock configuration 0 */
#define CPU_CLOCK_CONFIG_0              0x00U /* Clock configuration 0 identifier */
#define CPU_CORE_CLK_HZ_CONFIG_0        48000000UL /* Core clock frequency in clock configuration 0 */
#define CPU_BUS_CLK_HZ_CONFIG_0         24000000UL /* Bus clock frequency in clock configuration 0 */
#define CPU_FLEXBUS_CLK_HZ_CONFIG_0     0UL /* Flexbus clock frequency in clock configuration 0 */
#define CPU_FLASH_CLK_HZ_CONFIG_0       0UL /* FLASH clock frequency in clock configuration 0 */
#define CPU_USB_CLK_HZ_CONFIG_0         0UL /* USB clock frequency in clock configuration 0 */
#define CPU_PLL_FLL_CLK_HZ_CONFIG_0     48000000UL /* PLL/FLL clock frequency in clock configuration 0 */
#define CPU_MCGIR_CLK_HZ_CONFIG_0       32768UL /* MCG internal reference clock frequency in clock configuration 0 */
#define CPU_OSCER_CLK_HZ_CONFIG_0       8000000UL /* System OSC external reference clock frequency in clock configuration 0 */
#define CPU_ERCLK32K_CLK_HZ_CONFIG_0    1000UL /* External reference clock 32k frequency in clock configuration 0 */
#define CPU_MCGFF_CLK_HZ_CONFIG_0       15625UL /* MCG fixed frequency clock */


typedef struct  {
  uint32_t cpu_core_clk_hz;            /* Core clock frequency in clock configuration */
  uint32_t cpu_bus_clk_hz;             /* Bus clock frequency in clock configuration */
  uint32_t cpu_flexbus_clk_hz;         /* Flexbus clock frequency in clock configuration */
  uint32_t cpu_flash_clk_hz;           /* FLASH clock frequency in clock configuration */
  uint32_t cpu_usb_clk_hz;             /* USB clock frequency in clock configuration */
  uint32_t cpu_pll_fll_clk_hz;         /* PLL/FLL clock frequency in clock configuration */
  uint32_t cpu_mcgir_clk_hz;           /* MCG internal reference clock frequency in clock configuration */
  uint32_t cpu_oscer_clk_hz;           /* System OSC external reference clock frequency in clock configuration */
  uint32_t cpu_erclk32k_clk_hz;        /* External reference clock 32k frequency in clock configuration */
  uint32_t cpu_mcgff_clk_hz;           /* MCG fixed frequency clock */
} TCpuClockConfiguration;

/* The array of clock frequencies in configured clock configurations */
extern const TCpuClockConfiguration PE_CpuClockConfigurations[CPU_CLOCK_CONFIG_NUMBER];

  /* Interrupt vector table type definition */
  typedef void (*const tIsrFunc)(void);
  typedef struct {
    void * __ptr;
    tIsrFunc __fun[0x2F];
  } tVectorTable;
  
  extern const tVectorTable __vect_table;

/* Global variables */
/*lint -esym(765,SR_reg) Disable MISRA rule (8.10) checking for symbols (SR_reg). The SR_reg is used in inline assembler. */
extern volatile uint8_t SR_reg;        /* Current FAULTMASK register */
/*lint -esym(765,SR_lock) Disable MISRA rule (8.10) checking for symbols (SR_lock). The SR_reg is used in inline assembler. */
extern volatile uint8_t SR_lock;

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(Cpu_ivINT_PORTA);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_PORTA (component MKL25Z128LH4)
**
**     Description :
**         This ISR services the ivINT_PORTA interrupt shared by several 
**         components.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/*
** ===================================================================
**     Method      :  PE_low_level_init (component MKL25Z128LH4)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void);

/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(Cpu_INT_NMIInterrupt);
/*
** ===================================================================
**     Method      :  Cpu_INT_NMIInterrupt (component MKL25Z128LH4)
**
**     Description :
**         This ISR services the Non Maskable Interrupt interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Hard_Fault);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Hard_Fault (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved4);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved4 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved5);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved5 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved6);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved6 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved7);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved7 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved8);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved8 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved9);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved9 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved10);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved10 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_SVCall);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_SVCall (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved12);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved12 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved13);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved13 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_PendableSrvReq);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_PendableSrvReq (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved20);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved20 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_FTFA);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_FTFA (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_LVD_LVW);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_LVD_LVW (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_LLW);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_LLW (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_I2C0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_I2C0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_I2C1);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_I2C1 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_SPI0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_SPI0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_SPI1);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_SPI1 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_UART0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_UART0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_UART1);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_UART1 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_UART2);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_UART2 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_ADC0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_ADC0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_CMP0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_CMP0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_TPM0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_TPM0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_TPM1);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_TPM1 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_TPM2);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_TPM2 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_RTC);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_RTC (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_RTC_Seconds);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_RTC_Seconds (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_PIT);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_PIT (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved39);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved39 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_USB0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_USB0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_DAC0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_DAC0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_TSI0);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_TSI0 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_MCG);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_MCG (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_LPTimer);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_LPTimer (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_Reserved45);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_Reserved45 (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

PE_ISR(Cpu_ivINT_PORTD);
/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_PORTD (component MKL25Z128LH4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void __init_hardware(void);
/*
** ===================================================================
**     Method      :  __init_hardware (component MKL25Z128LH4)
**
**     Description :
**         Initializes the whole system like timing, external bus, etc.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

/* END Cpu. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* __Cpu_H */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
