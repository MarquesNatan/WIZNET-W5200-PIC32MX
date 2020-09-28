#include <stddef.h>
#include "wiznetinit.h"
#include "../SPI/spi32mx.h"
#include "../PERIPHERAL/PERIPHERAL.h"
#include "../TIMER/timer.h"
/*============================================================================*/

inline static void _wiz_spi_write_byte_func(uint8_t byte)
{
    SpiWrite(&byte, 1);
}
inline static uint8_t _wiz_spi_read_func(void)
{
    uint8_t byte;
    SpiRead(&byte, 1);
    return byte;
}

/*============================================================================*/
wiz_NetInfo wiznetConfig =
{
    .mac = {WIZ_MAC_OCT_1 ,WIZ_MAC_OCT_2 ,WIZ_MAC_OCT_3 ,WIZ_MAC_OCT_4 ,WIZ_MAC_OCT_5 , WIZ_MAC_OCT_6},
    .ip = {WIZ_IP_OCT_1, WIZ_IP_OCT_2, WIZ_IP_OCT_3, WIZ_IP_OCT_4},
    .sn = {WIZ_MASK_OCT_1, WIZ_MASK_OCT_2, WIZ_MASK_OCT_3, WIZ_MASK_OCT_4},
    .gw = {WIZ_GATE_OCT_1, WIZ_GATE_OCT_2, WIZ_GATE_OCT_3, WIZ_GATE_OCT_4},
    .dhcp = NETINFO_STATIC
};

wiz_NetTimeout wizNetTimeout =
{
    .retry_cnt = WIZ_RETRANS_COUNT,
    .time_100us = WIZ_TRANS_TIMEOUT
};



/*============================================================================*/
int WiznetInit(uint8_t* wizTxSize, uint8_t* wizRxSize, wiz_NetInfo* wizNetConfig,
               wiz_NetTimeout* wizNetTimeout)
{
    int wizStatus;
    
    
    WiznetReset();
    
    
    TimerWaitMS(10);
    WiznetStart();
    
    
    TimerWaitMS(250);
    
    
    reg_wizchip_cs_cbfunc(SpiSelect, SpiDeselect);
    reg_wizchip_spi_cbfunc(_wiz_spi_read_func, _wiz_spi_write_byte_func);
    
    wizStatus = wizchip_init(NULL, NULL);
    wizchip_setnetinfo(wizNetConfig);
    
    if(wizNetTimeout != NULL)
    {
        wizchip_settimeout(wizNetTimeout);
    }
    
    return wizStatus;
}

void WiznetSetIp(uint8_t ip[4])
{
	wiz_NetInfo wizNetConfig;
	
	wizchip_getnetinfo(&wizNetConfig);
	
	wizNetConfig.ip[0] = ip[0];
	wizNetConfig.ip[1] = ip[1];
	wizNetConfig.ip[2] = ip[2];
	wizNetConfig.ip[3] = ip[3];
	
	wizchip_setnetinfo(&wizNetConfig);
}
/*============================================================================*/
void WiznetGetIp(uint8_t ip[4])
{
	wiz_NetInfo wizNetConfig;
	
	wizchip_getnetinfo(&wizNetConfig);
	
	ip[0] = wizNetConfig.ip[0];
	ip[1] = wizNetConfig.ip[1];
	ip[2] = wizNetConfig.ip[2];
	ip[3] = wizNetConfig.ip[3];
}
/*============================================================================*/
void WiznetSetMac(uint8_t mac[6])
{
	wiz_NetInfo wizNetConfig;
	
	wizchip_getnetinfo(&wizNetConfig);
	
	wizNetConfig.mac[0] = mac[0];
	wizNetConfig.mac[1] = mac[1];
	wizNetConfig.mac[2] = mac[2];
	wizNetConfig.mac[3] = mac[3];
	wizNetConfig.mac[4] = mac[4];
	wizNetConfig.mac[5] = mac[5];
	
	wizchip_setnetinfo(&wizNetConfig);
}
/*============================================================================*/
void WiznetGetMac(uint8_t mac[6])
{
	wiz_NetInfo wizNetConfig;
	
	wizchip_getnetinfo(&wizNetConfig);
	
	mac[0] = wizNetConfig.mac[0];
    mac[1] = wizNetConfig.mac[1];
    mac[2] = wizNetConfig.mac[2];
    mac[3] = wizNetConfig.mac[3];
    mac[4] = wizNetConfig.mac[4];
    mac[5] = wizNetConfig.mac[5];
    
}
/*============================================================================*/
void WiznetSetGateway(uint8_t gateway[4])
{
	
	wiz_NetInfo wizNetConfig;
	
	wizchip_getnetinfo(&wizNetConfig);
	
	wizNetConfig.gw[0] = gateway[0];
	wizNetConfig.gw[1] = gateway[1];
	wizNetConfig.gw[2] = gateway[2];
	wizNetConfig.gw[3] = gateway[3];
	
	wizchip_setnetinfo(&wizNetConfig);
}
/*============================================================================*/