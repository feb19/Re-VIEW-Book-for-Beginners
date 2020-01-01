= その他便利なこと

== Visual Studio Code を使用する

Visual Studio Code は Microsoft 社が開発するエディターです。Windows/macOS/Linux などの環境で使用することができ、しかも無料で使うことができ、近年非常に人気のあるツールです。

https://azure.microsoft.com/ja-jp/products/visual-studio-code/

Visual Studio Code はプラグインを利用することができ、Re:VIEW のプラグインをインストールすることで、Re:VIEW のシンタックスハイライトや、プレビューを表示することができるようになります。

https://marketplace.visualstudio.com/items?itemName=atsushieno.language-review

//image[visualstudiocode][Visual Studio Code で Re:VIEW のプレビューを表示しながら執筆する様子][scale=0.7]{
//}

== Shell Script 化してもっと簡単なコマンドにする

一章では PDF を生成するにあたって少し長いコマンドを使用しました。これを短いコマンドで実現できるようにするために Shell Script 化します。

@<code>{build.sh} ファイルとして、以下を @<b>{src ディレクトリがあるディレクトリ} に保存してください。

//list[buildsh][build.sh]{
#!/bin/sh
docker run --rm -v `pwd`/src:/work vvakame/review:4.0 /bin/sh \
-c "cd /work && review-pdfmaker config.yml"
//}

さらに、プログラムとして実行できる権限を与えます。

//list[chmod][build.sh ファイルをプログラムとして実行できるようにする]{
chmod 755 build.sh
//}

これで @<code>{build.sh} ファイルをプログラムとして実行できるようになりました。以下のようにして実行します。

//list[execbuildsh][build.sh を実行する]{
./build.sh
//}