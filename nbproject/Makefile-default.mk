#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WIZNET-W5200-PIC32MX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WIZNET-W5200-PIC32MX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=FILES/APP_SOCKET/app_socket.c FILES/LED/led.c FILES/NVM/nvm.c FILES/PERIPHERAL/PERIPHERAL.c FILES/SPI/spi32mx.c FILES/SPI/spic32mx_drv.c FILES/TIMER/timer.c FILES/WIZNET/wiznetinit.c Ethernet/Ethernet/loopback.c Ethernet/Ethernet/socket.c Ethernet/Ethernet/W5200/w5200.c Ethernet/Ethernet/wizchip_conf.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o ${OBJECTDIR}/FILES/LED/led.o ${OBJECTDIR}/FILES/NVM/nvm.o ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o ${OBJECTDIR}/FILES/SPI/spi32mx.o ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o ${OBJECTDIR}/FILES/TIMER/timer.o ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o ${OBJECTDIR}/Ethernet/Ethernet/loopback.o ${OBJECTDIR}/Ethernet/Ethernet/socket.o ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o.d ${OBJECTDIR}/FILES/LED/led.o.d ${OBJECTDIR}/FILES/NVM/nvm.o.d ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o.d ${OBJECTDIR}/FILES/SPI/spi32mx.o.d ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o.d ${OBJECTDIR}/FILES/TIMER/timer.o.d ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o.d ${OBJECTDIR}/Ethernet/Ethernet/loopback.o.d ${OBJECTDIR}/Ethernet/Ethernet/socket.o.d ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o.d ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o ${OBJECTDIR}/FILES/LED/led.o ${OBJECTDIR}/FILES/NVM/nvm.o ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o ${OBJECTDIR}/FILES/SPI/spi32mx.o ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o ${OBJECTDIR}/FILES/TIMER/timer.o ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o ${OBJECTDIR}/Ethernet/Ethernet/loopback.o ${OBJECTDIR}/Ethernet/Ethernet/socket.o ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=FILES/APP_SOCKET/app_socket.c FILES/LED/led.c FILES/NVM/nvm.c FILES/PERIPHERAL/PERIPHERAL.c FILES/SPI/spi32mx.c FILES/SPI/spic32mx_drv.c FILES/TIMER/timer.c FILES/WIZNET/wiznetinit.c Ethernet/Ethernet/loopback.c Ethernet/Ethernet/socket.c Ethernet/Ethernet/W5200/w5200.c Ethernet/Ethernet/wizchip_conf.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/WIZNET-W5200-PIC32MX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o: FILES/APP_SOCKET/app_socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/APP_SOCKET" 
	@${RM} ${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o.d 
	@${RM} ${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o.d" -o ${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o FILES/APP_SOCKET/app_socket.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/LED/led.o: FILES/LED/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/LED" 
	@${RM} ${OBJECTDIR}/FILES/LED/led.o.d 
	@${RM} ${OBJECTDIR}/FILES/LED/led.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/LED/led.o.d" -o ${OBJECTDIR}/FILES/LED/led.o FILES/LED/led.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/LED/led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/NVM/nvm.o: FILES/NVM/nvm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/NVM" 
	@${RM} ${OBJECTDIR}/FILES/NVM/nvm.o.d 
	@${RM} ${OBJECTDIR}/FILES/NVM/nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/NVM/nvm.o.d" -o ${OBJECTDIR}/FILES/NVM/nvm.o FILES/NVM/nvm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/NVM/nvm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o: FILES/PERIPHERAL/PERIPHERAL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/PERIPHERAL" 
	@${RM} ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o.d 
	@${RM} ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o.d" -o ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o FILES/PERIPHERAL/PERIPHERAL.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/SPI/spi32mx.o: FILES/SPI/spi32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/SPI" 
	@${RM} ${OBJECTDIR}/FILES/SPI/spi32mx.o.d 
	@${RM} ${OBJECTDIR}/FILES/SPI/spi32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/SPI/spi32mx.o.d" -o ${OBJECTDIR}/FILES/SPI/spi32mx.o FILES/SPI/spi32mx.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/SPI/spi32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/SPI/spic32mx_drv.o: FILES/SPI/spic32mx_drv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/SPI" 
	@${RM} ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o.d 
	@${RM} ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/SPI/spic32mx_drv.o.d" -o ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o FILES/SPI/spic32mx_drv.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/SPI/spic32mx_drv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/TIMER/timer.o: FILES/TIMER/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/TIMER" 
	@${RM} ${OBJECTDIR}/FILES/TIMER/timer.o.d 
	@${RM} ${OBJECTDIR}/FILES/TIMER/timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/TIMER/timer.o.d" -o ${OBJECTDIR}/FILES/TIMER/timer.o FILES/TIMER/timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/TIMER/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/WIZNET/wiznetinit.o: FILES/WIZNET/wiznetinit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/WIZNET" 
	@${RM} ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o.d 
	@${RM} ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/WIZNET/wiznetinit.o.d" -o ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o FILES/WIZNET/wiznetinit.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/WIZNET/wiznetinit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Ethernet/Ethernet/loopback.o: Ethernet/Ethernet/loopback.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Ethernet/Ethernet" 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/loopback.o.d 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/loopback.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Ethernet/Ethernet/loopback.o.d" -o ${OBJECTDIR}/Ethernet/Ethernet/loopback.o Ethernet/Ethernet/loopback.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/Ethernet/Ethernet/loopback.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Ethernet/Ethernet/socket.o: Ethernet/Ethernet/socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Ethernet/Ethernet" 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/socket.o.d 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Ethernet/Ethernet/socket.o.d" -o ${OBJECTDIR}/Ethernet/Ethernet/socket.o Ethernet/Ethernet/socket.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/Ethernet/Ethernet/socket.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o: Ethernet/Ethernet/W5200/w5200.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Ethernet/Ethernet/W5200" 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o.d 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o.d" -o ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o Ethernet/Ethernet/W5200/w5200.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o: Ethernet/Ethernet/wizchip_conf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Ethernet/Ethernet" 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o.d 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o.d" -o ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o Ethernet/Ethernet/wizchip_conf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o: FILES/APP_SOCKET/app_socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/APP_SOCKET" 
	@${RM} ${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o.d 
	@${RM} ${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o.d" -o ${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o FILES/APP_SOCKET/app_socket.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/APP_SOCKET/app_socket.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/LED/led.o: FILES/LED/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/LED" 
	@${RM} ${OBJECTDIR}/FILES/LED/led.o.d 
	@${RM} ${OBJECTDIR}/FILES/LED/led.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/LED/led.o.d" -o ${OBJECTDIR}/FILES/LED/led.o FILES/LED/led.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/LED/led.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/NVM/nvm.o: FILES/NVM/nvm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/NVM" 
	@${RM} ${OBJECTDIR}/FILES/NVM/nvm.o.d 
	@${RM} ${OBJECTDIR}/FILES/NVM/nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/NVM/nvm.o.d" -o ${OBJECTDIR}/FILES/NVM/nvm.o FILES/NVM/nvm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/NVM/nvm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o: FILES/PERIPHERAL/PERIPHERAL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/PERIPHERAL" 
	@${RM} ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o.d 
	@${RM} ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o.d" -o ${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o FILES/PERIPHERAL/PERIPHERAL.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/PERIPHERAL/PERIPHERAL.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/SPI/spi32mx.o: FILES/SPI/spi32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/SPI" 
	@${RM} ${OBJECTDIR}/FILES/SPI/spi32mx.o.d 
	@${RM} ${OBJECTDIR}/FILES/SPI/spi32mx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/SPI/spi32mx.o.d" -o ${OBJECTDIR}/FILES/SPI/spi32mx.o FILES/SPI/spi32mx.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/SPI/spi32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/SPI/spic32mx_drv.o: FILES/SPI/spic32mx_drv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/SPI" 
	@${RM} ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o.d 
	@${RM} ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/SPI/spic32mx_drv.o.d" -o ${OBJECTDIR}/FILES/SPI/spic32mx_drv.o FILES/SPI/spic32mx_drv.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/SPI/spic32mx_drv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/TIMER/timer.o: FILES/TIMER/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/TIMER" 
	@${RM} ${OBJECTDIR}/FILES/TIMER/timer.o.d 
	@${RM} ${OBJECTDIR}/FILES/TIMER/timer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/TIMER/timer.o.d" -o ${OBJECTDIR}/FILES/TIMER/timer.o FILES/TIMER/timer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/TIMER/timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/FILES/WIZNET/wiznetinit.o: FILES/WIZNET/wiznetinit.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/FILES/WIZNET" 
	@${RM} ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o.d 
	@${RM} ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/FILES/WIZNET/wiznetinit.o.d" -o ${OBJECTDIR}/FILES/WIZNET/wiznetinit.o FILES/WIZNET/wiznetinit.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/FILES/WIZNET/wiznetinit.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Ethernet/Ethernet/loopback.o: Ethernet/Ethernet/loopback.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Ethernet/Ethernet" 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/loopback.o.d 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/loopback.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Ethernet/Ethernet/loopback.o.d" -o ${OBJECTDIR}/Ethernet/Ethernet/loopback.o Ethernet/Ethernet/loopback.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/Ethernet/Ethernet/loopback.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Ethernet/Ethernet/socket.o: Ethernet/Ethernet/socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Ethernet/Ethernet" 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/socket.o.d 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Ethernet/Ethernet/socket.o.d" -o ${OBJECTDIR}/Ethernet/Ethernet/socket.o Ethernet/Ethernet/socket.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/Ethernet/Ethernet/socket.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o: Ethernet/Ethernet/W5200/w5200.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Ethernet/Ethernet/W5200" 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o.d 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o.d" -o ${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o Ethernet/Ethernet/W5200/w5200.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/Ethernet/Ethernet/W5200/w5200.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o: Ethernet/Ethernet/wizchip_conf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/Ethernet/Ethernet" 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o.d 
	@${RM} ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o.d" -o ${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o Ethernet/Ethernet/wizchip_conf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/Ethernet/Ethernet/wizchip_conf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/WIZNET-W5200-PIC32MX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WIZNET-W5200-PIC32MX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/WIZNET-W5200-PIC32MX.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WIZNET-W5200-PIC32MX.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/WIZNET-W5200-PIC32MX.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
