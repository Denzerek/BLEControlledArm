/***************************************************************************//**
* \file CY_BLE.c
* \version 2.20
* 
* \brief
*  This file contains the source code of initialization of the config structure
*  for BLE.
* 
********************************************************************************
* \copyright
* Copyright 2017-2019, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "BLE_config.h"

#if (CY_BLE_HOST_CONTR_CORE)    
#include "flash/cy_flash.h"
#include "ble/cy_ble_event_handler.h"
#include "cyfitter_sysint_cfg.h"

#if (CY_BLE_MODE_PROFILE)
/***************************************
* Global Variables
***************************************/
/* Initializes the cy_stc_ble_gapp_disc_mode_info_t cy_ble_discoveryModeInfo  structure */
#if (CY_BLE_GAP_ROLE_PERIPHERAL || CY_BLE_GAP_ROLE_BROADCASTER)
static cy_stc_ble_gapp_adv_params_t cy_ble_gappAdvConfig[0x01u] = {

    /* Peripheral configuration 0 */
    {
        .fastAdvIntervalMin                 = 0x0020u, 
        .fastAdvIntervalMax                 = 0x0030u, 
        .fastAdvTimeOut                     = 0x0000u, 
        .slowAdvEnable                      = 0x00u, 
        .slowAdvIntervalMin                 = 0x0640u, 
        .slowAdvIntervalMax                 = 0x4000u, 
        .slowAdvTimeOut                     = 0x0096u, 
    },
};


cy_stc_ble_gapp_disc_param_t cy_ble_discoveryParam[0x01u] = {

    /* Peripheral configuration 0 */
    {
        0x0020u, /* uint16_t advertising_interval_min */ 
        0x0030u, /* uint16_t advertising_interval_max */ 
        CY_BLE_GAPP_CONNECTABLE_UNDIRECTED_ADV, /* uint8_t advertising_type */ 
        0x00u, /* uint8_t own_addr_type */ 
        0x00u, /* uint8_t direct_addr_type */ 
        {0x00u, 0x00u, 0x00u, 0x50u, 0xA0u, 0x00u}, /* uint8_t* direct_addr */ 
        0x07u, /* uint8_t advertising_channel_map */ 
        0x00u, /* uint8_t advertising_filter_policy */ 
    },
};


cy_stc_ble_gapp_disc_data_t cy_ble_discoveryData[0x01u] = {

    /* Peripheral configuration 0 */
    {
        { 0x02u, 0x01u, 0x06u, 0x07u, 0x09u, 0x42u, 0x4Cu,
        0x45u, 0x41u, 0x72u, 0x6Du, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u }, /* uint8_t advertising_data[CY_BLE_MAX_ADV_DATA_LEN] */ 
        0x0Bu, /* uint8_t adv_data_length */ 
    },
};


cy_stc_ble_gapp_scan_rsp_data_t cy_ble_scanRspData[0x01u] = {

    /* Peripheral configuration 0 */
    {
        { 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
        0x00u, 0x00u, 0x00u }, /* uint8_t scan_rsp_data[CY_BLE_MAX_SCAN_RSP_DATA_LEN] */ 
        0x00u, /* uint8_t scan_rsp_data_length */ 
    },
};


/* This array of type cy_stc_ble_gapp_disc_mode_info_t is present only when the 
   BLE component is configured for Peripheral or Broadcaster GAP roles. 
   It contains the Advertisement settings and also the Advertisement and 
   Scan response data parameters entered in the customizer. This variable
   can be used by advanced users to change Advertisement settings,
   Advertisement or Scan response data in runtime. 
*/
cy_stc_ble_gapp_disc_mode_info_t cy_ble_discoveryModeInfo[0x01u] = {

    /* Peripheral configuration 0 */
    {
        0x02u, /* uint8_t discMode */ 
        &cy_ble_discoveryParam[0], 
        &cy_ble_discoveryData[0], 
        &cy_ble_scanRspData[0], 
        0x0000u, /* uint16_t advTo */ 
    },
};


#endif /* CY_BLE_GAP_ROLE_PERIPHERAL || CY_BLE_GAP_ROLE_BROADCASTER */

