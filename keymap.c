// Copyright 2021 Atanas Janackovski (@atanasj)

#include QMK_KEYBOARD_H
#include "muse.h"

bool is_alt_tab_active = false;  // ADD this near the begining of keymap.c
__attribute__ ((weak))
bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  return true;
}

#include "keymap.h"

#ifdef COMBO_ENABLE
#    include "keymap_combo.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "tapdance.h"
#endif

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgbstuff.h"
#endif

// =============================================================================
// KEYMAP SECTION
// =============================================================================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//  =======================LEFT=========================      ======================RIGHT============================
[_BL] = LAYOUT_planck_mit(
    LG_Q,    WIND_W,  L_MS_E,  KC_R,    KC_T,    XXXXXXX,     XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,     RG_P,
    LC_A,    KC_S,    L_VI_D,  KC_F,    KC_G,    XXXXXXX,     XXXXXXX, KC_H,    KC_J,    L_FN_K,  KC_L,     RC_QUOT,
    LS_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,   RS_SLSH,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NUMPAD,  XXXXXXX,              T_A_SPC, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX
),
[_NL] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,     KC_EQL,
    KC_LGUI, KC_LALT, _______, T_SHDOT, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,     KC_MINS,
    XXXXXXX, T_NUMB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,     KC_PSLS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,              KC_0,    _______, XXXXXXX, XXXXXXX,  XXXXXXX
 ),
[_VI] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, XXXXXXX,     XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   T_SNAK,
    KC_LCMD, KC_LALT, _______, KC_LSFT, KC_LEAD, XXXXXXX,     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_F19,
    _______, T_VIL,   _______, KC_LCTL, _______, XXXXXXX,     XXXXXXX, DW_BKWD, KC_BSPC, KC_DEL,  DW_FRWD,  TD_DEL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,              _______, _______, XXXXXXX, XXXXXXX,  XXXXXXX
),
[_WL] = LAYOUT_planck_mit(
    MO_WQ,   _______, XXXXXXX, MO_DM,   _______, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN5,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,     XXXXXXX, HYP_H,   HYP_J,   HYP_K,   HYP_L,    XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,     XXXXXXX, HYP_I,   XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,              HYP_ENT, _______, XXXXXXX, XXXXXXX,  XXXXXXX
 ),
[_WQ] = LAYOUT_planck_mit(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN7,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, GS_GRV,  GUI_TAB, SG_TAB,  GUI_GRV,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,              XXXXXXX, _______, XXXXXXX, XXXXXXX,  XXXXXXX
 ),
[_DM] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, DM_REC1, DM_PLY1, DM_REC2, DM_PLY2,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,              DM_RSTP, _______, XXXXXXX, XXXXXXX,  XXXXXXX
 ),
[_MS] = LAYOUT_planck_mit(
    KC_ACL1, KC_ACL2, _______, KC_R,    XXXXXXX, KC_ACL0,     XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,  XXXXXXX,
    MS_GUIA, MS_ALTS, _______, MS_SFTF, XXXXXXX, XXXXXXX,     XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  XXXXXXX,
    XXXXXXX, T_MSL,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, CG_D,    KC_BTN3, KC_BTN2,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,              KC_BTN1, _______, XXXXXXX, XXXXXXX,  XXXXXXX
 ),
[_FN] = LAYOUT_planck_mit(
    KC_PIPE, KC_LCBR, KC_RCBR, KC_BSLS, SUSPEND, XXXXXXX,     XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, DEBUG,    XXXXXXX,
    KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN, KC_BRIU, XXXXXXX,     XXXXXXX, KC_LSFT, KC_LCTL, _______, KC_LALT,  KC_LGUI,
    KC_TILD, KC_LBRC, KC_RBRC, KC_GRV,  KC_BRID, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,              XXXXXXX, _______, XXXXXXX, XXXXXXX,  XXXXXXX
),
};

// =============================================================================
// MACRO DEFS
// =============================================================================

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {
        case GUI_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LGUI);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case SG_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LGUI);
                }
                register_code(KC_LSFT);
                register_code(KC_TAB);
            } else {
                unregister_code(KC_LSFT);
                unregister_code(KC_TAB);
            }
            break;
        case KC_RSFT:
            perform_space_cadet(record, KC_RSPC, KC_RSFT, KC_RSFT, KC_0);
            return false;
        case SUSPEND:
            if (record->event.pressed) {
                // if (is_led_on) {
                //     is_led_on = false;
                //     rgblight_disable();
                    SEND_STRING(SS_LCTL(SS_LGUI("q")) SS_DELAY(999) SS_TAP(X_ESC));
                // }
            }
            return true;
        default:
            if (record->event.pressed) {
                // if (!is_led_on) {
                //     is_led_on = true;
                //     rgblight_enable();
                // }
            }
    }
    // return true;
    return process_record_secrets(keycode, record);
}

