/*
 *  ======== ti_radio_config.h ========
 *  Configured RadioConfig module definitions
 *
 *  DO NOT EDIT - This file is generated for the CC1352P1F3RGZ
 *  by the SysConfig tool.
 *  
 *  Radio Config module version : 1.3
 *  SmartRF Studio data version : 2.15.0
 */
#ifndef _TI_RADIO_CONFIG_H_
#define _TI_RADIO_CONFIG_H_

#include <ti/devices/DeviceFamily.h>
#include DeviceFamily_constructPath(driverlib/rf_mailbox.h)
#include DeviceFamily_constructPath(driverlib/rf_common_cmd.h)
#include DeviceFamily_constructPath(driverlib/rf_prop_cmd.h)
#include <ti/drivers/rf/RF.h>


//*********************************************************************************
//  RF Setting:   5 kbps, SimpleLink Long Range (20 kchip/s, 2-GFSK, conv. FEC r=1/2 K=7, DSSS SF=2, Tx dev.: 5 kHz, Rx BW: 34 kHz)
//
//  PHY:          slr5kbps2gfsk     
//  Setting file: setting_tc880.json
//*********************************************************************************

// TX Power table size definition
#define TX_POWER_TABLE_SIZE_slr5kbps2gfsk_0 26

// TX Power Table Object
extern RF_TxPowerTable_Entry txPowerTable_slr5kbps2gfsk_0[];

// TI-RTOS RF Mode Object
extern RF_Mode RF_prop_slr5kbps2gfsk_0;

// RF Core API commands
extern rfc_CMD_PROP_RADIO_DIV_SETUP_PA_t RF_cmdPropRadioDivSetup_slr5kbps2gfsk_0;
extern rfc_CMD_FS_t RF_cmdFs_slr5kbps2gfsk_0;
extern rfc_CMD_PROP_TX_t RF_cmdPropTx_slr5kbps2gfsk_0;
extern rfc_CMD_PROP_RX_ADV_t RF_cmdPropRxAdv_slr5kbps2gfsk_0;

// RF Core API Overrides
extern uint32_t pOverrides_slr5kbps2gfsk_0[];
extern uint32_t pOverrides_slr5kbps2gfsk_0TxStd[];
extern uint32_t pOverrides_slr5kbps2gfsk_0Tx20[];

#endif // _TI_RADIO_CONFIG_H_
