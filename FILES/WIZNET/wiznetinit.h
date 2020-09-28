#ifndef WIZNETINIT_H
#define WIZNETINIT_H

#include <stdint.h>
#include "../../Ethernet/Ethernet/wizchip_conf.h"

/*============================================================================*/
#define PROTOCOL_TCP                    1
#define PROTOCOL_UDP                   2
/*============================================================================*/
/*============== =Defines of the file: system_configuration.h ================*/
/*============================================================================*/

// Ip address setting
#define WIZ_IP_OCT_1                        192
#define WIZ_IP_OCT_2                        168
#define WIZ_IP_OCT_3                        100
#define WIZ_IP_OCT_4                        120

// Mac address setting
#define WIZ_MAC_OCT_1                       0xAA
#define WIZ_MAC_OCT_2                       0x00
#define WIZ_MAC_OCT_3                       0x00
#define WIZ_MAC_OCT_4                       0xFF
#define WIZ_MAC_OCT_5                       0xFF
#define WIZ_MAC_OCT_6                       WIZ_IP_OCT_4

// Gatway address setting
#define WIZ_GATE_OCT_1                      WIZ_IP_OCT_1
#define WIZ_GATE_OCT_2                      WIZ_IP_OCT_2
#define WIZ_GATE_OCT_3                      WIZ_IP_OCT_3
#define WIZ_GATE_OCT_4                      254

// Definition of network mask
#define WIZ_MASK_OCT_1                      255
#define WIZ_MASK_OCT_2                      255
#define WIZ_MASK_OCT_3                      255
#define WIZ_MASK_OCT_4                      0

/*============================================================================*/

#define WIZ_INTERFACE_ID                    0
#define WIZ_SPI_ID                          1
#define WIZ_RETRANS_COUNT                   3
#define WIZ_TRANS_TIMEOUT                   4000

/*============================================================================*/
typedef struct
{
    uint8_t socketNumber; 
    uint8_t protocol;
    uint8_t flag;
    uint8_t connectionType;
    uint8_t localPort;
    uint8_t endpointIp[4];
    uint16_t endpointPort;
    
}wiznet_socket_config_t;

/*============================================================================*/
int WiznetInit(uint8_t* wizTxSize, uint8_t* wizRxSize, wiz_NetInfo* wizNetConfig,
                   wiz_NetTimeout* wizNettimeout);

void WiznetSetIp(uint8_t ip[4]);
void WiznetGetIp(uint8_t ip[4]);
void WiznetSetMac(uint8_t mac[6]);
void WiznetGetMac(uint8_t mac[6]);
void WiznetSetGateway(uint8_t gateway[4]);
/*============================================================================*/

#endif  /*WIZNETINITI_H*/