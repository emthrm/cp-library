---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/sparse_table.hpp
    title: sparse table
  - icon: ':x:'
    path: string/suffix_array.hpp
    title: "\u63A5\u5C3E\u8F9E\u914D\u5217 (suffix array)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/longest_common_prefix.test.cpp
    title: "\u6587\u5B57\u5217/longest common prefix"
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/longest_common_prefix.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <string>\n#include <utility>\n#include <vector>\n\
    \n#line 4 \"data_structure/sparse_table.hpp\"\n#include <functional>\n#line 6\
    \ \"data_structure/sparse_table.hpp\"\n\ntemplate <typename Band>\nstruct SparseTable\
    \ {\n  using Fn = std::function<Band(Band, Band)>;\n\n  SparseTable() = default;\n\
    \n  explicit SparseTable(const std::vector<Band>& a, const Fn fn) { init(a, fn);\
    \ }\n\n  void init(const std::vector<Band>& a, const Fn fn_) {\n    fn = fn_;\n\
    \    int n = a.size(), table_h = 0;\n    lg.assign(n + 1, 0);\n    for (int i\
    \ = 2; i <= n; ++i) {\n      lg[i] = lg[i >> 1] + 1;\n    }\n    while ((1 <<\
    \ table_h) <= n) ++table_h;\n    data.assign(table_h, std::vector<Band>(n));\n\
    \    std::copy(a.begin(), a.end(), data.front().begin());\n    for (int i = 1;\
    \ i < table_h; ++i) {\n      for (int j = 0; j + (1 << i) <= n; ++j) {\n     \
    \   data[i][j] = fn(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);\n      }\n\
    \    }\n  }\n\n  Band query(const int left, const int right) const {\n    assert(left\
    \ < right);\n    const int h = lg[right - left];\n    return fn(data[h][left],\
    \ data[h][right - (1 << h)]);\n  }\n\n private:\n  Fn fn;\n  std::vector<int>\
    \ lg;\n  std::vector<std::vector<Band>> data;\n};\n#line 3 \"string/suffix_array.hpp\"\
    \n#include <numeric>\n#line 6 \"string/suffix_array.hpp\"\n\ntemplate <typename\
    \ T = std::string>\nstruct SuffixArray {\n  std::vector<int> sa, rank;\n\n  template\
    \ <typename U = char>\n  explicit SuffixArray(const T& s_, const U sentinel =\
    \ 0) : s(s_) {\n    const int n = s.size();\n    s.push_back(sentinel);\n    sa.resize(n\
    \ + 1);\n    std::iota(sa.begin(), sa.end(), 0);\n    std::sort(sa.begin(), sa.end(),\
    \ [this](const int a, const int b) -> bool {\n      return s[a] == s[b] ? a >\
    \ b : s[a] < s[b];\n    });\n    rank.resize(n + 1);\n    for (int i = 0; i <=\
    \ n; ++i) {\n      rank[i] = s[i];\n    }\n    std::vector<int> tmp(n + 1), prev_sa(n\
    \ + 1);\n    for (int len = 1; len <= n; len <<= 1) {\n      tmp[sa[0]] = 0;\n\
    \      for (int i = 1; i <= n; ++i) {\n        if (rank[sa[i - 1]] == rank[sa[i]]\
    \ && sa[i - 1] + len <= n &&\n            rank[sa[i - 1] + (len >> 1)] == rank[sa[i]\
    \ + (len >> 1)]) {\n          tmp[sa[i]] = tmp[sa[i - 1]];\n        } else {\n\
    \          tmp[sa[i]] = i;\n        }\n      }\n      rank.swap(tmp);\n      std::iota(tmp.begin(),\
    \ tmp.end(), 0);\n      std::copy(sa.begin(), sa.end(), prev_sa.begin());\n  \
    \    for (int i = 0; i <= n; ++i) {\n        const int idx = prev_sa[i] - len;\n\
    \        if (idx >= 0) sa[tmp[rank[idx]]++] = idx;\n      }\n    }\n    for (int\
    \ i = 0; i <= n; ++i) {\n      rank[sa[i]] = i;\n    }\n  }\n\n  std::vector<int>\
    \ match(T* t) const {\n    const int lb = lower_bound(t);\n    ++t->back();\n\
    \    const int ub = lower_bound(t);\n    --t->back();\n    std::vector<int> res(ub\
    \ - lb);\n    std::copy(sa.begin() + lb, sa.begin() + ub, res.begin());\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n  }\n\n private:\n  T s;\n\n  int lower_bound(const\
    \ T* t) const {\n    const int s_size = s.size(), t_size = t->size();\n    int\
    \ lb = 0, ub = s_size;\n    while (ub - lb > 1) {\n      const int mid = (lb +\
    \ ub) >> 1;\n      int s_idx = sa[mid], t_idx = 0;\n      bool finished = false;\n\
    \      for (; s_idx < s_size && t_idx < t_size; ++s_idx, ++t_idx) {\n        if\
    \ (s[s_idx] != (*t)[t_idx]) {\n          (s[s_idx] < (*t)[t_idx] ? lb : ub) =\
    \ mid;\n          finished = true;\n          break;\n        }\n      }\n   \
    \   if (!finished) (s_idx == s_size && t_idx < t_size ? lb : ub) = mid;\n    }\n\
    \    return ub;\n  }\n};\n#line 10 \"string/longest_common_prefix.hpp\"\n\ntemplate\
    \ <typename T = std::string>\nstruct LongestCommonPrefix : SuffixArray<T> {\n\
    \  std::vector<int> lcp_array;\n\n  explicit LongestCommonPrefix(const T& s) :\
    \ SuffixArray<T>(s) {\n    const int n = s.size();\n    lcp_array.resize(n);\n\
    \    for (int i = 0, common = 0; i < n; ++i) {\n      const int j = this->sa[this->rank[i]\
    \ - 1];\n      if (common > 0) --common;\n      while (i + common < n && j + common\
    \ < n &&\n             s[i + common] == s[j + common]) {\n        ++common;\n\
    \      }\n      lcp_array[this->rank[i] - 1] = common;\n    }\n    st.init(lcp_array,\
    \ [](const int a, const int b) -> int {\n      return std::min(a, b);\n    });\n\
    \  }\n\n  int query(int i, int j) const {\n    assert(i != j);\n    i = this->rank[i];\n\
    \    j = this->rank[j];\n    if (i > j) std::swap(i, j);\n    return st.query(i,\
    \ j);\n  }\n\n private:\n  SparseTable<int> st;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <string>\n\
    #include <utility>\n#include <vector>\n\n#include \"../data_structure/sparse_table.hpp\"\
    \n#include \"./suffix_array.hpp\"\n\ntemplate <typename T = std::string>\nstruct\
    \ LongestCommonPrefix : SuffixArray<T> {\n  std::vector<int> lcp_array;\n\n  explicit\
    \ LongestCommonPrefix(const T& s) : SuffixArray<T>(s) {\n    const int n = s.size();\n\
    \    lcp_array.resize(n);\n    for (int i = 0, common = 0; i < n; ++i) {\n   \
    \   const int j = this->sa[this->rank[i] - 1];\n      if (common > 0) --common;\n\
    \      while (i + common < n && j + common < n &&\n             s[i + common]\
    \ == s[j + common]) {\n        ++common;\n      }\n      lcp_array[this->rank[i]\
    \ - 1] = common;\n    }\n    st.init(lcp_array, [](const int a, const int b) ->\
    \ int {\n      return std::min(a, b);\n    });\n  }\n\n  int query(int i, int\
    \ j) const {\n    assert(i != j);\n    i = this->rank[i];\n    j = this->rank[j];\n\
    \    if (i > j) std::swap(i, j);\n    return st.query(i, j);\n  }\n\n private:\n\
    \  SparseTable<int> st;\n};\n"
  dependsOn:
  - data_structure/sparse_table.hpp
  - string/suffix_array.hpp
  isVerificationFile: false
  path: string/longest_common_prefix.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/longest_common_prefix.test.cpp
documentation_of: string/longest_common_prefix.hpp
layout: document
title: longest common prefix
---


### 高さ配列 (longest common prefix array)

接尾辞配列中で隣接する接尾辞の最長共通接頭辞長を表す配列である．


## 時間計算量

テキスト長を $N$ とおくと $\langle O(N\log{N}), O(1) \rangle$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`LongestCommonPrefix<T = string>(s)`|$S$ の longest common prefix を考える．||
|`lcp_array`|高さ配列||
|`query(i, j)`|位置 $i, j$ を一文字目とする接尾辞の最長共通接頭辞長|$i \neq j$ でなければならない．|


## 参考

- https://github.com/beet-aizu/library/blob/8ca8433c2baf5ddd8efca091927475ad03caadce/string/longestcommonprefix.cpp
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.339-340，マイナビ出版（2012）


## Verified

https://judge.yosupo.jp/submission/3244