/* Initializes the cy_stc_ble_gapc_disc_info_t  cy_ble_discoveryInfo  structure */
#if (CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_OBSERVER)

#endif /* CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_OBSERVER */

#if ((CY_BLE_MODE_PROFILE) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES))

#if(CY_BLE_MODE_PROFILE)
    CY_SECTION(".cy_em_eeprom") CY_ALIGN(CY_FLASH_SIZEOF_ROW) static const cy_stc_ble_flash_storage_t cy_ble_flashStorage =
    {
        { 0x00u }, 
        {{
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        },
        {
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u, 0x00u, 
            0x00u /* CRC */
        }}, 
        0x0Au, /* CY_BLE_GATT_DB_CCCD_COUNT */ 
        0x11u, 
    };
#endif /* (CY_BLE_MODE_PROFILE) */

#endif  /* (CY_BLE_MODE_PROFILE) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES) */

#if (CY_BLE_GATT_ROLE_SERVER)
static const cy_stc_ble_gatts_t cy_ble_gatts =
{
    0x000Cu,    /* Handle of the GATT service */
    0x000Eu,    /* Handle of the Service Changed characteristic */
    0x000Fu,    /* Handle of the Client Characteristic Configuration descriptor */
};
static const cy_stc_ble_gaps_t cy_ble_gaps =
{
    0x0001u,    /* Handle of the GAP service */
    0x0003u,    /* Handle of the Device Name characteristic */
    0x0005u,    /* Handle of the Appearance characteristic */
    0x0007u,    /* Handle of the Peripheral Preferred Connection Parameters characteristic */
    0x0009u,    /* Handle of the Central Address Resolution characteristic */
    0x000Bu,    /* Handle of the Resolvable Private Address Only characteristic */
};
static uint8_t cy_ble_attValues[0xA6u] = {
    /* Device Name */
    (uint8_t)'B', (uint8_t)'L', (uint8_t)'E', (uint8_t)'A', (uint8_t)'r', (uint8_t)'m', 

    /* Appearance */
    0x00u, 0x00u, 

    /* Peripheral Preferred Connection Parameters */
    0x06u, 0x00u, 0x28u, 0x00u, 0x00u, 0x00u, 0xE8u, 0x03u, 

    /* Central Address Resolution */
    0x00u, 

    /* Resolvable Private Address Only */
    0x00u, 

    /* Service Changed */
    0x00u, 0x00u, 0x00u, 0x00u, 

    /* M1 */
    0x00u, 

    /* Custom Descriptor */
    0x00u, 0xA3u, 0xCEu, 0xE3u, 0x69u, 0xDBu, 0xF9u, 0xB1u, 0x98u, 0xC0u, 0x49u, 0x84u, 0x43u, 0x46u, 0x99u, 0xE6u, 0x1Au, 

    /* M2 */
    0x00u, 

    /* Custom Descriptor */
    0x00u, 0xA3u, 0xCEu, 0xE3u, 0x69u, 0xDBu, 0xF9u, 0xB1u, 0x98u, 0xC0u, 0x49u, 0x84u, 0x43u, 0x46u, 0x99u, 0xE6u, 0x1Au, 

    /* M1_REL */
    0x00u, 

    /* Custom Descriptor */
    0x00u, 0xA3u, 0xCEu, 0xE3u, 0x69u, 0xDBu, 0xF9u, 0xB1u, 0x98u, 0xC0u, 0x49u, 0x84u, 0x43u, 0x46u, 0x99u, 0xE6u, 0x1Au, 

    /* M2_REL */
    0x00u, 

    /* Custom Descriptor */
    0x00u, 0xA3u, 0xCEu, 0xE3u, 0x69u, 0xDBu, 0xF9u, 0xB1u, 0x98u, 0xC0u, 0x49u, 0x84u, 0x43u, 0x46u, 0x99u, 0xE6u, 0x1Au, 

    /* M3 */
    0x00u, 

    /* Custom Descriptor */
    0x00u, 0xA3u, 0xCEu, 0xE3u, 0x69u, 0xDBu, 0xF9u, 0xB1u, 0x98u, 0xC0u, 0x49u, 0x84u, 0x43u, 0x46u, 0x99u, 0xE6u, 0x1Au, 

    /* M4 */
    0x00u, 

    /* Custom Descriptor */
    0x00u, 0xA3u, 0xCEu, 0xE3u, 0x69u, 0xDBu, 0xF9u, 0xB1u, 0x98u, 0xC0u, 0x49u, 0x84u, 0x43u, 0x46u, 0x99u, 0xE6u, 0x1Au, 

    /* M3_REL */
    0x00u, 

    /* Custom Descriptor */
    0x00u, 0xA3u, 0xCEu, 0xE3u, 0x69u, 0xDBu, 0xF9u, 0xB1u, 0x98u, 0xC0u, 0x49u, 0x84u, 0x43u, 0x46u, 0x99u, 0xE6u, 0x1Au, 

    /* M4_REL */
    0x00u, 

    /* Custom Descriptor */
    0x00u, 0xA3u, 0xCEu, 0xE3u, 0x69u, 0xDBu, 0xF9u, 0xB1u, 0x98u, 0xC0u, 0x49u, 0x84u, 0x43u, 0x46u, 0x99u, 0xE6u, 0x1Au, 

};
#if(CY_BLE_GATT_DB_CCCD_COUNT != 0u)
static uint8_t cy_ble_attValuesCCCD[CY_BLE_GATT_DB_CCCD_COUNT];
#endif /* CY_BLE_GATT_DB_CCCD_COUNT != 0u */

