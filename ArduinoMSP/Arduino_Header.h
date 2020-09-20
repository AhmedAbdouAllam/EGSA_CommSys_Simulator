//Authors :Ahmed A.Allam
        // Mahmoud Aref
        // Amr Mamdouh
        // Mostafa el Gewily
//Date: 12/9/2020
//Description: this header file provides a method to make a simplified UART protocol for Transmission

#pragma once

#include "SSP_Framing.h"

#include "SSP_Deframing.h"
#include "Arduino.h"
typedef enum Mode_of_Operation
{
INIT_MODE,
InComm
}Mode_of_Operation;

//*****************************************************************************
//
// Prototypes for the Communication System Simulator.
//
//*****************************************************************************

//! \brief initializes UART Communication and Bluetooth Communication.
//!
//! \return none.
//
//*****************************************************************************

void Intialize(void);
//*****************************************************************************

//! \brief Sends Initialization Request
//! \return none .
//
//*****************************************************************************
void Send_Init(uint8_t Address);
//*****************************************************************************

//! \brief Sends Ping
//! none.
//
//*****************************************************************************
void Send_Ping(uint8_t Address);
//*****************************************************************************

//! \brief Sends Get Telemetry request
//! \return none.
//
//*****************************************************************************
void Send_Get_Telemetry(uint8_t Address);

//! \brief Receives a Frame
//! \return character array.
//
//*****************************************************************************
char* Recieve_Frame(void);


