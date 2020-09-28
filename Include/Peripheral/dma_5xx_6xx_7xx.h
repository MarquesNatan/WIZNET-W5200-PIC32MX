/*********************************************************************
 *
 *                  DMA API definitions
 *
 *********************************************************************
 * FileName:        Dma.h
 * Dependencies:    xc.h
 *                  int.h
 *
 * Processor:       PIC32
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc.
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the “Company”) for its PIC32/PIC24F Microcontroller is intended
 * and supplied to you, the Company’s customer, for use solely and
 * exclusively on Microchip PIC32/PIC24F Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN “AS IS” CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * $Id: Dma.h,v 1.9 2007/01/17 21:35:46 C12878 Exp $
 * $Name:  $
 *
 ********************************************************************/

#ifndef _DMA_5XX_6XX__7XX_H_
#define _DMA_5XX_6XX__7XX_H_

#include <xc.h>

/*
*  WARNING: All the Peripheral Library (PLIB) functions, including those in this file,
*  will be removed from future releases of MPLAB XC32 C/C++ Compiler.
*  Please refer to the MPLAB Harmony Libraries for new projects.  For legacy support,
*  these PLIB Libraries will be available for download from: www.microchip.com/pic32_peripheral_lib
*/

// DMA definitions

#ifdef _DMAC0
    #define _DMA_CHANNELS       // DMA channels exist


