#ifndef _ETHERNET_BOARD_CONFIG_H
#define _ETHERNET_BOARD_CONFIG_H


#define WIZNET 5200
#define TRANSPORT_LAYER_WIZNET

#define UDP_BTL_PORT        6234
#define UDP_DISCOVER_PORT   30303

#define MAC_ADDR_BYTE1  (0xAA)
#define MAC_ADDR_BYTE2  (0x00)
#define MAC_ADDR_BYTE3  (0x00)
#define MAC_ADDR_BYTE4  (0xFF)
#define MAC_ADDR_BYTE5  (0xFF)
#define MAC_ADDR_BYTE6  (0x05)
#define MY_IP_ADDRESS
#ifdef MY_IP_ADDRESS
#define IP_ADDR_BYTE1   (192)
#define IP_ADDR_BYTE2   (168)
#define IP_ADDR_BYTE3   (100)
#define IP_ADDR_BYTE4   (120)
#else 
    #error "change to your ip address"
#endif

#define IP_MASK_BYTE1   (255)
#define IP_MASK_BYTE2   (255)
#define IP_MASK_BYTE3   (255)
#define IP_MASK_BYTE4   (0)

#define IP_GATE_BYTE1   (192)
#define IP_GATE_BYTE2   (168)
#define IP_GATE_BYTE3   (250)
#define IP_GATE_BYTE4   (254)

#endif /* _ETHERNET_BOARD_CONFIG_H */