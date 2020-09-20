#include "headers.h"

Mode_of_Operation GCS_Operation=Not_intialized;
void main(void)
{

Intialize();
__enable_interrupt();
for(;;)
{
    if(GCS_Operation==Not_intialized)//
    {
        char* Init_Data=Recieve_Data();
        Frame_recieved Init_frame=  Return_from_frame(Init_Data);
       if(Init_frame.frameType==Init && Init_frame.destinationAddress==Sat_Address)
       {
           if(Init_frame.checked==1)
           {

               Send_Ack(GCS_Address);
               GCS_Operation=In_Comm;
           }
           else
           {

               Send_NAck(GCS_Address);
           }

       }
    }
       else if(GCS_Operation==In_Comm )
       {
           char* Ping_Data=Recieve_Data();
           Frame_recieved Ping_frame=  Return_from_frame(Ping_Data);
          if(Ping_frame.frameType==Ping&& Ping_frame.destinationAddress==Sat_Address)
          {
              if(Ping_frame.checked==1)
              {

                  Send_Comm_Ping(GCS_Address);
              }
              else
              {

                  Send_NAck(GCS_Address);
              }

          }
          else if(Ping_frame.frameType==GetTemperature&& Ping_frame.destinationAddress==Sat_Address)

                  {
              if(Ping_frame.checked==1)
                  {

                      Send_Telemetry(GCS_Address);

                  }
                  else
                  {

                      Send_NAck(GCS_Address);
                  }

                 }


    }

}
}
