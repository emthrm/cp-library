---
title: 最長共通部分列 (longest common subsequence)
documentation_of: include/emthrm/dynamic_programming/longest_common_subsequence.hpp
---

2列に対して双方に現れる部分列の内，最長のものである．


## 時間計算量

$O(NM)$


## 使用法

||説明|
|:--:|:--:|
|`longest_common_subsequence(a, b)`|$A$ と $B$ の最長共通部分列|


## 参考

- https://qiita.com/drken/items/03c7db44ccd27820ea0d


## TODO

- https://judge.yosupo.jp/problem/prefix_substring_lcs
- https://github.com/yosupo06/library-checker-problems/issues/732
- 高速化
  - http://www.prefield.com/algorithm/dp/lcs_hs.html


## Verified

https://atcoder.jp/contests/dp/submissions/9236673
