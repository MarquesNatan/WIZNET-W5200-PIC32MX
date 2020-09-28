#ifndef APP_SOCKET_H
#define APP_SOCKET_H

#include <stdint.h>
/*============================================================================*/
#define SOCK_FLAG_NONE          0
#define SOCK_FLAG_MULTICAST     1
#define SOCK_FLAG_IGMP_VER2     2
/*============================================================================*/
#define TYPE_SERVER             1
#define TYPE_CLIENT             0

#define PORT_5000               50000
#define PORT_30303              30303



#define WIZ_INTERFACE_ID        0
#define WIZ_SOCK_NUMBER         0
#define TYPE_CONNECTION         TYPE_SERVER
#define WIZ_SOCK_FLAG           SOCK_FLAG_NONE
#define TYPE_PROTOCOL           PROTOCOL_TCP
#define LOCAL_PORT              PORT_5000


/*============================================================================*/
#define GetStatus(sn) getSn_SR(sn)
/*============================================================================*/
typedef struct
{
    uint8_t interfaceId; 
    uint8_t socketNumber;
    uint8_t type;
    uint8_t protocol;
    
    uint16_t localPort;
    uint16_t endpointPort;
    
    uint8_t endpointIp[4];
    uint8_t connectionFlag;
}socket_config_t;

int32_t loopbackTCP(socket_config_t* socketConfig);

int8_t socketGetStatus(socket_config_t* socketConfig);

int8_t socketOpen(socket_config_t* socketConfig);
int8_t socketClose(socket_config_t* socketConfig);

int8_t socketListen(socket_config_t* socketConfig);

int8_t socketConnect(socket_config_t* socketConfig, uint8_t* addr, uint16_t port);
int8_t socketDisconnect(socket_config_t* socketConfig);

int32_t socketReceive(socket_config_t* socketConfig, int8_t* RxBuffer, uint16_t length);
int32_t socketSend(socket_config_t* socketConfig, int8_t* TxBuffer, int16_t length);
#endif /* APP_SOCKET_H*/