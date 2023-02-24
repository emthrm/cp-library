---
title: 部分列 DP
documentation_of: //include/emthrm/string/subsequence_dp.hpp
---


## 時間計算量

$O(\sigma \lvert S \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`std::vector<std::vector<int>> subsequence_dp(const std::string& s, const char basis = 'a', const int sigma = 26);`|$S$ の $i$ 文字目以降 (inclusive) で最初に文字 $c$ が現れるインデックス|


## 参考文献

- https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd


## Submissons

https://atcoder.jp/contests/arc081/submissions/26043202
