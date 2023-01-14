---
title: トライ木 (trie)
documentation_of: include/emthrm/string/trie.hpp
---

複数の文字列を高速に検索できる木である。


## 時間計算量

$O(\lvert S \rvert)$


## 仕様

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`Trie<σ = 26>(convert)`|トライ木||
|`convert(c)`|数に変換した文字 $c$||
|`nodes`|トライ木の頂点||
|`add(s, id = -1, pos = 0)`|$\mathrm{pos}$ 番目のノードから ID $\mathrm{id}$ の文字列 $S$ を追加する。||
|`find(t, pos = 0)`|$\mathrm{pos}$ 番目のノードを起点としたときに文字列 $T$ と対応するノードのインデックス|存在しないときは $-1$ となる。|


## 参考文献

- https://github.com/beet-aizu/library/blob/2ecdc969043f5276c3782a7752592bd3fe856524/string/trie.cpp


## TODO

- 永続 trie
  - https://ei1333.github.io/luzhiled/snippets/structure/binary-trie.html


## Submissons

https://yukicoder.me/submissions/413744
