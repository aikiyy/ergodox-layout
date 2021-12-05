#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "mousekey.h"
#include "version.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------------.           ,--------------------------------------------------------.
 * |  Esc   |   1   |   2   |   3   |   4   |   5   |       |           |       |   6   |   7   |   8   |   9   |   0   |   \ |  |
 * |--------+-------+-------+-------+-------+---------------|           |-------+-------+-------+-------+-------+-------+--------|
 * |  Tab   |   Q   |   W   |   E   |   R   |   T   |  - =  |           |  ^ ~  |   Y   |   U   |   I   |   O   |   P   |   _    |
 * |--------+-------+-------+-------+-------+-------|       |           |       |-------+-------+-------+-------+-------+--------|
 * |  Ctrl  |   A   |   S   |   D   |   F   |   G   |-------|           |-------|   H   |   J   |   K   |   L   |  ; +  | : * Cmd|
 * |--------+-------+-------+-------+-------+-------|   "   |           |   @   |-------+-------+-------+-------+-------+--------|
 * |  Shift |   Z   |   X   |   C   |   V   |   B   |       |           |   `   |   N   |   M   |  , <  |  / >  |  / Ct | Shift  |
 * `--------+-------+-------+-------+-------+---------------'           `---------------+-------+-------+-------+-------+--------'
 *   | [ {  |  ] }  | Opt   |  Cmd  | -En   |                                           |  Jpn  |  Cmd  |  Opt  | Layer1|Layer2|
 *   `--------------------------------------'                                           `--------------------------------------'
 *                                          ,---------------.           ,---------------.
 *                                          |       |       |           |  ↑   |   ↓    |
 *                                   ,------|-------|-------|           |------+--------+------.
 *                                   |      |       |       |           |  ←   |        |      |
 *                                   | Space|  Del  |-------|           |------|  Hyper |Enter |
 *                                   |      |       |       |           |  →   |        |      |
 *                                   `----------------------'           `----------------------'
 */

/* Keymap 1: Fuction layer (skip no used key description)
 *
 * ,--------------------------------------------------------.           ,--------------------------------------------------------.
 * |  Esc   |  Fn1  |  Fn2  |  Fn3  |  Fn4  |  Fn5  |  Fn6  |           |  Fn7  |  Fn8  |  Fn9  |  Fn10 |  Fn11 |  Fn12 |        |
 * |--------+-------+-------+-------+-------+---------------|           |-------+-------+-------+-------+-------+-------+--------|
 * |  Tab   |       |       |       |       |       |       |           |       |  Up   |   7   |   8   |   9   |       |        |
 * |--------+-------+-------+-------+-------+-------|       |           |       |-------+-------+-------+-------+-------+--------|
 * |  Ctrl  |       |       |       |       |       |-------|           |-------|  Down |   4   |   5   |   6   |       |        |
 * |--------+-------+-------+-------+-------+-------|       |           |       |-------+-------+-------+-------+-------+--------|
 * |  Shift |       |       |       |       |       |       |           |       |       |   1   |   2   |   3   |       | Shift  |
 * `--------+-------+-------+-------+-------+---------------'           `---------------+-------+-------+-------+-------+--------'
 *   |      |       | Opt   |  Cmd  | -En   |                                           |  Jpn  |  Cmd  |   0   |       |      |
 *   `--------------------------------------'                                           `--------------------------------------'
 *                                          ,---------------.           ,---------------.
 *                                          |       |       |           |  ↑   |   ↓    |
 *                                   ,------|-------|-------|           |------+--------+------.
 *                                   |      |       | Reset |           |  ←   |        |      |
 *                                   | Space|  Del  |-------|           |------|  Hyper |Enter |
 *                                   |      |       |       |           |  →   |        |      |
 *                                   `----------------------'           `----------------------'
 */

  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_INT3,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_MINUS,                                       KC_EQUAL,       KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_RO,
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      LGUI_T(KC_QUOTE),
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_AT,                                          KC_LBRACKET,    KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),KC_RSHIFT,
    KC_RBRACKET,    KC_BSLASH,      KC_LALT,        KC_LGUI,        KC_LANG2,                                                                                                       KC_LANG1,       KC_RGUI,        KC_RALT,        TG(1),          TG(2),
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_DOWN,
                                                                                                                    KC_TRANSPARENT, KC_LEFT,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_TRANSPARENT, KC_RIGHT,       KC_HYPR,        KC_ENTER
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,                                                                       KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_TRANSPARENT,
    KC_LSHIFT,      KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_RSHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LALT,        KC_LGUI,        KC_LANG2,                                                                                                       KC_LANG1,       KC_RGUI,        KC_0,           KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SLD,
                                                                                                                    HSV_86_255_128, KC_TRANSPARENT,
                                                                                    RGB_VAD,        RGB_VAI,        HSV_27_255_255, KC_TRANSPARENT, RGB_HUD,        RGB_HUI
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                                                                                                     KC_AUDIO_VOL_UP,KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_DOWN,
                                                                                                                    RESET,          KC_LEFT,
                                                                                    KC_SPACE,       KC_BSPACE,      KC_TRANSPARENT, KC_RIGHT,       KC_HYPR,        KC_ENTER
  ),
};


bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
