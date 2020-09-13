//Authors :Zeyad Hany
        // Hossam Sayed
        // Mostafa el Gewily
        // Ahmed Essam
//Date: 9/9/2020
//Description: this header file provieds a method to make a simplified SSP Deframing for a certain DataPacket
// The frame shape is as follow:
//  Flag[1-Byte]+Destination[1-Byte]+Source[1-Byte]+Type[1-Byte]+Length[1-Byte]+Data[N-Bytes]+Flag[1-Byte]
//Note that: N ranges from 1 till 256 Bytes
#ifndef SSP_DEFRAMING_H_INCLUDED
#define SSP_DEFRAMING_H_INCLUDED
#pragma once
#include <stdint.h> //to be removed after precombiled header being defined
#include <string.h>
#include <stdlib.h>
#include <string.h>
#define Empty_Message_Size 6
//*****************************************************************************
//
// The following are the values that can be passed as parameters for the framing functions
//
//*****************************************************************************
#define Flag 0xC0
#define delimiter 0xFF
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
// Prototypes for the SSP DeFraming.
//
//*****************************************************************************
//*****************************************************************************
// struct that will be used in deframing of SSP protocol, to return the needed fields of the frame
typedef struct{
     uint8_t destinationAddress;
     uint8_t frameType;
     uint8_t dataLength;
     char* data;
     uint8_t checked;

} Frame_recieved;
// Prototypes for the SSP DeFraming.
//
//*****************************************************************************

//! \brief Returns a struct which contains our required data
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
//! \param length.
//! \param data.
//! \return a struct
//
//*****************************************************************************
 Frame_recieved  Return_from_frame(char* frame);
#endif // SSP_DEFRAMING_H_INCLUDED
