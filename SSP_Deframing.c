#include "SSP_Deframing.h"


 Frame_recieved  Return_from_frame(char* frame)
{
    Frame_recieved fr;
    int i=0;
    int j=0;
    fr.destinationAddress=frame[1];
    fr.frameType=frame[3];
    fr.dataLength=frame[4];
    uint8_t stopping=(fr.dataLength+4);
    //char* ptr1=(char*) calloc(9,sizeof(char));
    fr.data[fr.dataLength]='\0';
    strncpy (fr.data, frame+5, frame[4] );

    fr.checked=1; // will be modified after CRC checking

    return fr;
}