static const uint8_t cy_ble_attUuid128[][16u] = {
    /* MOTOR */
    { 0x52u, 0x08u, 0x46u, 0x60u, 0xF7u, 0xCDu, 0x05u, 0xB8u, 0xA4u, 0x42u, 0xA1u, 0x62u, 0x09u, 0x9Fu, 0x89u, 0x02u },
    /* M1 */
    { 0x3Fu, 0xDAu, 0x0Fu, 0x3Eu, 0x44u, 0x65u, 0xC5u, 0xA4u, 0x67u, 0x48u, 0x7Du, 0xAAu, 0x4Bu, 0x87u, 0xCFu, 0xEBu },
    /* M2 */
    { 0x7Fu, 0xC5u, 0x4Du, 0x39u, 0x68u, 0x7Eu, 0xB4u, 0xA8u, 0x7Bu, 0x4Au, 0x48u, 0x75u, 0xA5u, 0xC2u, 0x12u, 0x34u },
    /* M1_REL */
    { 0x37u, 0x0Du, 0x2Cu, 0x36u, 0xEEu, 0x90u, 0xD7u, 0x8Au, 0x4Bu, 0x44u, 0xC8u, 0xD1u, 0x11u, 0x32u, 0x32u, 0xADu },
    /* M2_REL */
    { 0x36u, 0xACu, 0x71u, 0x39u, 0x21u, 0x56u, 0x80u, 0xA8u, 0x91u, 0x41u, 0x28u, 0xAFu, 0xFDu, 0x8Du, 0x13u, 0xBAu },
    /* M3 */
    { 0xAFu, 0x14u, 0xC3u, 0x7Fu, 0xC1u, 0x01u, 0xE9u, 0xBAu, 0x91u, 0x40u, 0xB9u, 0x20u, 0x20u, 0xC8u, 0x58u, 0xDEu },
    /* M4 */
    { 0x1Cu, 0x2Au, 0x80u, 0x59u, 0x6Au, 0xA0u, 0xFFu, 0x8Au, 0x66u, 0x4Du, 0x5Bu, 0xE1u, 0x25u, 0x54u, 0x17u, 0x15u },
    /* M3_REL */
    { 0x25u, 0x9Au, 0x70u, 0x12u, 0x46u, 0x8Cu, 0x42u, 0xB9u, 0xDEu, 0x46u, 0xF1u, 0x43u, 0x7Cu, 0x35u, 0xD2u, 0xBCu },
    /* M4_REL */
    { 0xA4u, 0xB8u, 0x24u, 0x5Bu, 0x50u, 0x46u, 0xFEu, 0x9Au, 0xC0u, 0x41u, 0xE4u, 0x84u, 0x24u, 0x7Cu, 0x7Du, 0x50u },
};

