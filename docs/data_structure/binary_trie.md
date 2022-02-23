---
title: binary trie
documentation_of: data_structure/binary_trie.hpp
---

非負整数を管理する[トライ木](../string/trie.md)である．


## 時間計算量

$O(B)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`BinaryTrie<ビット幅 = 32, T = std::uint32_t>()`|binary trie $S$ を考える．||
|`root`|根のポインタ||
|`clear()`|すべての要素を削除する．||
|`empty()`|$S$ は空集合であるか．||
|`size()`|$\lvert S \rvert$||
|`erase(x)`|$x$ を削除する．|存在しないときは何もしない．|
|`find(x)`|$x$ を指すノード|存在しないときは `nullptr` を返す．|
|`operator()[n]`|$n$ 番目 (0-based) の要素を指すノードと値||
|`find_nth(n, x)`|$\lbrace s \oplus x \mid s \in S \rbrace$ を考えたときの $n$ 番目 (0-based) の要素を指すノードと値||
|`insert(x)`|$x$ を挿入する．|返り値は $x$ を指すノードである．|
|`less_than(x)`|$\lvert \lbrace s \in S \mid s < x \rbrace \rvert$||
|`count(l, r)`|$\lvert \lbrace s \in S \mid l \leq x < r \rbrace \rvert$||
|`count(x)`|$\lvert \lbrace s \in S \mid s = x \rbrace \rvert$||
|`lower_bound(x)`|$x$ より小さくない最初の要素を指すノードと値|存在しないときは `{nullptr, -1}` を返す．|
|`upper_bound(x)`|$x$ より大きい最初の要素を指すノードと値|存在しないときは `{nullptr, -1}` を返す．|
|`max_element(x)`|$\mathrm{argmax} \lbrace s \oplus x \mid s \in S \rbrace$||
|`min_element(x)`|$\mathrm{argmin} \lbrace s \oplus x \mid s \in S \rbrace$||


## 参考

- https://kazuma8128.hatenablog.com/entry/2018/05/06/022654


## ToDo

- 永続 binary trie
  - https://kazuma8128.hatenablog.com/entry/2018/02/17/224151
- a powerful representation of integer sets
  - https://codeforces.com/blog/entry/83969
  - https://twitter.com/keijak/status/1488232021394702336


## Verified

https://judge.yosupo.jp/submission/33239
