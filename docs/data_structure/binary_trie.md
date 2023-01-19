---
title: binary trie
documentation_of: include/emthrm/data_structure/binary_trie.hpp
---

非負整数を管理する[トライ木](../string/trie.md)である。


## 時間計算量

$O(B)$


## 仕様

```cpp
template <int B = 32, typename T = std::uint32_t>
struct BinaryTrie;
```

- `B`：ビット幅
- `T`：要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::shared_ptr<Node> root;`|根のポインタ|

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`BinaryTrie();`|集合 $S \mathrel{:=} \emptyset$ を表すオブジェクトを構築する||
|`void clear();`|$S \gets \emptyset$||
|`bool empty() const;`|$S = \emptyset$ を満たすか。||
|`int size() const;`|$\lvert S \rvert$||
|`void erase(const T& x);`|$S \gets S \setminus \lbrace x \rbrace$|$x \notin S$ を満たすときは何もしない。|
|`std::shared_ptr<Node> find(const T& x) const;`|$x$ を指すノード。ただし $x \notin S$ を満たすときは `nullptr` を返す。|
|`std::pair<std::shared_ptr<Node>, T> operator[](const int n) const;`|$n$ 番目 (0-based) の要素を指すノードと値||
|`std::pair<std::shared_ptr<Node>, T> find_nth(int n, const T& x) const;`|$\lbrace s \oplus x \mid s \in S \rbrace$ における $n$ 番目 (0-based) の要素を表すノードと値||
|`std::shared_ptr<Node> insert(const T& x);`|$S \gets S \cup \lbrace x \rbrace$ の操作後、$x$ を表すノードを返す。|
|`int less_than(const T& x) const;`|$\lvert \lbrace s \in S \mid s < x \rbrace \rvert$||
|`int count(const T& l, const T& r) const;`|$\lvert \lbrace s \in S \mid l \leq x < r \rbrace \rvert$||
|`int count(const T& x) const;`|$\lvert \lbrace s \in S \mid s = x \rbrace \rvert$||
|`std::pair<std::shared_ptr<Node>, T> lower_bound(const T& x) const;`|$x$ より小さくない最初の要素を表すノードと値。ただしそのような要素が存在しないときは (`nullptr`, $-1$) を返す。|
|`std::pair<std::shared_ptr<Node>, T> upper_bound(const T& x) const;`|$x$ より大きい最初の要素を表すノードと値。ただし存在しないときは (`nullptr`, $-1$) を返す。||
|`std::pair<std::shared_ptr<Node>, T> max_element(const T& x = 0) const;`|$\mathrm{argmax} \lbrace s \oplus x \mid s \in S \rbrace$||
|`std::pair<std::shared_ptr<Node>, T> min_element(const T& x = 0) const;`|$\mathrm{argmin} \lbrace s \oplus x \mid s \in S \rbrace$||

#### メンバ型

|名前|説明|
|:--|:--|
|`Node`|ノードを表す構造体|

```cpp
struct Node;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::array<std::shared_ptr<Node>, 2> nxt`|子のポインタ|
|`int child`|部分木に属する要素の個数|

#### メンバ関数

|名前|効果|
|:--|:--|
|`Node();`|コンストラクタ|


## 参考文献

- https://kazuma8128.hatenablog.com/entry/2018/05/06/022654


## TODO

- 永続 binary trie
  - https://kazuma8128.hatenablog.com/entry/2018/02/17/224151
- a powerful representation of integer sets
  - https://codeforces.com/blog/entry/83969
  - https://twitter.com/keijak/status/1488232021394702336


## Submissons

https://judge.yosupo.jp/submission/33239
