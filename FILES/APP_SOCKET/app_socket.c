#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <proc/p32mx795f512l.h>
#include "app_socket.h"
#include "../WIZNET/wiznetinit.h"
#include "../../Ethernet/Ethernet/socket.h"
#include "../NVM/nvm.h"
#include "../LED/led.h"
#include "../TIMER/timer.h"
/*============================================================================*/
/*============================================================================*/
void blinkEstablished(void);
void led(void);
int32_t loopbackTCP(socket_config_t* socketConfig)
{
    int8_t socketSR;
    int8_t RxBuffer[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int8_t TxBuffer[10] = {48, 49, 50, 51, 52, 53, 54, 55, 56, 57};
    uint16_t length = 0x02;
    int32_t receiveStatus = 0x00;
    uint32_t DATA = 0x112233;
    switch(GetStatus(socketConfig->socketNumber))
    {
        case SOCK_ESTABLISHED:
            // socketReceive(socket_config_t* socketConfig, int8_t* RxBuffer, uint16_t length)
            receiveStatus = socketReceive(socketConfig, RxBuffer, length);
            if(receiveStatus > 0x00){
            socketSend(socketConfig, RxBuffer, length);
            /*
            led();
            socketClose(socketConfig);
             * */
            }

           
            break;
        case SOCK_CLOSE_WAIT:
            for(;;);
            break;
        case SOCK_INIT:
            socketListen(socketConfig);
            break;
        case SOCK_CLOSED:
            // Open a socket with user configuration 
            socketOpen(socketConfig);
            break;
        default:
            return -1;
            break;
    }
    
    socketSR = GetStatus(socketConfig->socketNumber);
    return 1;   
}
 

int32_t socketReceive(socket_config_t* socketConfig, int8_t* RxBuffer, uint16_t length)
{
    uint16_t receivedBytes      = 0x00;
    uint16_t totalBytesReceived = 0x00;
    if((receivedBytes = getSn_RX_RSR(socketConfig->socketNumber)) > 0x00)
    {
        totalBytesReceived = recv(socketConfig->socketNumber, RxBuffer, receivedBytes);    
    }
    
    if(totalBytesReceived == receivedBytes)
    {
        return totalBytesReceived;
    }
    else
    {
        return receivedBytes; 
    }
    
    return -1;
}

int32_t socketSend(socket_config_t* socketConfig, int8_t* TxBuffer, int16_t length)
{
    int16_t totalSent  = 0x00;
    int16_t sentBytes = 0x00;
    
    do
    {
        sentBytes = send(socketConfig->socketNumber, TxBuffer + totalSent, length);
        totalSent += sentBytes;
    }while(sentBytes > 0x00 && (length -=   sentBytes) > 0x00);
    
    if(sentBytes > 0x00)
    {
        return totalSent;
    }else
    {
        return sentBytes;
    }
}



int8_t socketGetStatus(socket_config_t* socketConfig)
{
    uint8_t socketStatus;
    socketStatus = GetStatus(socketConfig->socketNumber);
    
    return socketStatus;
}

int8_t socketOpen(socket_config_t* socketConfig)
{
    int8_t socketStatus;
    // Open socket with the user configuration
    // call functions sending parameters: Socket Number, Protocol, Port and Flags
    socketStatus = socket(socketConfig->socketNumber, socketConfig->protocol,
                          socketConfig->localPort, socketConfig->connectionFlag);
    if(socketStatus == socketConfig->socketNumber);
    return socketStatus;
}

int8_t socketClose(socket_config_t* socketConfig)
{
    uint8_t socketStatus;

    socketStatus = close(socketConfig->socketNumber);

    if(socketStatus);
    return socketStatus;
}

int8_t socketListen(socket_config_t* socketConfig)
{
    // Listen the conections of socket number n
    uint8_t socketStatus;
    socketStatus = listen(socketConfig->socketNumber);
    if(socketStatus);
    return socketStatus;
}


int8_t socketConnect(socket_config_t* socketConfig, uint8_t* addr, uint16_t port)
{
    uint8_t socketStatus;
    socketStatus = connect(socketConfig->socketNumber, addr, port);
    if(socketStatus);
    return socketStatus;
}

int8_t socketDisconnect(socket_config_t* socketConfig)
{
    uint8_t socketStatus;
    socketStatus = disconnect(socketConfig->socketNumber);
    if(socketStatus);
    
    return socketStatus;
}
