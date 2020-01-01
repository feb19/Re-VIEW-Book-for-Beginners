= Re:VIEW 概要と環境構築

//lead{
本書で使用する Re:VIEW を使えるようにしてみましょう。
//}

== Re:VIEW とは

Re:VIEW は OSS (Open Source Software) で、多くの同人サークルが技術本を書くときや、プロが書く商業本においても使われています。

https://github.com/kmuto/review/

Markdown 形式に似た構文（シンタックス）を用いて文章を書くことができ、Markdown 形式や PDF、EPUB、HTML など様々な形式に書き出すことができます。

//list[syntax of review][Re:VIEW の構文]{

= 表題

== 見出し

=== 小見出し

本文本文本文本文本文本文

 * リスト
 * リスト

//}

== Docker をインストールする

まず Docker をインストールをします。次の URL からダウンロードしてインストールします。

https://www.docker.com/products/docker-desktop

Docker とは OS などのシステムの基礎となるソフトウェアを仮想化し、様々なソフトウェアをその仮想化された環境下で実行できるツールで、すなわち不特定多数のエンジニア・システムに同じ環境を用意できる現代の開発に必要不可欠なツールです。

Docker を使うと、本を書くために必要となる多種多様なソフトウェアをお使いのマシンにインストールすることなく、Re:VIEW を実行できます。

Docker を使って Re:VIEW を実行できる環境＝「イメージ」を作ってくださった有志の方々（Re:VIEW も同様）のおかげです。

では Re:VIEW が実行できる Docker のイメージを取得して、これを元に Re:VIEW 形式で書いた文章を PDF 化してみましょう。

== Re:VIEW をセットアップする

Docker を使って、Re:VIEW が実行できる @<b>{Docker イメージ}を取得します。ターミナルを立ち上げて、以下のコマンドを入力します。

//list[installdockerimage][Docker イメージをインストール]{
docker pull vvakame/review:4.0
//}

これで Re:VIEW 4.0 に対応した Docker イメージが準備されました。

== Ruby をセットアップする

Re:VIEW で本を作るにあたっていくつか必要なファイルがあります。@<code>{review-init} コマンドというものを使うとそのファイルを準備することができます。

@<code>{review-init} コマンドは、@<b>{Ruby} で作られており、マシンに Ruby の環境を準備することでインストール、実行できます。

というわけで Ruby をお使いの Mac にインストールします。

まず macOS では @<b>{Xcode} が必要です。Xcode を Mac App Store からダウンロードします。インストールが終わったら以下を実行して、コマンドラインツールも使えるようにします。

//list[commandlinetools][コマンドライン・デベロッパーツールのインストール]{
xcode-select --install
//}

//image[commandlinetools][コマンドライン・デベロッパーツールをインストールする時に表示される許諾]{
//}

次に macOS 向けのパッケージマネージャの @<b>{Homebrew} のインストールです。ターミナルで以下を実行してください。

//list[homebrew][Homebrew をインストールする]{
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/ \
Homebrew/install/master/install)"
//}

@<code>{brew} コマンドが使えるようになったので、Ruby のバージョンマネージャ @<b>{rbenv} をインストールします。以下を一行ずつターミナルで実行していきます。

//list[rbenv][rbenv をインストールする]{
brew update

brew install rbenv ruby-build

echo 'eval "$(rbenv init -)"' >> ~/.bash_profile

source ~/.bash_profile

rbenv --version
//}

@<code>{rbenv} コマンドが使えるようになったので、@<b>{Ruby} をインストールします。現状インストールできる Ruby のバージョンを確認します。

//list[rbenvinstalll][Ruby インストールのためにバージョンを確認]{
rbenv install -l
//}

2.6.4 が執筆時点で安定バージョンかつ最新だったので、これをインストールして使えるようにします。以下を一行ずつターミナルで実行していきます。

//list[rubyinstall][Ruby 2.6.4 をインストールする]{
rbenv install 2.6.4

rbenv global 2.6.4

rbenv rehash
//}

これで Ruby が使える環境がお使いの Mac に整いました。

== review-init コマンドのインストールと実行

いよいよ @<code>{review-init} コマンドを使えるようにして、Re:VIEW 形式での必要なファイルを出力します。以下を一行ずつターミナルで実行していきます。

//list[install-review-init][review gemをインストールする]{
gem install review
rbenv rehash
//}

これで @<code>{review-init} コマンドが使えるようになりました。では必要なファイルを生成します。

//list[review-init][review-init を実行してファイルを生成する]{
review-init sample
//}

実行すると sample ディレクトリができ、以下のような構成になっています。

//list[sampledir][sample ディレクトリの中身]{
sample
├── Gemfile
├── Rakefile
├── catalog.yml
├── config.yml
├── doc
├── images
├── lib
├── sample.re
├── sty
└── style.css
//}

このうち、sty ディレクトリ、style.css、config.yml、catalog.yml が必要になります。

@<b>{sty ディレクトリ}と @<b>{style.css} は文章の見た目を定義するファイルです。好みに合わせてカスタマイズしてください。ネット上にこのファイルのカスタマイズ方法が色々見つかりますので、@<code>{style.css Re:VIEW} などで検索してください。

@<b>{config.yml} は本のメタデータ情報、レイアウト情報を決める重要なファイルです。タイトルや出版日、著者名などのメタデータや、A5 版か B5 版かだったり、一行に何文字入れるかなどのレイアウト情報を設定できます。

@<b>{catalog.yml} は目次ファイルです。本として構成する .re ファイルを指定します。

これらを @<b>{src} という名前のディレクトリを作成して、その中にコピーします。

//list[srcdir][src ディレクトリを作って、必要なファイルを入れる]{
src
├── catalog.yml
├── config.yml
├── sty
└── style.css
//}

== Re:VIEW 形式で文章を書く

この章の前半で掲載したような構文を用いて以下のような文章を作って、src ディレクトリに保存します。

//list[reviewsample][test.re - Re:VIEW 形式の文章]{
= こんにちは

== はじめまして

Re:VIEW で書く文章です！
//}

catalog.yml で今作った test.re ファイルを指定します。

//list[catalogyml][catalog.yml の中身]{
PREDEF:

CHAPS:
  - test.re

APPENDIX:

POSTDEF:
//}

== PDF 化する

いよいよ PDF 化します。

@<b>{src ディレクトリがあるディレクトリ} で、以下を実行します。

//list[buildpdf][PDF を生成する]{
docker run --rm -v `pwd`/src:/work vvakame/review:4.0 /bin/sh \
-c "cd /work && review-pdfmaker config.yml"
//}

PDF ファイルができたら完成です！

//image[testbook][testbook.pdf]{
//}

その後、.re ファイルを増やして catalog.yml に追加したり、config.yml の設定を調整したりして、実際の電子書籍や、物理本のための入稿データを作っていけば、あなたの想いの詰まった素敵な技術本を作ることができます。