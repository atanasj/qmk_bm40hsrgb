/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
  _BL,
  _VI,
  _NL,
  _MS,
  _FN,
  _LOWER
};

#include "keymap_combo.h"

// =============================================================================
// KEY DEF SECTION
// =============================================================================

#define LOWER  LT(_LOWER, KC_SPC)
#define NUMPAD LT(_NL, KC_SPC)
#define L_VI_D LT(_VI, KC_D)
#define L_MS_E LT(_MS, KC_E)

#define OS_LCAG OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT))
#define OS_HYPR OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT))

#define M_GC_ESC MT(MOD_LGUI|MOD_LCTL,KC_ESC)
#define M_GA_SPC MT(MOD_LGUI|MOD_LALT,KC_SPC)
#define T_G_TAB LCMD_T(KC_TAB)
#define T_C_ESC LCTL_T(KC_ESC)
#define T_A_SPC ALT_T(KC_SPC)
#define TD_SEMI TD(SEMI_)
#define TD_HELP TD(SL_HLP)
#define T_SHDOT LSFT_T(KC_PDOT)

// =============================================================================
// LED SECTION
// =============================================================================
// TODO figure out what he config means and customise to my liking

bool is_led_on = true;

//layer led colors

void rgb_matrix_indicators_user(void) {

//game indicators
//
if(IS_LAYER_ON(_LOWER)) {
  /* rgb_matrix_set_color(11, 50, 0, 0); */
  rgb_matrix_set_color_all(50, 0, 0);
}

//layer indicators

/* if(IS_LAYER_ON(_BL)) { */
/*   rgb_matrix_set_color_all(0, 40, 50); */
/*   /\* rgb_matrix_set_color(40, 0, 40, 50); *\/ */
/*   /\* rgb_matrix_set_color(19, 0, 40, 50); *\/ */
/*   /\* rgb_matrix_set_color(20, 0, 40, 50); *\/ */
/*   /\* rgb_matrix_set_color(21, 0, 40, 50); *\/ */
/*   /\* rgb_matrix_set_color(22, 0, 40, 50); *\/ */
/* } */

if(IS_LAYER_ON(_VI)) {
  rgb_matrix_set_color_all(50, 10, 20);
  /* rgb_matrix_set_color(39, 50, 10, 20); */
  /* rgb_matrix_set_color(19, 50, 10, 20); */
  /* rgb_matrix_set_color(22, 50, 10, 20); */
  /* rgb_matrix_set_color(42, 50, 10, 20); */
}

if(IS_LAYER_ON(_NL)) {
  rgb_matrix_set_color_all(50, 0, 0);
  /* rgb_matrix_set_color(43, 50, 0, 0); */

  /* rgb_matrix_set_color(1, 50, 0, 0); */
  /* rgb_matrix_set_color(2, 50, 0, 0); */
  /* rgb_matrix_set_color(3, 50, 0, 0); */
  /* rgb_matrix_set_color(4, 50, 0, 0); */

  /* rgb_matrix_set_color(13, 50, 0, 0); */
  /* rgb_matrix_set_color(14, 50, 0, 0); */
  /* rgb_matrix_set_color(15, 50, 0, 0); */
  /* rgb_matrix_set_color(16, 50, 0, 0); */

  /* rgb_matrix_set_color(25, 50, 0, 0); */
  /* rgb_matrix_set_color(26, 50, 0, 0); */
  /* rgb_matrix_set_color(27, 50, 0, 0); */
  /* rgb_matrix_set_color(28, 50, 0, 0); */
}

if(IS_LAYER_ON(_MS)) {
  rgb_matrix_set_color_all(10, 0, 50);
  /* rgb_matrix_set_color(42, 10, 0, 50); */

  /* rgb_matrix_set_color(2, 10, 0, 50); */
  /* rgb_matrix_set_color(3, 10, 0, 50); */
  /* rgb_matrix_set_color(4, 10, 0, 50); */

  /* rgb_matrix_set_color(14, 10, 0, 50); */
  /* rgb_matrix_set_color(15, 10, 0, 50); */
  /* rgb_matrix_set_color(16, 10, 0, 50); */

  /* rgb_matrix_set_color(26, 10, 0, 50); */
  /* rgb_matrix_set_color(27, 10, 0, 50); */
  /* rgb_matrix_set_color(28, 10, 0, 50); */

  /* rgb_matrix_set_color(38, 10, 0, 50); */
  /* rgb_matrix_set_color(39, 10, 0, 50); */
  /* rgb_matrix_set_color(40, 10, 0, 50); */
}

if(IS_LAYER_ON(_FN)) {
  rgb_matrix_set_color_all(0, 50, 1.9);
  /* rgb_matrix_set_color(41, 0, 50, 1.9); */

  /* rgb_matrix_set_color(1, 0, 50, 1.9); */
  /* rgb_matrix_set_color(2, 0, 50, 1.9); */
  /* rgb_matrix_set_color(3, 0, 50, 1.9); */
  /* rgb_matrix_set_color(4, 0, 50, 1.9); */
  /* rgb_matrix_set_color(5, 0, 50, 1.9); */

  /* rgb_matrix_set_color(13, 0, 50, 1.9); */
  /* rgb_matrix_set_color(14, 0, 50, 1.9); */
  /* rgb_matrix_set_color(15, 0, 50, 1.9); */
  /* rgb_matrix_set_color(16, 0, 50, 1.9); */
  /* rgb_matrix_set_color(17, 0, 50, 1.9); */

  /* rgb_matrix_set_color(25, 0, 50, 1.9); */
  /* rgb_matrix_set_color(26, 0, 50, 1.9); */
  /* rgb_matrix_set_color(27, 0, 50, 1.9); */
  /* rgb_matrix_set_color(28, 0, 50, 1.9); */
  /* rgb_matrix_set_color(29, 0, 50, 1.9); */

}

//capslock leds

if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    rgb_matrix_set_color_all(50, 15.6, 0);
  }

}

