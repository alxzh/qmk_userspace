#include <stdint.h>
#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_PRSC,
  ST_RCAST,
  ST_ARROW,
  ST_GE,
  ST_EE,
  ST_LE,
  MAC_MISSION_CONTROL,
  MAC_LOCK,
};

#define HOME_N MT(MOD_LGUI, KC_N)
#define HOME_R MT(MOD_LCTL, KC_R)
#define HOME_T LT(2, KC_T)
#define HOME_S MT(MOD_LSFT, KC_S)
#define MEH_Y MT(MOD_MEH, KC_Y)
#define MEH_G MT(MOD_MEH, KC_G)
#define HOME_H MT(MOD_RSFT, KC_H)
#define HOME_A LT(2, KC_A)
#define HOME_E MT(MOD_RCTL, KC_E)
#define HOME_I MT(MOD_RGUI, KC_I)
#define NAV LT(1,KC_BSPC)
#define NUMS LT(3,KC_SPACE)


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_voyager(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                            '*', '*',  '*', '*'
    );


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_NO,  KC_MAIL,KC_MPRV, KC_MPLY,   KC_MNXT,    ST_PRSC,     ST_RCAST,   KC_WREF,    KC_MUTE,  KC_VOLD, KC_VOLU,  MAC_LOCK,
    KC_NO,  KC_B,   KC_L,    KC_D,      KC_W,       KC_Z,        KC_QUOTE,   KC_F,       KC_O,     KC_U,    KC_J,     KC_NO,
    KC_NO,  HOME_N, HOME_R,  HOME_T,    HOME_S,     MEH_G,       MEH_Y,      HOME_H,     HOME_A,   HOME_E,  HOME_I,   KC_NO,
    KC_NO,  KC_Q,   KC_X,    KC_M,      KC_C,       KC_V,        KC_K,       KC_P,       KC_COMMA, KC_DOT,  KC_SLASH, KC_NO,
                                        NUMS,       QK_GESC,     KC_ENTER,    NAV
  ),
  [1] = LAYOUT_voyager(
    UG_TOGG, KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
    UG_NEXT, KC_NO,   KC_MPRV, KC_MPLY,KC_MNXT,ST_PRSC, CW_TOGG, KC_MUTE, KC_VOLD, KC_VOLU, MAC_LOCK, KC_TRNS,
    KC_TRNS, KC_LGUI, KC_LCTL, KC_LALT,KC_LSFT,KC_MEH,  KC_HASH, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
    RGB_SLD, UG_TOGG, UG_NEXT, RGB_SLD,KC_NO,  ST_GE,   QK_LLCK, KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS,
                                       KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [2] = LAYOUT_voyager(
    KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_EXLM,  KC_CIRC,   KC_MINUS,  KC_SLASH,  KC_PERC,   KC_DQUO, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_TRNS,
    KC_TRNS, KC_UNDS,  KC_EQUAL,  KC_PLUS,   KC_ASTR,   KC_DLR,    KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_COLN, KC_TRNS,
    KC_TRNS, CW_TOGG,  KC_BSLS,   KC_PIPE,   KC_AMPR,   KC_TILD,   KC_GRAVE,KC_AT,   KC_LABK, KC_RABK, KC_QUES, KC_TRNS,
                                             KC_TRNS,   KC_TRNS,   KC_TRNS, KC_TAB
  ),
  [3] = LAYOUT_voyager(
    UG_TOGG, KC_F1,          KC_F2,          KC_F3,          KC_F4,         KC_F5,        KC_F6,       KC_F7, KC_F8,   KC_F9,KC_F10,  KC_F11,
    UG_NEXT, ST_LE,          ST_EE,          ST_GE,          ST_ARROW,      KC_ESC,       KC_PLUS,     KC_7,  KC_8,    KC_9, KC_ASTR, KC_TRNS,
    KC_TRNS, OSM(MOD_LGUI),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LSFT), OSM(MOD_MEH), KC_MINUS,    KC_4,  KC_5,    KC_6, KC_0,    KC_TRNS,
    RGB_SLD, KC_MAC_UNDO,    KC_MAC_CUT,     KC_MAC_COPY,    KC_MAC_PASTE,  KC_NO,        KC_DOT,      KC_1,  KC_2,    KC_3, KC_SLASH,KC_TRNS,
                                                             KC_TRNS,       KC_TRNS,      KC_TRNS,     KC_TRNS
  )
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_PRSC:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_4))));
    }
    break;
    case ST_RCAST:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)));
    }
    break;
    case ST_ARROW:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
    }
    break;
    case ST_GE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
    }
    break;
    case ST_EE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_TAP(X_EQUAL));
    }
    break;
    case ST_LE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_COMMA)));
    }
    break;
    case MAC_MISSION_CONTROL:
      HCS(0x29F);
    case MAC_LOCK:
      HCS(0x19E);

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_S:
        case HOME_H:
        case NAV:
        case NUMS:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_S:
        case HOME_H:
        case NAV:
        case NUMS:
            return 190;
        default:
            return TAPPING_TERM;
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case HOME_N:
           if (other_keycode == HOME_S) {
               return true;
           }
           break;
        case HOME_I:
           if (other_keycode == HOME_H) {
               return true;
           }
           break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}

const key_override_t cmd_home_s_tab_override = ko_make_basic(MOD_BIT_LGUI, HOME_S, LGUI(KC_TAB));
const key_override_t cmd_home_h_tab_override = ko_make_basic(MOD_BIT_RGUI, HOME_H, LGUI(KC_TAB));
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t *key_overrides[] = {
    &cmd_home_s_tab_override,
    &cmd_home_h_tab_override,
	&delete_key_override
};
