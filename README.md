# QMK firmware (odanny用)

qmk firmwareのリポジトリに上書きする感じで使ってください。

https://github.com/qmk/qmk_firmware

<br>

## 編集手順

1. QMKMSYS を開く。※環境設定はQMK Firmware 0.16.9
1. キーマップを修正。`\qmk_firmware\keyboards\handwired\dactyl_manuform\5x6\keymaps\default\keymap.c`
1. hexファイルを作成。`make handwired/dactyl_manuform/5x6:default`, `qmk compile -kb handwired/dactyl_manuform/5x6 -km default`
1. WEBで書き込み。[Pro Micro Web Updater](https://sekigon-gonnoc.github.io/promicro-web-updater/index.html)

<br>

## Tightyl
scadやstlはこちら。

https://github.com/dannyso16/dactyl-manuform-tight

