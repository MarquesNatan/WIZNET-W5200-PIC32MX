#ifndef BOARD_PINOUT_H
#define BOARD_PINOUT_H

#define PIC32MX795F512L
#if defined PIC32MM0256GPM064

/*============================================================================*/
#define SPI1_MOSI_PORT                  D
#define SPI1_MOSI_BIT                   0
#define SPI1_MOSI_MASK                  (1 << SPI1_MOSI_BIT)

#define SPI1_MISO_PORT                  D   
#define SPI1_MISO_BIT                   4
#define SPI1_MISO_MASK                  (1 << SPI1_MISO_BIT)

#define SPI1_SCK_PORT                   C
#define SPI1_SCK_BIT                    13
#define SPI1_SCK_MASK                   (1 << SPI1_CLK_BIT)

#define SPI1_CS_PORT                    D
#define SPI1_CS_BIT                     2
#define SPI1_CS_MASK                    (1 << SPI1_CS_BIT)

/*============================================================================*/
#define WIZ_RST_PORT                     D 
#define WIZ_RST_BIT                      1
#define WIZ_RST_MASK                     (1 << WIZ_RST_BIT)


#define WIZ_SS_SELECT_PORT               C
#define WIZ_SS_SELECT_BIT                9
#define WIZ_SS_SELECT_MASK               (1 << WIZ_SS_SELECT_BIT)
/*============================================================================*/
#endif /*PIC32MM0256GPM064*/
#if defined PIC32MX795F512L
#define LED_COMM_PORT               B
#define LED_COMM_BIT                0
#define LED_COMM_MASK               (1 << LED_COMM_BIT)

#define LED_PROFILE_PORT            B
#define LED_PROFILE_BIT             1
#define LED_PROFILE_MASK            (1 << LED_PROFILE_BIT)

#define LED_HEARTBEAT_PORT          B
#define LED_HEARTBEAT_BIT           2
#define LED_HEARTBEAT_MASK          (1 << LED_HEARTBEAT_BIT)
/*============================================================================*/
#define SPI1_SCK_PORT               D
#define SPI1_SCK_BIT                15
#define SPI1_SCK_MASK               (1 << SPI1_SCK_BIT)

#define SPI1_MISO_PORT              F
#define SPI1_MISO_BIT               2
#define SPI1_MISO_MASK              (1 << SPI1_MISO_BIT)

#define SPI1_MOSI_PORT              F
#define SPI1_MOSI_BIT               8
#define SPI1_MOSI_MASK              (1 << SPI1_MOSI_BIT)

#define SPI1_CS_PORT                B
#define SPI1_CS_BIT                 12
#define SPI1_CS_MASK                (1 << SPI1_CS_BIT)
/*============================================================================*/
#define WIZ_RST_PORT                G
#define WIZ_RST_BIT                 12
#define WIZ_RST_MASK                (1 << WIZ_RST_BIT)
/*============================================================================*/
#define WIZ_PWRDOWN_PORT            F
#define WIZ_PWRDOWN_BIT             3
#define WIZ_PWRDOWN_MASK            (1 << WIZ_PWRDOWN_BIT)
/*============================================================================*/
#define WIZ_INT_PORT                E
#define WIZ_INT_BIT                 9
#define WIZ_INT_MASK                (1 << WIZ_INT_BIT)
/*============================================================================*/
#define UART_2_FLOW_CTROL_PORT      E
#define UART_2_FLOW_CTROL_BIT       7
#define UART_2_FLOW_CTROL_MASK      (1 << UART_2_FLOW_CTROL_BIT)
/*============================================================================*/
#define I2C_1_SCL_PPS               5050
#define I2C_1_SDA_PPS               5051
/*============================================================================*/


#endif
/*Pinos de seleção do modulo Wiznet*/
#endif /**/