# production_for_crypton

◯作品概要<br>
２つのWaveファイルを結合して一つのWaveファイルにする<br>
手法：バイナリ形式でWaveファイルを読みこみ<br>
①チャンクの更新<br>
②ファイルの結合<br>
<br><br>
◯使用方法<br>
・そのまま実行するとtest1.wav→test2.wav の順にファイルが結合されたファイル arranged.wav が生成されます。<br>
・結合するファイルを変更するには、40−42 のプログラム内の<br>
char outfile[] = "./test1.wav";  //読み込むファイルの指定<br>
char outfile_next[] = "./test2.wav";  //くっつけるファイルの指定<br>
char new_filename[] = "./arranged.wav"; // 生成するファイル名を設定<br>
これらのファイル名を変更することでアクセスするファイルを変更することができます。<br>

＜参考にしたサイト＞<br>
◯C++学習サイト<br>
・C++入門<br>
http://www.asahi-net.or.jp/~yf8k-kbys/newcpp0.html<br>
<br><br>
◯作品制作参考サイト<br>
・バイナリファイルの読み込みと書き込み　Ｃ＋＋<br>
http://gurigumi.s349.xrea.com/programming/binary.html<br>
<br><br>
・C/C++のファイル操作速度比較<br>
https://qiita.com/kurasho/items/c2abb79b4db516491fa4<br>
<br><br>
・構造体や変数をバイナリファイルで出力する<br>
https://jyn.jp/cpp-structure-file/<br>
<br><br>
・washiの備忘録　std::fstream でファイルサイズを取得<br>
http://washieagle.blogspot.com/2010/01/stdfstream.html<br>
<br><br>
◯waveファイルの学習<br>
https://www.youfit.co.jp/archives/1418<br>
作品制作に利用したwaveファイル sample.wavもこのサイト内のサンプルを用いた。<br>
<br><br>
sample1.wav,sample2.wav：魔王魂よりダウンロード<br>
