#pragma once

#include QMK_KEYBOARD_H
// #include "muse.h"
#include "keymap.h"

// =============================================================================
// RGBLIGHT SECTION
// =============================================================================

#ifdef RGBLIGHT_ENABLE
// track led status
// bool is_led_on = true;
// caps lock
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_RED},
    {1, 1, HSV_RED},
    {1, 2, HSV_RED},
    {1, 3, HSV_RED},
    {1, 4, HSV_RED},
    {1, 5, HSV_RED},
    {1, 6, HSV_RED},
    {1, 7, HSV_RED},
    {1, 8, HSV_RED}
);
// base layer
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 0, HSV_CYAN}
);
// snake layer
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // capslock leds
    // if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
    // {1, 1, HSV_RED},
    // {1, 4, HSV_RED},
    // {1, 6, HSV_RED},
    // {1, 7, HSV_RED},

    // {1, 0, HSV_CHARTREUSE},
    // {1, 2, HSV_CHARTREUSE},
    // {1, 3, HSV_CHARTREUSE},
    // {1, 5, HSV_CHARTREUSE},
    // {1, 8, HSV_CHARTREUSE}
    // }
    // else{
    {1, 0, HSV_CHARTREUSE},
    {1, 1, HSV_CHARTREUSE},
    {1, 2, HSV_CHARTREUSE},
    {1, 3, HSV_CHARTREUSE},
    {1, 4, HSV_CHARTREUSE},
    {1, 5, HSV_CHARTREUSE},
    {1, 6, HSV_CHARTREUSE},
    {1, 7, HSV_CHARTREUSE},
    {1, 8, HSV_CHARTREUSE}
    // }
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_SPRINGGREEN},
    {1, 1, HSV_SPRINGGREEN},
    {1, 2, HSV_SPRINGGREEN},
    {1, 3, HSV_SPRINGGREEN},
    {1, 4, HSV_SPRINGGREEN},
    {1, 5, HSV_SPRINGGREEN},
    {1, 6, HSV_SPRINGGREEN},
    {1, 7, HSV_SPRINGGREEN},
    {1, 8, HSV_SPRINGGREEN}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_GOLDENROD},
    {1, 1, HSV_GOLDENROD},
    {1, 2, HSV_GOLDENROD},
    {1, 3, HSV_GOLDENROD},
    {1, 4, HSV_GOLDENROD},
    {1, 5, HSV_GOLDENROD},
    {1, 6, HSV_GOLDENROD},
    {1, 7, HSV_GOLDENROD},
    {1, 8, HSV_GOLDENROD}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_PINK},
    {1, 1, HSV_PINK},
    {1, 2, HSV_PINK},
    {1, 3, HSV_PINK},
    {1, 4, HSV_PINK},
    {1, 5, HSV_PINK},
    {1, 6, HSV_PINK},
    {1, 7, HSV_PINK},
    {1, 8, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_MAGENTA},
    {1, 1, HSV_MAGENTA},
    {1, 2, HSV_MAGENTA},
    {1, 3, HSV_MAGENTA},
    {1, 4, HSV_MAGENTA},
    {1, 5, HSV_MAGENTA},
    {1, 6, HSV_MAGENTA},
    {1, 7, HSV_MAGENTA},
    {1, 8, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM my_layer7_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 0, HSV_BLUE},
    {1, 1, HSV_BLUE},
    {1, 2, HSV_BLUE},
    {1, 3, HSV_BLUE},
    {1, 4, HSV_BLUE},
    {1, 5, HSV_BLUE},
    {1, 6, HSV_BLUE},
    {1, 7, HSV_BLUE},
    {1, 8, HSV_BLUE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer,    // Overrides other layers
    my_layer4_layer,    // Overrides other layers
    my_layer5_layer,    // Overrides other layers
    my_layer6_layer,    // Overrides other layers
    my_layer7_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _BL));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _SL));
    rgblight_set_layer_state(3, layer_state_cmp(state, _VI));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NL));
    rgblight_set_layer_state(5, layer_state_cmp(state, _MS));
    rgblight_set_layer_state(6, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(7, layer_state_cmp(state, _MD));
    return state;
}

/* void suspend_power_down_user(void) { */
/*     rgb_matrix_set_suspend_state(true); */
/* } */

