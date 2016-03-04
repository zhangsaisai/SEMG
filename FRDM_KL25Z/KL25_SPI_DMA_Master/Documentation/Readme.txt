******************************************************************************
******************* Processor Expert Demonstration Project *******************
******************************************************************************

Project: SPI

Short description: SPI synchronous transfer example

Target platforms: TWR-KL25Z48M


Function Description
====================
This project demonstrates synchronous transfer with SPIMaster and
SPISlave components. It consists of two tests:
1. Master to slave data path 
   Calling ReceiveBlock method of the slave prepares the slave
   for data reception. Master then sends small message. 
   When slave receives data both messages are compared.

2. Slave to master data path. 
   Calling ReceiveBlock method of the master prepares the master
   for data reception. Data to send from slave to master are prepared
   by calling the SendBlock method of the slave. To initialize the data
   transmission the master sends arbitrary data of the same length as
   the expected response  from slave (these data are discarded). 
   When master receives the answer, the message is compared with 
   original request. 

Comments and test results are sent to ConsoleUART (Serial component)
on Tower Serial Module (TWR-SER).
RS232 settings: 38400baud rate, 8-bit, 1-stop bit, no parity.

Component brief description
===========================
SM1 (SPIMaster) - SPI master
SS1 (SPISlave) - SPI slave
CsIO1 (ConsoleIO) - UART on TWR-SER module for console output

Required Hardware and Settings
==============================
TWR-KL25Z48M board
TWR-ELEV Tower elevator module (to interconnect TWR-KL25Z48M with TWR-SER module)
TWR-SER Serial module (for console output)
Connections:
PTD3 with PTE1
PTD2 with PTE3
PTD1 with PTE2
PTD0 with PTE4

Building The Project
====================
Build the project usual way in CodeWarrior.
No special settings are required.

Running The Project
===================
Run the project usual way. 

*** End Of File ***
