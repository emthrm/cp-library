---
title: 区間を std::set で管理するやつ
documentation_of: //include/emthrm/data_structure/intervals_managed_by_set.hpp
---

閉区間を `std::set` によって管理するデータ構造である。


## 時間計算量

amortized $O(\log{N})$ ?


## 仕様

```cpp
template <typename T>
struct IntervalsManagedBySet;
```

- `T`：要素型

#### メンバ変数

|名前|説明|備考|
|:--|:--|:--|
|`IntervalsType intervals`|区間の集合|番兵 $\lbrack -\infty, -\infty \rbrack, \lbrack \infty, \infty \rbrack$ を含む。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`IntervalsManagedBySet();`|デフォルトコンストラクタ。集合 $S \mathrel{:=} \emptyset$ を表すオブジェクトを構築する。|
|`bool contains(const T x) const;`|$x \in S$ を満たすか。|
|`bool contains(const T left, const T right) const;`|任意の $x \in \lbrace \mathrm{left}, \ldots, \mathrm{right} \rbrace$ に対して $x \in S$ を満たすか。|
|`std::pair<IntervalsType::const_iterator, bool> erase(const T x);`|$S \gets S \setminus \lbrace x \rbrace$ の操作後、削除された要素の次を指すイテレータと実際に削除したかを返す。|
|`std::pair<IntervalsType::const_iterator, T> erase(const T left, const T right);`|$S \gets S \setminus \lbrace \mathrm{left}, \ldots, \mathrm{right} \rbrace$ の操作後、削除された要素の次を指すイテレータと削除した要素数を返す。|
|`IntervalsType::const_iterator find(const T x) const;`|$x$ を含む区間へのイテレータ。ただし $x \notin S$ を満たすときは `intervals.end()` を返す。|
|`IntervalsType::const_iterator find(const T left, const T right) const;`|$\lbrack \mathrm{left}, \mathrm{right} \rbrack$ を含む区間へのイテレータ。ただし $x \notin S$ を満たす $x \in \lbrace \mathrm{left}, \ldots, \mathrm{right} \rbrace$ が存在するときは `intervals.end()` を返す。|
|`std::pair<IntervalsType::const_iterator, bool> insert(const T x);`|$S \gets S \cup \lbrace x \rbrace$ の操作後、要素へのイテレータと実際に挿入されたかどうかを返す。|
|`std::pair<IntervalsType::const_iterator, T> insert(T left, T right);`|$S \gets S \cup \lbrace \mathrm{left}, \ldots, \mathrm{right} \rbrace$ の操作後、要素へのイテレータと実際に挿入した要素数を返す。|
|`T mex(const T x = 0) const;`|$\mathrm{mex}(S)$|
|`friend std::ostream& operator<<(std::ostream& os, const IntervalsManagedBySet& x);`||

#### メンバ型

|名前|説明|
|:--|:--|
|`IntervalsType`|`std::set<std::pair<T, T>>`|


## 参考文献

- https://mugen1337.hatenablog.com/entry/2020/10/14/134022


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2880/review/5242323/emthrm/C++17