// =============================================================================
// TAPPING TERM PER KEY SECTION
// =============================================================================

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case L_MS_E:
    case L_VI_D:
    case L_FN_K:
    case WIND_W:
    case NUMPAD:
        return 225;
    case LG_Q:
    case LS_Z:
    case RG_P:
    case RC_QUOT:
    case RS_SLSH:
    case LC_A:
        return 150;
    case FN_LAY:
        return 35;
    default:
        return TAPPING_TERM;
    }
}

// =============================================================================
// RETRO TAPPING PER KEY SECTION
// =============================================================================

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_MS_E:
        case L_VI_D:
        case L_FN_K:
        case WIND_W:
        case LG_Q:
        case LC_A:
        case LS_Z:
        case RG_P:
        case RC_QUOT:
        case RS_SLSH:
            return true;
        default:
            return false;
    }
}

// =============================================================================
// PERMISSIVE HOLD PER KEY SECTION
// =============================================================================

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case L_MS_E:
        case L_VI_D:
        case L_FN_K:
        case WIND_W:
        case NUMPAD:
        case LG_Q:
        case LC_A:
        case LS_Z:
        case RG_P:
        case RC_QUOT:
        case RS_SLSH:
            return true;
        default:
            return false;
    }
}

// =============================================================================
// MOD TAP INTERRUP PER KEY SECTION
// =============================================================================
// NOTE this is experimental, review it's use
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case T_A_SPC:
        case NUMPAD:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// =============================================================================
// MOD TAP INTERRUP PER KEY SECTION
// =============================================================================

// but all keys that are problematic with rolling keystrokes here
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LG_Q:
        case LC_A:
        // case LS_Z:
        case RG_P:
        case RC_QUOT:
        // case RS_SLSH:
        case T_A_SPC:
            return true;
        default:
            return false;
    }
}

// =============================================================================
// LEADER KEY SECTION
// =============================================================================

LEADER_EXTERNS();

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (!layer_state_is(_WQ)) {
            unregister_code(KC_LGUI);
            is_alt_tab_active = false;
        }
    }
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        // R section
        SEQ_TWO_KEYS(KC_R, KC_QUOT) {
            SEND_STRING(" <-");
        }
        SEQ_TWO_KEYS(KC_R, KC_DOT) {
            SEND_STRING(" |>");
        }
        SEQ_TWO_KEYS(KC_R, KC_P) {
            SEND_STRING(" %>%");
        }
        SEQ_TWO_KEYS(KC_R, KC_I) {
            SEND_STRING(" %in%");
        }
        // Signature section
        // signature, smile
        SEQ_TWO_KEYS(KC_S, KC_S) {
            SEND_STRING("Cheers,  :-)" SS_TAP(X_ENT) SS_TAP(X_ENT) "Atanas");
        }
        // signature, no smile
        SEQ_TWO_KEYS(KC_A, KC_A) {
            SEND_STRING("Cheers," SS_TAP(X_ENT) SS_TAP(X_ENT) "Atanas");
        }
        // reset
        // SEQ_TWO_KEYS(KC_R, KC_R) {
        //     register_code(RESET);
        //     unregister_code(RESET);
        // }
        /* // Kamoji section */
        /* SEQ_TWO_KEYS(KC_K, KC_F) { */
        /*     send_unicode_string("(ノಠ痊ಠ)ノ彡┻━┻"); */
        /* } */
        /* // Emoticons section */
        /* SEQ_TWO_KEYS(KC_E, KC_T) { */
        /*     SEND_STRING(SS_LALT("D83D+DC83")); // 💃 */
        /* } */
        /* SEQ_TWO_KEYS(KC_E, KC_P) { */
        /*     SEND_STRING(SS_LALT("D83D+DCA9")); // 💩 */
        /* } */
    }
}


// Alt + esc = Alt + spc
// const key_override_t num_esc_override = ko_make_basic(MOD_MASK_ALT, KC_ESC, A(KC_SPC));

// const key_override_t **key_overrides = (const key_override_t *[]){
//     &num_esc_override,
//     NULL
// };
// =============================================================================
// END KEYMAP.C
// =============================================================================
