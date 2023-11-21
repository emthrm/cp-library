---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/string/longest_common_prefix.hpp
    title: longest common prefix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/longest_common_prefix.test.cpp
    title: "\u6587\u5B57\u5217/longest common prefix"
  - icon: ':heavy_check_mark:'
    path: test/string/suffix_array.test.cpp
    title: "\u6587\u5B57\u5217/\u63A5\u5C3E\u8F9E\u914D\u5217"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/string/suffix_array.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <numeric>\n#include <string>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <typename T = std::string>\nrequires requires { typename\
    \ T::value_type; }\nstruct SuffixArray {\n  std::vector<int> sa, rank;\n\n  explicit\
    \ SuffixArray(const T& s_, const typename T::value_type sentinel = 0)\n      :\
    \ s(s_) {\n    const int n = s.size();\n    s.push_back(sentinel);\n    sa.resize(n\
    \ + 1);\n    std::iota(sa.rbegin(), sa.rend(), 0);\n    std::ranges::stable_sort(\n\
    \        sa, {}, [this](const int index) -> int { return s[index]; });\n    rank.resize(n\
    \ + 1);\n    for (int i = 0; i <= n; ++i) {\n      rank[i] = s[i];\n    }\n  \
    \  std::vector<int> tmp(n + 1), prev_sa(n + 1);\n    for (int len = 1; len <=\
    \ n; len <<= 1) {\n      tmp[sa[0]] = 0;\n      for (int i = 1; i <= n; ++i) {\n\
    \        if (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n &&\n     \
    \       rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {\n        \
    \  tmp[sa[i]] = tmp[sa[i - 1]];\n        } else {\n          tmp[sa[i]] = i;\n\
    \        }\n      }\n      rank.swap(tmp);\n      std::iota(tmp.begin(), tmp.end(),\
    \ 0);\n      std::copy(sa.begin(), sa.end(), prev_sa.begin());\n      for (int\
    \ i = 0; i <= n; ++i) {\n        const int idx = prev_sa[i] - len;\n        if\
    \ (idx >= 0) sa[tmp[rank[idx]]++] = idx;\n      }\n    }\n    for (int i = 0;\
    \ i <= n; ++i) {\n      rank[sa[i]] = i;\n    }\n  }\n\n  std::vector<int> match(T*\
    \ t) const {\n    const int lb = lower_bound(t);\n    ++t->back();\n    const\
    \ int ub = lower_bound(t);\n    --t->back();\n    std::vector<int> res(ub - lb);\n\
    \    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n  }\n\n private:\n  T s;\n\n  int lower_bound(const\
    \ T* t) const {\n    const int s_size = s.size(), t_size = t->size();\n    int\
    \ lb = 0, ub = s_size;\n    while (ub - lb > 1) {\n      const int mid = std::midpoint(lb,\
    \ ub);\n      int s_idx = sa[mid], t_idx = 0;\n      bool finished = false;\n\
    \      for (; s_idx < s_size && t_idx < t_size; ++s_idx, ++t_idx) {\n        if\
    \ (s[s_idx] != (*t)[t_idx]) {\n          (s[s_idx] < (*t)[t_idx] ? lb : ub) =\
    \ mid;\n          finished = true;\n          break;\n        }\n      }\n   \
    \   if (!finished) (s_idx == s_size && t_idx < t_size ? lb : ub) = mid;\n    }\n\
    \    return ub;\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_STRING_SUFFIX_ARRAY_HPP_\n#define EMTHRM_STRING_SUFFIX_ARRAY_HPP_\n\
    \n#include <algorithm>\n#include <numeric>\n#include <string>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T = std::string>\nrequires requires\
    \ { typename T::value_type; }\nstruct SuffixArray {\n  std::vector<int> sa, rank;\n\
    \n  explicit SuffixArray(const T& s_, const typename T::value_type sentinel =\
    \ 0)\n      : s(s_) {\n    const int n = s.size();\n    s.push_back(sentinel);\n\
    \    sa.resize(n + 1);\n    std::iota(sa.rbegin(), sa.rend(), 0);\n    std::ranges::stable_sort(\n\
    \        sa, {}, [this](const int index) -> int { return s[index]; });\n    rank.resize(n\
    \ + 1);\n    for (int i = 0; i <= n; ++i) {\n      rank[i] = s[i];\n    }\n  \
    \  std::vector<int> tmp(n + 1), prev_sa(n + 1);\n    for (int len = 1; len <=\
    \ n; len <<= 1) {\n      tmp[sa[0]] = 0;\n      for (int i = 1; i <= n; ++i) {\n\
    \        if (rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + len <= n &&\n     \
    \       rank[sa[i - 1] + (len >> 1)] == rank[sa[i] + (len >> 1)]) {\n        \
    \  tmp[sa[i]] = tmp[sa[i - 1]];\n        } else {\n          tmp[sa[i]] = i;\n\
    \        }\n      }\n      rank.swap(tmp);\n      std::iota(tmp.begin(), tmp.end(),\
    \ 0);\n      std::copy(sa.begin(), sa.end(), prev_sa.begin());\n      for (int\
    \ i = 0; i <= n; ++i) {\n        const int idx = prev_sa[i] - len;\n        if\
    \ (idx >= 0) sa[tmp[rank[idx]]++] = idx;\n      }\n    }\n    for (int i = 0;\
    \ i <= n; ++i) {\n      rank[sa[i]] = i;\n    }\n  }\n\n  std::vector<int> match(T*\
    \ t) const {\n    const int lb = lower_bound(t);\n    ++t->back();\n    const\
    \ int ub = lower_bound(t);\n    --t->back();\n    std::vector<int> res(ub - lb);\n\
    \    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n  }\n\n private:\n  T s;\n\n  int lower_bound(const\
    \ T* t) const {\n    const int s_size = s.size(), t_size = t->size();\n    int\
    \ lb = 0, ub = s_size;\n    while (ub - lb > 1) {\n      const int mid = std::midpoint(lb,\
    \ ub);\n      int s_idx = sa[mid], t_idx = 0;\n      bool finished = false;\n\
    \      for (; s_idx < s_size && t_idx < t_size; ++s_idx, ++t_idx) {\n        if\
    \ (s[s_idx] != (*t)[t_idx]) {\n          (s[s_idx] < (*t)[t_idx] ? lb : ub) =\
    \ mid;\n          finished = true;\n          break;\n        }\n      }\n   \
    \   if (!finished) (s_idx == s_size && t_idx < t_size ? lb : ub) = mid;\n    }\n\
    \    return ub;\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_STRING_SUFFIX_ARRAY_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/string/suffix_array.hpp
  requiredBy:
  - include/emthrm/string/longest_common_prefix.hpp
  timestamp: '2023-07-07 02:42:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/suffix_array.test.cpp
  - test/string/longest_common_prefix.test.cpp
documentation_of: include/emthrm/string/suffix_array.hpp
layout: document
title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
---

文字列の全接尾辞を辞書順に並べた配列である。


## 時間計算量

テキスト長を $N$、パターン長を $M$ とおくと $\langle O(N\log{N}), O(M\log{N}) \rangle$


## 仕様

```cpp
template <typename T = std::string>
requires requires { typename T::value_type; }
struct SuffixArray;
```

- `T`：$S$ の要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> sa`|接尾辞配列|
|`std::vector<int> rank`|$\mathrm{rank}_i$ は `S[i:]` の接尾辞配列中での位置を表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit SuffixArray(const T& s_, const typename T::value_type sentinel = 0);`|$S$ に対してオブジェクトを構築する。|
|`std::vector<int> match(T* t) const;`|$T$ が出現する文字列 $S$ 中の位置|


## 参考文献

- https://github.com/beet-aizu/library/blob/2ecdc969043f5276c3782a7752592bd3fe856524/string/suffixarray.cpp
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.335-339，マイナビ出版（2012）
- http://wk1080id.hatenablog.com/entry/2018/12/25/005926


## TODO

- パターンマッチングを $O(M + \log{N})$ に高速化する。
  - ~~http://www.prefield.com/algorithm/string/suffix_array.html~~
- SA-IS
  - https://qiita.com/flare/items/ac11972dbc590a91980d
  - ~~https://topcoder.g.hatena.ne.jp/iwiwi/20110720/1311168147~~
  - https://mametter.hatenablog.com/entry/20180130/p1
  - https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html
  - http://gasin.hatenadiary.jp/entry/2017/06/08/101525
  - http://sile.hatenablog.jp/entry/20101213/1292190698
  - ~~https://lumakernel.github.io/ecasdqina/string/SA-IS~~
  - https://github.com/atcoder/ac-library/blob/master/atcoder/string.hpp#L51
  - https://gist.github.com/tjkendev/99d7330fe5642004b68268b31ba38ad4
  - https://docs.google.com/presentation/d/1R9ZgXqX4bpkO3nYkVoqU9Ng2uCIKLbf-UJ2C6hlVYFI
  - https://github.com/defineProgram/JOISS-2020/blob/master/doc/SA-IS.pdf
- 接尾辞オートマトン (suffix automaton)
  - https://ja.wikipedia.org/wiki/%E6%8E%A5%E5%B0%BE%E8%BE%9E%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3
  - https://w.atwiki.jp/uwicoder/pages/2842.html
  - https://github.com/KodamaD/JOISS2020/blob/master/docs/presentation.pdf
  - https://github.com/spaghetti-source/algorithm/blob/master/string/suffix_automaton.cc
  - https://codeforces.com/contest/1780/problem/G
- 接尾辞木 (suffix tree)
  - https://ja.wikipedia.org/wiki/%E6%8E%A5%E5%B0%BE%E8%BE%9E%E6%9C%A8
  - https://qiita.com/goonew/items/548fe90e9f68c6bba9e9
  - https://docs.google.com/presentation/d/1m-FpwlEg47kHCQx7FSImN0bPY7XJToRVbSMeCsLpI7g
  - https://github.com/spaghetti-source/algorithm/blob/master/string/suffix_tree.cc
  - ~~https://github.com/eandbsoftware/libraryCPP/tree/master/Ukkonen~~


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4972832/emthrm/C++17
