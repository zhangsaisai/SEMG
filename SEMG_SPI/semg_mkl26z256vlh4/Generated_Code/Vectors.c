/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Vectors.c
**     Project     : ProcessorExpert
**     Processor   : MKL26Z256VLH4
**     Version     : Component 01.006, Driver 01.04, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-01-02, 19:11, # CodeGen: 275
**     Abstract    :
**
**     Settings    :
**
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Vectors.c                                                  
** @version 01.04
** @brief
**
*/         
/*!
**  @addtogroup Vectors_module Vectors module documentation
**  @{
*/         

  #include "Cpu.h"
  #include "SM_SPI0.h"
  #include "SS_SPI1.h"
  #include "SysTick.h"
  #include "BitIO_AD_NOT_RESET0.h"
  #include "BitIO_AD_START0.h"
  #include "BitIO_UPRDY.h"
  #include "BitIO_AD_NOT_CS0.h"
  #include "EINT_AD_NOT_DRDY0.h"
  #include "EINT_SYNC_INT.h"
  #include "DMAT_M_SPI_TX.h"
  #include "DMA_CTRL.h"
  #include "DMAT_M_SPI_RX.h"
  #include "DMAT_S_SPI_TX.h"
  #include "DMAT_S_SPI_RX.h"
  #include "BitIO_AD_NOT_CS1.h"
  #include "BitIO_AD_NOT_RESET1.h"
  #include "Events.h"


  /* ISR prototype */
  extern uint32_t __SP_INIT;
  extern
  #ifdef __cplusplus
  "C"
  #endif
  void __thumb_startup( void );
  
  
  /*lint -esym(765,__vect_table) Disable MISRA rule (8.10) checking for symbols (__vect_table). Definition of the interrupt vector table placed by linker on a predefined location. */
  /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. Need to explicitly cast pointers to the general ISR for Interrupt vector table */
  
  __attribute__ ((section (".vectortable"))) const tVectorTable __vect_table = { /* Interrupt vector table */
  
    /* ISR name                             No. Address      Pri Name                          Description */
    &__SP_INIT,                        /* 0x00  0x00000000   -   ivINT_Initial_Stack_Pointer   used by PE */
    {
    (tIsrFunc)&__thumb_startup,        /* 0x01  0x00000004   -   ivINT_Initial_Program_Counter used by PE */
    (tIsrFunc)&Cpu_INT_NMIInterrupt,   /* 0x02  0x00000008   -2   ivINT_NMI                     used by PE */
    (tIsrFunc)&Cpu_ivINT_Hard_Fault,   /* 0x03  0x0000000C   -1   ivINT_Hard_Fault              unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved4,    /* 0x04  0x00000010   -   ivINT_Reserved4               unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved5,    /* 0x05  0x00000014   -   ivINT_Reserved5               unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved6,    /* 0x06  0x00000018   -   ivINT_Reserved6               unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved7,    /* 0x07  0x0000001C   -   ivINT_Reserved7               unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved8,    /* 0x08  0x00000020   -   ivINT_Reserved8               unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved9,    /* 0x09  0x00000024   -   ivINT_Reserved9               unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved10,   /* 0x0A  0x00000028   -   ivINT_Reserved10              unused by PE */
    (tIsrFunc)&Cpu_ivINT_SVCall,       /* 0x0B  0x0000002C   -   ivINT_SVCall                  unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved12,   /* 0x0C  0x00000030   -   ivINT_Reserved12              unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved13,   /* 0x0D  0x00000034   -   ivINT_Reserved13              unused by PE */
    (tIsrFunc)&Cpu_ivINT_PendableSrvReq, /* 0x0E  0x00000038   -   ivINT_PendableSrvReq          unused by PE */
    (tIsrFunc)&SysTick_Interrupt,      /* 0x0F  0x0000003C   0   ivINT_SysTick                 used by PE */
    (tIsrFunc)&DMA_CTRL_Channel0Interrupt, /* 0x10  0x00000040   1   ivINT_DMA0                    used by PE */
    (tIsrFunc)&DMA_CTRL_Channel1Interrupt, /* 0x11  0x00000044   1   ivINT_DMA1                    used by PE */
    (tIsrFunc)&DMA_CTRL_Channel2Interrupt, /* 0x12  0x00000048   2   ivINT_DMA2                    used by PE */
    (tIsrFunc)&DMA_CTRL_Channel3Interrupt, /* 0x13  0x0000004C   2   ivINT_DMA3                    used by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved20,   /* 0x14  0x00000050   -   ivINT_Reserved20              unused by PE */
    (tIsrFunc)&Cpu_ivINT_FTFA,         /* 0x15  0x00000054   -   ivINT_FTFA                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_LVD_LVW,      /* 0x16  0x00000058   -   ivINT_LVD_LVW                 unused by PE */
    (tIsrFunc)&Cpu_ivINT_LLW,          /* 0x17  0x0000005C   -   ivINT_LLW                     unused by PE */
    (tIsrFunc)&Cpu_ivINT_I2C0,         /* 0x18  0x00000060   -   ivINT_I2C0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_I2C1,         /* 0x19  0x00000064   -   ivINT_I2C1                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_SPI0,         /* 0x1A  0x00000068   -   ivINT_SPI0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_SPI1,         /* 0x1B  0x0000006C   -   ivINT_SPI1                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_UART0,        /* 0x1C  0x00000070   -   ivINT_UART0                   unused by PE */
    (tIsrFunc)&Cpu_ivINT_UART1,        /* 0x1D  0x00000074   -   ivINT_UART1                   unused by PE */
    (tIsrFunc)&Cpu_ivINT_UART2,        /* 0x1E  0x00000078   -   ivINT_UART2                   unused by PE */
    (tIsrFunc)&Cpu_ivINT_ADC0,         /* 0x1F  0x0000007C   -   ivINT_ADC0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_CMP0,         /* 0x20  0x00000080   -   ivINT_CMP0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_TPM0,         /* 0x21  0x00000084   -   ivINT_TPM0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_TPM1,         /* 0x22  0x00000088   -   ivINT_TPM1                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_TPM2,         /* 0x23  0x0000008C   -   ivINT_TPM2                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_RTC,          /* 0x24  0x00000090   -   ivINT_RTC                     unused by PE */
    (tIsrFunc)&Cpu_ivINT_RTC_Seconds,  /* 0x25  0x00000094   -   ivINT_RTC_Seconds             unused by PE */
    (tIsrFunc)&Cpu_ivINT_PIT,          /* 0x26  0x00000098   -   ivINT_PIT                     unused by PE */
    (tIsrFunc)&Cpu_ivINT_I2S0,         /* 0x27  0x0000009C   -   ivINT_I2S0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_USB0,         /* 0x28  0x000000A0   -   ivINT_USB0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_DAC0,         /* 0x29  0x000000A4   -   ivINT_DAC0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_TSI0,         /* 0x2A  0x000000A8   -   ivINT_TSI0                    unused by PE */
    (tIsrFunc)&Cpu_ivINT_MCG,          /* 0x2B  0x000000AC   -   ivINT_MCG                     unused by PE */
    (tIsrFunc)&Cpu_ivINT_LPTimer,      /* 0x2C  0x000000B0   -   ivINT_LPTimer                 unused by PE */
    (tIsrFunc)&Cpu_ivINT_Reserved45,   /* 0x2D  0x000000B4   -   ivINT_Reserved45              unused by PE */
    (tIsrFunc)&Cpu_ivINT_PORTA,        /* 0x2E  0x000000B8   2   ivINT_PORTA                   used by PE */
    (tIsrFunc)&Cpu_ivINT_PORTC_PORTD   /* 0x2F  0x000000BC   -   ivINT_PORTC_PORTD             unused by PE */
    }
  };
  /*lint -restore Enable MISRA rule (11.4) checking. */
  

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