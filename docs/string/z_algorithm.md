---
title: Z algorithm
documentation_of: include/emthrm/string/z_algorithm.hpp
---

文字列 $S$ に対して $S$ と `S[i:]` の最長共通接頭辞の長さを求めるアルゴリズムである。


## 時間計算量

$O(\lvert S \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T> std::vector<int> z_algorithm(const T &s);`|$S$ と `S[i:]` の最長共通接頭辞の長さ|


## 参考文献

- https://snuke.hatenablog.com/entry/2014/12/03/214243
- https://sen-comp.hatenablog.com/entry/2020/01/16/174230


## TODO

- 動的 Z algorithm
  - https://heno239.hatenablog.com/entry/2020/07/07/140651


## Submissons

https://judge.yosupo.jp/submission/27816
