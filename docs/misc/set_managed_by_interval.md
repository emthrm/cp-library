---
title: std::set を区間で管理するやつ
documentation_of: misc/set_managed_by_interval.hpp
---

`std::set` を閉区間の集合によって管理するデータ構造である．


## 時間計算量

$\text{amortized } O(\log{n})$ ?


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`SetManagedByInterval`|`std::set` を区間で管理するやつ||
|`interval`|閉区間の集合||
|`contains(x)`|$x$ は集合に含まれるか．||
|`contains(left, right)`|$[\mathrm{left}, \mathrm{right}]$ は集合に含まれるか．||
|`erase(x)`|集合から $x$ を削除する．|返り値は削除された要素の次を指すイテレータと実際に削除したかである．|
|`erase(left, right)`|集合から $x \in [\mathrm{left}, \mathrm{right}]$ を削除する．|返り値は削除された要素の次を指すイテレータと削除した要素数である．|
|`insert(x)`|集合に $x$ を挿入する．|返り値は要素へのイテレータと挿入されたかどうかである．|
|`insert(left, right)`|集合に $x$ を挿入する．|返り値は要素へのイテレータと挿入した要素数である．|
|`mex(x = 0)`|mex||


## 参考

- https://mugen1337.hatenablog.com/entry/2020/10/14/134022


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2880/review/5242323/emthrm/C++17
