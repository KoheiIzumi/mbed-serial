#include "mbed.h"

#define READBUFFERSIZE (32)

Serial pc(USBTX, USBRX);

int main()
{
    char buffer[20];
    while(1){
        if (pc.readable()){
            pc.scanf("%s", &buffer);
        }
        pc.printf("%s\n", buffer);
    }
}