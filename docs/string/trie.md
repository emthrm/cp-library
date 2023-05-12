---
title: トライ木 (trie)
documentation_of: //include/emthrm/string/trie.hpp
---

複数の文字列を高速に検索できる木である。


## 時間計算量

$O(\lvert S \rvert)$


## 仕様

```cpp
template <int Sigma = 26>
struct Trie;
```

- `Sigma`：アルファベットサイズ

#### メンバ変数

|名前|説明|
|:--|:--|
|`const std::function<int(const char)> convert`|文字を数に変換する関数|
|`std::vector<Node> nodes`|トライ木の頂点|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit Trie(const std::function<int(const char)> convert = [](const char c) -> int { return c - 'a'; });`|コンストラクタ||
|`void add(const std::string& s, const int id = -1, int pos = 0);`|$\mathrm{pos}$ 番目のノードから ID $\mathrm{id}$ の文字列 $S$ を追加する。||
|`int find(const std::string& t, int pos = 0) const;`|$\mathrm{pos}$ 番目のノードから見たとき、文字列 $T$ に対応するノードのインデックス。ただし存在しないときは $-1$ を返す。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Node`|ノードを表す構造体|

```cpp
struct Node
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`char c`|そのノードが表す文字|
|`std::array<int, Sigma> nxt`|子のインデックス|
|`std::vector<int> tails`|そのノードを末尾とする文字列の ID 集合|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit Node(const char c);`|コンストラクタ|


## 参考文献

- Edward Fredkin: Trie Memory, *Communications of the ACM*, Vol. 3, No. 9, pp. 490–499 (1960). https://doi.org/10.1145/367390.367400
- https://github.com/beet-aizu/library/blob/2ecdc969043f5276c3782a7752592bd3fe856524/string/trie.cpp


## TODO

- 永続 trie
  - https://ei1333.github.io/luzhiled/snippets/structure/binary-trie.html


## Submissons

https://yukicoder.me/submissions/413744
