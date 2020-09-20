#include "Arduino_Header.h"
Mode_of_Operation GCS;
char Tempreture;
void setup() {
    Intialize();
    GCS=INIT_MODE;
}
#include "Arduino_Header.h"
void loop() {
char command=Serial.read();


if(GCS==INIT_MODE &&command=='a' )
{
Send_Init(Sat_Address);
////
  char* Init_Data=Recieve_Frame();
        Frame_recieved Init_frame=  Return_from_frame(Init_Data);
       if(Init_frame.frameType==ACK && Init_frame.destinationAddress==GCS_Address)
       {
           if(Init_frame.checked==1)
           {
               Serial.write("a");
               GCS=InComm;
           }
  
        }
}
else if (GCS==InComm && command=='b')
{
Send_Ping(Sat_Address);
  char* Init_Data=Recieve_Frame();
        Frame_recieved Init_frame=  Return_from_frame(Init_Data);
       if(Init_frame.frameType==ACK && Init_frame.destinationAddress==GCS_Address && Init_frame.data==Ping_Message)
       {
          Serial.write('b');
        }



  
}
else if (GCS==InComm && command=='c') // here we add a condition for android application but for now it will remain as it is
{
Send_Get_Telemetry(Sat_Address);  
  char* Init_Data=Recieve_Frame();
        Frame_recieved Init_frame=  Return_from_frame(Init_Data);
       if(Init_frame.frameType==ACK && Init_frame.destinationAddress==GCS_Address)
       {
           if(Init_frame.checked==1)
           {

             Tempreture=Init_frame.data[0];
             Serial.write(Tempreture);
           }
  
        }  
}

}
