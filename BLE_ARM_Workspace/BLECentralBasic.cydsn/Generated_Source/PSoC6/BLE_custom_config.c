/***************************************************************************//**
* \file CY_BLE_custom_config.c
* \version 2.20
* 
* \brief
*  This file contains the source code of initialization of the config structure for
*  the Custom Service.
*
********************************************************************************
* \copyright
* Copyright 2017-2019, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ble/cy_ble_custom.h"

#if (CY_BLE_MODE_PROFILE && defined(CY_BLE_CUSTOM))
#ifdef CY_BLE_CUSTOM_SERVER
/* If any Custom Service with custom characteristics is defined in the
* customizer's GUI, their handles will be present in this array.
*/
/* This array contains attribute handles for the defined Custom Services and their characteristics and descriptors.
   The array index definitions are located in the BLE_custom.h file. */


#endif /* (CY_BLE_CUSTOM_SERVER) */

#ifdef CY_BLE_CUSTOM_CLIENT

static const cy_stc_ble_uuid128_t cy_ble_customUuid128[] = {
    /* LED */
    { {0x41u, 0x2Fu, 0xF8u, 0xD4u, 0x17u, 0xCDu, 0x2Bu, 0xA3u, 0xDAu, 0x44u, 0xDBu, 0xBCu, 0x23u, 0x57u, 0x3Du, 0x84u} },
    /* GREEN */
    { {0x10u, 0xBBu, 0x3Du, 0x88u, 0x82u, 0x8Bu, 0x28u, 0x80u, 0xEDu, 0x48u, 0x61u, 0xF6u, 0xD8u, 0xBDu, 0xB9u, 0xA6u} },
};

static const cy_ble_uuid16_t cy_ble_customUuid16[] = {
    /* Characteristic User Description */
    0x2901u,
};

static cy_stc_ble_customc_desc_t cy_ble_customCDesc[0x01u] = {

    /* Characteristic User Description */
    {
        .descHandle = {CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE}, /* Descriptor handle */ 
        .uuid       = (const cy_ble_uuid16_t *) &cy_ble_customUuid16[0], /* 16-bit UUID */ 
        .uuidFormat = 0x01u, /* UUID Format - 16-bit (0x01) or 128-bit (0x02) */ 
    },
};

static cy_stc_ble_customc_char_t cy_ble_customCChar[0x01u] = {

    /* GREEN */
    {
        .customServCharHandle    = {CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE}, /* Characteristic handle */ 
        .customServCharEndHandle = {CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE}, /* Characteristic end handle */ 
        .uuid                    = (const cy_stc_ble_uuid128_t *) &cy_ble_customUuid128[1], /* 128-bit UUID */ 
        .uuidFormat              = 0x02u, /* UUID Format - 16-bit (0x01) or 128-bit (0x02) */ 
        .properties              = {0x00u}, /* Characteristic properties */ 
        .descCount               = 0x01u, /* Number of descriptors */ 
        .customServCharDesc      = &cy_ble_customCDesc[0], /* Characteristic Descriptors */ 
    },
};

cy_stc_ble_customc_t cy_ble_customCServ[CY_BLE_CUSTOMC_SERVICE_COUNT] = {

    /* LED */
    {
        .customServHandle = {CY_BLE_GATT_INVALID_ATTR_HANDLE_VALUE}, /* Custom Service handle */ 
        .uuid             = (const cy_stc_ble_uuid128_t *) &cy_ble_customUuid128[0], /* 128-bit UUID */ 
        .uuidFormat       = 0x02u, /* UUID Format - 16-bit (0x01) or 128-bit (0x02) */ 
        .charCount        = 0x01u, /* Number of characteristics */ 
        .customServChar   = &cy_ble_customCChar[0], /* Custom Service Characteristics */ 
    },
};


#endif /* (CY_BLE_CUSTOM_CLIENT) */

/**
* \addtogroup group_globals
* @{
*/

/** The configuration structure for the Custom Services. */
cy_stc_ble_custom_config_t cy_ble_customConfig =
{
    /* Custom Services GATT DB handles structure */
    #ifdef CY_BLE_CUSTOM_SERVER
    .customs      = cy_ble_customs,
    #endif /* (CY_BLE_CUSTOM_SERVER) */

    /* Custom Service handle */
    #ifdef CY_BLE_CUSTOM_CLIENT
    .customc  = cy_ble_customCServ,
    #endif /* (CY_BLE_CUSTOM_CLIENT) */
};

/** @} group_globals */
#endif /* (CY_BLE_MODE_PROFILE && defined(CY_BLE_CUSTOM)) */

/* [] END OF FILE */
