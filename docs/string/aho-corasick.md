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
|`AhoCorasick<σ = 26>(convert)`|エイホ-コラシック法を考える．||
|`nums[i]`|$i$番目のノードが保有する文字列の数||
|`build(完全版か? = false)`|オートマトンを構築する．||
|`move(c, pos)`|$\mathrm{pos}$ 番目のノードを起点としたときに文字 $c$ と対応するノードのインデックス||
|`match(t, pos = 0)`|$\mathrm{pos}$ 番目のノードを起点としたときに文字列 $T$ とマッチした回数||
|`match_fully(t, pos = 0)`|$\mathrm{pos}$ 番目のノードを起点としたとき，文字列 $T$ と追加したそれぞれの文字列がマッチした回数|完全版のみ|


## 参考

- https://naoya-2.hatenadiary.org/entry/20090405/aho_corasick
- https://ei1333.github.io/luzhiled/snippets/string/aho-corasick.html
- https://github.com/beet-aizu/library/blob/02578ddfa9d2a46e3c724df82e84797dd41eabac/string/ahocorasick.cpp


## Verified

https://yukicoder.me/submissions/575927
