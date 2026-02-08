/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef __APP_ESB_H
#define __APP_ESB_H

#include <zephyr/kernel.h>

typedef enum {
    APP_ESB_EVT_TX_SUCCESS,
    APP_ESB_EVT_TX_FAIL,
    APP_ESB_EVT_RX
} app_esb_event_type_t;

typedef enum {
    APP_ESB_MODE_PTX,
    APP_ESB_MODE_PRX
} app_esb_mode_t;

typedef struct {
    app_esb_event_type_t evt_type;
    uint8_t *buf;
    uint32_t data_length;
} app_esb_event_t;

typedef struct {
    uint8_t *data;
    uint32_t len;
} app_esb_data_t;

typedef struct {
    app_esb_mode_t mode;
} app_esb_config_t;

typedef void (*app_esb_callback_t)(app_esb_event_t *event);

struct esb_simple_addr {
    uint8_t base_0[4];
    uint8_t base_1[4];
    uint8_t prefix[8];
};

int zmk_split_esb_init(app_esb_mode_t mode, app_esb_callback_t callback);

int zmk_split_esb_set_enable(bool enabled);

int zmk_split_esb_send(app_esb_data_t *tx_packet, uint8_t pipe);


/**
 * ESB transmission statistics
 */
typedef struct {
    uint32_t total_transmissions;
    uint32_t successful_transmissions;
    uint32_t failed_transmissions;
    uint32_t retry_count;
    float success_rate;
    uint32_t last_tx_timestamp;
    bool last_tx_succeeded;
    uint32_t total_received;
    uint32_t last_rx_timestamp;
} esb_stats_t;

/**
 * Get current ESB statistics
 */
int zmk_split_esb_get_stats(esb_stats_t *stats);

/**
 * Reset ESB statistics
 */
int zmk_split_esb_reset_stats(void);

/**
 * Check if ESB is ready for transmission
 */
bool zmk_split_esb_is_ready(void);

#endif
