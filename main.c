#include "headers.h"
typedef enum Mode_of_Operation
{
Not_intialized,
Wait_for_ping,
Wait_for_Command
}Mode_of_Operation;

Mode_of_Operation GCS_Operation=Not_intialized;
void main(void)
{

    Intialize();
    __enable_interrupt();
    char * data =get_converted_data();



}