static cy_stc_ble_gatts_att_gen_val_len_t cy_ble_attValuesLen[0x24u] = {
    { 0x0006u, (void *)&cy_ble_attValues[0] }, /* Device Name */
    { 0x0002u, (void *)&cy_ble_attValues[6] }, /* Appearance */
    { 0x0008u, (void *)&cy_ble_attValues[8] }, /* Peripheral Preferred Connection Parameters */
    { 0x0001u, (void *)&cy_ble_attValues[16] }, /* Central Address Resolution */
    { 0x0001u, (void *)&cy_ble_attValues[17] }, /* Resolvable Private Address Only */
    { 0x0004u, (void *)&cy_ble_attValues[18] }, /* Service Changed */
    { 0x0002u, (void *)&cy_ble_attValuesCCCD[0] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cy_ble_attUuid128[0] }, /* MOTOR UUID */
    { 0x0010u, (void *)&cy_ble_attUuid128[1] }, /* M1 UUID */
    { 0x0001u, (void *)&cy_ble_attValues[22] }, /* M1 */
    { 0x0001u, (void *)&cy_ble_attValues[23] }, /* Custom Descriptor */
    { 0x0002u, (void *)&cy_ble_attValuesCCCD[2] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cy_ble_attUuid128[2] }, /* M2 UUID */
    { 0x0001u, (void *)&cy_ble_attValues[40] }, /* M2 */
    { 0x0001u, (void *)&cy_ble_attValues[41] }, /* Custom Descriptor */
    { 0x0002u, (void *)&cy_ble_attValuesCCCD[4] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cy_ble_attUuid128[3] }, /* M1_REL UUID */
    { 0x0001u, (void *)&cy_ble_attValues[58] }, /* M1_REL */
    { 0x0001u, (void *)&cy_ble_attValues[59] }, /* Custom Descriptor */
    { 0x0010u, (void *)&cy_ble_attUuid128[4] }, /* M2_REL UUID */
    { 0x0001u, (void *)&cy_ble_attValues[76] }, /* M2_REL */
    { 0x0001u, (void *)&cy_ble_attValues[77] }, /* Custom Descriptor */
    { 0x0010u, (void *)&cy_ble_attUuid128[5] }, /* M3 UUID */
    { 0x0001u, (void *)&cy_ble_attValues[94] }, /* M3 */
    { 0x0001u, (void *)&cy_ble_attValues[95] }, /* Custom Descriptor */
    { 0x0002u, (void *)&cy_ble_attValuesCCCD[6] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cy_ble_attUuid128[6] }, /* M4 UUID */
    { 0x0001u, (void *)&cy_ble_attValues[112] }, /* M4 */
    { 0x0001u, (void *)&cy_ble_attValues[113] }, /* Custom Descriptor */
    { 0x0002u, (void *)&cy_ble_attValuesCCCD[8] }, /* Client Characteristic Configuration */
    { 0x0010u, (void *)&cy_ble_attUuid128[7] }, /* M3_REL UUID */
    { 0x0001u, (void *)&cy_ble_attValues[130] }, /* M3_REL */
    { 0x0001u, (void *)&cy_ble_attValues[131] }, /* Custom Descriptor */
    { 0x0010u, (void *)&cy_ble_attUuid128[8] }, /* M4_REL UUID */
    { 0x0001u, (void *)&cy_ble_attValues[148] }, /* M4_REL */
    { 0x0001u, (void *)&cy_ble_attValues[149] }, /* Custom Descriptor */
};

