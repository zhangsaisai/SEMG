/*
 * Macros.h
 *
 *  Created on: May 4, 2015
 *      Author: lab
 */

#ifndef MACROS_H_
#define MACROS_H_

#include "PE_Types.h"


#define USING_ADC_COUNT 0x01U                                     /*!< The count of ADC used. */

#define CHANNEL_COUNT 0x08U                                    /*!< Count of ADC's channel. */
#define RAW_DATA_HEAD_SIZE 0x03U                                  /*!< Head size of raw data from ADC. */
#define USING_CHANNEL_COUNT 0x09U                              /*!< Count of ADC channels used currently. */
#define RAW_DATA_SIZE 0x09U //9 axis                                     /*!< Size of raw data: 9 axis  = 18 Bytes. */
#define SENSOR_DATA_COUNT 0x12U//18 bytes                                  /*!< The count of channel data uploaded to ARM each time per ADC. */
#define CHANNEL_DATA_COUNT 5U//5 times                                 /*!< The times of channel data uploaded to ARM */

/*!
 * The length of data frame.
 *
   @verbatim
   ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   |0xb7|channel_package_length_high|channel_package_length_low|expected_frame_high|expected_frame_low|wait_time|status_high|status_low|data|0xed|
   ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
   status_high: [7] - x
                [6] - x
                [5] - x
                [4:2] - Buffer Status(empty, write, full or overflow)
                [1] - Buffer Label(left buffer or right buffer)
   status_low: [7-0] - Overflow Count
   @endverbatim
 */
#define DATA_FRAME_LENGTH 96                                 /*!< The length of a data frame when using 2 ADC. */
    

/*
 * ===================================================================
 * User Type Definition
 * ===================================================================
 */
    /*!
     * @addtogroup EnumGrp Enum Group
     * @{
     */
typedef enum ARM_DATA_BUFFER{eLeftBuffer = 0, eRightBuffer = 1} EARMDataBuffer;                                     /*!< The value of flag to mark the name of the arm data buffer. */
typedef enum SENSOR_DATA_STATUS_FLAG{eIdle = -1, eReceiving = 0, eReceived = 1} ESENSORDataStatusFlag;                    /*!< The value of flag to mark the status of receiving ADC data. */
typedef enum SENSOR_FLAG{eADC0 = 0, eADC1 = 1} ESENSORFlag;                                                               /*!< The value of flag to mark ADC. */
typedef enum ARM_DATA_BUF_FLAG{eNull = -1, eEmpty = 0, eRead = 1, eWrite = 2, eFull = 3, eOverflow = 4} EARMDataBufferFlag;        /*!< The value of flag to mark which buffer's data transmitting to ARM. */
typedef enum TRANSMITION_CONTENT_FLAG{eNothing = -1, eCommand = 0, eData = 1} ETransmitionContent;                  /*!< The value of flag to mark what content is being transmitted. */                                               /*!< The value of flag to mark what SPI mode is used. */

/*!
 * A structure of data about sensor.
 *
    @verbatim
    ---------------------------------------------------------------------------------------------
    |              mag             |             gyro            |              acc             |
    ---------------------------------------------------------------------------------------------
    |  XH | XL | YH | YL | ZH | ZL | XH | XL | YH | YL | ZH | ZL |  XH | XL | YH | YL | ZH | ZL |
    ---------------------------------------------------------------------------------------------
    |         6*1=6Bytes           |            6*1= 6Bytes      |          6*1=6Bytes
    ---------------------------------------------------------------------------------------------
    @endverbatim
 */
struct TSENSORData
{
	short  rawData[RAW_DATA_SIZE];                              /*!< The raw data from SENSOR, including status bytes. */
};
typedef struct TSENSORData TSENSORData;
typedef struct TSENSORData* TSENSORDataPtr;

/*!
* A structure of SENSOR's setting.
*/
struct TSENSORSetting
{
	volatile bool isChannelEnabled[0x09];             /*!< Flag of whether channel is enabled. */
};
typedef struct TSENSORSetting TSENSORSetting;
typedef struct TSENSORSetting* TSENSORSettingPtr;

/*!
* A structure of SENSOR's status.
*/
struct TSENSORStatus
{
    volatile bool isDataReady;                                  /*!< Flag of whether sensor' data is ready. */
    volatile ETransmitionContent transmitionContent;                 /*!< Flag of what content is being transmitted. */
    volatile ESENSORDataStatusFlag sensorDataStatus;                             /*!< Flag of whether the sensor data is received. */
};
typedef struct TSENSORStatus TSENSORStatus;
typedef struct TSENSORStatus* TSENSORStatusPtr;

