---
title: トライ木 (trie)
documentation_of: string/trie.hpp
---

複数の文字列を高速に検索することができる木である．


## 時間計算量

$O(\lvert S \rvert)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Trie<σ = 26>(基準 = 'a')`|トライ木||
|`nodes`|木の頂点||
|`add(s, id = -1, pos = 0)`|ノード $\mathrm{pos}$ から ID $\mathrm{id}$ の文字列 $S$ を追加する．||
|`find(t, pos = 0)`|ノード $\mathrm{pos}$ から辿った文字列 $T$ に対応するノードのインデックス|存在しない場合は $-1$ となる．|
|`convert(c)`|数に変換した文字 $c$||


## 参考

- https://github.com/beet-aizu/library/blob/master/string/trie.cpp


## ToDo

- 永続 trie
  - https://ei1333.github.io/luzhiled/snippets/structure/binary-trie.html


## Verified

https://yukicoder.me/submissions/413744
