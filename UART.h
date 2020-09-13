//Authors :Ahmed A.Allam
        // Mahmoud Aref
        // Amr Mamdouh
        // Mostafa el Gewily
//Date: 12/9/2020
//Description: this header file provieds a method to make a simplified UART protocol for Transmission

#pragma once
#include <stdint.h> //to be removed after precombiled header being defined
#include <string.h>
#include <stdlib.h>
#include <msp430.h>
volatile char* Data;
volatile char data_to_be_recieved ;
volatile int Recieve_Ended;
volatile int delimiter_State;
#define Flag 0xC0
#define delimiter 0xFF

//*****************************************************************************
//
// Prototypes for the UART Communication.
//
//*****************************************************************************

//! \brief initializes UART Communication.
//!
//! \return none.
//
//*****************************************************************************

void Intialize_UART(void);
//*****************************************************************************

//! \brief Enables Receive Interrupt
//! \return none .
//
//*****************************************************************************
void Enable_INT_Recieve(void);
//*****************************************************************************

//! \brief Transmits a Block
//! \param Array of Characters.
//! none.
//
//*****************************************************************************
void Transmit_UART(char* data);
//*****************************************************************************

//! \brief disables receive interrupt
//! \return none.
//
//*****************************************************************************
void Disable_INT_Recieve(void);

//! \brief receives Data
//! \return character array.
//
//*****************************************************************************
char* Recieve_Data(void);
