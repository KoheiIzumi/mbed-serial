mbed-serial
===========

mbed(LPC1768)でPCとシリアル通信を行うプログラム

* キーボードの入力を読み込む
* キーボードの入力を開始すると、シリアル送信はストップ
* キーボードの入力が終わり、Enterを押すとシリアル送信が開始
* 次のキーボード入力まで、シリアル送信を続ける
* onを送ると、LED1がONになり、offを送るとLED1がOFFになります

以上のような仕様になっています
