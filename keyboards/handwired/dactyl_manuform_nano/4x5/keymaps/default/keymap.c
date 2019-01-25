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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |ALT/  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  '   |   -  |                                                         |   [  |   ]  |
 *        '------+------'-------------'------+------' '------+------'-------------'------+------'
 *                             |SPACE |CTLTAB|RAS_~`| |RASDEL|CTLBAC|SPACE |
 *                             |   +  |------+------' '------+------|  +   |
 *                             |ESCAPE|GUIESC|LOW_=+| |LOW_\||GUIENT|ESCAPE|
 *                             +------'------+------' '------+------'------+
 */

[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E, KC_R, KC_T,                                                    KC_Y, KC_U, KC_I,    KC_O,   KC_P,           \
  KC_A, KC_S, KC_D, KC_F, KC_G,                                                    KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,        \
  KC_Z, KC_X, KC_C, KC_V, KC_B,                                                    KC_N, KC_M, KC_COMM, KC_DOT, ALT_T(KC_SLSH), \
        KC_QUOT, KC_MINS,                                                                               KC_LBRC, KC_RBRC,       \
                          SFT_SPC,                                                 SFT_SPC,                                     \
                          CTL_T(KC_TAB),  LT(_RAISE, KC_GRV),  LT(_RAISE, KC_DEL), CTL_T(KC_BSPC),                              \
                          GUI_T(KC_ESC),  LT(_LOWER, KC_EQL),  LT(_LOWER, KC_BSLS), GUI_T(KC_ENT)
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * | mbn2 | mbn3 |  mup |mbn4  |whelup|                             |      | VOL+ | mute | VOL- | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * | mbn1 | mleft| mdown|mright|wheldn|                             | left | down | up   |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             |      |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |reset |      |                                                         |      |reset |
 *        '------+------'-------------'------+------' '------+------'-------------'------+------'
 *                             |      |      |      | |      |      |      |
 *                             |      |------+------' '------+------|      |
 *                             |      |      |      | |      |      |      |
 *                             +------'------+------' '------+------'------+
 */

[_RAISE] = LAYOUT( \
  KC_MB2, KC_MB3,  KC_MU, KC_MB4, KC_MS_WH_UP,                  ____,    KC_VOLU, KC_MUTE, KC_VOLD,  KC_PGUP,    \
  KC_MB1, KC_ML,   KC_MD, KC_MR,  KC_MS_WH_DOWN,                KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PGDOWN,  \
  ____,    ____,   ____,  ____,   ____,                         ____,    KC_SLSH, KC_BSLS, KC_QUES,  KC_PIPE,    \
           RESET,   ____,                                                          ____,    RESET,               \
                                   ____,                        ____,                                            \
                                        ____, ____,  ____, ____,                                                 \
                                        ____, ____,  ____, ____                                                  \
),
/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * | F1   | F2   | F3   | F4   | F5   |                             |  F6  | F7   |  F8  |  F9  |  F10 |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | F11  | F12  |                                                         |  -   |  =   |
 *        '------+------'-------------'------+------' '------+------'-------------'------+------'
 *                             |      |      |      | |      |      |      |
 *                             |      |------+------' '------+------|      |
 *                             |      |      |      | |      |      |      |
 *                             +------'------+------' '------+------'------+
 */

[_LOWER] = LAYOUT( \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                           KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                              KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                             KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  \
  KC_F11,  KC_F12,                                                                        KC_MINS, KC_EQL,           \
                                    ____,                        ____,                                               \
                                         ____, ____,  ____, ____,                                                    \
                                         ____, ____,  ____, ____                                                     \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
