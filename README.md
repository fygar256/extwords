# extwords
# ラテン文字辞書ファイルから、先頭の単語の列を取り出すプログラム。

英和辞書ファイルなどから、単語列を抜き出すコードextword.cppです。

・英辞郎のダウンロード可能の辞書、

・PDSのejdic-hand-utf8.txt、

・stardictの辞書から「stardict-editor」で、DeCompileしたTab File

・英単語で始まって、セパレータがアルファベット以外で、\nで行が終わるファイル。

などに対応しています。

sed、awk等で書きたかったのですが、sed,awkは、基本的に、英辞郎のバイナリファイルは扱えませんので。。。

コンパイルの仕方:c++ extwords.cpp -o extwords

使い方:extwords dicfile

パッケージ extwordsには、extwordsの実行ファイルが、
パッケージ ewordsには、抽出された単語ファイルが入ってます。
