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
  bundledCode: "#line 2 \"misc/sqrt_decomposition.hpp\"\n#include <cmath>\n#include\
    \ <vector>\n\nstruct SqrtDecomposition {\n  const int block_size, n;\n  std::vector<int>\
    \ ls, rs;\n  std::vector<bool> to_be_eval;\n\n  explicit SqrtDecomposition(const\
    \ int n_)\n      : block_size(std::round(std::sqrt(n_))),\n        n((n_ + block_size\
    \ - 1) / block_size) {\n    ls.resize(n);\n    rs.resize(n);\n    to_be_eval.assign(n,\
    \ false);\n    for (int i = 0; i < n; ++i) {\n      ls[i] = block_size * i;\n\
    \      rs[i] = (i + 1 == n ? n_ : block_size * (i + 1));\n    }\n  }\n\n  template\
    \ <typename T> void partial_update(const int idx, const T val);\n\n  template\
    \ <typename T> void total_update(const int idx, const T val);\n\n  template <typename\
    \ T>\n  void update(const int l, const int r, const T val) {\n    if (r <= l)\
    \ return;\n    const int b_l = l / block_size, b_r = (r - 1) / block_size;\n \
    \   if (b_l < b_r) {\n      if (l == ls[b_l]) {\n        total_update(b_l, val);\n\
    \      } else {\n        for (int i = l; i < rs[b_l]; ++i) {\n          partial_update(i,\
    \ val);\n        }\n      }\n      for (int i = b_l + 1; i < b_r; ++i) {\n   \
    \     total_update(i, val);\n      }\n      if (r == rs[b_r]) {\n        total_update(b_r,\
    \ val);\n      } else {\n        for (int i = ls[b_r]; i < r; ++i) {\n       \
    \   partial_update(i, val);\n        }\n      }\n    } else {\n      for (int\
    \ i = l; i < r; ++i) {\n        partial_update(i, val);\n      }\n    }\n  }\n\
    \n  template <typename T> void partial_query(const int idx, T* val);\n\n  template\
    \ <typename T> void total_query(const int idx, T* val);\n\n  template <typename\
    \ T>\n  T query(const int l, const int r, const T id) {\n    const int b_l = l\
    \ / block_size, b_r = (r - 1) / block_size;\n    T res = id;\n    if (b_l < b_r)\
    \ {\n      if (l == ls[b_l]) {\n        total_query(b_l, &res);\n      } else\
    \ {\n        for (int i = l; i < rs[b_l]; ++i) {\n          partial_query(i, &res);\n\
    \        }\n      }\n      for (int i = b_l + 1; i < b_r; ++i) {\n        total_query(i,\
    \ &res);\n      }\n      if (r == rs[b_r]) {\n        total_query(b_r, &res);\n\
    \      } else {\n        for (int i = ls[b_r]; i < r; ++i) {\n          partial_query(i,\
    \ &res);\n        }\n      }\n    } else {\n      for (int i = l; i < r; ++i)\
    \ {\n        partial_query(i, &res);\n      }\n    }\n    return res;\n  }\n};\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\nstruct SqrtDecomposition\
    \ {\n  const int block_size, n;\n  std::vector<int> ls, rs;\n  std::vector<bool>\
    \ to_be_eval;\n\n  explicit SqrtDecomposition(const int n_)\n      : block_size(std::round(std::sqrt(n_))),\n\
    \        n((n_ + block_size - 1) / block_size) {\n    ls.resize(n);\n    rs.resize(n);\n\
    \    to_be_eval.assign(n, false);\n    for (int i = 0; i < n; ++i) {\n      ls[i]\
    \ = block_size * i;\n      rs[i] = (i + 1 == n ? n_ : block_size * (i + 1));\n\
    \    }\n  }\n\n  template <typename T> void partial_update(const int idx, const\
    \ T val);\n\n  template <typename T> void total_update(const int idx, const T\
    \ val);\n\n  template <typename T>\n  void update(const int l, const int r, const\
    \ T val) {\n    if (r <= l) return;\n    const int b_l = l / block_size, b_r =\
    \ (r - 1) / block_size;\n    if (b_l < b_r) {\n      if (l == ls[b_l]) {\n   \
    \     total_update(b_l, val);\n      } else {\n        for (int i = l; i < rs[b_l];\
    \ ++i) {\n          partial_update(i, val);\n        }\n      }\n      for (int\
    \ i = b_l + 1; i < b_r; ++i) {\n        total_update(i, val);\n      }\n     \
    \ if (r == rs[b_r]) {\n        total_update(b_r, val);\n      } else {\n     \
    \   for (int i = ls[b_r]; i < r; ++i) {\n          partial_update(i, val);\n \
    \       }\n      }\n    } else {\n      for (int i = l; i < r; ++i) {\n      \
    \  partial_update(i, val);\n      }\n    }\n  }\n\n  template <typename T> void\
    \ partial_query(const int idx, T* val);\n\n  template <typename T> void total_query(const\
    \ int idx, T* val);\n\n  template <typename T>\n  T query(const int l, const int\
    \ r, const T id) {\n    const int b_l = l / block_size, b_r = (r - 1) / block_size;\n\
    \    T res = id;\n    if (b_l < b_r) {\n      if (l == ls[b_l]) {\n        total_query(b_l,\
    \ &res);\n      } else {\n        for (int i = l; i < rs[b_l]; ++i) {\n      \
    \    partial_query(i, &res);\n        }\n      }\n      for (int i = b_l + 1;\
    \ i < b_r; ++i) {\n        total_query(i, &res);\n      }\n      if (r == rs[b_r])\
    \ {\n        total_query(b_r, &res);\n      } else {\n        for (int i = ls[b_r];\
    \ i < r; ++i) {\n          partial_query(i, &res);\n        }\n      }\n    }\
    \ else {\n      for (int i = l; i < r; ++i) {\n        partial_query(i, &res);\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/sqrt_decomposition.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
  - https://sotanishy.github.io/cp-library-cpp/tree/auxiliary_tree.cpp
  - https://atcoder.jp/contests/typical90/tasks/typical90_ai
- 木の平方分割
  - http://topcoder.g.hatena.ne.jp/iwiwi/20111205/1323099376
  - https://tubo28.me/compprog/algorithm/sqrt-decomp-tree/
  - http://noshi91.hatenablog.com/entry/2019/12/07/140433


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4087985/emthrm/C++14
