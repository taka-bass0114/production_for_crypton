# production_for_crypton

◯作品概要
２つのWaveファイルを結合して一つのWaveファイルにする
手法：バイナリ形式でWaveファイルを読みこみ
①チャンクの更新
②ファイルの結合

◯使用方法
・そのまま実行するとtest1.wav→test2.wav の順にファイルが結合されたファイル arranged.wav が生成されます。
・結合するファイルを変更するには、40−42 のプログラム内の
char outfile[] = "./test1.wav";  //読み込むファイルの指定
char outfile_next[] = "./test2.wav";  //くっつけるファイルの指定
char new_filename[] = "./arranged.wav"; // 生成するファイル名を設定
これらのファイル名を変更することでアクセスするファイルを変更することができます。

＜参考にしたサイト＞
◯C++学習サイト
・C++入門
http://www.asahi-net.or.jp/~yf8k-kbys/newcpp0.html

◯作品制作参考サイト
・バイナリファイルの読み込みと書き込み　Ｃ＋＋
http://gurigumi.s349.xrea.com/programming/binary.html

・C/C++のファイル操作速度比較
https://qiita.com/kurasho/items/c2abb79b4db516491fa4

・構造体や変数をバイナリファイルで出力する
https://jyn.jp/cpp-structure-file/

・washiの備忘録　std::fstream でファイルサイズを取得
http://washieagle.blogspot.com/2010/01/stdfstream.html

◯waveファイルの学習
https://www.youfit.co.jp/archives/1418
作品制作に利用したwaveファイル sample.wavもこのサイト内のサンプルを用いた。

sample1.wav,sample2.wav：魔王魂よりダウンロード
