#include "mbed.h"

#define READBUFFERSIZE (32)

Serial g_serial(USBTX, USBRX);

int ReadLineString( Serial& serial,
                    char szReadBuffer[], const int ciReadBufferSize, int& riIndexChar,
                    char szLineString[], const int ciLineStringSize )
{
    while( 1 )
    {
        if( !serial.readable() )
        {
            break;
        }
        char c = serial.getc();
        if( '\r' == c  )
        {
            szReadBuffer[riIndexChar] = '\0';
            strncpy( szLineString, szReadBuffer, ciLineStringSize - 1 );
            szLineString[ciLineStringSize - 1] = '\0';
            riIndexChar = 0;
            return 1;
        }
        else if( '\n' == c )
        {
            ;
        }
        else
        {
            if( (ciReadBufferSize - 1) > riIndexChar )
            {
                szReadBuffer[riIndexChar] = c;
                riIndexChar++;
            }
        }
    }

    return 0;
}

int main()
{
    // setup
    g_serial.baud(9600);
    wait(0.001);
    
    // loop
    char szReadBuffer[READBUFFERSIZE] = "";
    int iIndexChar = 0;
    while(1)
    {
        char szLineString[READBUFFERSIZE];
        if( !ReadLineString( g_serial, 
                             szReadBuffer, READBUFFERSIZE, iIndexChar,
                             szLineString, READBUFFERSIZE ) )
        {
            continue;
        }
    }
}
