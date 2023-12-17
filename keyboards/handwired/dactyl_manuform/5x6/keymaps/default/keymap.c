#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FN     1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define EISU LALT(KC_GRV)
#define S_BSLAH  SFT_T(KC_INT1) // ホールドでシフト、タップで\ KC_BSLASH
#define A_DOWN  ALT_T(KC_DOWN) // ホールドでALT、タップで下キー
#define C_RGHT  CTL_T(KC_RGHT) // ホールドでCTRL、タップで右キー
#define G_LEFT  GUI_T(KC_LEFT) // ホールドでWIN、タップで左キー
#define A_UP    RALT_T(KC_UP  ) // ホールドでALT、タップで上キー
#define F_DEL  LT(_FN, KC_DEL) //ホールドでFNレイヤ、タップでDEL
#define F_BSPC LT(_FN, KC_BSPC)//ホールドでFNレイヤ、タップでBSPC

#define GUICH RGUI(KC_TAB) // ウィンドウ切り替え
#define PRTSC SGUI(KC_S) // 画面スクショ
#define SNAP RGUI(KC_Z) // スナップレイアウト
#define PIPE S(KC_INT3) // |

// Tap Danceの設定 一回押しでウィンドウ切り替え、2回押しでスクショ
// Tap Danceの設定 一回押しで変換(かな）、2回押しで無変換（英数）
enum {
  TD_MACRO = 0
  ,TD_IME = 1
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_MACRO] = ACTION_TAP_DANCE_DOUBLE(GUICH, PRTSC)
  , [TD_IME] = ACTION_TAP_DANCE_DOUBLE(KC_INT5, KC_INT4)
};

 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,
        KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,S_BSLAH,
          TD(TD_MACRO) , A_UP  , G_LEFT,                                                        C_RGHT ,A_DOWN ,TD(TD_IME),
                                         F_DEL ,KC_SPC ,                         KC_ENT, F_BSPC
    ),

    [_FN] = LAYOUT_5x6(
        _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_EQL,KC_INT3,
        _______,_______, KC_7  , KC_8  , KC_9  ,_______,                        _______,_______, KC_UP ,_______,_______,_______,
        _______,_______, KC_4  , KC_5  , KC_6  ,_______,                        _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,
        _______,_______, KC_1  , KC_2  , KC_3  ,_______,                        _______,_______,_______,_______,_______,_______,
                 GUICH , KC_0  , KC_DOT,                                                        _______,_______,_______,
                                        _______,_______,                        _______,_______
    )
};
