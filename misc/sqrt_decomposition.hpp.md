---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/sqrt_decomposition.test.cpp
    title: "\u305D\u306E\u4ED6/\u5E73\u65B9\u5206\u5272"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/sqrt_decomposition.hpp\"\n#include <cmath>\r\n#include\
    \ <vector>\r\n\r\nstruct SqrtDecomposition {\r\n  const int block_size, n;\r\n\
    \  std::vector<int> ls, rs;\r\n  std::vector<bool> to_be_eval;\r\n\r\n  explicit\
    \ SqrtDecomposition(const int n_)\r\n      : block_size(std::round(std::sqrt(n_))),\r\
    \n        n((n_ + block_size - 1) / block_size) {\r\n    ls.resize(n);\r\n   \
    \ rs.resize(n);\r\n    to_be_eval.assign(n, false);\r\n    for (int i = 0; i <\
    \ n; ++i) {\r\n      ls[i] = block_size * i;\r\n      rs[i] = (i + 1 == n ? n_\
    \ : block_size * (i + 1));\r\n    }\r\n  }\r\n\r\n  template <typename T> void\
    \ partial_update(const int idx, const T val);\r\n\r\n  template <typename T> void\
    \ total_update(const int idx, const T val);\r\n\r\n  template <typename T>\r\n\
    \  void update(const int l, const int r, const T val) {\r\n    if (r <= l) return;\r\
    \n    const int b_l = l / block_size, b_r = (r - 1) / block_size;\r\n    if (b_l\
    \ < b_r) {\r\n      if (l == ls[b_l]) {\r\n        total_update(b_l, val);\r\n\
    \      } else {\r\n        for (int i = l; i < rs[b_l]; ++i) {\r\n          partial_update(i,\
    \ val);\r\n        }\r\n      }\r\n      for (int i = b_l + 1; i < b_r; ++i) {\r\
    \n        total_update(i, val);\r\n      }\r\n      if (r == rs[b_r]) {\r\n  \
    \      total_update(b_r, val);\r\n      } else {\r\n        for (int i = ls[b_r];\
    \ i < r; ++i) {\r\n          partial_update(i, val);\r\n        }\r\n      }\r\
    \n    } else {\r\n      for (int i = l; i < r; ++i) {\r\n        partial_update(i,\
    \ val);\r\n      }\r\n    }\r\n  }\r\n\r\n  template <typename T> void partial_query(const\
    \ int idx, T* val);\r\n\r\n  template <typename T> void total_query(const int\
    \ idx, T* val);\r\n\r\n  template <typename T>\r\n  T query(const int l, const\
    \ int r, const T id) {\r\n    const int b_l = l / block_size, b_r = (r - 1) /\
    \ block_size;\r\n    T res = id;\r\n    if (b_l < b_r) {\r\n      if (l == ls[b_l])\
    \ {\r\n        total_query(b_l, &res);\r\n      } else {\r\n        for (int i\
    \ = l; i < rs[b_l]; ++i) {\r\n          partial_query(i, &res);\r\n        }\r\
    \n      }\r\n      for (int i = b_l + 1; i < b_r; ++i) {\r\n        total_query(i,\
    \ &res);\r\n      }\r\n      if (r == rs[b_r]) {\r\n        total_query(b_r, &res);\r\
    \n      } else {\r\n        for (int i = ls[b_r]; i < r; ++i) {\r\n          partial_query(i,\
    \ &res);\r\n        }\r\n      }\r\n    } else {\r\n      for (int i = l; i <\
    \ r; ++i) {\r\n        partial_query(i, &res);\r\n      }\r\n    }\r\n    return\
    \ res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <cmath>\r\n#include <vector>\r\n\r\nstruct SqrtDecomposition\
    \ {\r\n  const int block_size, n;\r\n  std::vector<int> ls, rs;\r\n  std::vector<bool>\
    \ to_be_eval;\r\n\r\n  explicit SqrtDecomposition(const int n_)\r\n      : block_size(std::round(std::sqrt(n_))),\r\
    \n        n((n_ + block_size - 1) / block_size) {\r\n    ls.resize(n);\r\n   \
    \ rs.resize(n);\r\n    to_be_eval.assign(n, false);\r\n    for (int i = 0; i <\
    \ n; ++i) {\r\n      ls[i] = block_size * i;\r\n      rs[i] = (i + 1 == n ? n_\
    \ : block_size * (i + 1));\r\n    }\r\n  }\r\n\r\n  template <typename T> void\
    \ partial_update(const int idx, const T val);\r\n\r\n  template <typename T> void\
    \ total_update(const int idx, const T val);\r\n\r\n  template <typename T>\r\n\
    \  void update(const int l, const int r, const T val) {\r\n    if (r <= l) return;\r\
    \n    const int b_l = l / block_size, b_r = (r - 1) / block_size;\r\n    if (b_l\
    \ < b_r) {\r\n      if (l == ls[b_l]) {\r\n        total_update(b_l, val);\r\n\
    \      } else {\r\n        for (int i = l; i < rs[b_l]; ++i) {\r\n          partial_update(i,\
    \ val);\r\n        }\r\n      }\r\n      for (int i = b_l + 1; i < b_r; ++i) {\r\
    \n        total_update(i, val);\r\n      }\r\n      if (r == rs[b_r]) {\r\n  \
    \      total_update(b_r, val);\r\n      } else {\r\n        for (int i = ls[b_r];\
    \ i < r; ++i) {\r\n          partial_update(i, val);\r\n        }\r\n      }\r\
    \n    } else {\r\n      for (int i = l; i < r; ++i) {\r\n        partial_update(i,\
    \ val);\r\n      }\r\n    }\r\n  }\r\n\r\n  template <typename T> void partial_query(const\
    \ int idx, T* val);\r\n\r\n  template <typename T> void total_query(const int\
    \ idx, T* val);\r\n\r\n  template <typename T>\r\n  T query(const int l, const\
    \ int r, const T id) {\r\n    const int b_l = l / block_size, b_r = (r - 1) /\
    \ block_size;\r\n    T res = id;\r\n    if (b_l < b_r) {\r\n      if (l == ls[b_l])\
    \ {\r\n        total_query(b_l, &res);\r\n      } else {\r\n        for (int i\
    \ = l; i < rs[b_l]; ++i) {\r\n          partial_query(i, &res);\r\n        }\r\
    \n      }\r\n      for (int i = b_l + 1; i < b_r; ++i) {\r\n        total_query(i,\
    \ &res);\r\n      }\r\n      if (r == rs[b_r]) {\r\n        total_query(b_r, &res);\r\
    \n      } else {\r\n        for (int i = ls[b_r]; i < r; ++i) {\r\n          partial_query(i,\
    \ &res);\r\n        }\r\n      }\r\n    } else {\r\n      for (int i = l; i <\
    \ r; ++i) {\r\n        partial_query(i, &res);\r\n      }\r\n    }\r\n    return\
    \ res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/sqrt_decomposition.hpp
  requiredBy: []
  timestamp: '2022-02-16 18:14:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/sqrt_decomposition.test.cpp
