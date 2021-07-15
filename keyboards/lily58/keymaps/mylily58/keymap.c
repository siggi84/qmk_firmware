#include QMK_KEYBOARD_H
#include "keymap_icelandic.h"
#include "sendstring_icelandic.h"

/*
- Add home-row modifiers (but not on the homerow due to vim).

*/
enum layer_number {
  _QWERTY = 0,
  _QWERTG,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE,
  _FN,
  _NUMPAD,
  _SYM,
  _ICE
};

enum my_keycodes {
  KC_QWTY = SAFE_RANGE,
  KC_QWTG,
  KC_CMAK,
  MY_SLSH,
  MY_QUOT,
  MY_HAT,
  MY_EC,
  MY_YC,
  MY_UC,
  MY_IC,
  MY_OC,
  MY_AC,
};

// Thumb keys (only on gaming layer)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Thumb keys
#define MT_MOUR_GUI LT(_MOUSE, KC_LGUI)
#define MT_ICE_ESC LT(_ICE, KC_ESC)
#define MT_LOWE_SPC LT(_LOWER, KC_SPC)
#define MT_RAIS_ENT LT(_RAISE, KC_ENT)
/* #define MT_FUNL_DEL LT(_NUMPAD, KC_DEL) */
#define MT_PAD_BSPC LT(_FN, KC_BSPC)

// Home-row mods
#define MY_MOD1 KC_LGUI
#define MY_MOD2 KC_LALT
#define MY_MOD3 KC_LCTL
#define MY_MOD4 KC_LSFT

#define QM_A LGUI_T(IS_A)
#define QM_S LALT_T(IS_S)
#define QM_X RALT_T(IS_X)
#define QM_D LCTL_T(IS_D)
#define QM_F LSFT_T(IS_F)

#define QM_J RSFT_T(IS_J)
#define QM_K RCTL_T(IS_K)
#define QM_L LALT_T(IS_L)
#define QM_DOT RALT_T(IS_DOT)
#define QM_AE LGUI_T(IS_AE)

// Home-row mods (Colemak)
#define CM_A LGUI_T(IS_A)
#define CM_R LALT_T(IS_R)
#define CM_X RALT_T(IS_X)
#define CM_S LCTL_T(IS_S)
#define CM_T LSFT_T(IS_T)

#define CM_N RSFT_T(IS_N)
#define CM_E RCTL_T(IS_E)
#define CM_I LALT_T(IS_I)
#define CM_DOT RALT_T(IS_DOT)
#define CM_O LGUI_T(IS_O)

// Home-row mods ICE
#define MY_ETH RSFT_T(IS_ETH)


#define SFTQUO RSFT_T(IS_ACUT)

