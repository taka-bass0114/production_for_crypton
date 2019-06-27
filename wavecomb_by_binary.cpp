// waveconbiation_by_binary.cpp

/***********
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

◯作品概要
２つのWaveファイルを結合して一つのWaveファイルにする
手法：バイナリ形式でWaveファイルを読みこみ
①チャンクの更新
②ファイルの結合

◯waveファイルの学習：
https://www.youfit.co.jp/archives/1418
作品制作に利用したwaveファイル sample.wavもこのサイト内のサンプルを用いた。


************/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    char outfile[] = "./sample.wav";  //読み込むファイルの指定
    char outfile_next[] = "./test2.wav";  //くっつけるファイルの指定
    char new_filename[] = "./arranged.wav"; // 生成するファイル名を設定

    ofstream fout;

    fout.open(new_filename, ios::out|ios::binary|ios::trunc);

    ifstream fin( outfile, ios::in | ios::binary );
    //  ファイルを開く
    //  ios::in は読み込み専用  ios::binary はバイナリ形式

    if (!fin){
        cout << "ファイル fin が開けません";
        return 1;
    }
    //  ファイルが開けなかったときの対策

    ifstream fin2( outfile_next, ios::in | ios::binary );
    //  ファイルを開く
    //  ios::in は読み込み専用  ios::binary はバイナリ形式

    if (!fin2){
        cout << "ファイル fin2 が開けません";
        return 1;
    }
    //  ファイルが開けなかったときの対策

    if (!fout) {
        cout << "ファイル fout が開けません";
        return 1;
    }
    //  ファイルが開けなかったときのエラー表示

    fin2.seekg ( 44*sizeof (char) );  //ポインタの位置を移動

    /* ファイル２の長さを調べ、ファイル１の長さフラグを更新する */
    fin.seekg ( 44*sizeof(char) ); // finのポインタ位置を移動

    uint data　= 0;

    /* 以下参考：
    http://washieagle.blogspot.com/2010/01/stdfstream.html
     */

    fin.seekg(0, fstream::end);//ファイル末尾を探す
	  uint eofPos = fin.tellg();//ファイル末尾インデクスを取得

	  fin.clear();//先頭にもどるために一度clear()をかける。これをしないと次のseekg()でコケるときがある。
	  fin.seekg(0, fstream::beg);//ファイル先頭に戻る

    fin.seekg ( 44*sizeof(char) ); // finのポインタ位置を移動

	  uint begPos = fin.tellg();//ファイル先頭インデクスを取得
	  uint size = eofPos - begPos;//末尾-先頭でファイルサイズを計算

    /* 参考ここまで */

    /* ファイルの大きさの確認その１ */

    data += size;
    cout << outfile << "のデータ部分のサイズ：" << data <<endl;

    /* 以下参考：
    http://washieagle.blogspot.com/2010/01/stdfstream.html
     */

    fin2.seekg(0, fstream::end);//ファイル末尾を探す
	  eofPos = fin2.tellg();//ファイル末尾インデクスを取得

	  fin2.clear();//先頭にもどるために一度clear()をかける。これをしないと次のseekg()でコケるときがある。
	  fin2.seekg(0, fstream::beg);//ファイル先頭に戻る

    fin2.seekg ( 44*sizeof(char) ); // finのポインタ位置を移動

	  begPos = fin2.tellg();//ファイル先頭インデクスを取得
	  size = eofPos - begPos;//末尾-先頭でファイルサイズを計算

    /* 参考ここまで */

    data += size;
    cout << outfile_next << "のデータ部分のサイズ；" << size <<endl;
    cout << "生成される"<< new_filename <<"データのサイズ：" << data <<endl;

    cout<<endl;

    fin.clear();//先頭にもどるために一度clear()をかける。これをしないと次のseekg()でコケるときがある。
	  fin.seekg(0, fstream::beg);//ファイル先頭に戻る

    fin2.clear();//先頭にもどるために一度clear()をかける。これをしないと次のseekg()でコケるときがある。
	  fin2.seekg(0, fstream::beg);//ファイル先頭に戻る

    fin2.seekg ( 44*sizeof(char) ); // finのポインタ位置を移動

    fout<<fin.rdbuf();
    fout<<fin2.rdbuf();

    fin.close();  //ファイルを閉じる
    fin2.close();  //ファイルを閉じる
    fout.close();

    // ファイルサイズの更新。チャンク２箇所を更新する
    /*参考：
    https://jyn.jp/cpp-structure-file/
    */

    fstream fout2( new_filename, ios::in | ios::out | ios::binary );

    if (!fout2){
        cout << "ファイル fout2 が開けません";
        return 1;
    }

    fout2.seekg(4*sizeof(char));

    uint tmp = data -8; // 以下１行のための変数

    fout2.write((char *)&(tmp),4*sizeof(char));

    tmp -= 118;

    fout2.seekg(40*sizeof(char));

    fout2.write((char *)&(data),4*sizeof(char));

    fout2.close();

    return 0;
}