static const cy_stc_ble_gatts_db_t cy_ble_gattDB[0x2Cu] = {
    { 0x0001u, 0x2800u /* Primary service                     */, 0x00000001u /*           */, 0x000Bu, {{0x1800u, NULL}}                           },
    { 0x0002u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0003u, {{0x2A00u, NULL}}                           },
    { 0x0003u, 0x2A00u /* Device Name                         */, 0x01020001u /* rd        */, 0x0003u, {{0x0006u, (void *)&cy_ble_attValuesLen[0]}} },
    { 0x0004u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0005u, {{0x2A01u, NULL}}                           },
    { 0x0005u, 0x2A01u /* Appearance                          */, 0x01020001u /* rd        */, 0x0005u, {{0x0002u, (void *)&cy_ble_attValuesLen[1]}} },
    { 0x0006u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0007u, {{0x2A04u, NULL}}                           },
    { 0x0007u, 0x2A04u /* Peripheral Preferred Connection Par */, 0x01020001u /* rd        */, 0x0007u, {{0x0008u, (void *)&cy_ble_attValuesLen[2]}} },
    { 0x0008u, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x0009u, {{0x2AA6u, NULL}}                           },
    { 0x0009u, 0x2AA6u /* Central Address Resolution          */, 0x01020001u /* rd        */, 0x0009u, {{0x0001u, (void *)&cy_ble_attValuesLen[3]}} },
    { 0x000Au, 0x2803u /* Characteristic                      */, 0x00020001u /* rd        */, 0x000Bu, {{0x2AC9u, NULL}}                           },
    { 0x000Bu, 0x2AC9u /* Resolvable Private Address Only     */, 0x01020001u /* rd        */, 0x000Bu, {{0x0001u, (void *)&cy_ble_attValuesLen[4]}} },
    { 0x000Cu, 0x2800u /* Primary service                     */, 0x00000001u /*           */, 0x000Fu, {{0x1801u, NULL}}                           },
    { 0x000Du, 0x2803u /* Characteristic                      */, 0x00200001u /* ind       */, 0x000Fu, {{0x2A05u, NULL}}                           },
    { 0x000Eu, 0x2A05u /* Service Changed                     */, 0x01200000u /* ind       */, 0x000Fu, {{0x0004u, (void *)&cy_ble_attValuesLen[5]}} },
    { 0x000Fu, 0x2902u /* Client Characteristic Configuration */, 0x030A0101u /* rd,wr     */, 0x000Fu, {{0x0002u, (void *)&cy_ble_attValuesLen[6]}} },
    { 0x0010u, 0x2800u /* Primary service                     */, 0x08000001u /*           */, 0x002Cu, {{0x0010u, (void *)&cy_ble_attValuesLen[7]}} },
    { 0x0011u, 0x2803u /* Characteristic                      */, 0x001A0001u /* rd,wr,ntf */, 0x0014u, {{0x0010u, (void *)&cy_ble_attValuesLen[8]}} },
    { 0x0012u, 0x874Bu /* M1                                  */, 0x091A0101u /* rd,wr,ntf */, 0x0014u, {{0x0001u, (void *)&cy_ble_attValuesLen[9]}} },
    { 0x0013u, 0x9946u /* Custom Descriptor                   */, 0x09000001u /*           */, 0x0013u, {{0x0001u, (void *)&cy_ble_attValuesLen[10]}} },
    { 0x0014u, 0x2902u /* Client Characteristic Configuration */, 0x030A0101u /* rd,wr     */, 0x0014u, {{0x0002u, (void *)&cy_ble_attValuesLen[11]}} },
    { 0x0015u, 0x2803u /* Characteristic                      */, 0x001A0001u /* rd,wr,ntf */, 0x0018u, {{0x0010u, (void *)&cy_ble_attValuesLen[12]}} },
    { 0x0016u, 0xC2A5u /* M2                                  */, 0x091A0101u /* rd,wr,ntf */, 0x0018u, {{0x0001u, (void *)&cy_ble_attValuesLen[13]}} },
    { 0x0017u, 0x9946u /* Custom Descriptor                   */, 0x09000001u /*           */, 0x0017u, {{0x0001u, (void *)&cy_ble_attValuesLen[14]}} },
    { 0x0018u, 0x2902u /* Client Characteristic Configuration */, 0x030A0101u /* rd,wr     */, 0x0018u, {{0x0002u, (void *)&cy_ble_attValuesLen[15]}} },
    { 0x0019u, 0x2803u /* Characteristic                      */, 0x00080001u /* wr        */, 0x001Bu, {{0x0010u, (void *)&cy_ble_attValuesLen[16]}} },
    { 0x001Au, 0x3211u /* M1_REL                              */, 0x09080100u /* wr        */, 0x001Bu, {{0x0001u, (void *)&cy_ble_attValuesLen[17]}} },
    { 0x001Bu, 0x9946u /* Custom Descriptor                   */, 0x09000001u /*           */, 0x001Bu, {{0x0001u, (void *)&cy_ble_attValuesLen[18]}} },
    { 0x001Cu, 0x2803u /* Characteristic                      */, 0x00080001u /* wr        */, 0x001Eu, {{0x0010u, (void *)&cy_ble_attValuesLen[19]}} },
    { 0x001Du, 0x8DFDu /* M2_REL                              */, 0x09080100u /* wr        */, 0x001Eu, {{0x0001u, (void *)&cy_ble_attValuesLen[20]}} },
    { 0x001Eu, 0x9946u /* Custom Descriptor                   */, 0x09000001u /*           */, 0x001Eu, {{0x0001u, (void *)&cy_ble_attValuesLen[21]}} },
    { 0x001Fu, 0x2803u /* Characteristic                      */, 0x001A0001u /* rd,wr,ntf */, 0x0022u, {{0x0010u, (void *)&cy_ble_attValuesLen[22]}} },
    { 0x0020u, 0xC820u /* M3                                  */, 0x091A0101u /* rd,wr,ntf */, 0x0022u, {{0x0001u, (void *)&cy_ble_attValuesLen[23]}} },
    { 0x0021u, 0x9946u /* Custom Descriptor                   */, 0x09000001u /*           */, 0x0021u, {{0x0001u, (void *)&cy_ble_attValuesLen[24]}} },
    { 0x0022u, 0x2902u /* Client Characteristic Configuration */, 0x030A0101u /* rd,wr     */, 0x0022u, {{0x0002u, (void *)&cy_ble_attValuesLen[25]}} },
    { 0x0023u, 0x2803u /* Characteristic                      */, 0x001A0001u /* rd,wr,ntf */, 0x0026u, {{0x0010u, (void *)&cy_ble_attValuesLen[26]}} },
    { 0x0024u, 0x5425u /* M4                                  */, 0x091A0101u /* rd,wr,ntf */, 0x0026u, {{0x0001u, (void *)&cy_ble_attValuesLen[27]}} },
    { 0x0025u, 0x9946u /* Custom Descriptor                   */, 0x09000001u /*           */, 0x0025u, {{0x0001u, (void *)&cy_ble_attValuesLen[28]}} },
    { 0x0026u, 0x2902u /* Client Characteristic Configuration */, 0x030A0101u /* rd,wr     */, 0x0026u, {{0x0002u, (void *)&cy_ble_attValuesLen[29]}} },
    { 0x0027u, 0x2803u /* Characteristic                      */, 0x00080001u /* wr        */, 0x0029u, {{0x0010u, (void *)&cy_ble_attValuesLen[30]}} },
    { 0x0028u, 0x357Cu /* M3_REL                              */, 0x09080100u /* wr        */, 0x0029u, {{0x0001u, (void *)&cy_ble_attValuesLen[31]}} },
    { 0x0029u, 0x9946u /* Custom Descriptor                   */, 0x09000001u /*           */, 0x0029u, {{0x0001u, (void *)&cy_ble_attValuesLen[32]}} },
    { 0x002Au, 0x2803u /* Characteristic                      */, 0x00080001u /* wr        */, 0x002Cu, {{0x0010u, (void *)&cy_ble_attValuesLen[33]}} },
    { 0x002Bu, 0x7C24u /* M4_REL                              */, 0x09080100u /* wr        */, 0x002Cu, {{0x0001u, (void *)&cy_ble_attValuesLen[34]}} },
    { 0x002Cu, 0x9946u /* Custom Descriptor                   */, 0x09000001u /*           */, 0x002Cu, {{0x0001u, (void *)&cy_ble_attValuesLen[35]}} },
};

