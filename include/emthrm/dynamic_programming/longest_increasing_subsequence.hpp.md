---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dynamic_programming/longest_increasing_subsequence.test.cpp
    title: "\u52D5\u7684\u8A08\u753B\u6CD5/\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/dynamic_programming/longest_increasing_subsequence.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#include <limits>\n#include\
    \ <vector>\n\nnamespace emthrm {\n\ntemplate <bool IS_STRICT = true, typename\
    \ T>\nstd::vector<T> longest_increasing_subsequence(const std::vector<T>& a) {\n\
    \  const T inf = std::numeric_limits<T>::max();\n  const int n = a.size();\n \
    \ std::vector<int> idx(n);\n  std::vector<T> tmp(n, inf);\n  for (int i = 0; i\
    \ < n; ++i) {\n    idx[i] = std::distance(\n        tmp.begin(),\n        IS_STRICT\
    \ ? std::lower_bound(tmp.begin(), tmp.end(), a[i]) :\n                    std::upper_bound(tmp.begin(),\
    \ tmp.end(), a[i]));\n    tmp[idx[i]] = a[i];\n  }\n  int res_size =\n      std::distance(tmp.begin(),\
    \ std::lower_bound(tmp.begin(), tmp.end(), inf));\n  std::vector<T> res(res_size--);\n\
    \  for (int i = n - 1; res_size >= 0 && i >= 0; --i) {\n    if (idx[i] == res_size)\
    \ res[res_size--] = a[i];\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\
    \n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_HPP_\n\
    #define EMTHRM_DYNAMIC_PROGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_HPP_\n\n#include\
    \ <algorithm>\n#include <iterator>\n#include <limits>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <bool IS_STRICT = true, typename T>\nstd::vector<T> longest_increasing_subsequence(const\
    \ std::vector<T>& a) {\n  const T inf = std::numeric_limits<T>::max();\n  const\
    \ int n = a.size();\n  std::vector<int> idx(n);\n  std::vector<T> tmp(n, inf);\n\
    \  for (int i = 0; i < n; ++i) {\n    idx[i] = std::distance(\n        tmp.begin(),\n\
    \        IS_STRICT ? std::lower_bound(tmp.begin(), tmp.end(), a[i]) :\n      \
    \              std::upper_bound(tmp.begin(), tmp.end(), a[i]));\n    tmp[idx[i]]\
    \ = a[i];\n  }\n  int res_size =\n      std::distance(tmp.begin(), std::lower_bound(tmp.begin(),\
    \ tmp.end(), inf));\n  std::vector<T> res(res_size--);\n  for (int i = n - 1;\
    \ res_size >= 0 && i >= 0; --i) {\n    if (idx[i] == res_size) res[res_size--]\
    \ = a[i];\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DYNAMIC_PROGRAMMING_LONGEST_INCREASING_SUBSEQUENCE_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dynamic_programming/longest_increasing_subsequence.test.cpp
documentation_of: include/emthrm/dynamic_programming/longest_increasing_subsequence.hpp
layout: document
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (longest increasing subsequence)"
---

$i < j$ を満たす任意の $i, j$ に対して $A_i < A_j$ を満たす部分列 $A$ の内、最長のものである。


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|戻り値|備考|
|:--|:--|:--|
|`template <bool IS_STRICT = true, typename T>`<br>`std::vector<T> longest_increasing_subsequence(const std::vector<T>& a);`|$A$ の最長増加部分列|`IS_STRICT` は広義単調増加であるかを表す。|


## 参考文献

- Craige Schensted: Longest Increasing and Decreasing Subsequences, *Canadian Journal of Mathematics*, Vol. 13, pp. 179–191 (1961). https://doi.org/10.4153/CJM-1961-015-3
- ~~http://www.prefield.com/algorithm/dp/lis_fast.html~~
- http://noshi91.hatenablog.com/entry/2018/02/03/204950


## TODO

- longest Zig-Zag subsequence
  - https://github.com/spaghetti-source/algorithm/blob/master/dynamic_programming/longest_zigzag_subsequence.cc
- range longest increasing subsequence query
  - https://twitter.com/noshi91/status/1388201116148539393
  - https://judge.yosupo.jp/problem/static_range_lis_query


## Submissons

https://judge.yosupo.jp/submission/99391
