
/*
 *  ======== ti_easylink_config.c ========
 *  Configured EasyLink module definitions
 *
 *  DO NOT EDIT - This file is generated for the CC1352P_2_LAUNCHXL
 *  by the SysConfig tool.
 */

/***** Includes *****/
#include "easylink/EasyLink.h"
#include <stdint.h>

/* TI Drivers */
#include <ti/drivers/rf/RF.h>

/* RF Studio */
#include <ti_radio_config.h>

EasyLink_RfSetting EasyLink_supportedPhys[] = {
    {
        .EasyLink_phyType = EasyLink_Phy_Custom,
        .RF_pProp = &RF_prop_slr5kbps2gfsk_0,
        .RF_uCmdPropRadio.RF_pCmdPropRadioDivSetup = &RF_cmdPropRadioDivSetup_slr5kbps2gfsk_0,
        .RF_pCmdFs = &RF_cmdFs_slr5kbps2gfsk_0,
        .RF_pCmdPropTx = &RF_cmdPropTx_slr5kbps2gfsk_0,
        .RF_pCmdPropTxAdv = NULL,
        .RF_pCmdPropRxAdv = &RF_cmdPropRxAdv_slr5kbps2gfsk_0,
        .RF_pTxPowerTable = txPowerTable_slr5kbps2gfsk_0,
        .RF_txPowerTableSize = TX_POWER_TABLE_SIZE_slr5kbps2gfsk_0,
    },
};

const uint8_t EasyLink_numSupportedPhys = sizeof(EasyLink_supportedPhys)/sizeof(EasyLink_RfSetting);
