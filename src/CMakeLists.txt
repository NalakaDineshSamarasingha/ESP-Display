SET(SOURCES ui_Screen1.c
    ui_Screen2.c
    ui_Screen3.c
    ui_Screen4.c
    ui_Screen5.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    fonts/ui_font_Font1.c
    fonts/ui_font_Font2.c
    fonts/ui_font_Font3.c
    fonts/ui_font_Font4.c)

add_library(ui ${SOURCES})
