---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/lcp.hpp
    title: longest common prefix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/lcp.test.cpp
    title: "\u6587\u5B57\u5217/longest common prefix"
  - icon: ':heavy_check_mark:'
    path: test/string/suffix_array.test.cpp
    title: "\u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/suffix_array.hpp\"\n#include <algorithm>\r\n#include\
    \ <numeric>\r\n#include <string>\r\n#include <vector>\r\n\r\ntemplate <typename\
    \ T = std::string>\r\nstruct SuffixArray {\r\n  std::vector<int> sa, rank;\r\n\
    \r\n  SuffixArray(const T &s_) : s(s_) {\r\n    int n = s.size();\r\n    s.push_back('\
    \ ');\r\n    sa.resize(n + 1);\r\n    std::iota(sa.begin(), sa.end(), 0);\r\n\
    \    std::sort(sa.begin(), sa.end(), [&](int a, int b) -> bool { return s[a] ==\
    \ s[b] ? a > b : s[a] < s[b]; });\r\n    rank.resize(n + 1);\r\n    for (int i\
    \ = 0; i <= n; ++i) rank[i] = s[i];\r\n    std::vector<int> tmp(n + 1), prev_sa(n\
    \ + 1);\r\n    for (int len = 1; len <= n; len <<= 1) {\r\n      tmp[sa[0]] =\
    \ 0;\r\n      for (int i = 1; i <= n; ++i) {\r\n        if (rank[sa[i - 1]] ==\
    \ rank[sa[i]] && sa[i - 1] + len <= n && rank[sa[i - 1] + (len >> 1)] == rank[sa[i]\
    \ + (len >> 1)]) {\r\n          tmp[sa[i]] = tmp[sa[i - 1]];\r\n        } else\
    \ {\r\n          tmp[sa[i]] = i;\r\n        }\r\n      }\r\n      rank.swap(tmp);\r\
    \n      std::iota(tmp.begin(), tmp.end(), 0);\r\n      std::copy(sa.begin(), sa.end(),\
    \ prev_sa.begin());\r\n      for (int i = 0; i <= n; ++i) {\r\n        int idx\
    \ = prev_sa[i] - len;\r\n        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;\r\n\
    \      }\r\n    }\r\n    for (int i = 0; i <= n; ++i) rank[sa[i]] = i;\r\n  }\r\
    \n\r\n  std::vector<int> match(T &t) const {\r\n    int lb = lower_bound(t);\r\
    \n    ++t.back();\r\n    int ub = lower_bound(t);\r\n    --t.back();\r\n    std::vector<int>\
    \ res(ub - lb);\r\n    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\r\
    \n    std::sort(res.begin(), res.end());\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  T s;\r\n\r\n  int lower_bound(const T &t) const {\r\n    int s_sz = s.size(),\
    \ t_sz = t.size(), lb = 0, ub = s_sz;\r\n    while (ub - lb > 1) {\r\n      int\
    \ mid = (lb + ub) >> 1, s_idx = sa[mid], t_idx = 0;\r\n      bool finished = false;\r\
    \n      for (; s_idx < s_sz && t_idx < t_sz; ++s_idx, ++t_idx) {\r\n        if\
    \ (s[s_idx] != t[t_idx]) {\r\n          (s[s_idx] < t[t_idx] ? lb : ub) = mid;\r\
    \n          finished = true;\r\n          break;\r\n        }\r\n      }\r\n \
    \     if (!finished) (s_idx == s_sz && t_idx < t_sz ? lb : ub) = mid;\r\n    }\r\
    \n    return ub;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <numeric>\r\n#include <string>\r\
    \n#include <vector>\r\n\r\ntemplate <typename T = std::string>\r\nstruct SuffixArray\
    \ {\r\n  std::vector<int> sa, rank;\r\n\r\n  SuffixArray(const T &s_) : s(s_)\
    \ {\r\n    int n = s.size();\r\n    s.push_back(' ');\r\n    sa.resize(n + 1);\r\
    \n    std::iota(sa.begin(), sa.end(), 0);\r\n    std::sort(sa.begin(), sa.end(),\
    \ [&](int a, int b) -> bool { return s[a] == s[b] ? a > b : s[a] < s[b]; });\r\
    \n    rank.resize(n + 1);\r\n    for (int i = 0; i <= n; ++i) rank[i] = s[i];\r\
    \n    std::vector<int> tmp(n + 1), prev_sa(n + 1);\r\n    for (int len = 1; len\
    \ <= n; len <<= 1) {\r\n      tmp[sa[0]] = 0;\r\n      for (int i = 1; i <= n;\
    \ ++i) {\r\n        if (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n\
    \ && rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {\r\n         \
    \ tmp[sa[i]] = tmp[sa[i - 1]];\r\n        } else {\r\n          tmp[sa[i]] = i;\r\
    \n        }\r\n      }\r\n      rank.swap(tmp);\r\n      std::iota(tmp.begin(),\
    \ tmp.end(), 0);\r\n      std::copy(sa.begin(), sa.end(), prev_sa.begin());\r\n\
    \      for (int i = 0; i <= n; ++i) {\r\n        int idx = prev_sa[i] - len;\r\
    \n        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;\r\n      }\r\n    }\r\n  \
    \  for (int i = 0; i <= n; ++i) rank[sa[i]] = i;\r\n  }\r\n\r\n  std::vector<int>\
    \ match(T &t) const {\r\n    int lb = lower_bound(t);\r\n    ++t.back();\r\n \
    \   int ub = lower_bound(t);\r\n    --t.back();\r\n    std::vector<int> res(ub\
    \ - lb);\r\n    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\r\n\
    \    std::sort(res.begin(), res.end());\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  T s;\r\n\r\n  int lower_bound(const T &t) const {\r\n    int s_sz = s.size(),\
    \ t_sz = t.size(), lb = 0, ub = s_sz;\r\n    while (ub - lb > 1) {\r\n      int\
    \ mid = (lb + ub) >> 1, s_idx = sa[mid], t_idx = 0;\r\n      bool finished = false;\r\
    \n      for (; s_idx < s_sz && t_idx < t_sz; ++s_idx, ++t_idx) {\r\n        if\
    \ (s[s_idx] != t[t_idx]) {\r\n          (s[s_idx] < t[t_idx] ? lb : ub) = mid;\r\
    \n          finished = true;\r\n          break;\r\n        }\r\n      }\r\n \
    \     if (!finished) (s_idx == s_sz && t_idx < t_sz ? lb : ub) = mid;\r\n    }\r\
    \n    return ub;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.hpp
  requiredBy:
  - string/lcp.hpp
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/lcp.test.cpp
  - test/string/suffix_array.test.cpp
