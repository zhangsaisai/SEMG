/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : CsIO1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ConsoleIO
**     Version     : Component 01.012, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-09-29, 14:34, # CodeGen: 6
**     Abstract    :
**         This component generates low-level methods for redirecting console I/O to the selected UART.
**         These methods are typically used by printf()/scanf() methods.
**     Settings    :
**          Component name                                 : CsIO1
**          Serial_LDD_Link                                : ConsoleIO_Serial_LDD
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file CsIO1.c
** @version 01.00
** @brief
**         This component generates low-level methods for redirecting console I/O to the selected UART.
**         These methods are typically used by printf()/scanf() methods.
*/         
/*!
**  @addtogroup CsIO1_module CsIO1 module documentation
**  @{
*/         

/* MODULE CsIO1. */

#include "IO_Map.h"
#include "stdio.h"
#include <stdarg.h>
#include "UART0_PDD.h"

#ifdef _EWL_STDINT_H

/*
** ===================================================================
**     Method      :  CsIO1___read_console (component ConsoleIO)
**
**     Description :
**         __read_console
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
int __read_console(__file_handle handle, unsigned char* buffer, size_t * count)
{
  size_t CharCnt = 0x00;

  (void)handle;                        /* Parameter is not used, suppress unused argument warning */
  for (;*count > 0x00; --*count) {
    if ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_RDRF_MASK) == 0x00) { /* Any data in receiver buffer */
      /* Clear error flags */
      UART0_PDD_ClearInterruptFlags(UART0_BASE_PTR,0x1FU);
      if (CharCnt != 0x00) {           /* No, at least one char received? */
        break;                         /* Yes, return received char(s) */
      } else {                         /* Wait until a char is received */
        return ( __io_EOF);
      }
    }
    CharCnt++;                         /* Increase char counter */
    /* Save character received by UARTx device into the receive buffer */
    *buffer = (unsigned char)UART0_PDD_GetChar8(UART0_BASE_PTR);
    /* Stop reading if CR (Ox0D) character is received */
    if (*buffer == 0x0DU) {            /* New line character (CR) received ? */
      *buffer = '\n';                  /* Yes, convert LF to '\n' char. */
      break;                           /* Stop loop and return received char(s) */
    }
    buffer++;                          /* Increase buffer pointer */
  }
  *count = CharCnt;
  return (__no_io_error);
}

/*
** ===================================================================
**     Method      :  CsIO1___write_console (component ConsoleIO)
**
**     Description :
**         __write_console
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
int __write_console(__file_handle handle, unsigned char* buffer, size_t* count)
{
  size_t CharCnt = 0x00;

  (void)handle;                        /* Parameter is not used, suppress unused argument warning */
  for (;*count > 0x00; --*count) {
    /* Wait until UART is ready for saving a next character into the transmit buffer */
    while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_TDRE_MASK) == 0) {};
    if (*buffer == '\n') {
      /* Send '\r'(0x0D) before each '\n'(0x0A). */
      /* Save a character into the transmit buffer of the UART0 device */
      UART0_PDD_PutChar8(UART0_BASE_PTR, 0x0DU);
      /* Wait until UART is ready for saving a next character into the transmit buffer */
      while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_TDRE_MASK) == 0) {};
    }
    /* Save a character into the transmit buffer of the UART0 device */
    UART0_PDD_PutChar8(UART0_BASE_PTR, (unsigned char)*buffer);
    buffer++;                          /* Increase buffer pointer */
    CharCnt++;                         /* Increase char counter */
  }
  *count = CharCnt;
  return(__no_io_error);
}

/*
** ===================================================================
**     Method      :  CsIO1___close_console (component ConsoleIO)
**
**     Description :
**         __close_console
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
int __close_console(__file_handle handle)
{
  (void)handle;                        /* Parameter is not used, suppress unused argument warning */
  return(__no_io_error);
}

#endif /* _EWL_STDINT_H */

#ifndef _EWL_STDINT_H

/*
** ===================================================================
**     Method      :  CsIO1__read (component ConsoleIO)
**
**     Description :
**         _read
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
int _read (int fd, const void *buf, size_t count)
{
  size_t CharCnt = 0x00;

  (void)fd;                            /* Parameter is not used, suppress unused argument warning */
  for (;count > 0x00; --count) {
    if ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_RDRF_MASK) == 0x00) { /* Any data in receiver buffer */
      /* Clear error flags */
      UART0_PDD_ClearInterruptFlags(UART0_BASE_PTR,0x1FU);
      if (CharCnt != 0x00) {           /* No, at least one char received? */
        break;                         /* Yes, return received char(s) */
      } else {                         /* Wait until a char is received */
        return ( __io_EOF);
      }
    }
    CharCnt++;                         /* Increase char counter */
    /* Save character received by UARTx device into the receive buffer */
    *(uint8_t*)buf = (unsigned char)UART0_PDD_GetChar8(UART0_BASE_PTR);
    /* Stop reading if CR (Ox0D) character is received */
    if (*(uint8_t*)buf == 0x0DU) {     /* New line character (CR) received ? */
      *(uint8_t*)buf = '\n';           /* Yes, convert LF to '\n' char. */
      break;                           /* Stop loop and return received char(s) */
    }
    (uint8_t*)buf++;                   /* Increase buffer pointer */
  }
  return 1;
}

/*
** ===================================================================
**     Method      :  CsIO1__write (component ConsoleIO)
**
**     Description :
**         _write
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
int _write (int fd, const void *buf, size_t count)
{
  size_t CharCnt = 0x00;

  (void)fd;                            /* Parameter is not used, suppress unused argument warning */
  for (;count > 0x00; --count) {
    /* Wait until UART is ready for saving a next character into the transmit buffer */
    while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_TDRE_MASK) == 0) {};
    if (*(uint8_t*)buf == '\n') {
      /* Send '\r'(0x0D) before each '\n'(0x0A). */
      /* Save a character into the transmit buffer of the UART0 device */
      UART0_PDD_PutChar8(UART0_BASE_PTR, 0x0DU);
      /* Wait until UART is ready for saving a next character into the transmit buffer */
      while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_TDRE_MASK) == 0) {};
    }
    /* Save a character into the transmit buffer of the UART0 device */
    UART0_PDD_PutChar8(UART0_BASE_PTR, (unsigned char)*(uint8_t*)buf);
    (uint8_t*)buf++;                   /* Increase buffer pointer */
    CharCnt++;                         /* Increase char counter */
  }
  return count;
}

#endif /* _EWL_STDINT_H */

/* END CsIO1. */

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
