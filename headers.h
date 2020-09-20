//Authors :Ahmed A.Allam
        // Mahmoud Aref
        // Amr Mamdouh
        // Mostafa el Gewily
//Date: 12/9/2020
//Description: this header file provides a method to make a simplified UART protocol for Transmission

#pragma once
#include "UART.h"

#include "ADC.h"

#include "SSP_Framing.h"

#include "SSP_Deframing.h"

typedef enum Mode_of_Operation
{
Not_intialized,
In_Comm
}Mode_of_Operation;

//*****************************************************************************
//
// Prototypes for the Communication System Simulator.
//
//*****************************************************************************

//! \brief initializes UART Communication ,ADC , Watch-dog timer and enables global intterupt.
//!
//! \return none.
//
//*****************************************************************************

void Intialize(void);
//*****************************************************************************

//! \brief Sends acknowledgment
//! \return none .
//
//*****************************************************************************
void Send_Ack(uint8_t Address);
//*****************************************************************************

//! \brief Sends Communication Ping
//! none.
//
//*****************************************************************************
void Send_Comm_Ping(uint8_t Address);
//*****************************************************************************

//! \brief Sends Telemetry information
//! \return none.
//
//*****************************************************************************
void Send_Telemetry(uint8_t Address);


//! \brief Sends non-acknowledgment
//! \return none .
//
//*****************************************************************************
void Send_NAck(uint8_t Address);
//*****************************************************************************
