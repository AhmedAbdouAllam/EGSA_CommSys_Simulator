#include "SSP_Deframing.h"


 Frame_recieved  Return_from_frame(char* frame)
{
     Frame_recieved fr;

        fr.destinationAddress=frame[1];
        fr.frameType=frame[3];
        if(frame[4]!=0xFF)
          fr.dataLength=frame[4];
         else
         fr.dataLength=0;
        fr.data[fr.dataLength]='\0';
        if(fr.dataLength!=0)
        strncpy (fr.data, frame+5, frame[4] );
        else
        fr.data[0]='\0';
        fr.checked=1; // will be modified after CRC checking

        return fr;
}
