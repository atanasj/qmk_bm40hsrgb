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
  _LOWER,
  _RAISE,
  _ADJUST
};

#include "keymap_combo.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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
            SEND_STRING(SS_LCTL(SS_LGUI("q")) SS_DELAY(500) SS_TAP(X_ESC));
        }
        return true;
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

#define OS_LCAG OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT))
#define OS_HYPR OSM(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT))

//layer led colors

/* void rgb_matrix_indicators_user(void) { */

/*   for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) { */
/*     if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) { */
/*         rgb_matrix_set_color(i, 0, 0, 0); */
/*     } */
/*     if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_KEYLIGHT)) { */
/*         rgb_matrix_set_color(i, 0, 0, 0); */
/*     } */
/*   } */

/*   //capslock */
/*   if (host_keyboard_led_state().caps_lock) { */
/*     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) { */
/*       if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) { */
/*             rgb_matrix_set_color(i, 255, 255, 255); */
/*       } */
/*     } */
/*   } */

/*   //nav layer */
/*   if (IS_LAYER_ON(_VI)) { */
/*     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) { */
/*       if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) { */
/*             rgb_matrix_set_color(i, 0, 204, 255); */
/*       } */
/*     } */
/*   } */

/*   //funl layer */
/*   if (IS_LAYER_ON(_NL)) { */
/*     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) { */
/*       if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) { */
/*             rgb_matrix_set_color(i, 255, 0, 0); */
/*       } */
/*     } */
/*   } */

/*   //nsl layer */
/*   if (IS_LAYER_ON(_MS)) { */
/*     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) { */
/*       if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) { */
/*             rgb_matrix_set_color(i, 51, 0, 255); */
/*       } */
/*     } */
/*   } */

/*   //nssl layer */
/*   if (IS_LAYER_ON(_FN)) { */
/*     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) { */
/*       if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) { */
/*             rgb_matrix_set_color(i, 0, 255, 0); */
/*       } */
/*     } */
/*   } */

/*   //game layer */
/*   if (IS_LAYER_ON(_LOWER)) { */
/*     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) { */
/*       if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) { */
/*             rgb_matrix_set_color(i, 0, 204, 255); */
/*       } */
/*     } */
/*   } */

/*   //secgame layer */
/*   if (IS_LAYER_ON(_RAISE)) { */
/*     for (uint8_t i = 0; i < DRIVER_LED_TOTAL; ++i) { */
/*       if (HAS_ANY_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) { */
/*             rgb_matrix_set_color(i, 255, 0, 0); */
/*       } */
/*     } */
/*   } */

/* } */

// =============================================================================
// KEYMAP SECTION
// =============================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BL] = LAYOUT_planck_mit(
    LCMD_T(KC_TAB),  KC_Q,                         KC_W,                         LT(_MS,KC_E), KC_R,  KC_T,          KC_Y,  KC_U,            KC_I,    KC_O,   KC_P,       RCMD_T(KC_BSPC),
    LCTL_T(KC_ESC),  KC_A,                         KC_S,                         LT(_VI,KC_D), KC_F,  KC_G,          KC_H,  KC_J,            KC_K,    KC_L,   TD(SEMI_),  RCTL_T(KC_QUOT),
    KC_LSPO,         KC_Z,                         KC_X,                         KC_C,         KC_V,  KC_B,          KC_N,  KC_M,            KC_COMM, KC_DOT, TD(SL_HLP), KC_RSFT,
    OS_HYPR, MT(MOD_LGUI|MOD_LCTL,KC_ESC), MT(MOD_LGUI|MOD_LALT,KC_SPC), KC_LALT,      LOWER, ALT_T(KC_SPC), OS_LCAG, RAISE, KC_DOWN, KC_UP,  SGUI_T(KC_RGHT)
),
  /* VI layer */
 [_VI] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, KC_HOME,    KC_PGDN,  KC_PGUP, KC_END,    XXXXXXX, XXXXXXX,
    _______, KC_LCMD, KC_LALT, _______, KC_LSFT, KC_LEAD, KC_LEFT,    KC_DOWN,  KC_UP,   KC_RIGHT,  KC_F19,  KC_CAPS,
    XXXXXXX, MO(_NL), _______, _______, _______, _______, A(KC_BSPC), KC_BSPC,  KC_DEL,  A(KC_DEL), TD(B_F_DEL), _______,
    _______, _______, _______, _______, _______,      _______,        _______,  _______, _______,   _______, _______
),
 /* NL layer */
 [_NL] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX, _______,  XXXXXXX,         XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_EQL,  XXXXXXX,
    _______, KC_LGUI, KC_LALT, _______,  LSFT_T(KC_PDOT), XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    KC_MINS, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_LGUI,         XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_PSLS, XXXXXXX,
    XXXXXXX, XXXXXXX, _______, _______,  _______,         KC_0,             _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
 ),
 /* MS layer */
 [_MS] = LAYOUT_planck_mit(
    KC_ACL0, KC_ACL2, KC_ACL1, _______, KC_R,    XXXXXXX, KC_WH_L, KC_WH_U,    KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
    _______, KC_A,    KC_S,    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D,    KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, C(G(KC_D)), XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_BTN1,     XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
 ),
// FN layer
 [_FN] = LAYOUT_planck_mit(
    SUSPEND, S(KC_GRV),  KC_GRV,  KC_BSLS, S(KC_BSLS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, S(KC_LBRC), KC_LBRC, KC_RBRC, S(KC_RBRC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
    XXXXXXX, S(KC_MINS), XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET,   DEBUG,      RGB_TOG, RGB_MOD, RGB_HUI,    RGB_HUD,          RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


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
