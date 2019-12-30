#include "dactyl_manuform_nano.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _MIDI 3
#define _MIDIU 4

// Fillers to make layering more clear
#define ____ KC_TRNS

#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ESC SFT_T(KC_ESC)

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
  EXLM_GRV = 0,
  SCLN_ENT = 1,
  A_ESC = 2,
  SLSH_BSLS = 3
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [EXLM_GRV]  = ACTION_TAP_DANCE_DOUBLE(KC_EXLM, KC_GRV),
  [SCLN_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_ENT),
  [A_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC),
  [SLSH_BSLS]  = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BSLS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |  p   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * | CTL a|   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  | ;    |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  | /    |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |  =   |  -   |                                                         |   [  |   ]  |
 *        '------+------'-------------'------+------' '------+------'-------------'------+------'
 *                             |SFTSPC|CTLTAB|RAIENT| |RAIBAC|ALTENT|SFTSPC|
 *                             +------|------+------' '------+------|------+
 *                                    |GUIESC|LOWgrv| |LOWquo|GUI \ |
 *                                    +------'------+ +------'------+
 */

[_BASE] = LAYOUT( \
  KC_Q, KC_W,  KC_E, KC_R, KC_T,                                           KC_Y, KC_U, KC_I,    KC_O,   KC_P,    \
  CTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,                                     KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, \
  KC_Z,        KC_X, KC_C, KC_V, KC_B,                                     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
               KC_EQL, KC_MINS,                                            KC_LBRC, KC_RBRC,                     \
                       SFT_SPC,                                            SFT_SPC,                              \
               CTL_T(KC_TAB), LT(_RAISE, KC_DEL),         LT(_RAISE, KC_BSPC), ALT_T(KC_ENT),                    \
               GUI_T(KC_ESC), LT(_LOWER, KC_GRV),         LT(_LOWER, KC_QUOT), GUI_T(KC_BSLS)
),

/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |mbn2  |wheldn|  mup |whelup|      |                             |      | VOL- | mute | VOL+ | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |mbn1  | mleft| mdown|mright|      |                             | left | down | up   |right | PgDn |
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
  KC_MB2, KC_MS_WH_DOWN,  KC_MU, KC_MS_WH_UP, ____,             ____,    KC_VOLD, KC_MUTE, KC_VOLU,  KC_PGUP,    \
  KC_MB1, KC_ML, KC_MD, KC_MR, ____,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PGDOWN,  \
  ____, ____, ____, ____, ____,                                 ____,    ____,    ____,    ____,     ____,       \
        RESET,   ____,                                                            ____,    RESET,                \
                              TG(_MIDI),                        ____,                                            \
                                        ____, ____,  ____, ____,                                                 \
                                        ____, ____,  ____, ____                                                  \
),

/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * |  ! ` |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   1  |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  10  |
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
  TD(EXLM_GRV), KC_AT, KC_HASH, KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                              KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  ____, ____, ____, ____, ____,                                        ____,    ____,    ____,    ____,     ____,    \
  ____,   ____,                                                                        ____,    ____,             \
                                    ____,                        ____,                                               \
                                         ____, ____,  ____, ____,                                                    \
                                         ____, ____,  ____, ____                                                     \
),


#if defined(MIDI_ENABLE) && defined(MIDI_ADVANCED)
  [_MIDI] = LAYOUT( \
  MI_Cs, MI_Ds, KC_NO, MI_Fs, MI_Gs,                          MI_Cs_1, MI_Ds_1, KC_NO,   MI_Fs_1, MI_Gs_1, \
  MI_C,  MI_D,  MI_E,  MI_F,  MI_G,                           MI_C_1,  MI_D_1,  MI_E_1,  MI_F_1,  MI_G_1,  \
  KC_NO, MI_As, KC_NO, KC_NO, KC_NO,                          KC_NO,   KC_NO,   MI_As_1, KC_NO,   KC_NO,    \
         MI_A,  MI_B,                                                           MI_A_1,  MI_B_1,           \
                           TT(_MIDIU),                        TT(_MIDIU),                  \
                                 ____, ____,            ____, ____,                                 \
                            TG(_MIDI), ____,            ____, ____                                  \
),
  [_MIDIU] = LAYOUT( \
  MI_Cs_2, MI_Ds_2, ____,   MI_Fs_2, MI_Gs_2,            MI_Cs_3, MI_Ds_3, ____,    MI_Fs_3, MI_Gs_3, \
  MI_C_2,  MI_D_2,  MI_E_2, MI_F_2,  MI_G_2,             MI_C_3,  MI_D_3,  MI_E_3,  MI_F_3,  MI_G_3,  \
  MI_As_2, ____,    ____,   ____,    ____,               ____,    ____,    MI_As_3, ____,    ____,    \
  MI_A_2,  MI_B_2,                                                         MI_A_3,  MI_B_3,           \
                                ____,                  ____,                                    \
                                ____, ____,            ____, ____,                                 \
                                ____, ____,            ____, ____                                  \
  ),
#endif
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
