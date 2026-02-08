/*
 * Copyright (c) 2025 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef ZMK_SPLIT_ESB_STATS_H
#define ZMK_SPLIT_ESB_STATS_H

#include <zephyr/kernel.h>
#include <stdbool.h>

/**
 * ESB statistics structure (TX for peripherals, RX for central)
 */
typedef struct {
    // TX stats (peripheral mode - PTX)
    uint32_t total_transmissions;
    uint32_t successful_transmissions;
    uint32_t failed_transmissions;
    uint32_t retry_count;
    float success_rate;
    uint32_t last_tx_timestamp;
    bool last_tx_succeeded;
    
    // RX stats (central mode - PRX)
    uint32_t total_received;
    uint32_t last_rx_timestamp;
} esb_stats_t;

/**
 * Get current ESB statistics
 * @param stats Pointer to store statistics
 * @return 0 on success, negative error code on failure
 */
int zmk_split_esb_get_stats(esb_stats_t *stats);

/**
 * Reset ESB statistics
 * @return 0 on success, negative error code on failure
 */
int zmk_split_esb_reset_stats(void);

/**
 * Check if ESB is ready for transmission
 * @return true if radio is idle and ready, false otherwise
 */
bool zmk_split_esb_is_ready(void);

#endif /* ZMK_SPLIT_ESB_STATS_H */