documentation_of: string/suffix_array.hpp
layout: document
title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
---

ある文字列の全接尾辞を辞書順に並べた配列である．


## 時間計算量

テキスト長を $N$，パターン長を $M$ とおくと $\langle O(N\log{N}), O(M\log{N}) \rangle$．


## 使用法

||説明|
|:--:|:--:|
|`SuffixArray<T = string>(s)`|$S$ の接尾辞配列を考える．|
|`sa`|接尾辞配列|
|`rank[i]`|`S[i:]` の接尾辞配列中での位置|
|`match(t)`|$T$ が出現する文字列 $S$ 中の位置|


## 参考

- https://github.com/beet-aizu/library/blob/master/string/suffixarray.cpp
- プログラミングコンテストチャレンジブック \[第2版\] pp.335-339
- http://wk1080id.hatenablog.com/entry/2018/12/25/005926


## ToDo

- パターンマッチングを $O(M + \log{N})$ に高速化する．
  - http://www.prefield.com/algorithm/string/suffix_array.html
- SA-IS
  - https://qiita.com/flare/items/ac11972dbc590a91980d
  - https://topcoder.g.hatena.ne.jp/iwiwi/20110720/1311168147
  - https://mametter.hatenablog.com/entry/20180130/p1
  - https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html
  - http://gasin.hatenadiary.jp/entry/2017/06/08/101525
  - http://sile.hatenablog.jp/entry/20101213/1292190698
  - https://lumakernel.github.io/ecasdqina/string/SA-IS
  - https://github.com/atcoder/ac-library/blob/master/atcoder/string.hpp#L51
  - https://gist.github.com/tjkendev/99d7330fe5642004b68268b31ba38ad4
  - https://docs.google.com/presentation/d/1R9ZgXqX4bpkO3nYkVoqU9Ng2uCIKLbf-UJ2C6hlVYFI
  - https://github.com/defineProgram/JOISS-2020/blob/master/doc/SA-IS.pdf
- 接尾辞オートマトン (suffix automaton)
  - https://ja.wikipedia.org/wiki/%E6%8E%A5%E5%B0%BE%E8%BE%9E%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3
  - https://w.atwiki.jp/uwicoder/pages/2842.html
  - https://github.com/KodamaD/JOISS2020/blob/master/docs/presentation.pdf
  - https://github.com/spaghetti-source/algorithm/blob/master/string/suffix_automaton.cc
- 接尾辞木 (suffix tree)
  - https://ja.wikipedia.org/wiki/%E6%8E%A5%E5%B0%BE%E8%BE%9E%E6%9C%A8
  - https://qiita.com/goonew/items/548fe90e9f68c6bba9e9
  - https://docs.google.com/presentation/d/1m-FpwlEg47kHCQx7FSImN0bPY7XJToRVbSMeCsLpI7g
  - https://github.com/spaghetti-source/algorithm/blob/master/string/suffix_tree.cc
  - https://github.com/eandbsoftware/libraryCPP/tree/master/Ukkonen


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4972832/emthrm/C++17