/**
 * @file n64ra.c
 * @brief Install the n64ra RetroAchievements agent
 * @ingroup boot
 *
 * The agent (https://github.com/croissantpigbear/n64ra, n64ra_agent.h) is
 * one blob. Like the cheat engine, it is staged in RDRAM that the reboot
 * keeps, and the end of the game's IPL3 is pointed at its patcher, which
 * moves it to the top of the Expansion Pak, takes over the exception
 * vector and starts the game. Each frame the agent sends the watched
 * memory over the SC64's USB to the n64ra bridge on the PC, through the
 * SC64's data buffer, so ROMs of any size (64 MB included) keep all of SDRAM.
 */

#include <libdragon.h>
#include <string.h>

#include "boot_io.h"
#include "cheats.h"
#include "n64ra.h"
#include "n64ra_agent.h"

#define N64RA_MAGIC         (0x4E365241)

typedef struct {
    uint32_t magic;
    uint32_t version;
    uint32_t final_addr;
    uint32_t size;
    uint32_t patcher;
    uint32_t stage_addr;
    uint32_t rom_size;
    uint32_t flags;
    uint8_t rom_header[64];
} n64ra_header_t;

bool n64ra_install (cic_type_t cic_type, boot_params_t *params) {
    const n64ra_header_t *blob = (const n64ra_header_t *) (n64ra_blob);

    if (blob->magic != N64RA_MAGIC || blob->size > sizeof(n64ra_blob)) {
        return false;
    }
    if (!is_memory_expanded()) {
        return false;
    }

    n64ra_header_t *staged = (n64ra_header_t *) (blob->stage_addr);
    memcpy(staged, n64ra_blob, blob->size);
    staged->rom_size = params->rom_size;
    for (int i = 0; i < 16; i++) {
        uint32_t w = io_read((uint32_t) (&ROM_CART[i]));
        memcpy(&staged->rom_header[i * 4], &w, 4);
    }
    data_cache_hit_writeback(staged, blob->size);

    if (cheats_patch_ipl3(cic_type, (io32_t *) (staged->patcher))) {
        debugf("n64ra: unsupported IPL3, booting without achievements\n");
        return false;
    }

    debugf("n64ra: agent staged at %08lX, patcher %08lX\n", (unsigned long) staged, (unsigned long) staged->patcher);
    return true;
}