// existent DMA channels
    typedef enum
    {
        DMA_CHANNEL0,
    #ifdef _DMAC1
        DMA_CHANNEL1,
    #ifdef _DMAC2
        DMA_CHANNEL2,
    #ifdef _DMAC3
        DMA_CHANNEL3,
    #ifdef _DMAC4
        DMA_CHANNEL4,
    #ifdef _DMAC5
        DMA_CHANNEL5,
    #ifdef _DMAC6
        DMA_CHANNEL6,
    #ifdef _DMAC7
        DMA_CHANNEL7,
    #endif  // _DMAC7
    #endif  // _DMAC6
    #endif  // _DMAC5
    #endif  // _DMAC4
    #endif  // _DMAC3
    #endif  // _DMAC2
    #endif  // _DMAC1
        //  add/remove DMA channel as needed here

        DMA_CHANNELS    // number of current available channels
    }DmaChannel;


    // Relative Dma channels priority, between each other
    typedef enum
    {
        DMA_CHN_PRI0,
        DMA_CHN_PRI1,
        DMA_CHN_PRI2,
        DMA_CHN_PRI3
    }DmaChannelPri;



    // high level definitions for the API functions

    typedef enum
    {
        DMA_OPEN_DEFAULT = 0,                                   // DMA default operation
        DMA_OPEN_AUTO   = _DCH0CON_CHAEN_MASK,                  // DMA channel is auto enabled
        DMA_OPEN_CHAIN_LOW  = (_DCH0CON_CHCHN_MASK|_DCH0CON_CHCHNS_MASK),   // DMA channel is chained to lower channel
        DMA_OPEN_CHAIN_HI  = (_DCH0CON_CHCHN_MASK),             // DMA channel is chained to higher channel
        DMA_OPEN_DET_EN = _DCH0CON_CHAED_MASK,                  // events detection enabled while channel off
        DMA_OPEN_ENABLE = _DCH0CON_CHEN_MASK,                   // DMA channel is enabled after open
        DMA_OPEN_MATCH  = 0x80000000,                           // DMA channel stops on match
    }DmaOpenFlags;  // flags for the channel open


    typedef enum
    {
        DMA_EV_ERR =            0x1,        // address error event
        DMA_EV_ABORT =          0x2,        // transfer abort event
        DMA_EV_CELL_DONE =      0x4,        // cell transfer complete event
        DMA_EV_BLOCK_DONE =     0x8,        // block transfer complete event
        DMA_EV_DST_HALF =       0x10,       // destination half event
        DMA_EV_DST_FULL =       0x20,       // destination full event
        DMA_EV_SRC_HALF =       0x40,       // source half event
        DMA_EV_SRC_FULL =       0x80,       // source full event

        DMA_EV_ALL_EVNTS=       (DMA_EV_ERR|DMA_EV_ABORT|DMA_EV_CELL_DONE|DMA_EV_BLOCK_DONE|DMA_EV_DST_HALF|
                                    DMA_EV_DST_FULL|DMA_EV_SRC_HALF|DMA_EV_SRC_FULL)                // all available events
    }DmaEvFlags;    // flags for controlling the DMA channel events; Bit fields from the processor header file.


    typedef enum
    {
        DMA_TXFER_OK,           // the transfer was performed successfully
        DMA_TXFER_ADD_ERR,      // address error while performing the transfer
        DMA_TXFER_ABORT,        // the DMA transfer was aborted
        DMA_TXFER_BC_ERR,       // block complete not set after the DMA transfer performed
        DMA_TXFER_CC_ERR,       // cell complete not set after the DMA transfer performed
        DMA_TXFER_TMO           // DMA transfer timeout
    }DmaTxferRes;       // DMA transfer result

    typedef enum
    {
        DMA_WAIT_NOT,       // don't wait for the transfer to complete, return immediately
        DMA_WAIT_CELL,      // wait for the cell transfer to complete, than return
        DMA_WAIT_BLOCK      // wait for the block transfer to complete, than return
    }DmaWaitMode;       // DMA transfer wait mode

    typedef enum
    {
        DMA_CHKSUM_CRC,     // LFSR CRC
        DMA_CHKSUM_IP,      // IP Checksum
    }DmaChksumType;     // DMA SFM supported checksum types

    typedef enum
    {
        DMA_BITO_MSb,       // MSb first (not reflected)
        DMA_BITO_LSb,       // LSb first (reflected)
    }DmaBitOrder;       // DMA SFM supported bit ordering

    typedef enum
    {
        DMA_REORDER_NOT,    // no reordering, destination matches the source
        DMA_REORDER_ENDIAN, // change endianess on word (32 bit) boundaries: LE<->BE
        DMA_REORDER_SWAP_HALF,  // swap half words (16 bit) within word (32 bit)
        DMA_REORDER_SWAP_BYTE,  // swap bytes within half word (16 bit)
    }DmaReorderMode;    // DMA SFM supported re-ordering modes


    // High level Special Function Module (SFM) functions

    /*********************************************************************
     * Function:        void DmaSfmConfigure(DmaChksumType cType, DmaBitOrder bitO, DmaReorderMode rMode)
     *
     * PreCondition:    cType, bitO, rMode - valid values
     *
     * Input:           cType - checksum type to be calculated: CRC or IP Checksum
     *                  bitO  - the bit order to be used MSb or LSb first
     *                  rMode - the reordering mode of the bytes when calculating the checksum
     *
     * Output:          None
     *
     * Side Effects:    Whenever the Transfer re-ordering is enabled the rMode setting will influence the destination data layout
     *
     * Overview:        The function configures the SFM module by setting the parameters that define the behavior:
     *                      - the type of the checksum to be calculated (either CRC or IP checksum are supported)
     *                      - the bit ordering (how a specific byte is used in the checksum calculation: MSb or LSb first)
     *                      - the data re-ordering (how bytes are re-ordered before calculating the checksum).
     *                      All these values affect the way the checksum is calculated.
     *
     * Note:            None
     *
     * Example:         DmaSfmConfigure(DMA_CHKSUM_CRC, DMA_BITO_LSb, DMA_REORDER_ENDIAN);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmConfigure(DmaChksumType cType, DmaBitOrder bitO, DmaReorderMode rMode)
    {
        DCRCCONCLR=_DCRCCON_CRCTYP_MASK|_DCRCCON_BITO_MASK|_DCRCCON_BYTO_MASK;
        DCRCCONSET=(cType<<_DCRCCON_CRCTYP_POSITION)|(bitO<<_DCRCCON_BITO_POSITION)|(rMode<<_DCRCCON_BYTO_POSITION);
    }

    /*********************************************************************
     * Function:        void DmaSfmTxferReorder(int enable)
     *
     * PreCondition:    None
     *
     * Input:           enable - boolean to enable/disable the re-ordering of the data transfer
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function configures the data transfer re-ordering of the SFM module.
     *                  If the re-ordering is enabled, the data is read from the source, re-ordered accordingly and then written to the destination.
     *                  Otherwise the data is written to the destination un-modified.
     *                  The re-ordering is the one specified by the DmaReorderMode parameter in the DmaSfmConfigure() call.
     *
     *
     * Note:            - The data transfer re-ordering should be used only for normal (background mode) data transfers.
     *                  - In append mode the data transfer re-ordering should not be enabled (undefined behavior)!
     *                  - Whenever the data re-ordering is enabled, the transfer should be aligned at both ends (source and destination).
     *                    Un-aligned transfers are not supported (undefined behavior)!
     *
     * Example:         DmaSfmTxferReorder();
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmTxferReorder(int enable)
    {
        DCRCCONCLR=_DCRCCON_WBO_MASK;
        DCRCCONSET=(enable<<_DCRCCON_WBO_POSITION);
    }


     /*********************************************************************
     * Function:        void DmaSfmCrcConfigure(unsigned int polynomial, int pLen, unsigned int seed)
     *
     * PreCondition:    pLen   - valid polynomial length within 1-32
     *
     * Input:           polynomial  - the layout of the CRC generator
     *                  pLen        - the length of the CRC generator polynomial
     *                  seed        - the initial seed of the CRC generator
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function configures the SFM CRC module by setting the parameters that define the generator polynomial:
     *                  - the length of the CRC generator polynomial, pLen;
     *                  - the function sets the layout of the shift stages that take place in the CRC generation.
     *                    Setting a bit to 1 enables the XOR input from the MSb (pLen bit) to the selected stage in the shift register.
     *                    If bit is cleared, the selected shift stage gets data directly from the previous stage in the shift register.
     *                    Note that in a proper CRC polynomial, both the most significant bit (MSb) and least significant bit(LSb)
     *                    are always a '1'. Considering the generator polynomial: X^16+X^15+X^2+1, the value to be written as
     *                    feedback should be 0x8005, or 0x8004, but not 0x018005;
     *                  - the function sets the seed of the CRC generator. This is the initial data present in the
     *                   CRC shift register before the CRC calculation begins. A good initial value is usually 0xffffffff.
     *
     * Note:            - Bit 0 of the generator polynomial is always XOR'ed.
     *                  - When the append mode is set, the attached DMA channel has to have destination size <=4.
     *                    Upon the transfer completion the calculated CRC is stored at the destination address.
     *                  - When append mode is cleared, the DMA transfer occurs normally, and the CRC value is available using
     *                    the CrcResult() function.
     *                  - The CRC module should be configured before enabled.
     *                  - These settings are relevant only when the SFM is configured for the CRC type of checksum.
     *                  - The checksum register is the same for CRC or IP checksum mode. Therefore, this function changes also the seed for the IP checksum.
     *                  - The way the data is fed into the checksum calculation block and the type of the checksum performed is affected by DmaSfmConfigure().
     *
     * Example:         DmaSfmCrcConfigure(0x04c11db7, 32, 0xffffffff);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmCrcConfigure(unsigned int polynomial, int pLen, unsigned int seed)
    {
        DCRCCONCLR=_DCRCCON_PLEN_MASK;
        DCRCCONSET=(pLen-1)<<_DCRCCON_PLEN_POSITION;
        DCRCDATA=seed;
        DCRCXOR=polynomial;
    }

    #define DmaCrcConfigure DmaSfmCrcConfigure  // PIC32_3xx backward compatibility name

    /*********************************************************************
     * Function:        unsigned int DmaSfmChecksum(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          the current value of the checksum generator.
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the calculated checksum value.
     *
     * Note:            - The function returns the valid checksum result. The masking out the unused MSbits in the checksum register is done by the hardware.
     *                  - The way the data is fed into the checksum calculation block and the type of the checksum performed is affected by DmaSfmConfigure().
     *
     * Example:         unsigned int myChk=DmaSfmChecksum();
     ********************************************************************/
    extern __inline__ int __attribute__((always_inline)) DmaSfmChecksum(void)
    {
        return DCRCDATA;
    }
    #define     CrcResult   DmaSfmChecksum      // PIC32_3xx backward compatibility name
    #define     DmaCrcGetValue  DmaSfmChecksum      // PIC32_3xx backward compatibility name


    /*********************************************************************
     * Function:        void DmaSfmSetSeed(unsigned int seed)
     *
     * PreCondition:    None
     *
     * Input:           seed    - the initial seed of the checksum generator
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the seed of the checksum generator. This is the initial data present in the
     *                  CRC shift register or the IP checksum calculator before the actual transfer/calculation begins.
     *
     * Note:            When the SFM is configured for IP checksum mode, only the least significant 16 bits are relevant.
     *
     * Example:         DmaSfmSetSeed(0xffffffff);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmSetSeed(unsigned int seed)
    {
        DCRCDATA=seed;
    }
    #define     DmaCrcSetSeed   DmaSfmSetSeed       // PIC32_3xx backward compatibility name


/*********************  end of high level functions ****************************************/

    // low level definitions for the API functions


    typedef struct
    {
        union
        {
            struct
            {
                unsigned int chn:   3;      // last active DMA channel
                unsigned int rdOp:  1;      // last DMA operation, read if 1, write if 0
            };
            unsigned int    w;                      // word access
        }lastAccess;
        void*   lastAddress;        // most recent DMA address
    }DmaStatus;         // DMA controller status

    typedef enum
    {
        DMA_GFLG_SUSPEND =  _DMACON_SUSPEND_MASK,   // suspend DMA controller operation
        DMA_GFLG_ON =       _DMACON_ON_MASK,        // DMA module enabled/desabled
        //
        DMA_GFLG_ALL_FLAGS= DMA_GFLG_SUSPEND|DMA_GFLG_ON        // all flags
    }DmaGlblFlags;  // flags for controlling global DMA controller behavior. From processor header file.




    typedef enum
    {
        DMA_EV_ABORT_IRQ_EN =       _DCH0ECON_AIRQEN_MASK,
        DMA_EV_START_IRQ_EN =       _DCH0ECON_SIRQEN_MASK,
        // use DMA_EV_START_IRQ() and DMA_EV_ABORT_IRQ() below for selecting
        // the start and abort IRQ signals
        DMA_EV_MATCH_EN =           _DCH0ECON_PATEN_MASK,


        // compiler use only field
        _DMA_EV_MAX_MASK =     _DCH0ECON_CHAIRQ_MASK,
    }DmaEvCtrlFlags;    /*DMA channel event control fields accessible as flags also
                          part of DmaEvCtrlFlags:
                        */
    #define DMA_EV_START_IRQ(irq)   (DMA_EV_START_IRQ_EN | ((irq)<<_DCH0ECON_CHSIRQ_POSITION))  // NOTE: irq has to be a symbol from the processor header file
    #define DMA_EV_ABORT_IRQ(irq)   (DMA_EV_ABORT_IRQ_EN | ((irq)<<_DCH0ECON_CHAIRQ_POSITION))  // NOTE: irq has to be a symbol from the processor header file

    // DMA channel event control as a structure:
    #define DmaEvCtrl   __DCH0ECONbits_t




    typedef enum
    {
        DMA_CTL_AUTO_EN =       _DCH0CON_CHAEN_MASK,
        DMA_CTL_CHAIN_EN =      _DCH0CON_CHCHN_MASK,
        DMA_CTL_DET_EN =        _DCH0CON_CHAED_MASK,
        DMA_CTL_CHN_EN =        _DCH0CON_CHEN_MASK,
        DMA_CTL_CHAIN_DIR =     _DCH0CON_CHCHNS_MASK,
        // use the DMA_CTL_PRI() below for selecting the DMA
        // channel priority
    }DmaChnCtrlFlags;   // controlling the DMA channel with flags
    // also part of DmaChnCtrlFlags:
    #define DMA_CTL_PRI(pri)    ((pri)&_DCH0CON_CHPRI_MASK) // DMA Control channel priority

    // DMA channel control as a structure:
    #define DmaChnCtrl      __DCH0CONbits_t

    typedef struct
    {
        void*   vSrcAdd;        // source of the DMA transfer, virtual
        void*   vDstAdd;        // destination of the DMA transfer, virtual
        int srcSize;        // source buffer size, 1 to DmaGetMaxTxferSize() bytes. Wrapped around.
        int dstSize;        // destination buffer size, 1 to DmaGetMaxTxferSize() bytes. Wrapped around.
        int cellSize;       // no of bytes txferred per event, 1 to DmaGetMaxTxferSize().
    }DmaTxferCtrl;      // transfer setting: the transfer source, destination addresses and size, cell size


    /********************** low level DMA channel functions *******************************/



    // Global DMA controller functions

    /*********************************************************************
     * Function:        void DmaEnable(int enable)
     *
     * PreCondition:    None
     *
     * Input:           enable - boolean to enable/disable the DMA controller
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:       The function enables/disables the DMA controller.
     *
     * Note:           None.
     *
     * Example:        DmaEnable(1);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaEnable(int enable)
    {
        if(enable)
        {
            DMACONSET=_DMACON_ON_MASK;
        }
        else
        {
            DMACONCLR=_DMACON_ON_MASK;
            while(DMACONbits.ON);       // wait to take effect
        }
    }

    /*********************************************************************
     * Function:        void DmaReset(void)
     *
     * PreCondition:    None
     *
     * Input:       None
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function resets the DMA controller.
     *
     * Note:            None.
     *
     * Example:        DmaReset();
     ********************************************************************/
    #define            DmaReset()   DmaEnable(0)


    /*********************************************************************
     * Function:        int DmaSuspend(void)
     *
     * PreCondition:    None
     *
     * Input:       None
     *
     * Output:          true if the DMA was previously suspended, false otherwise
     *
     *
     * Side Effects:    None
     *
     * Overview:        The function suspends the DMA controller.
     *
     * Note:            After the execution of this function the DMA operation is supposed to be suspended.
     *                  I.e. the function has to wait for the suspension to take place!
     *
     * Example:         int susp=DmaSuspend();
     ********************************************************************/
        extern __inline__ int __attribute__((always_inline)) DmaSuspend(void)
    {
        int suspSt;
        if(!(suspSt=DMACONbits.SUSPEND))
        {
            DMACONSET=_DMACON_SUSPEND_MASK;     // suspend
            while((DMACONbits.DMABUSY));    // wait to be actually suspended
        }
        return suspSt;
    }



    /*********************************************************************
     * Function:        void DmaResume(int susp)
     *
     * PreCondition:    None
     *
     * Input:       the desired DMA suspended state.
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function restores the DMA controller activity to the old suspended mode.
     *
     * Note:            None.
     *
     * Example:         int isSusp=DmaSuspend(); {....}; DmaResume(isSusp);
     ********************************************************************/
        extern __inline__ void __attribute__((always_inline)) DmaResume(int susp)
    {
        if(susp)
        {
            DmaSuspend();
        }
        else
        {
            DMACONCLR=_DMACON_SUSPEND_MASK;     // resume DMA activity
        }
    }


    /*********************************************************************
     * Function:        void DmaSetGlobalFlags(DmaGlblFlags gFlags)
     *
     * PreCondition:    None
     *
     * Input:           gFlags - flags to be set, having the following fields:
     *          - DMA_GFLG_SUSPEND: DMA controller operation suspend
     *          - DMA_GFLG_ON: DMA controller enabled/desabled
     *          - DMA_GFLG_ALL_FLAGS: all flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function affects the global behavior of the DMA controller.
     *                  It sets the specified flags. Any flag that is set in the gFlags will be
     *                  enabled, the other flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         DmaSetGlobalFlags(DMA_GFLG_ON);
     ********************************************************************/
        extern __inline__ void __attribute__((always_inline)) DmaSetGlobalFlags(DmaGlblFlags gFlags)
    {
        DMACONSET=gFlags;
    }

    /*********************************************************************
     * Function:        void DmaClrGlobalFlags(DmaGlblFlags gFlags)
     *
     * PreCondition:    None
     *
     * Input:           gFlags - flags to be cleared, having the following fields:
     *                               - DMA_GFLG_SUSPEND: DMA controller operation suspend
     *                               - DMA_GFLG_ON: DMA controller enabled/desabled
     *                               - DMA_GFLG_ALL_FLAGS: all flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function affects the global behavior of the DMA controller.
     *                  It clears the specified flags. Any flag that is set in the gFlags will be
     *                  cleared, the other flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         DmaClrGlobalFlags(DMA_GFLG_SUSPEND);
     ********************************************************************/
        extern __inline__ void __attribute__((always_inline)) DmaClrGlobalFlags(DmaGlblFlags gFlags)
    {
        DMACONCLR=gFlags;
    }


    /*********************************************************************
     * Function:        void DmaWriteGlobalFlags(DmaGlblFlags gFlags)
     *
     * PreCondition:    None
     *
     * Input:           gFlags - flags to be set, having the following fields:
     *                                 - DMA_GFLG_SUSPEND: DMA controller operation suspend
     *                                 - DMA_GFLG_ON: DMA controller enabled/desabled
     *                                 - DMA_GFLG_ALL_FLAGS: all flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function affects the global behavior of the DMA controller.
     *                  It forces the flags to have the specified gFlags value.
     *
     * Note:            None.
     *
     * Example:         DmaWriteGlobalFlags(DMA_GFLG_ALL_FLAGS);
     ********************************************************************/
        extern __inline__ void __attribute__((always_inline)) DmaWriteGlobalFlags(DmaGlblFlags gFlags)
    {
        DMACON=gFlags;
    }

    /*********************************************************************
     * Function:        DmaGlblFlags DmaGetGlobalFlags(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          The current DMA controller flags settings.
     *                              - DMA_GFLG_SUSPEND: DMA controller operation suspend
     *                              - DMA_GFLG_ON: DMA controller enabled/desabled
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the global flags of the DMA controller.
     *
     * Note:            None.
     *
     * Example:         DmaGlblFlags dmaFlags=DmaGetGlobalFlags();
     ********************************************************************/
        extern __inline__ DmaGlblFlags __attribute__((always_inline)) DmaGetGlobalFlags(void)
    {
        return (DmaGlblFlags)DMACON;
    }


    /*********************************************************************
     * Function:        int DmaGetMaxTxferSize(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          The maximum transfer capacity for a DMA channel, in bytes.
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the maximum number of bytes that can be transferred by a DMA channel.
     *
     * Note:            Revision dependant.
     *
     * Example:         int dmaMaxSz=DmaGetMaxTxferSize();
     ********************************************************************/
    extern __inline__ int __attribute__((always_inline)) DmaGetMaxTxferSize(void)
    {
        return 65536;
    }

    // Direct Channel control functions

    typedef enum
    {
        DMA_CONFIG_DEFAULT = 0,                             // DMA default operation
        DMA_CONFIG_AUTO = _DCH0CON_CHAEN_MASK,              // DMA channel is auto enabled
        DMA_CONFIG_CHAIN_LOW  = (_DCH0CON_CHCHN_MASK|_DCH0CON_CHCHNS_MASK), // DMA channel is chained to lower channel
        DMA_CONFIG_CHAIN_HI  = (_DCH0CON_CHCHN_MASK),       // DMA channel is chained to higher channel
        DMA_CONFIG_DET_EN = _DCH0CON_CHAED_MASK,            // events detection enabled while channel off
        DMA_CONFIG_ENABLE = _DCH0CON_CHEN_MASK,             // DMA channel is enabled after open
        DMA_CONFIG_MATCH    = 0x80000000,                   // DMA channel stops on match
    }DmaConfigFlags;    // flags for the channel configuration


    // Low level checksum functions

    /*********************************************************************
     * Function:        void DmaSfmEnable(int enable)
     *
     * PreCondition:    None
     *
     * Input:           enable _ boolean to enable/disable the SFM functionality
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function enables/diables the checksum module functionality.
     *                  When enabled the attached DMA channel transfers are routed to the SFM module.
     *
     * Note:            The SFM module should be properly configured before enabled.
     *
     * Example:         DmaSfmEnable(1);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmEnable(int enable)
    {
        if(enable)
        {
            DCRCCONSET=_DCRCCON_CRCEN_MASK;
        }
        else
        {
            DCRCCONCLR=_DCRCCON_CRCEN_MASK;
        }
    }
    #define DmaCrcEnable    DmaSfmEnable        // PIC32_3xx backward compatibility


    /*********************************************************************
     * Function:        int DmaSfmGetEnable(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          TRUE, if the SFM module is enabled
     *          FALSE otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the SFM module enabling status.
     *
     * Note:            None
     *
     * Example:     int isSfmEnabled=DmaSfmGetEnable();
     ********************************************************************/
    extern __inline__ int __attribute__((always_inline)) DmaSfmGetEnable(void)
    {
        return DCRCCONbits.CRCEN!=0;
    }
    #define     DmaCrcGetEnable     DmaSfmGetEnable     // PIC32_3xx backward compatibility


    /*********************************************************************
     * Function:        void DmaSfmAppendEnable(int enable)
     *
     * PreCondition:    None
     *
     * Input:           enable _ boolean to enable/disable the SFM append mode
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function enables the SFM append mode. In this mode, the attached DMA channel reads
     *                  the source data but does not write it to the destination address. The data it's just passed
     *                  to the checksum generator for CRC/IP checksum calculation.
     *                  When the block transfer is completed, the checksum result is written to the
     *                  DMA channel destination address.
     *
     * Note:            The SFM module should be properly configured before enabled.
     *
     * Example:         DmaSfmAppendModeEnable(TRUE);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmAppendEnable(int enable)
    {
        if(enable)
        {
            DCRCCONSET=_DCRCCON_CRCAPP_MASK;
        }
        else
        {
            DCRCCONCLR=_DCRCCON_CRCAPP_MASK;
        }
    }
    #define     DmaCrcAppendModeEnable  DmaSfmAppendEnable  // PIC32_3xx backward compatibility


    /*********************************************************************
     * Function:        int DmaSfmGetAppendMode(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          TRUE, if the SFM append mode is enabled
     *                  FALSE otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the SFM module enabling status.
     *
     * Note:            None
     *
     * Example:         int isAppendEnabled=DmaSfmGetAppendMode();
     ********************************************************************/
    extern __inline__ int __attribute__((always_inline)) DmaSfmGetAppendMode(void)
    {
        return DCRCCONbits.CRCAPP!=0;
    }
    #define DmaCrcGetAppendMode DmaSfmGetAppendMode     // PIC32_3xx backward compatibility


    /*********************************************************************
     * Function:        void DmaSfmSetAttach(DmaChannel chn)
     *
     * PreCondition:    chn     - valid DMA channel
     *
     * Input:           chn - the DMA channel to be attached to the SFM module (the DMA channel transfers will be routed to the SFM module)
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function directly attaches a DMA channel to the SFM module.
     *
     * Note:            None
     *
     * Example:         DmaSfmSetAttach(DMA_CHANNEL3);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmSetAttach(DmaChannel chn)
    {
        DCRCCONCLR=_DCRCCON_CRCCH_MASK;
        DCRCCONSET=chn;
    }
    #define     DmaCrcSetAttach     DmaSfmSetAttach     // PIC32_3xx backward compatibility


    /*********************************************************************
     * Function:        DmaChannel DmaSfmGetAttach(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          the DMA channel that is currently attached to the CRC module
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the DMA channel number that is currently attached to the SFM module.
     *
     * Note:            None
     *
     * Example:         DmaChannel chn=DmaSfmGetAttach();
     ********************************************************************/
    extern __inline__ DmaChannel __attribute__((always_inline)) DmaSfmGetAttach(void)
    {
        return (DmaChannel)DCRCCONbits.CRCCH;
    }
    #define     DmaCrcGetAttach     DmaSfmGetAttach     // PIC32_3xx backward compatibility

    /*********************************************************************
     * Function:        void DmaCrcSetPLen(int pLen)
     *
     * PreCondition:    pLen - valid polynomial length within 1-32
     *
     * Input:           pLen    - the length of the CRC generator polynomial
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The length of the CRC generator polynomial is set as being pLen;
     *
     * Note:            None
     *
     * Example:         DmaCrcSetPLen(32);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaCrcSetPLen(int pLen)
    {
        DCRCCONCLR=_DCRCCON_PLEN_MASK;
        DCRCCONSET=(pLen)-1;
    }

    /*********************************************************************
     * Function:        int DmaCrcGetPLen(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          the length of the CRC generator polynomial
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the current length of the CRC generator polynomial.
     *                  It's always a number between 1 and 32.
     *
     * Note:            None
     *
     * Example:         int polyLen=DmaCrcGetPLen();
     ********************************************************************/
    extern __inline__ int __attribute__((always_inline)) DmaCrcGetPLen(void)
    {
        return  DCRCCONbits.PLEN+1;
    }

    /*********************************************************************
     * Function:        void DmaCrcSetShiftFeedback(unsigned int feedback)
     *
     * PreCondition:    None
     *
     * Input:           feedback - the layout of the CRC generator
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the layout of the shift stages that take place in the CRC generation.
     *                  Setting a bit to 1 enables the XOR input from the MSb (pLen bit) to the selected stage in the shift register.
     *                  If bit is cleared, the selected shift stage gets data directly from the previous stage in the shift register.
     *
     * Note:            Bit 0 of the generator polynomial is always XOR'ed.
     *
     * Example:         DmaCrcSetShiftFeedback(0x04c11db7);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaCrcSetShiftFeedback(unsigned int feedback)
    {
        DCRCXOR=feedback;
    }


    /*********************************************************************
     * Function:        unsigned int DmaCrcGetShiftFeedback(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          the current layout of the CRC generator
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the layout of the shift stages that take place in the CRC generation.
     *                  A bit set to 1 enables the XOR input from the MSb (pLen bit) to the selected stage in the shift register.
     *                  If a bit is cleared, the selected shift stage gets data directly from the previous stage in the shift register.
     *
     * Note:            Bit 0 of the generator polynomial is always XOR'ed.
     *
     * Example:         int feedback=DmaCrcGetShiftFeedback();
     ********************************************************************/
    extern __inline__ unsigned int __attribute__((always_inline)) DmaCrcGetShiftFeedback(void)
    {
        return DCRCXOR;
    }


#else
    #undef _DMA_CHANNELS        // no DMA channels
#endif  // _DMAC0

#endif /*_DMA_5XX_6XX__7XX_H_*/


