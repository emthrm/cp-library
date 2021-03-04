---
title: エイホ-コラシック法 (Aho-Corasick algorithm)
documentation_of: string/aho-corasick.hpp
---

トライ木を用いてパターンマッチングを行うアルゴリズムである．


## 時間計算量

検索する文字列の長さを $N$, トライ木に追加する文字列の長さを $M$ とおくと $\langle O(\sum{M}), O(N + \sum{M}) \rangle$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`AhoCorasick<σ = 26>(基準 = 'a')`|エイホ-コラシック法を考える．||
|`cnt[i]`|ノード $i$ が保有する文字列の数||
|`build(重量版か? = false)`|オートマトンを構築する．||
|`move(c, pos)`|ノード $\mathrm{pos}$ から辿った文字 $c$ に対応するノードのインデックス||
|`match(t, pos = 0)`|ノード $\mathrm{pos}$ から見た文字列 $T$ のパターンマッチングの回数||
|`match_heavy(t, pos = 0)`|ノード $\mathrm{pos}$ から見た文字列 $T$ の追加した各文字列におけるパターンマッチングの回数|重量版のみ|


## 参考

- https://naoya-2.hatenadiary.org/entry/20090405/aho_corasick
- https://ei1333.github.io/luzhiled/snippets/string/aho-corasick.html
- https://github.com/beet-aizu/library/blob/master/string/ahocorasick.cpp


## Verified

https://yukicoder.me/submissions/575927
