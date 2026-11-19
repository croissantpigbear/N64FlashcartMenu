/**
 * @file n64ra.h
 * @brief RetroAchievements agent (n64ra)
 * @ingroup boot
 */
#ifndef N64RA_BOOT_H__
#define N64RA_BOOT_H__

#include <stdbool.h>

#include "boot.h"
#include "cic.h"

bool n64ra_install (cic_type_t cic_type, boot_params_t *params);

#endif
