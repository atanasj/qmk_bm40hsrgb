#pragma once

#undef TAPPING_TERM
#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

// #define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
// #define ONESHOT_TIMEOUT 1000  /* Time (in ms) before the one shot key is released */

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 500

// Limits the max. amount of layers to 8 to save firmware memory.
#define LAYER_STATE_8BIT

#ifdef MIDI_ENABLE
// override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes)
#define MIDI_ADVANCED
// #define MIDI_TONE_KEYCODE_OCTAVES 2
#endif

#define COMBO_VARIABLE_LEN
// #define COMBO_COUNT 13
#define COMBO_TERM 20

// Set the mouse settings to a comfortable speed/accuracy trade-off
// Assume the screen refresh rate is 60 Hz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
// #undef to override default settings
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100

#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LAYERS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
#    define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#    define RGBLIGHT_SLEEP
#    if defined(__AVR__) && !defined(__AVR_AT90USB1286__)
#        undef RGBLIGHT_ANIMATIONS
#        define RGBLIGHT_EFFECT_BREATHING
#        define RGBLIGHT_EFFECT_SNAKE
#        define RGBLIGHT_EFFECT_KNIGHT
#    else
#        define RGBLIGHT_ANIMATIONS
// #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
// #        define RGBLIGHT_LIMIT_VAL 10
#    endif
#endif  // RGBLIGHT_ENABLE

// bootmagic
#define BOOTMAGIC_KEY_SALT KC_V
#define BOOTMAGIC_KEY_EEPROM_CLEAR KC_Q

#ifdef RGB_MATRIX_ENABLE

//--------------------------------------------------------------------------------------------------------
#    define RGB_MATRIX_KEYPRESSES                // reacts to keypresses (will slow down matrix scan by a lot)
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (not recommened)
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#    define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
// #   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
// #   define EECONFIG_RGB_MATRIX (uint32_t *)16
// disable broken animations
#    define DISABLE_RGB_MATRIX_ALPHAS_MODS
#    define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    define DISABLE_RGB_MATRIX_BREATHING
#    define DISABLE_RGB_MATRIX_BAND_SAT
#    define DISABLE_RGB_MATRIX_BAND_VAL
#    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    define DISABLE_RGB_MATRIX_CYCLE_ALL
#    define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#    define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
//#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#define DISABLE_RGB_MATRIX_DUAL_BEACON
#    define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#    define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define DISABLE_RGB_MATRIX_RAINDROPS
#    define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS  // DO NOT ENABLE
// NOTE drop all below to save space
// #    define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#    define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    define DISABLE_RGB_MATRIX_SPLASH
#    define DISABLE_RGB_MATRIX_MULTISPLASH
#    define DISABLE_RGB_MATRIX_SOLID_SPLASH
#    define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

#    undef RGB_MATRIX_STARTUP_MODE

#    define RGBLIGHT_HUE_STEP 20

#endif
