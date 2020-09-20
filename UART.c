#include "UART.h"


void Intialize_UART(void)
{
    //intialize
    BCSCTL1 = CALBC1_1MHZ;                     // Set DCO "Digitaly Controled Oscillator"
    DCOCTL = CALDCO_1MHZ;
    P1SEL = BIT1 | BIT2 ;                     // P1.1 = RXD, P1.2=TXD
    P1SEL2 = BIT1 | BIT2;
    UCA0CTL1 &= UCSWRST;
    UCA0CTL1 |= UCSSEL_2;                     // SMCLK
    UCA0BR0 = 104;                              // 1MHz 115200
    UCA0BR1 = 0;                              // 1MHz 115200
    UCA0MCTL = UCBRS0;               // Modulation UCBRSx = 5
    UCA0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
    Recieve_Ended=0;
    delimiter_State=0;
    first_flag=1;
    Data=(char*) malloc(20);
}


void Enable_INT_Recieve(void)
{
    IE2 |=  UCA0RXIE;
}


void Transmit_UART(char* data)
{
    int length =strlen (data);
    int i =0;
    for (i=0;i<length;i++)
    {
        while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready?
        if(data[i]!=0)
            UCA0TXBUF = (uint8_t)data[i];
        else
            UCA0TXBUF = 0xC0;

    }
//    while (!(IFG2&UCA0TXIFG)); // USCI_A0 TX buffer ready?
//    UCA0TXBUF = 0xC0;



}




void Disable_INT_Recieve(void)
{
    IE2 &= ~ UCA0RXIE;

}
char* Recieve_Data(void)
{
    Enable_INT_Recieve();
    Data[0]='\0';
    Recieve_Ended=0;
    delimiter_State=0;
    first_flag=1;
    while(Recieve_Ended==0)
    {}
return Data;

}
// Interrupt Service routine of UART Receive
#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void)
{
  data_to_be_recieved = UCA0RXBUF;
  const char* Temp=Data;
  int length = strlen(Temp);
  if(data_to_be_recieved==delimiter && delimiter_State==0 && first_flag==0)
  {

      delimiter_State=1;
  }
  else if(data_to_be_recieved==delimiter && delimiter_State==1 && first_flag==0)
  {

      delimiter_State=0;
      Data[length]=  data_to_be_recieved;
      Data[length+1]='\0';
  }
  else if(data_to_be_recieved==Flag && delimiter_State==1  && first_flag==0)
  {

      delimiter_State=0;
      Data[length]=  data_to_be_recieved;
      Data[length+1]='\0';

  }
  else if(data_to_be_recieved==Flag && delimiter_State==0 && first_flag==0)
  {
      Data[length]=  data_to_be_recieved;
      Data[length+1]='\0';
      Recieve_Ended=1;

  //    Disable_INT_Recieve();
  }
  else if(data_to_be_recieved==Flag && delimiter_State==0 && first_flag==1)
  {
      Data[length]=  data_to_be_recieved;
      Data[length+1]='\0';
      first_flag=0;
  }
  else if(first_flag==0) {
      Data[length]=  data_to_be_recieved;
      Data[length+1]='\0';

  }
}