// =============================================================================
// MACRO SECTION
// =============================================================================

enum macros {
    SUSPEND = SAFE_RANGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_RSFT:
        perform_space_cadet(record, KC_RSPC, KC_RSFT, KC_RSFT, KC_0);
        return false;
    case SUSPEND:
        if (record->event.pressed) {
            if(is_led_on) {
                is_led_on = false;
                rgblight_disable();
                SEND_STRING(SS_LCTL(SS_LGUI("q")) SS_DELAY(500) SS_TAP(X_ESC));
            }
        }
        return true;
    default:
        if (record->event.pressed) {
            if(!is_led_on) {
                is_led_on = true;
                rgblight_enable();
            }
        }
    }
    return true;
}

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
};

// Tap dance enums
enum {
    SL_HLP,
    SEMI_,
    B_F_DEL
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// =============================================================================
// TAPPING TERM PER KEY SECTION
// =============================================================================

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LT(_MS,KC_E):
        return 225;
    case LT(_VI,KC_D):
        return 225;
    case RCTL_T(KC_ENT):
        return 350;
    case SL_HLP:
        return 150;
    case KC_LSPO:
        return 127;
    case KC_RSPC:
        return 127;
    case SEMI_:
        return 155;
    default:
        return TAPPING_TERM;
    }
}

// =============================================================================
// MOD TAP INTERRUP PER KEY SECTION
// =============================================================================

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_SPC):
            return true;
        case KC_LSPO:
            return true;
        case KC_RSFT:
            return true;
        default:
            return false;
    }
}

// =============================================================================
// KEYMAP SECTION
// =============================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT_planck_mit(
    T_G_TAB, KC_Q,     KC_W,     L_MS_E, KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RCMD_T(KC_BSPC),
    T_C_ESC, KC_A,     KC_S,     L_VI_D, KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD_SEMI, RCTL_T(KC_QUOT),
    KC_LSPO, KC_Z,     KC_X,     KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  TD_HELP, KC_RSFT,
    OS_HYPR, M_GC_ESC, M_GA_SPC, LOWER,  NUMPAD, T_A_SPC,          OS_LCAG, OS_LCAG, KC_DOWN, KC_UP,   SGUI_T(KC_ENT)
),
[_VI] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, KC_HOME,    KC_PGDN,  KC_PGUP, KC_END,    XXXXXXX,     XXXXXXX,
    _______, KC_LCMD, KC_LALT, _______, KC_LSFT, KC_LEAD, KC_LEFT,    KC_DOWN,  KC_UP,   KC_RIGHT,  KC_F19,      KC_CAPS,
    XXXXXXX, MO(_NL), _______, _______, _______, _______, A(KC_BSPC), KC_BSPC,  KC_DEL,  A(KC_DEL), TD(B_F_DEL), _______,
    _______, _______, _______, _______, _______, _______,             _______,  _______, _______,   _______,     _______
),
[_NL] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_EQL,  XXXXXXX,
    _______, KC_LGUI, KC_LALT, _______,  T_SHDOT, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_MINS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_LGUI, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PSLS, XXXXXXX,
    XXXXXXX, XXXXXXX, _______, _______,  _______, KC_0,             _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
 ),
 [_MS] = LAYOUT_planck_mit(
    KC_ACL0, KC_ACL2, KC_ACL1, _______, KC_R,    XXXXXXX, KC_WH_L, KC_WH_U,    KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
    _______, KC_A,    KC_S,    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D,    KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(G(KC_D)), XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_BTN1,     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
 ),
 [_FN] = LAYOUT_planck_mit(
    SUSPEND, S(KC_GRV),  KC_GRV,  KC_BSLS, S(KC_BSLS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, S(KC_LBRC), KC_LBRC, KC_RBRC, S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
    XXXXXXX, S(KC_MINS), XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_TOG, RGB_MOD,    RGB_HUI, RGB_HUD, RGB_SAI,    RGB_SAD,          RGB_VAI, RGB_VAD, XXXXXXX, DEBUG,   RESET
),
[_LOWER] = LAYOUT_planck_mit(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______,    _______, _______, _______,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MPRV, KC_VOLD, KC_VOLU,    KC_MNXT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MUTE, S(KC_NUBS), _______, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______,    _______, _______, _______
)
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _LOWER, _FN, _ADJUST); */
/* } */


