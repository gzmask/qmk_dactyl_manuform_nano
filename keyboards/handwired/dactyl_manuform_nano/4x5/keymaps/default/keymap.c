#include "dactyl_manuform_nano.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear
#define ____ KC_TRNS

#define SFT_SPC SFT_T(KC_SPC)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2
#define KC_MB3 KC_MS_BTN3
#define KC_MB4 KC_MS_BTN4

//Tap Dance Declarations
enum {
  A_ESC = 0,
  ONE_GRV = 1,
  SCLN_ENT = 2,
  SLSH_BSLS = 3,
  Q_TAB = 4
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [A_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC),
  [ONE_GRV]  = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_GRV),
  [SCLN_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ENT),
  [SLSH_BSLS]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS),
  [Q_TAB]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_TAB)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * | q TAB|   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |  p   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * | a ESC|   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  | ; ENT|
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  | / \  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | ALT =|  -   |                                                         |   [  |   ]  |
 *        '------+------'-------------'------+------' '------+------'-------------'------+------'
 *                             |SPACE |CTLDEL|RAISE | |RAISE |CTLBAC|SPACE |
 *                             |   +  |------+------' '------+------|  +   |
 *                             |SHIFT |GUIquo|LOWER | |LOWER |GUIquo|SHIFT |
 *                             +------'------+------' '------+------'------+
 */

[_BASE] = LAYOUT( \
  TD(Q_TAB), KC_W, KC_E, KC_R, KC_T,                                               KC_Y, KC_U, KC_I,    KC_O,   KC_P,          \
  TD(A_ESC), KC_S, KC_D, KC_F, KC_G,                                               KC_H, KC_J, KC_K,    KC_L,   TD(SCLN_ENT),  \
  KC_Z, KC_X, KC_C, KC_V, KC_B,                                                    KC_N, KC_M, KC_COMM, KC_DOT, TD(SLSH_BSLS), \
        ALT_T(KC_EQL), KC_MINS,                                                                KC_LBRC, KC_RBRC,               \
                          SFT_SPC,                                                 SFT_SPC,                                    \
                          CTL_T(KC_DEL),  OSL(_RAISE),  TT(_RAISE), CTL_T(KC_BSPC),                                            \
                          GUI_T(KC_QUOT), OSL(_LOWER),  TT(_LOWER), GUI_T(KC_QUOT)
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      | mbn2 |  mup | mbn1 |      |                             |      | VOL+ | mute | VOL- | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |wheldn| mleft| mdown|mright|whelup|                             | left | down | up   |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             |      |      |      |      |      |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |reset |      |                                                         |      |reset |
 *        '------+------'-------------'------+------' '------+------'-------------'------+------'
 *                             |      |      |      | |      |      |      |
 *                             |      |------+------' '------+------|      |
 *                             |      |      |      | |      |      |      |
 *                             +------'------+------' '------+------'------+
 */

[_RAISE] = LAYOUT( \
  ____, KC_MB2,  KC_MU, KC_MB1, ____,                           ____,    KC_VOLU, KC_MUTE, KC_VOLD,  KC_PGUP,    \
  KC_MS_WH_DOWN, KC_ML, KC_MD, KC_MR, KC_MS_WH_UP,              KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PGDOWN,  \
  ____, ____, ____, ____, ____,                 ____,    ____,    ____,    ____,     ____,       \
           RESET,   ____,                                                          ____,   RESET,                \
                                   ____,                        ____,                                            \
                                        ____, ____,  ____, ____,                                                 \
                                        ____, ____,  ____, ____                                                  \
),
/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1 ` |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |      |      |
 *        '------+------'-------------'------+------' '------+------'-------------'------+------'
 *                             |      |      |      | |      |      |      |
 *                             |      |------+------' '------+------|      |
 *                             |      |      |      | |      |      |      |
 *                             +------'------+------' '------+------'------+
 */

[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                           KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
  TD(ONE_GRV), KC_2,   KC_3,    KC_4,   KC_5,                          KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                             KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  KC_F11,  KC_F12,                                                                        ____,    ____,             \
                                    ____,                        ____,                                               \
                                         ____, ____,  ____, ____,                                                    \
                                         ____, ____,  ____, ____                                                     \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