enum combos {
  QW_TAB,
  FP_LBRC,
  LU_RBRC,
  PB_LCBR,
  JL_RCBR,
  HCOMM_SCLN,
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM fp_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM lu_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM pb_combo[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM hcomm_combo[] = {KC_H, KC_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
  [FP_LBRC] = COMBO(fp_combo, IS_LBRC),
  [LU_RBRC] = COMBO(lu_combo, IS_RBRC),
  [PB_LCBR] = COMBO(pb_combo, IS_LCBR),
  [JL_RCBR] = COMBO(jl_combo, IS_RCBR),
  [HCOMM_SCLN] = COMBO(hcomm_combo, IS_SCLN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Ð   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Ö   | SFTA |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  | SFTÆ |  '/" |     
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  | CTLRC|   V  |   B  |-------|    |-------|   N  |   M  |CTLR, |   .  |   Þ  |  Ö   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |  ESC | /Space  /       \ Enter\  |BackSP|  RALT | RGUI |
 *                   |      |      | MOUSE|/ LOWER /         \RAISE \ |      |   FN  |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  _______,   IS_1,   IS_2,    IS_3,    IS_4,    IS_5,                     IS_6,    IS_7,    IS_8,    IS_9,    IS_0,    IS_ODIA, \
  KC_TAB,    IS_Q,   IS_W,    IS_E,    IS_R,    IS_T,                     IS_Y,    IS_U,    IS_I,    IS_O,    IS_P,    IS_ETH, \
  IS_ODIA,   QM_A,   QM_S,    QM_D,    QM_F,    IS_G,                     IS_H,    QM_J,    QM_K,    QM_L,    QM_AE,   IS_ACUT, \
  MY_SLSH,   IS_Z,   QM_X,    IS_C,    IS_V,    IS_B, KC_LBRC,  KC_MINS,  IS_N,    IS_M,    KC_COMM, QM_DOT, IS_THRN,  MY_QUOT, \
                     _______, MT_MOUR_GUI, MT_ICE_ESC, MT_LOWE_SPC,MT_RAIS_ENT, KC_BSPC, KC_DEL, _______\
),

 [_QWERTG] = LAYOUT( \
  KC_ESC,   IS_1,   IS_2,    IS_3,    IS_4,    IS_5,                     IS_6,    IS_7,    IS_8,    IS_9,    IS_0,    IS_ODIA, \
  KC_TAB,   IS_Q,   IS_W,    IS_E,    IS_R,    IS_T,                     IS_Y,    IS_U,    IS_I,    IS_O,    IS_P,    IS_ETH, \
  KC_LSFT,  IS_A,   IS_S,    IS_D,    IS_F,    IS_G,                     IS_H,    IS_J,    IS_K,    IS_L,    IS_AE,   SFTQUO, \
  KC_LCTL,  IS_Z,   IS_X,    IS_C,    IS_V,    IS_B, KC_LBRC,  KC_MINS,  IS_N,    IS_M,    IS_COMM, IS_DOT,  IS_THRN, IS_ODIA, \
                        KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_ENT, RAISE, KC_BSPC, KC_RALT\
),
/* COLEMAK_DHm
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   Æ  |  Ð   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ShEs |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |'/Shi |     
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   Þ  |  Ö   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |  ESC | /Space  /       \ Enter\  |BackSP|  RALT | RGUI |
 *                   |      |      | LALT |/ LOWER /         \RAISE \ |      |       |      |
 *                   `----------------------------'           '------''--------------------'
 */
 /* [_COLEMAK] = LAYOUT( \ */
 /*  _______,  IS_1,   IS_2,    IS_3,    IS_4,    IS_5,                     IS_6,    IS_7,    IS_8,    IS_9,    IS_0,    IS_ODIA, \ */
 /*  KC_TAB,   IS_Q,   IS_W,    IS_F,    IS_P,    IS_B,                     IS_J,    IS_L,    IS_U,    IS_Y,    IS_AE,   IS_ETH, \ */
 /*  IS_ODIA,  CM_A,   CM_R,    CM_S,    CM_T,    IS_G,                     IS_M,    CM_N,    CM_E,    CM_I,    CM_O ,   TD(TD_ACUT_QUES), \ */
 /*  _______,  IS_Z,   IS_X,    IS_C,    IS_D,    IS_V, KC_LBRC,  KC_MINS,  IS_K,    IS_H,    IS_COMM, IS_DOT,  IS_THRN, TD(TD_QUOT_DQUO), \ */
 /*                    _______, MT_MOUR_GUI, MT_ICE_ESC, MT_LOWE_SPC,MT_RAIS_ENT, KC_BSPC, KC_DEL, _______\ */
/* ), */

     [_COLEMAK] = LAYOUT( \
  _______,   IS_1,   IS_2,    IS_3,    IS_4,    IS_5,                     IS_6,    IS_7,    IS_8,    IS_9,    IS_0,    _______, \
  _______,   IS_Q,   IS_W,    IS_F,    IS_P,    IS_B,                     IS_J,    IS_L,    IS_U,    IS_Y, MY_QUOT,    _______, \
  _______,   CM_A,   CM_R,    CM_S,    CM_T,    IS_G,                     IS_M,    CM_N,    CM_E,    CM_I,    CM_O,   _______, \
  _______,   IS_Z,   QM_X,    IS_C,    IS_D,    IS_V, KC_LBRC,  KC_MINS,  IS_K,    IS_H,    KC_COMM, QM_DOT, MY_SLSH,  _______, \
                     _______, MT_MOUR_GUI, MT_ICE_ESC, MT_LOWE_SPC,MT_RAIS_ENT, MT_PAD_BSPC, KC_DEL, _______\
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   /  |   _  |   -  |   (  |   )  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |   µ  |   °  |   €  |      |-------|    |-------|   =  |   +  |      |      |   *  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |  ESC | /Space  /       \ Enter\  |BackSP|  RALT | RGUI |
 *                   |      |      | LALT |/ LOWER /         \RAISE \ |      |       |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_LOWER] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______,  _______, _______, _______, _______, _______,\
  _______, IS_1,    IS_2,    IS_3,    IS_4,    IS_5,                      IS_6,     IS_7,    IS_8,    IS_9,    IS_0,    _______, \
  _______, IS_EXLM, IS_AT,   IS_HASH, IS_DLR,  IS_PERC,                   IS_SLSH,  IS_UNDS, IS_MINS, IS_LPRN, IS_RPRN, _______, \
  _______, _______, IS_MICR, IS_DEG,  IS_EURO, _______, _______, _______, IS_EQL,   IS_PLUS, _______, _______, IS_ASTR, _______, \
                     _______, MT_MOUR_GUI, MT_ICE_ESC, MT_LOWE_SPC,MT_RAIS_ENT, MT_PAD_BSPC, KC_DEL, _______\
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   >  |   }  |   ]  |   )  |  |   |                    | MUTE | VOLD | VOLU | MPLY | MPRV | MNXT |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   <  |   {  |   [  |   (  |  \   |-------.    ,-------| Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |   ^  |   &  |   ~  |  "   |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |  ESC | /Space  /       \ Enter\  |BackSP|  RALT | RGUI |
 *                   |      |      | LALT |/ LOWER /         \RAISE \ |      |       |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  XXXXXXX, IS_RCBR, IS_RABK, IS_RBRC, IS_RPRN, IS_PIPE,                     KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, XXXXXXX,  \
  XXXXXXX, IS_LCBR, IS_LABK, IS_LBRC, IS_LPRN, IS_BSLS,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, _______, \
  XXXXXXX, IS_GRV,  MY_HAT,  IS_AMPR, IS_TILD, _______, _______, _______,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS, _______, \
                     _______, MT_MOUR_GUI, MT_ICE_ESC, MT_LOWE_SPC,MT_RAIS_ENT, MT_PAD_BSPC, KC_DEL, _______\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |QWERTY|      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| HOME | PGDN | PGUP |  END |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |COLEMK|      |      |-------|    |-------|      |      |      |      |      |      | 
 * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      | LGUI |  ESC | /Space  /       \ Enter\  |BackSP|  RALT | RGUI |
 *                   |      |      | LALT |/ LOWER /         \RAISE \ |      |       |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_QWTY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QWTG,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, KC_CMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                              _______, _______, _______, _______, _______,  _______, _______, _______ \
  ),

  [_MOUSE] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, XXXXXXX, \
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MSTP, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_MUTE, XXXXXXX,\
                              _______, _______, _______, _______, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, _______ \
  ),

/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F12 |  F7  |  F8  |  F9  | PSCR |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F11 |  F4  |  F5  |  F6  | SLCK |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  F10 |  F1  |  F2  |  F3  | PAUS |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | LGUI |  ESC | /Space  /       \ Enter\  |BackSP|  RALT | RGUI |
 *                   |      |      | LALT |/ LOWER /         \RAISE \ |      |       |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_FN] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                   XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, \
  XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX,\
                             _______, KC_APP,  KC_ESC,  KC_SPC,  XXXXXXX, XXXXXXX, _______, _______ \
  ),
  
  [_NUMPAD] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, IS_LBRC,   IS_7,    IS_8,    IS_9, IS_RBRC,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, IS_RABK,   IS_4,    IS_5,    IS_6, IS_EQL,                     XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, \
  XXXXXXX, IS_GRV,    IS_1,    IS_2,    IS_3, IS_BSLS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,  XXXXXXX,\
                                XXXXXXX, IS_DOT, IS_0, IS_MINS,  _______, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

 [_SYM] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______,  _______, _______, _______, _______, _______,\
  _______, IS_LCBR, IS_AMPR, IS_ASTR, IS_LPRN, IS_RCBR,                   XXXXXXX,  IS_MICR, IS_DEG,  IS_EURO, XXXXXXX,    _______, \
  _______, IS_LABK, IS_DLR,  IS_PERC, MY_HAT,  IS_PLUS,                   XXXXXXX,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, \
  _______, IS_TILD, IS_EXLM, IS_AT,   IS_HASH, IS_PIPE, _______, _______, XXXXXXX,  XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, _______, \
                             _______, IS_LPRN, IS_RPRN, IS_UNDS, _______, _______, _______, _______\
),

  [_ICE] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, IS_THRN, MY_UC,  MY_YC,    IS_ODIA, XXXXXXX, \
  XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                   XXXXXXX, MY_ETH,  MY_EC,  MY_IC,    MY_OC,   XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, IS_AE,  MY_AC,  XXXXXXX, XXXXXXX,\
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX \
  )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    /* oled_write_ln(read_layer_state(), false); */
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            if (biton32(default_layer_state) == _QWERTY) {
                oled_write_P(PSTR("Qwerty\n"), false);
            }
            else if (biton32(default_layer_state) == _QWERTG) {
                oled_write_P(PSTR("Gaming\n"), false);
            }
            else {
                oled_write_P(PSTR("Colemak\n"), false);
            }
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("Fn\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _ICE:
            oled_write_P(PSTR("Ice\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

void process_acut(bool rec_event, uint8_t mod_state, uint16_t keycode) {
       if (rec_event) {
           if (mod_state & MOD_MASK_SHIFT) {
               del_mods(MOD_MASK_SHIFT);
           }
           register_code(IS_ACUT);
           unregister_code(IS_ACUT);
           set_mods(mod_state);
           register_code(keycode);
       } else {
           unregister_code(keycode);
       }

    }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
  }
    // set_timelog();
    uint8_t mod_state = get_mods();
    switch (keycode) {
        case KC_QWTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_CMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_QWTG:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTG);
            }
            return false;
        case MY_SLSH:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    SEND_STRING("?");
                    set_mods(mod_state);
                } else {
                    SEND_STRING("/");
                }
            }
            return false;
        case MY_QUOT:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    SEND_STRING("\"");
                    set_mods(mod_state);
                } else {
                    tap_code(IS_QUOT);
                    /* SEND_STRING("'"); */
                }
            }
            return false;
        case MY_HAT:
            if (record->event.pressed) {
                SEND_STRING("^ ");
            }
            return false;
        case MY_EC:
            process_acut(record->event.pressed, mod_state, IS_E);
            return false;
        case MY_YC:
            process_acut(record->event.pressed, mod_state, IS_Y);
            return false;
        case MY_UC:
            process_acut(record->event.pressed, mod_state, IS_U);
            return false;
        case MY_IC:
            process_acut(record->event.pressed, mod_state, IS_I);
            return false;
        case MY_OC:
            process_acut(record->event.pressed, mod_state, IS_O);
            return false;
        case MY_AC:
            process_acut(record->event.pressed, mod_state, IS_A);
            return false;
    }
  return true;
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CM_T:
            return true;
        case CM_N:
            return true;
        case MT_ICE_ESC:
            return true;
        case MT_RAIS_ENT:
            return true;
        case MT_LOWE_SPC:
            return true;
        default:
            return false;
    }
}
