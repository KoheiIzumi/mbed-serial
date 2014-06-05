/*--------------------------------------------------*/
/* @Program name ; mbed_serial                      */
/* @Author : Kohei Izumi                            */
/* @Comment : Serial communication for mbed         */
/*                                                  */
/* Copyright(c) 2014 Kohei Izumi                    */
/*--------------------------------------------------*/

#include "mbed.h"

Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);

/*--------------------------------------------------*/
/* Function     : Return buffer                     */
/* NAME         : ReturnBuffer                      */
/* Argument     : buffer                            */
/* Return value : buffer                            */
/*--------------------------------------------------*/
char *ReturnBuffer(char buffer[20]){
    return buffer;
}

/*--------------------------------------------------*/
/* Function     : Receive                           */
/* NAME         : Receive                           */
/* Argument     : ---                               */
/* Return value : ReturnBuffer                      */
/*--------------------------------------------------*/
char *Receive(){
    char buffer[20];
    if(pc.readable()){
        pc.scanf("%s", &buffer);
    }
    return ReturnBuffer(buffer);
}

/*--------------------------------------------------*/
/* Function     : main program                      */ 
/* NAME         : main                              */
/* Argument     : ---                               */
/* Return value : ---                               */
/*--------------------------------------------------*/
int main()
{
    char buffer[20];

    while(1){
        strcpy(buffer, Receive());
        
        if(!strcmp(buffer, "on")) led1 = 1;
        if(!strcmp(buffer, "off")) led1 = 0;
        
        pc.printf("%s\n", buffer);
    }
}
