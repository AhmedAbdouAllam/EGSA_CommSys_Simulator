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

volatile char Temperature  ;
volatile int Conversion_Ended;


//*****************************************************************************
//
// Prototypes for the ADC.
//
//*****************************************************************************

//! \brief initializes ADC operation.
//!
//! \return none.
//
//*****************************************************************************

void Intialize_ADC(void);
//*****************************************************************************

//! \brief Starts a single channel one time conversion
//! \return none .
//
//*****************************************************************************
void Start_Conversion_ADC(void);
//*****************************************************************************

//! \brief gets converted data.
//! \return none .
//
//*****************************************************************************
char* get_converted_data(void);
//*****************************************************************************