#endif /* (CY_BLE_GATT_ROLE_SERVER) */

/* Default device security */
#if (CY_BLE_MODE_PROFILE) 
    cy_stc_ble_gap_auth_info_t cy_ble_authInfo[0x01u] = {

    /* Security configuration 0 */
    {
        .security = (CY_BLE_GAP_SEC_MODE_1 | CY_BLE_GAP_SEC_LEVEL_1 ), 
        .bonding = CY_BLE_GAP_BONDING, 
        .ekeySize = 0x10u, 
        .authErr = CY_BLE_GAP_AUTH_ERROR_NONE, 
        .pairingProperties = 0x01u, 
    },
};

#endif /* CY_BLE_MODE_PROFILE */

/** Initialize BLE configuration parameters structure */
static const cy_stc_ble_params_t cy_ble_params =
{
        .txPowerLevelAdv                    = CY_BLE_LL_PWR_LVL_0_DBM,
        .txPowerLevelConn                   = CY_BLE_LL_PWR_LVL_0_DBM,

        .securityIoCapability               = CY_BLE_GAP_IOCAP_DISPLAY_ONLY,
        .securityPairingMethod              = 0x00u,
    
        .siliconDeviceAddressEnabled        = 0x01u,
    
        .gattDbIndexCount                   = 0x002Cu,
};

