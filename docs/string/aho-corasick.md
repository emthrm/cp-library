---
title: Aho–Corasick algorithm
documentation_of: include/emthrm/string/aho-corasick.hpp
---

[トライ木](./trie.md)を用いてパターンマッチングを行うアルゴリズムである。


## 時間計算量

検索する文字列の長さを $N$, トライ木に追加する文字列の長さを $M$ とおくと $\langle O(\sum{M}), O(N + \sum{M}) \rangle$


## 仕様

```cpp
template <int Sigma = 26>
struct AhoCorasick : Trie<Sigma + 1>;
```

- `Sigma`：アルファベットサイズ

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> nums`|各ノードが保有する文字列の数|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
||[継承コンストラクタ](./trie.md)||
|`void build(const bool is_full_ver_ = false);`|オートマトンを構築する。||
|`int move(char c, int pos) const;`|$\mathrm{pos}$ 番目のノードから見たときに、文字 $c$ に対応するノードのインデックス||
|`int match(const std::string& t, int pos = 0) const;`|$\mathrm{pos}$ 番目のノードをから見たときに、文字列 $T$ とマッチする回数||
|`std::map<int, int> match_fully(const std::string& t, int pos = 0) const;`|$\mathrm{pos}$ 番目のノードから見たときに、文字列 $T$ とそれぞれの文字列がマッチする回数|完全版|


## 参考文献

- https://naoya-2.hatenadiary.org/entry/20090405/aho_corasick
- https://ei1333.github.io/luzhiled/snippets/string/aho-corasick.html
- https://github.com/beet-aizu/library/blob/02578ddfa9d2a46e3c724df82e84797dd41eabac/string/ahocorasick.cpp


## Submissons

https://yukicoder.me/submissions/575927
