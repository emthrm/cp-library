---
title: 最長増加部分列 (longest increasing subsequence)
documentation_of: dynamic_programming/longest_increasing_subsequence.hpp
---

$i < j$ を満たす任意の $i, j$ に対して $A_i < A_j$ を満たす部分列 $A$ の内，最長のものである．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`longest_increasing_subsequence(a, 広義単調増加か? = true)`|$A$ の最長増加部分列|


## 参考

- http://www.prefield.com/algorithm/dp/lis_fast.html
- http://noshi91.hatenablog.com/entry/2018/02/03/204950


## ToDo

- longest Zig-Zag subsequence
  - https://github.com/spaghetti-source/algorithm/blob/master/dynamic_programming/longest_zigzag_subsequence.cc
- range longest increasing subsequence query
  - https://twitter.com/noshi91/status/1388201116148539393
  - https://judge.yosupo.jp/problem/static_range_lis_query


## Verified

https://judge.yosupo.jp/submission/99391
