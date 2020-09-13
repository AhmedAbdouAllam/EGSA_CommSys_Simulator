#include "ADC.h"

void Intialize_ADC(void)
{
    ADC10CTL0 = ADC10SHT_2 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
    ADC10CTL1 = INCH_3;                       // input A3
    ADC10AE0 |= 0x08;                         // PA.1 ADC option select
    Conversion_Ended=0;
}





void Start_Conversion_ADC(void)
{
    ADC10CTL0 |= ENC + ADC10SC;
}
//Interrupt Service routine of ADC10 Conversion ended


char* get_converted_data(void)
{

        Start_Conversion_ADC();
        while (Conversion_Ended==0){}
        Conversion_Ended=0;
        char* data=(char*) malloc(2);;
        data[0]=Temperature;
        data[1]='\0';
        return data;
}
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  Temperature = ADC10MEM ;
  Conversion_Ended=1;
}
