#include "ui.h"
#include "os.h"

/*
 * Defines the main menu and idle actions for the app
 */

#if defined(TARGET_NANOS)
static const ux_menu_entry_t menu_main[4];

static const ux_menu_entry_t menu_about[3] = {
    {
        .menu = NULL,
        .callback = NULL,
        .userid = 0,
        .icon = NULL,
        .line1 = "Version",
        .line2 = APPVERSION,
        .text_x = 0,
        .icon_x = 0,
    },

    {
        .menu = menu_main,
        .callback = NULL,
        .userid = 0,
        .icon = &C_icon_back,
        .line1 = "Back",
        .line2 = NULL,
        .text_x = 61,
        .icon_x = 40,
    },

    UX_MENU_END
};

static const ux_menu_entry_t menu_main[4] = {
    {
        .menu = NULL,
        .callback = NULL,
        .userid = 0,
        .icon = NULL,
        .line1 = "Awaiting",
        .line2 = "Commands",
        .text_x = 0,
        .icon_x = 0
    },
    {
        .menu = menu_about,
        .callback = NULL,
        .userid = 0,
        .icon = NULL,
        .line1 = "About",
        .line2 = NULL,
        .text_x = 0,
        .icon_x = 0,
    },

    {
        .menu = NULL,
        .callback = &os_sched_exit,
        .userid = 0,
        .icon = &C_icon_dashboard,
        .line1 = "Quit app",
        .line2 = NULL,
        .text_x = 50,
        .icon_x = 29,
    },

    UX_MENU_END
};
#elif defined(TARGET_NANOX)

#endif // TARGET

void ui_idle(void) {
#if defined(TARGET_NANOS)
    UX_MENU_DISPLAY(0, menu_main, NULL);
#elif defined(TARGET_NANOX)
#endif // #if TARGET_
}