/* void suspend_wakeup_init_user(void) { */
/*     rgb_matrix_set_suspend_state(false); */
/* } */
#endif

// =============================================================================
// RGB MATRIX SECTION
// =============================================================================
// layer led colors
#ifdef RGB_MATRIX_ENABLE

// track led status
// NOTE not sure if this is needed as taken from AP2 config
// bool is_led_on = true;

void rgb_matrix_indicators_user(void) {
    switch (biton32(layer_state)) {
        case _BL:
            // capslock leds
            if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
                rgb_matrix_set_color_all(RGB_RED);
            }
            break;
        case _SL:
            if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
                // rgb_matrix_set_color_all(RGB_RED);
                rgb_matrix_set_color(0, RGB_RED);
                rgb_matrix_set_color(1, RGB_RED);
                rgb_matrix_set_color(2, RGB_RED);
                rgb_matrix_set_color(3, RGB_RED);
                rgb_matrix_set_color(4, RGB_RED);
                rgb_matrix_set_color(5, RGB_RED);

                rgb_matrix_set_color(6, RGB_MAGENTA);
                rgb_matrix_set_color(7, RGB_MAGENTA);
                rgb_matrix_set_color(8, RGB_MAGENTA);
                rgb_matrix_set_color(9, RGB_MAGENTA);
                rgb_matrix_set_color(10, RGB_MAGENTA);
                rgb_matrix_set_color(11, RGB_MAGENTA);

                rgb_matrix_set_color(12, RGB_RED);
                rgb_matrix_set_color(13, RGB_RED);
                rgb_matrix_set_color(14, RGB_RED);
                rgb_matrix_set_color(15, RGB_RED);
                rgb_matrix_set_color(16, RGB_RED);
                rgb_matrix_set_color(17, RGB_RED);

                rgb_matrix_set_color(18, RGB_MAGENTA);
                rgb_matrix_set_color(19, RGB_MAGENTA);
                rgb_matrix_set_color(20, RGB_MAGENTA);
                rgb_matrix_set_color(21, RGB_MAGENTA);
                rgb_matrix_set_color(22, RGB_MAGENTA);
                rgb_matrix_set_color(23, RGB_MAGENTA);

                // media controls
                rgb_matrix_set_color(24, RGB_RED);
                rgb_matrix_set_color(25, RGB_RED);
                rgb_matrix_set_color(26, RGB_RED);
                rgb_matrix_set_color(27, RGB_RED);
                rgb_matrix_set_color(28, RGB_RED);
                rgb_matrix_set_color(29, RGB_RED);

                rgb_matrix_set_color(30, RGB_MAGENTA);
                rgb_matrix_set_color(31, RGB_MAGENTA);
                rgb_matrix_set_color(32, RGB_MAGENTA);
                rgb_matrix_set_color(33, RGB_MAGENTA);
                rgb_matrix_set_color(34, RGB_MAGENTA);
                rgb_matrix_set_color(35, RGB_MAGENTA);

                rgb_matrix_set_color(36, RGB_RED);
                rgb_matrix_set_color(37, RGB_RED);
                rgb_matrix_set_color(38, RGB_RED);
                rgb_matrix_set_color(39, RGB_RED);
                rgb_matrix_set_color(40, RGB_RED);

                rgb_matrix_set_color(42, RGB_MAGENTA);
                rgb_matrix_set_color(43, RGB_MAGENTA);
                rgb_matrix_set_color(44, RGB_MAGENTA);
                rgb_matrix_set_color(45, RGB_MAGENTA);
                rgb_matrix_set_color(46, RGB_MAGENTA);
            }
            else rgb_matrix_set_color_all(RGB_MAGENTA);
            break;
        case _LOWER:
            // function keys
            rgb_matrix_set_color(0, 20, 88, 99);
            rgb_matrix_set_color(1, 20, 88, 99);
            rgb_matrix_set_color(2, 20, 88, 99);
            rgb_matrix_set_color(3, 20, 88, 99);
            rgb_matrix_set_color(4, 20, 88, 99);
            rgb_matrix_set_color(5, 20, 88, 99);

            rgb_matrix_set_color(12, 20, 88, 99);
            rgb_matrix_set_color(13, 20, 88, 99);
            rgb_matrix_set_color(14, 20, 88, 99);
            rgb_matrix_set_color(15, 20, 88, 99);
            rgb_matrix_set_color(16, 20, 88, 99);
            rgb_matrix_set_color(17, 20, 88, 99);

            // media controls
            rgb_matrix_set_color(10, 0, 200, 0);
            rgb_matrix_set_color(18, 0, 200, 0);
            rgb_matrix_set_color(19, 0, 200, 0);
            rgb_matrix_set_color(20, 0, 200, 0);
            rgb_matrix_set_color(21, 0, 200, 0);

            rgb_matrix_set_color(30, 0, 200, 0);
            break;
        case _MD:
            rgb_matrix_set_color_all(RGB_TEAL);
            break;
        case _VI:
            rgb_matrix_set_color(6, 10, 50, 50);
            rgb_matrix_set_color(7, 10, 50, 50);
            rgb_matrix_set_color(8, 10, 50, 50);
            rgb_matrix_set_color(9, 10, 50, 50);

            rgb_matrix_set_color(18, 0, 50, 60);
            rgb_matrix_set_color(19, 0, 50, 60);
            rgb_matrix_set_color(20, 0, 50, 60);
            rgb_matrix_set_color(21, 0, 50, 60);

            rgb_matrix_set_color(30, 0, 50, 50);
            rgb_matrix_set_color(31, 0, 50, 50);
            rgb_matrix_set_color(32, 0, 50, 50);
            rgb_matrix_set_color(33, 0, 50, 50);
            rgb_matrix_set_color(34, 0, 50, 50);
            break;
        case _NL:
            rgb_matrix_set_color(7, 255, 0, 0);
            rgb_matrix_set_color(8, 255, 0, 0);
            rgb_matrix_set_color(9, 255, 0, 0);
            rgb_matrix_set_color(10, 255, 0, 0);

            rgb_matrix_set_color(19, 255, 0, 0);
            rgb_matrix_set_color(20, 255, 0, 0);
            rgb_matrix_set_color(21, 255, 0, 0);
            rgb_matrix_set_color(22, 255, 0, 0);

            rgb_matrix_set_color(31, 255, 0, 0);
            rgb_matrix_set_color(32, 255, 0, 0);
            rgb_matrix_set_color(33, 255, 0, 0);
            rgb_matrix_set_color(34, 255, 0, 0);

            rgb_matrix_set_color(42, 255, 0, 0);
            break;
        case _MS:
            rgb_matrix_set_color(6, 5, 89, 45);
            rgb_matrix_set_color(7, 5, 89, 45);
            rgb_matrix_set_color(8, 5, 89, 45);
            rgb_matrix_set_color(9, 5, 89, 45);

            rgb_matrix_set_color(18, 5, 89, 45);
            rgb_matrix_set_color(19, 5, 89, 45);
            rgb_matrix_set_color(20, 5, 89, 45);
            rgb_matrix_set_color(21, 5, 89, 45);

            rgb_matrix_set_color(30, 5, 89, 45);
            rgb_matrix_set_color(31, 5, 89, 45);
            rgb_matrix_set_color(32, 5, 89, 45);
            rgb_matrix_set_color(33, 5, 89, 45);
            rgb_matrix_set_color(34, 5, 89, 45);
            break;
        case _FN:
            rgb_matrix_set_color(1, 0, 50, 1.9);
            rgb_matrix_set_color(2, 0, 50, 1.9);
            rgb_matrix_set_color(3, 0, 50, 1.9);
            rgb_matrix_set_color(4, 0, 50, 1.9);

            rgb_matrix_set_color(13, 0, 50, 2.9);
            rgb_matrix_set_color(14, 0, 50, 2.9);
            rgb_matrix_set_color(15, 0, 50, 2.9);
            rgb_matrix_set_color(16, 0, 50, 2.9);
            rgb_matrix_set_color(17, 0, 50, 2.9);

            rgb_matrix_set_color(24, 0, 50, 3.9);
            rgb_matrix_set_color(25, 0, 50, 3.9);
            rgb_matrix_set_color(26, 0, 50, 3.9);
            break;
    }
}

#endif

// =============================================================================
// END RGB.C
// =============================================================================
