#pragma once

#include QMK_KEYBOARD_H
// #include "muse.h"
#include "keymap.h"

// =============================================================================
// LED SECTION
// =============================================================================

#ifdef RGBLIGHT_ENABLE
// track led status
bool is_led_on = true;
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
// RGB_MATRIX
// =============================================================================
#ifdef RGB_MATRIX_ENABLE

bool is_led_on = true;

//layer led colors
void rgb_matrix_indicators_user(void) {

if(IS_LAYER_ON(_LOWER)) {
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

}
if(IS_LAYER_ON(_VI)) {
  /* rgb_matrix_set_color_all(0, 50, 50); */
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
}

if(IS_LAYER_ON(_NL)) {
  /* rgb_matrix_set_color_all(255, 0, 0); */
  rgb_matrix_set_color(7, 255, 0, 0);
  rgb_matrix_set_color(8, 255, 0, 0);
  rgb_matrix_set_color(9, 255, 0, 0);
  rgb_matrix_set_color(10, 255, 0, 0);

  rgb_matrix_set_color(19, 0, 0, 0);
  rgb_matrix_set_color(20, 0, 0, 0);
  rgb_matrix_set_color(21, 0, 0, 0);
  rgb_matrix_set_color(22, 0, 0, 0);

  rgb_matrix_set_color(31, 255, 0, 0);
  rgb_matrix_set_color(32, 255, 0, 0);
  rgb_matrix_set_color(33, 255, 0, 0);
  rgb_matrix_set_color(34, 255, 0, 0);

  rgb_matrix_set_color(43, 255, 0, 0);
}
if(IS_LAYER_ON(_MS)) {
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
}
if(IS_LAYER_ON(_FN)) {
  /* rgb_matrix_set_color_all(150, 9, 145); */
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

}

//capslock leds
  if (host_keyboard_led_state().caps_lock) {
    rgb_matrix_sethsv_noeeprom(HSV_TEAL);
    /* rgb_kmatrix_set_color_all(50, 50, 0); */
  }

}


#endif
// =============================================================================
// END RGB.C
// =============================================================================
