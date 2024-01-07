#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FN     1

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define EISU LALT(KC_GRV)
#define A_RGHT  ALT_T(KC_RGHT) // ホールドでALT、タップで右キー
#define A_LEFT  ALT_T(KC_LEFT) // ホールドでALT、タップで左キー

#define C_DEL  CTL_T(KC_DEL) // ホールドでCTRL、タップでDEL
#define C_BSPC  CTL_T(KC_BSPC) // ホールドでCTRL、タップでBSPC

#define S_BSLAH  SFT_T(KC_INT1) // ホールドでシフト、タップで\ KC_BSLASH

// #define G_LEFT  GUI_T(KC_LEFT) // ホールドでWIN、タップで左キー
#define G_HNKN GUI_T(KC_INT5) //ホールドでWIN、タップで変換(IME ON)
#define G_MHNKN GUI_T(KC_INT4) //ホールドでWIN、タップで無変換(IME OFF)

#define F_SPC  LT(_FN, KC_SPC) //ホールドでFNレイヤ、タップでSPACE
#define F_ENT LT(_FN, KC_ENT)//ホールドでFNレイヤ、タップでENTER

#define GUICH RGUI(KC_TAB) // ウィンドウ切り替え
#define PRTSC SGUI(KC_S) // 画面スクショ
#define SNAP RGUI(KC_Z) // スナップレイアウト
#define PIPE S(KC_INT3) // |

 
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_LBRC,
        KC_CAPS, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,S_BSLAH,
                 GUICH, G_HNKN, A_LEFT,                                                        A_RGHT ,G_MHNKN, PRTSC ,
                                         C_DEL , F_SPC ,                         F_ENT, C_BSPC
    ),
  
    [_FN] = LAYOUT_5x6(
        _______, KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                         KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_EQL,KC_INT3,
        _______,_______, KC_7  , KC_8  , KC_9  ,_______,                        _______,_______, KC_UP ,_______,_______,KC_RBRC,
        _______,_______, KC_4  , KC_5  , KC_6  ,_______,                        _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,KC_NUHS,
        _______,_______, KC_1  , KC_2  , KC_3  ,_______,                        _______,_______,_______,_______,_______,_______,
                  KC_0 , KC_DOT,_______,                                                        _______,_______,_______,
                                        _______,_______,                        _______,_______
    )
};
