
#include "SSP_Framing.h"

char* Get_Frame(uint8_t destinationAddress,uint8_t frameType,char* data)
{
  //Note that here we assume that the data is already byte stiffed
//please don't forget to change the source address used here
int dataLength=strlen(data);
if(dataLength>256) return NULL;
char* frame =(char*) malloc(Empty_Message_Size+dataLength+2);
int len =0;
frame[len] = Flag;
frame[len+1] = '\0';

len ++;
frame[len] = destinationAddress;
frame[len+1] = '\0';

len++;
frame[len] = Src_Address;  //Source address assuming that this is the Sattellite Communication Subsystem
frame[len+1] = '\0';

len++;
frame[len] = frameType;
frame[len+1] = '\0';

len++;
if(dataLength!=0)
{
frame[len] = dataLength;
frame[len+1] = '\0';
strcat(frame,data);
}
else
{
frame[len] = 0xFF;
frame[len+1] = '\0';

 }
len = strlen(frame);


frame[len] = Flag;
frame[len+1] = '\0';

return frame;
}

char* Make_initialization_Message(uint8_t destinationAddress)
{
return Get_Frame(destinationAddress,Init, (char*)"");
}

char* Make_Ping_Message(uint8_t destinationAddress)
{
  return Get_Frame(destinationAddress,Ping, (char*)"");
}

char* Make_ACK_Message(uint8_t destinationAddress)
{
    return Get_Frame(destinationAddress,ACK,(char*)"");
}

char* Make_NACK_Message(uint8_t destinationAddress)
{
  return Get_Frame(destinationAddress,NACK, (char*)"");
}

char* Make_CommPing_Message(uint8_t destinationAddress)
{
  return Get_Frame(destinationAddress,Comm_Ping,(char*)Ping_Message);
}

char* Make_Temp_Message(uint8_t destinationAddress,char* data)
{
  return Get_Frame(destinationAddress,Temp,data);
}

char* Make_GetTemp_Message(uint8_t destinationAddress)
{
  return Get_Frame(destinationAddress,GetTemperature, (char*)"");
}
