---
title: 区間を std::set で管理するやつ
documentation_of: include/emthrm/data_structure/interval_managed_by_set.hpp
---

閉区間を `std::set` によって管理するデータ構造である．


## 時間計算量

amortized $O(\log{N})$ ?


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`IntervalManagedBySet<T>`|区間を std::set で管理するやつ||
|`intervals`|閉区間の集合||
|`contains(x)`|$x$ は集合に含まれるか．||
|`contains(left, right)`|$\lbrack \mathrm{left}, \mathrm{right} \rbrack$ は集合に含まれるか．||
|`erase(x)`|集合から $x$ を削除する．|返り値は削除された要素の次を指すイテレータと実際に削除したかである．|
|`erase(left, right)`|集合から $x \in \lbrack \mathrm{left}, \mathrm{right} \rbrack$ を削除する．|返り値は削除された要素の次を指すイテレータと削除した要素数である．|
|`insert(x)`|集合に $x$ を挿入する．|返り値は要素へのイテレータと挿入されたかどうかである．|
|`insert(left, right)`|集合に $x \in \lbrack \mathrm{left}, \mathrm{right} \rbrack$ を挿入する．|返り値は要素へのイテレータと挿入した要素数である．|
|`mex(x = 0)`|mex||


## 参考

- https://mugen1337.hatenablog.com/entry/2020/10/14/134022


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2880/review/5242323/emthrm/C++17