// =============================================================================
// TAP DANCE SECTION
// =============================================================================

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    } else return 8;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap help_tap_state = {
    .is_press_action = true,
    .state = 0
};

void help_finished(qk_tap_dance_state_t *state, void *user_data) {
    help_tap_state.state = cur_dance(state);
    switch (help_tap_state.state) {
    case SINGLE_TAP:
        register_code(KC_SLSH);
        break;
    case DOUBLE_TAP:
        register_code(KC_LCMD);
        register_code(KC_LSFT);
        register_code(KC_SLSH);
    }
}

void help_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (help_tap_state.state) {
    case SINGLE_TAP:
        unregister_code(KC_SLSH);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_LCMD);
        unregister_code(KC_LSFT);
        unregister_code(KC_SLSH);
    }
    help_tap_state.state = 0;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap semi_tap_state = {
    .is_press_action = true,
    .state = 0
};

void semi_finished(qk_tap_dance_state_t *state, void *user_data) {
    semi_tap_state.state = cur_dance(state);
    switch (semi_tap_state.state) {
    case SINGLE_TAP:
        register_code(KC_SCLN);
        break;
    case SINGLE_HOLD:
        layer_on(_FN);
        break;
    case DOUBLE_TAP:
        register_code(KC_LSFT);
        register_code(KC_MINS);
    }
}

void semi_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (semi_tap_state.state) {
    case SINGLE_TAP:
        unregister_code(KC_SCLN);
        break;
    case SINGLE_HOLD:
        layer_off(_FN);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_LSFT);
        unregister_code(KC_MINS);
    }
    semi_tap_state.state = 0;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap bfdel_tap_state = {
    .is_press_action = true,
    .state = 0
};

void bfdel_finished(qk_tap_dance_state_t *state, void *user_data) {
    bfdel_tap_state.state = cur_dance(state);
    switch (bfdel_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_LCMD);
            register_code(KC_LSFT);
            tap_code(KC_LEFT);
            unregister_code(KC_LCMD);
            unregister_code(KC_LSFT);
            tap_code(KC_BSPC);
            break;
        case DOUBLE_TAP:
            register_code(KC_LCMD);
            register_code(KC_LSFT);
            tap_code(KC_RIGHT);
            unregister_code(KC_LCMD);
            unregister_code(KC_LSFT);
            tap_code(KC_BSPC);
    }
}

void bfdel_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (bfdel_tap_state.state) {
    case SINGLE_TAP:
        unregister_code(KC_BSPC);
        break;
    case DOUBLE_TAP:
        unregister_code(KC_BSPC);
    }
    bfdel_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [SL_HLP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, help_finished, help_reset),
    [SEMI_]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, semi_finished, semi_reset),
    [B_F_DEL]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, bfdel_finished, bfdel_reset)
};


// =============================================================================
// LEADER KEY SECTION
// =============================================================================

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        // NOTE in built R operators
        SEQ_ONE_KEY(KC_A) {
            /* needs to a as semi colon is a tap dance key */
            SEND_STRING(" <-");
        }
        SEQ_ONE_KEY(KC_P) {
            SEND_STRING(" %>%");
        }
        SEQ_ONE_KEY(KC_I) {
            SEND_STRING(" %in% ");
        }
        SEQ_ONE_KEY(KC_N) {
            SEND_STRING(" %!in% ");
        }
    }
}

// =============================================================================
// END KEYMAP.C
// =============================================================================
