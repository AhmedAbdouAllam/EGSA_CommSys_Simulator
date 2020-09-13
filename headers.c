#include "headers.h"

void Intialize(void)
{
    WDTCTL=WDTPW+WDTHOLD;
    Intialize_ADC();
    Intialize_UART();

}

void Send_Ack(uint8_t Address)
{
    char* ACK_MSG=Make_ACK_Message(Address);
    Transmit_UART(ACK_MSG);
}

void Send_Comm_Ping(uint8_t Address)
{
    char* CPing_MSG=Make_CommPing_Message(Address);
    Transmit_UART(CPing_MSG);

}

void Send_Telemetry(uint8_t Address)
{
    char* data=get_converted_data();

    char* T_MSG= Make_Temp_Message(Address,data);
    Transmit_UART(T_MSG);

}
void Send_NAck(uint8_t Address)
{
    char* NACK_MSG=Make_NACK_Message(Address);
    Transmit_UART(NACK_MSG);
}
