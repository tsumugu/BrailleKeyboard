# About
点字と同じように入力できるキーボードのためのプログラム。点字の6つの点とテンキーのキーを対応させることで、同じように入力できる。
![キーマップ](https://i.readme.tsumugu2626.xyz/hgrdpDicTO0.png)
# 必要なもの
- Raspberry Pi Zero
- Pro Micro
- テンキー(型番: TNK-SU231SL)
- LED 6個
- ケーブル類
# 配線方法
![配線](https://i.readme.tsumugu2626.xyz/FKozLOLzbQJ.png)
## Raspberry Piの役割
1. テンキーの入力を受け取り、ローマ字入力に変換、そのasciiコードをi2c通信でPro Microに送信する。
2. ステータスランプを、制御コードをi2c通信でPro Microに送信する。
## Pro Microの役割
1. Pro Microは接続された側からはUSBキーボードとして認識される。`Keyboard.h` を使用して、Raspberry Piからi2c通信で送られてきたasciiコードを `Keyboard.write` することでキーボードとして振る舞う。
2. Raspberry Piからi2c通信で送られてきた制御コードからステータスランプを制御する。
# プログラムの設定
## 1. Raspberry Pi側の設定
### 自動ログインと、main.jsの自動起動
[Raspberry Pi OS Lite版のノウハウ](https://qiita.com/tukiyo3/items/1d4bc86e9128611f7875) を参考に、自動ログインとmain.jsの自動起動を設定する。

```shell: .bash_login
nodejs /home/tsumugu/BrailleKeyboard/main.js
```
## 2. Pro Micro側の設定
Arduinoディレクトリに入っているスケッチを書き込む。