cy_stc_ble_gap_bd_addr_t cy_ble_deviceAddress = {{0x00u, 0x00u, 0x00u, 0x50u, 0xA0u, 0x00u}, 0x00u };

/**
* \addtogroup group_globals
* @{
*/
#endif /* CY_BLE_MODE_PROFILE */

/** The configuration structure for BLE */
cy_stc_ble_config_t cy_ble_config =
{
#if (CY_BLE_MODE_PROFILE)
    /* Initialize the GAPP structures */
    /* Initialize the cy_stc_ble_gapp_disc_mode_info_t cy_ble_discoveryModeInfo structure */
    #if (CY_BLE_GAP_ROLE_PERIPHERAL || CY_BLE_GAP_ROLE_BROADCASTER)
        .discoveryModeInfo = cy_ble_discoveryModeInfo,
        .gappAdvParams = cy_ble_gappAdvConfig,
    #else
        .discoveryModeInfo = NULL,
    #endif /* CY_BLE_GAP_ROLE_PERIPHERAL || CY_BLE_GAP_ROLE_BROADCASTER */

    /* Initialize the cy_stc_ble_gapc_disc_info_t  cy_ble_discoveryInfo  structure */
    #if (CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_OBSERVER)
        .discoveryInfo = cy_ble_discoveryInfo,
        .gapcScanParams = cy_ble_gapcScanConfig,
    #else
        .discoveryInfo = NULL,
    #endif /* CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_OBSERVER */

    /* Initialize the GATT structures */
    #if ((CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES))
        .flashStorage = &cy_ble_flashStorage,
    #else
        .flashStorage = NULL,
    #endif /* CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL) && (CY_BLE_BONDING_REQUIREMENT == CY_BLE_BONDING_YES */

    #if (CY_BLE_GATT_ROLE_SERVER)
        .gatts            = &cy_ble_gatts,
        .gaps             = &cy_ble_gaps,
        .attValuesCCCD    = cy_ble_attValuesCCCD,
        .gattDB           = cy_ble_gattDB,
    #else
        .gatts            = NULL,
        .attValuesCCCD    = NULL,
        .gattDB           = NULL,
    #endif /* CY_BLE_GATT_ROLE_SERVER */

    #if (CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL)
        /* Initialize the device security structure */
        .authInfo = cy_ble_authInfo,
    #else
        .authInfo = NULL,
    #endif /* (CY_BLE_GAP_ROLE_CENTRAL || CY_BLE_GAP_ROLE_PERIPHERAL */

    /* Initialize the BLE configuration parameters structure */
    .params   = &cy_ble_params,

    /* An application layer event callback function to receive service events from the BLE Component. */
    .callbackFunc   = NULL,
    
    .deviceAddress  = &cy_ble_deviceAddress,
#endif /* CY_BLE_MODE_PROFILE */

#if (CY_BLE_CONFIG_STACK_CONTR_CORE)
    /* The BLESS interrupt configuration */
    .blessIsrConfig = &BLE_1_bless_isr_cfg,
#endif /* CY_BLE_CONFIG_STACK_CONTR_CORE */
};

#endif /* CY_BLE_HOST_CONTR_CORE */ 

/** @} group_globals */

/* [] END OF FILE */
