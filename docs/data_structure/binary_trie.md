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
|`BinaryTrie<ビット幅 = 32, T = int>()`|binary trie $S$ を考える．||
|`~BinaryTrie()`|||
|`root`|根のポインタ||
|`clear()`|すべての要素を削除する．||
|`empty()`|$S$ は空集合であるか．||
|`size()`|$\|S\|$||
|`erase(x)`|$x$ を削除する．|存在しない場合は何もしない．|
|`find(x)`|$x$ を指すノード|存在しない場合は `nullptr` を返す．|
|`operator()[n]`|$n$ 番目 (0-based) の要素を指すノードと値||
|`find_nth(n, x)`|$\{s \oplus x \mid s \in S \}$ を考えたときの $n$ 番目 (0-based) の要素を指すノードと値||
|`insert(x)`|$x$ を挿入する．|返り値は $x$ を指すノードである．|
|`less_than(x)`|$\|\{s \in S \mid s < x \}\|$||
|`count(l, r)`|$\|\{s \in S \mid l \leq x < r \}\|$||
|`count(x)`|$\|\{s \in S \mid s = x \}\|$||
|`lower_bound(x)`|$x$ より小さくない最初の要素を指すノードと値|存在しない場合は `{nullptr, -1}` を返す．|
|`upper_bound(x)`|$x$ より大きい最初の要素を指すノードと値|存在しない場合は `{nullptr, -1}` を返す．|
|`max_element(x)`|$\mathrm{argmax}\{s \oplus x \mid s \in S\}$||
|`min_element(x)`|$\mathrm{argmin}\{s \oplus x \mid s \in S\}$||


## 参考

- https://kazuma8128.hatenablog.com/entry/2018/05/06/022654


## ToDo

- 永続 binary trie
  - https://kazuma8128.hatenablog.com/entry/2018/02/17/224151


## Verified

https://judge.yosupo.jp/submission/33239
