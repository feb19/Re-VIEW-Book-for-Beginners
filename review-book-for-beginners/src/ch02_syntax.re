= Re:VIEW の様々な構文

//lead{
著者がよく使用する＆本書で使用した Re:VIEW 構文をご紹介します。
//}

== 基本的な文章

@<code>{=} 記号が見出しです。Markdown 形式の書き方と非常に似ています。

//list[syntax of review][Re:VIEW の基本構文]{

= 表題

== 見出し

=== 小見出し

本文本文本文本文本文本文

 * リスト
 * リスト

 1. 番号リスト
 2. 番号リスト

//}

== 画像の挿入

@<code>{image} 命令を使うことで画像が挿入できます。src ディレクトリの中に images ディレクトリを作って、その中に画像を入れます。

//emlist[画像の挿入]{
//image[画像ファイル名][説明文]{
@<embed>{/}/}
//}

== コードブロックの挿入

@<code>{list} 命令を使うことでリストが挿入できます。

//emlist[コードブロックの作成]{
//list[識別ID][説明文]{
const hoge = "Hello world."
@<embed>{/}/}
//}

//list[samplecodeblock][コードブロック例]{
const hoge = "Hello world."
//}

== インラインコードの挿入

本文中にコード（等幅フォント）を入力する場合は @<code>{code} インライン命令を使用します。

//emlist[code インライン命令]{
@<raw>{@}<code>{printf("書式文字列", 変数1, 変数2, ・・・)}
//}

== テーブルの挿入

@<code>{table} 命令を使うことでリストが挿入できます。

//emlist[テーブルの作成]{
//table[識別ID][説明文]{
名称	説明
----------------------------
Homebrew	macOS のパッケージマネージャ。Mac 買ったら入れるやつ。
Ruby	気軽に使えるスクリプト言語。なんだかんだで便利。
rbenv	Ruby のバージョン管理ツール。似たツールもあります。お好みで！
Docker	とても便利な環境再現ツール。これなしでもう開発できない。
Re:VIEW	本を作れるツール。凄すぎる。
@<embed>{/}/}
//}

//table[tablesample][table サンプル]{
名称	説明
----------------------------
Homebrew	macOS のパッケージマネージャ。Mac 買ったら入れるやつ。
Ruby	気軽に使えるスクリプト言語。なんだかんだで便利。
rbenv	Ruby のバージョン管理ツール。似たツールもあります。お好みで！
Docker	とても便利な環境再現ツール。これなしでもう開発できない。
Re:VIEW	本を作れるツール。凄すぎる。
//}

セルの区切りは「ハードタブ」を指定します。

== 脚注の挿入

@<code>{fn} インライン命令と @<code>{footnote} 命令を使うことでリストが挿入できます。

//emlist[fn インライン命令]{
@<raw>{@}<fn>{識別ID}
//}

//emlist[脚注の作成]{
//footnote[識別ID][脚注の内容]
//}

== 定義リストの挿入

用語解説などに使える定義リストを @<code>{:} で作成できます。

//emlist[定義リストの作成]{
: HealthKit Book for Beginners
  Apple iOS/watchOS で使用できるヘルスケア SDK「HealthKit」についての解説本です。
  http://feb19.jp/books/healthkitbookforbeginners

: Google Fit Book for Beginners
  Google Android、Web で使用できるヘルスケア SDK「Google Fit」についての解説本です。
  http://feb19.jp/books/googlefitbookforbeginners
//}

定義リストサンプル

: HealthKit Book for Beginners
  Apple iOS/watchOS で使用できるヘルスケア SDK「HealthKit」についての解説本です。
  http://feb19.jp/books/healthkitbookforbeginners

: Google Fit Book for Beginners
  Google Android、Web で使用できるヘルスケア SDK「Google Fit」についての解説本です。
  http://feb19.jp/books/googlefitbookforbeginners

== 本文を太字にする

@<code>{b} で@<b>{太字}にできます。

//emlist[b インライン命令]{
@<raw>{@}<b>{太字にしたい文章}
//}