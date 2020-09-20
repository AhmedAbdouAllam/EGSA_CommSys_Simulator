#include "Arduino_Header.h"
// Any test line will have a comment "test" and you have to get it out for the code sequence to work right and not intterupt the code sequence.....
void Intialize(void)
{
    Serial.begin(38400); // to be changed when interfacing with bluetooth module.... Ahmed A.Allam 38400 ...
    // I have edited it please when dealing with Serial monintor or Terminal please change Data Rate
    Serial1.begin(9600);

}

void Send_Init(uint8_t Address)
{
    char* INIT_MSG=Make_initialization_Message(Address);
    Serial1.print(INIT_MSG); // Have to check its validity..... Ahmed A.Allam


}
void Send_Ping(uint8_t Address)
{
    char* Ping_MSG=Make_Ping_Message(Address);
    Serial1.print(Ping_MSG); // Have to check its validity..... Ahmed A.Allam

}
void Send_Get_Telemetry(uint8_t Address)
{
    char* Get_Tele=Make_GetTemp_Message(Address);
    Serial1.print(Get_Tele); // Have to check its validity..... Ahmed A.Allam

}

char* Recieve_Frame(void)
{

uint8_t data_to_be_recieved;
int Recieve_Ended=0;
int delimiter_State=0;
char* Data=(char*) malloc(20);
Data[0]='\0';
bool first_flag=true;
while (Recieve_Ended==0)

{
  int length =strlen(Data);
  
if(Serial1.available()>0)
{
    data_to_be_recieved=Serial1.read();
// test x lines
Serial.println("****************");
Serial.print("Data:");
Serial.println (data_to_be_recieved);
Serial.print("Length: ");
Serial.println(length);
    if(data_to_be_recieved==delimiter && delimiter_State==0 && first_flag==false)
    {

        delimiter_State=1;
        //test 1 line:
 Serial.println("data_to_be_recieved==delimiter && delimiter_State==0 && first_flag==false");
    }
    else if(data_to_be_recieved==delimiter && delimiter_State==1&& first_flag==false)
    {

        delimiter_State=0;
        Data[length]=  data_to_be_recieved;
        Data[length+1]='\0';
        //test 1 line:
        Serial.println("data_to_be_recieved==delimiter && delimiter_State==1&& first_flag==false");
    }
    else if(data_to_be_recieved==Flag && delimiter_State==1 && first_flag==false)
    {
      

        delimiter_State=0;
        Data[length]=  data_to_be_recieved;
        Data[length+1]='\0';
                //test 1 line:
        Serial.println("data_to_be_recieved==Flag && delimiter_State==1 && first_flag==false");

    }
    else if(data_to_be_recieved==Flag && delimiter_State==0 && first_flag==false)
    {
        Data[length]=  data_to_be_recieved;
        Data[length+1]='\0';
        Recieve_Ended=1;
                //test 1 line:
        Serial.println("data_to_be_recieved==Flag && delimiter_State==0 && first_flag==false");
     
    }
    else if(data_to_be_recieved==Flag && delimiter_State==0 && first_flag==true)
    {
        Data[length]=  data_to_be_recieved;
        Data[length+1]='\0';
        first_flag=false;      
                        //test 1 line:
        Serial.println("data_to_be_recieved==Flag && delimiter_State==0 && first_flag==true");
      
     }
    else if(first_flag==false){
        Data[length]=  data_to_be_recieved;
        Data[length+1]='\0';
                        //test 1 line:
        Serial.println("first_flag==false");
    }


}

}
return Data;

}