/*!
* A structure of SENSOR device.
*/
struct TSENSOR
{
    TSENSORStatus sensorStatus;
    TSENSORSetting sensorSetting;
    TSENSORData sensorData;
};
typedef struct TSENSOR TSENSOR;
typedef struct TSENSOR* TSENSORPtr;



/*!
 * A structure of data being processing or processed in MCU.
 */
struct TMCUData
{
    short axisData[USING_CHANNEL_COUNT][CHANNEL_DATA_COUNT];            /*!< The value of every channel's data from ADC. */
};
typedef struct TMCUData TMCUData;
typedef struct TMCUData* TMCUDataPtr;

/*!
 * A structure of MCU's setting.
 */
struct TMCUSetting
{

};
typedef struct TMCUSetting TMCUSetting;
typedef struct TMCUSetting* TMCUSettingPtr;

/*!
 * A structure of MCU's Status.
 */
struct TMCUStatus
{
    volatile bool isReceivingADCData : 1;                           /*!< Flag of whether MCU is receiving data from ADC. */
    volatile bool isMasterReceived : 1;                             /*!< Flag of whether Master SPI finishing reception. */
    volatile bool isMasterSent : 1;                                 /*!< Flag of whether Master SPI finishing transmission. */
    volatile bool isSlaveReceived : 1;                              /*!< Flag of whether Slave SPI finishing reception. */
    volatile bool isSlaveSent : 1;                                  /*!< Flag of whether Slave SPI finishing transmission. */
    volatile bool isUartReceived : 1;                               /*!< Flag of whether UART finishing reception. */
    volatile bool isUartSent : 1;                                   /*!< Flag of whether UART finishing transmission. */
};
typedef struct TMCUStatus TMCUStatus;
typedef struct TMCUStatus* TMCUStatusPtr;

/*!
 *  A structure of MCU device.
 */
struct TMCU
{
    TMCUStatus mcuStatus;
    TMCUSetting mcuSetting;
    TMCUData mcuData;
};
typedef struct TMCU TMCU;
typedef struct TMCU* TMCUPtr;

/*!
 * A structure of data from or to ARM.
 */
struct TARMData
{
    byte dataFrame[DATA_FRAME_LENGTH];                          /*!< The data frame transmitted to ARM. */
};
typedef struct TARMData TARMData;
typedef struct TARMData* TARMDataPtr;

/*!
 * A structure of ARM's setting.
 */
struct TARMSetting
{

};
typedef struct TARMSetting TARMSetting;
typedef struct TARMSetting* TARMSettingPtr;

/*!
 * A structure of ARM's status.
 */
struct TARMStatus
{
    volatile bool isRequiringData : 1;                              /*!< Flag of whether arm requires data. */
    volatile bool isUploadReady : 1;                                /*!< Flag of whether data is ready for uploading to ARM. */
    volatile bool isForeBufferEmpty : 1;                            /*!< Flag of is the foreground buffer empty. TRUE: Cannot be read, can swap. */
    volatile bool isForeBufferFull : 1;                             /*!< Flag of is the foreground buffer full. TRUE: Cannot swap, can be read. */
    volatile bool isBackBufferEmpty : 1;                            /*!< Flag of is the background buffer empty. TRUE: Cannot swap, can be written. */
    volatile bool isBackBufferFull : 1;                             /*!< Flag of is the background buffer full. TRUE: Cannot be written, can swap*/
    volatile bool isTransmittingData : 1;                           /*!< Flag of whether the data is being transmitted, difference from commands or others being transmitted. */
    volatile ETransmitionContent transmitionContent;            /*!< Flag of what content is being transmitted. */
    volatile EARMDataBufferFlag foreBufferStatus;               /*!< Flag of foreground buffer status. */
    volatile EARMDataBufferFlag backBufferStatus;               /*!< Flag of background buffer status. */

};
typedef struct TARMStatus TARMStatus;
typedef struct TARMStatus* TARMStatusPtr;

/*!
 *  A structure of ARM device.
 */
struct TARM
{
    TARMStatus armStatus;
    TARMSetting armSetting;
    TARMData armDataLeft;                   /*!< Buffer1. */
    TARMData armDataRight;                  /*!< Buffer2. */
    byte* foreBuffer;                       /*!< The pointer to the buffer to be transmitted. */
    byte* backBuffer;                       /*!< The pointer to the buffer to be written. */
};
typedef struct TARM TARM;
typedef struct TARM* TARMPtr;




#endif /* MACROS_H_ */
