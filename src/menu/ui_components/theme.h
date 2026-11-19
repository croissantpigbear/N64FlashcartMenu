/**
 * @file theme.h
 * @brief Colour themes (n64ra): Trophy Night (default) and Gold Rush.
 * @ingroup ui_components
 *
 * Chosen at build time: make THEME=trophynight (default) or THEME=goldrush.
 * Each theme also has a built-in background, shown until you set your own.
 */
#ifndef THEME_H__
#define THEME_H__

#if defined(THEME_GOLDRUSH)
/* Gold Rush: cream and gold, dark ink */
#define THEME_BACKGROUND_SPRITE     "rom:/menu/sprites/theme_goldrush.sprite"
#define THEME_BG                    RGBA32(0xF7, 0xF1, 0xE4, 0xFF)
#define THEME_OVERLAY               RGBA32(0xF7, 0xF1, 0xE4, 0x90)
#define THEME_BORDER                RGBA32(0xD6, 0x96, 0x1C, 0xFF)
#define THEME_PANEL                 RGBA32(0xFF, 0xFC, 0xF4, 0xFF)
#define THEME_PANEL_DIM             RGBA32(0xE2, 0xD6, 0xBE, 0xFF)
#define THEME_PANEL_MID             RGBA32(0xCD, 0xBE, 0xA0, 0xFF)
#define THEME_HIGHLIGHT             RGBA32(0xEE, 0xDA, 0xA8, 0xFF)
#define THEME_ACCENT                RGBA32(0xD6, 0x96, 0x1C, 0xFF)
#define THEME_TEXT                  RGBA32(0x28, 0x22, 0x1A, 0xFF)
#define THEME_TEXT_GREEN            RGBA32(0x1E, 0x78, 0x3C, 0xFF)
#define THEME_TEXT_BLUE             RGBA32(0x1E, 0x5A, 0xAA, 0xFF)
#define THEME_TEXT_YELLOW           RGBA32(0xA8, 0x6C, 0x08, 0xFF)
#define THEME_TEXT_ORANGE           RGBA32(0xBE, 0x5A, 0x0A, 0xFF)
#define THEME_TEXT_RED              RGBA32(0xB4, 0x1E, 0x1E, 0xFF)
#define THEME_TEXT_GRAY             RGBA32(0x78, 0x68, 0x50, 0xFF)
#define THEME_TEXT_OUTLINE          RGBA32(0xFF, 0xFC, 0xF4, 0xFF)
#else
/* Trophy Night: deep navy and trophy gold */
#define THEME_BACKGROUND_SPRITE     "rom:/menu/sprites/theme_trophynight.sprite"
#define THEME_BG                    RGBA32(0x0D, 0x13, 0x24, 0xFF)
#define THEME_OVERLAY               RGBA32(0x0D, 0x13, 0x24, 0x80)
#define THEME_BORDER                RGBA32(0xF2, 0xB3, 0x3D, 0xFF)
#define THEME_PANEL                 RGBA32(0x11, 0x1A, 0x30, 0xFF)
#define THEME_PANEL_DIM             RGBA32(0x16, 0x20, 0x3C, 0xFF)
#define THEME_PANEL_MID             RGBA32(0x1E, 0x2A, 0x4A, 0xFF)
#define THEME_HIGHLIGHT             RGBA32(0x26, 0x36, 0x60, 0xFF)
#define THEME_ACCENT                RGBA32(0xF2, 0xB3, 0x3D, 0xFF)
#define THEME_TEXT                  RGBA32(0xE8, 0xEC, 0xF6, 0xFF)
#define THEME_TEXT_GREEN            RGBA32(0x78, 0xDC, 0x96, 0xFF)
#define THEME_TEXT_BLUE             RGBA32(0x82, 0xB4, 0xFF, 0xFF)
#define THEME_TEXT_YELLOW           RGBA32(0xF2, 0xB3, 0x3D, 0xFF)
#define THEME_TEXT_ORANGE           RGBA32(0xFF, 0x96, 0x3C, 0xFF)
#define THEME_TEXT_RED              RGBA32(0xFF, 0x5A, 0x5A, 0xFF)
#define THEME_TEXT_GRAY             RGBA32(0x8F, 0x9A, 0xB8, 0xFF)
#define THEME_TEXT_OUTLINE          RGBA32(0x05, 0x08, 0x12, 0xFF)
#endif

#endif /* THEME_H__ */
