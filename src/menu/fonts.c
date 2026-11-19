#include "ui_components/theme.h"
#include <libdragon.h>

#include "fonts.h"
#include "utils/fs.h"


static void load_default_font (char *custom_font_path) {
    char *font_path = "rom:/menu/fonts/Firple-Bold.font64";

    if (custom_font_path != NULL && strlen(custom_font_path) > 0) {
        // Only check file_exists if custom_font_path is a valid filesystem path (not rom:/)
        if (strncmp(custom_font_path, "rom:/", 5) != 0 && file_exists(custom_font_path)) {
            font_path = custom_font_path;
        }
    }

    rdpq_font_t *default_font = rdpq_font_load(font_path);

    rdpq_font_style(default_font, STL_DEFAULT, &((rdpq_fontstyle_t) { .color = THEME_TEXT, .outline_color = THEME_TEXT_OUTLINE }));
    rdpq_font_style(default_font, STL_GREEN, &((rdpq_fontstyle_t) { .color = THEME_TEXT_GREEN, .outline_color = THEME_TEXT_OUTLINE }));
    rdpq_font_style(default_font, STL_BLUE, &((rdpq_fontstyle_t) { .color = THEME_TEXT_BLUE, .outline_color = THEME_TEXT_OUTLINE }));
    rdpq_font_style(default_font, STL_YELLOW, &((rdpq_fontstyle_t) { .color = THEME_TEXT_YELLOW, .outline_color = THEME_TEXT_OUTLINE }));
    rdpq_font_style(default_font, STL_ORANGE, &((rdpq_fontstyle_t) { .color = THEME_TEXT_ORANGE, .outline_color = THEME_TEXT_OUTLINE }));
    rdpq_font_style(default_font, STL_RED, &((rdpq_fontstyle_t) { .color = THEME_TEXT_RED, .outline_color = THEME_TEXT_OUTLINE }));
    rdpq_font_style(default_font, STL_GRAY, &((rdpq_fontstyle_t) { .color = THEME_TEXT_GRAY, .outline_color = THEME_TEXT_OUTLINE }));

    rdpq_text_register_font(FNT_DEFAULT, default_font);
}


void fonts_init (char *custom_font_path) {
    load_default_font(custom_font_path);
}