documentation_of: misc/sqrt_decomposition.hpp
layout: document
title: "\u5E73\u65B9\u5206\u5272 (sqrt decomposition)"
---


## 時間計算量

$\langle O(N), O(\sqrt{N}) \rangle$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`SqrtDecomposition(n)`|サイズ $N$ の平方分割を考える．||
|`block_size`|ブロックのサイズ||
|`n`|ブロックの数||
|[`ls[i]`, `rs[i]`)|ブロック $i$ に対応する列のインデックス||
|`partial_update(idx, val)`|$\mathrm{val}$ を基に $A_{\mathrm{idx}}$ を更新する．|関数プロトタイプ|
|`total_update(idx, val)`|$\mathrm{val}$ を基に $B_{\mathrm{idx}}$ を更新する．|関数プロトタイプ|
|`update(l, r, val)`|$\mathrm{val}$ を基に $\lbrack l, r)$ を更新する．||
|`partial_query(idx, &val)`|$A_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する．|関数プロトタイプ|
|`total_query(idx, &val)`|$B_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する．|関数プロトタイプ|
|`query(l, r, 単位元)`|$\lbrack l, r)$ に対するクエリの解||


## 参考

- https://twitter.com/chokudai/status/1125634200084729857


## ToDo

- https://www.hamayanhamayan.com/entry/2017/04/12/180257
- 指定された頂点たちの最小共通祖先関係を保って木を圧縮してできる補助的な木
  - https://dic.kimiyuki.net/auxiliary-tree
  - https://www.slideshare.net/iwiwi/2-12188845/7
  - http://drken1215.hatenablog.com/entry/2018/08/14/193500
  - https://atcoder.jp/contests/typical90/tasks/typical90_ai
- 木の平方分割
  - http://topcoder.g.hatena.ne.jp/iwiwi/20111205/1323099376
  - https://tubo28.me/compprog/algorithm/sqrt-decomp-tree/
  - http://noshi91.hatenablog.com/entry/2019/12/07/140433


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4087985/emthrm/C++14
