
//Authors :Ahmed A.Allam
        // Mahmoud Aref
        // Amr Mamdouh
        // Mostafa el Gewily
//Date: 7/9/2020
//Description: this header file provides a method to make a simplified SSP framing for a certain DataPacket
// The frame shape is as follow:
//  Flag[1-Byte]+Destination[1-Byte]+Source[1-Byte]+Type[1-Byte]+Length[1-Byte]+Data[N-Bytes]+Flag[1-Byte]
//Note that: N ranges from 1 till 256 Bytes

#pragma once
#include <stdint.h> //to be removed after precombiled header being defined
#include <string.h>
#include <stdlib.h>

#define Empty_Message_Size 6
//*****************************************************************************
//
// The following are the values that can be passed as parameters for the framing functions
//
//*****************************************************************************
#define Flag 0xC0
#define delimiter 0xF0
// Very important Note: if you are going to use the same code in the GCS MCU you have to flip the source and Destination values
#define Sat_Address 0x50 // Comm-Sat Address
#define GCS_Address 0x10 //GCS Address
#define Src_Address 0x50
//*****************************************************************************
//
// The following are the values that can be passed as types for the framing functions
//
//*****************************************************************************

#define Init 0x01
#define Ping 0x02
#define GetTemperature 0x03
#define ACK 0xAC
#define NACK 0xF0
#define Comm_Ping 0x04
#define Temp 0x05
//*****************************************************************************
//
// The following are used as a predefined Message
//
//*****************************************************************************
#define Ping_Message "comm_ping"

//*****************************************************************************
//
// Prototypes for the SSP Framing.
//
//*****************************************************************************

//! \brief Returns the framed Packet
//!
//! \param destinationAddress is the value of destination Address.
//!        Valid values are:
//!        - \b Sat_Address
//!        - \b GCS_Address
//! \param frameType.
//!        - \b Init
//!        - \b Ping
//!        - \b ACK
//!        - \b NACK
//!        - \b Comm_Ping
//!        - \b Temp
//!        - \b GetTemperature
//! \param data.
//! \return a char array .
//
//*****************************************************************************
char* Get_Frame(uint8_t destinationAddress,
    uint8_t frameType,
    char* data
);
//*****************************************************************************

//! \brief makes initialization Message
//! \param destinationAddress is the value of destination Address.
//!        Valid values are:
//!        - \b Sat_Address
//!        - \b GCS_Address
//! \return a char array .
//
//*****************************************************************************
char* Make_initialization_Message(uint8_t destinationAddress);
//*****************************************************************************

//! \brief makes ping Message
//! \param destinationAddress is the value of destination Address.
//!        Valid values are:
//!        - \b Sat_Address
//!        - \b GCS_Address
//! \return a char array .
//
//*****************************************************************************
char* Make_Ping_Message(uint8_t destinationAddress);
//*****************************************************************************

//! \brief gets Ack Message
//! \param destinationAddress is the value of destination Address.
//!        Valid values are:
//!        - \b Sat_Address
//!        - \b GCS_Address
//! \return a char array .
//
//*****************************************************************************
char* Make_ACK_Message(uint8_t destinationAddress);
//*****************************************************************************

//! \brief makes NACK Message
//! \param destinationAddress is the value of destination Address.
//!        Valid values are:
//!        - \b Sat_Address
//!        - \b GCS_Address
//! \return a char array .
//
//*****************************************************************************
char* Make_NACK_Message(uint8_t destinationAddress);

//*****************************************************************************

//! \brief makes Communication Ping Message
//! \param destinationAddress is the value of destination Address.
//!        Valid values are:
//!        - \b Sat_Address
//!        - \b GCS_Address
//! \return a char array .
//
//*****************************************************************************
char* Make_CommPing_Message(uint8_t destinationAddress);
//*****************************************************************************

//! \brief makes Temperature Message
//! \param destinationAddress is the value of destination Address.
//!        Valid values are:
//!        - \b Sat_Address
//!        - \b GCS_Address
//! \param data.
//! \return a char array .
//
//Important note don't forget to cast Temperature data
//*****************************************************************************
char* Make_Temp_Message(uint8_t destinationAddress, char* data);
//*****************************************************************************

//! \brief makes Get Temperature Message
//! \param destinationAddress is the value of destination Address.
//!        Valid values are:
//!        - \b Sat_Address
//!        - \b GCS_Address
//! \return a char array .
//
//*****************************************************************************
char* Make_GetTemp_Message(uint8_t destinationAddress);
