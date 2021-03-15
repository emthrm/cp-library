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
    \ <vector>\r\n\r\nstruct SqrtDecomposition {\r\n  int b, n;\r\n  std::vector<int>\
    \ left, right;\r\n  std::vector<bool> need_to_be_eval;\r\n\r\n  SqrtDecomposition(int\
    \ n_) : b(std::sqrt(n_)) {\r\n    n = (n_ + b - 1) / b;\r\n    left.resize(n);\r\
    \n    right.resize(n);\r\n    need_to_be_eval.assign(n, false);\r\n    for (int\
    \ i = 0; i < n; ++i) {\r\n      left[i] = b * i;\r\n      right[i] = i + 1 ==\
    \ n ? n_ : b * (i + 1);\r\n    }\r\n  }\r\n\r\n  template <typename T> void partial_update(int\
    \ idx, T val);\r\n\r\n  template <typename T> void total_update(int idx, T val);\r\
    \n\r\n  template <typename T>\r\n  void update(int l, int r, T val) {\r\n    if\
    \ (r <= l) return;\r\n    int l_b = l / b, r_b = (r - 1) / b;\r\n    if (l_b <\
    \ r_b) {\r\n      if (l == left[l_b]) {\r\n        total_update(l_b, val);\r\n\
    \      } else {\r\n        for (int i = l; i < right[l_b]; ++i) partial_update(i,\
    \ val);\r\n      }\r\n      for (int i = l_b + 1; i < r_b; ++i) total_update(i,\
    \ val);\r\n      if (r == right[r_b]) {\r\n        total_update(r_b, val);\r\n\
    \      } else {\r\n        for (int i = left[r_b]; i < r; ++i) partial_update(i,\
    \ val);\r\n      }\r\n    } else {\r\n      for (int i = l; i < r; ++i) partial_update(i,\
    \ val);\r\n    }\r\n  }\r\n\r\n  template <typename T> void partial_query(int\
    \ idx, T &val);\r\n\r\n  template <typename T> void total_query(int idx, T &val);\r\
    \n\r\n  template <typename T>\r\n  T query(int l, int r, const T ID) {\r\n   \
    \ int l_b = l / b, r_b = (r - 1) / b;\r\n    T res = ID;\r\n    if (l_b < r_b)\
    \ {\r\n      if (l == left[l_b]) {\r\n        total_query(l_b, res);\r\n     \
    \ } else {\r\n        for (int i = l; i < right[l_b]; ++i) partial_query(i, res);\r\
    \n      }\r\n      for (int i = l_b + 1; i < r_b; ++i) total_query(i, res);\r\n\
    \      if (r == right[r_b]) {\r\n        total_query(r_b, res);\r\n      } else\
    \ {\r\n        for (int i = left[r_b]; i < r; ++i) partial_query(i, res);\r\n\
    \      }\r\n    } else {\r\n      for (int i = l; i < r; ++i) partial_query(i,\
    \ res);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <cmath>\r\n#include <vector>\r\n\r\nstruct SqrtDecomposition\
    \ {\r\n  int b, n;\r\n  std::vector<int> left, right;\r\n  std::vector<bool> need_to_be_eval;\r\
    \n\r\n  SqrtDecomposition(int n_) : b(std::sqrt(n_)) {\r\n    n = (n_ + b - 1)\
    \ / b;\r\n    left.resize(n);\r\n    right.resize(n);\r\n    need_to_be_eval.assign(n,\
    \ false);\r\n    for (int i = 0; i < n; ++i) {\r\n      left[i] = b * i;\r\n \
    \     right[i] = i + 1 == n ? n_ : b * (i + 1);\r\n    }\r\n  }\r\n\r\n  template\
    \ <typename T> void partial_update(int idx, T val);\r\n\r\n  template <typename\
    \ T> void total_update(int idx, T val);\r\n\r\n  template <typename T>\r\n  void\
    \ update(int l, int r, T val) {\r\n    if (r <= l) return;\r\n    int l_b = l\
    \ / b, r_b = (r - 1) / b;\r\n    if (l_b < r_b) {\r\n      if (l == left[l_b])\
    \ {\r\n        total_update(l_b, val);\r\n      } else {\r\n        for (int i\
    \ = l; i < right[l_b]; ++i) partial_update(i, val);\r\n      }\r\n      for (int\
    \ i = l_b + 1; i < r_b; ++i) total_update(i, val);\r\n      if (r == right[r_b])\
    \ {\r\n        total_update(r_b, val);\r\n      } else {\r\n        for (int i\
    \ = left[r_b]; i < r; ++i) partial_update(i, val);\r\n      }\r\n    } else {\r\
    \n      for (int i = l; i < r; ++i) partial_update(i, val);\r\n    }\r\n  }\r\n\
    \r\n  template <typename T> void partial_query(int idx, T &val);\r\n\r\n  template\
    \ <typename T> void total_query(int idx, T &val);\r\n\r\n  template <typename\
    \ T>\r\n  T query(int l, int r, const T ID) {\r\n    int l_b = l / b, r_b = (r\
    \ - 1) / b;\r\n    T res = ID;\r\n    if (l_b < r_b) {\r\n      if (l == left[l_b])\
    \ {\r\n        total_query(l_b, res);\r\n      } else {\r\n        for (int i\
    \ = l; i < right[l_b]; ++i) partial_query(i, res);\r\n      }\r\n      for (int\
    \ i = l_b + 1; i < r_b; ++i) total_query(i, res);\r\n      if (r == right[r_b])\
    \ {\r\n        total_query(r_b, res);\r\n      } else {\r\n        for (int i\
    \ = left[r_b]; i < r; ++i) partial_query(i, res);\r\n      }\r\n    } else {\r\
    \n      for (int i = l; i < r; ++i) partial_query(i, res);\r\n    }\r\n    return\
    \ res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/sqrt_decomposition.hpp
  requiredBy: []
  timestamp: '2021-02-13 04:45:32+09:00'
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
|`b`|ブロックのサイズ||
|`n`|ブロックの数||
|[`left[i]`, `right[i]`)|ブロック $i$ に対応する列のインデックス||
|`partial_update(idx, val)`|$A_{\mathrm{idx}}$ に対して $\mathrm{val}$ を基に更新する．|関数プロトタイプ|
|`total_update(idx, val)`|$B_{\mathrm{idx}}$ に対して $\mathrm{val}$ を基に更新する．|関数プロトタイプ|
|`update(l, r, val)`|$\lbrack l, r)$ に対して $\mathrm{val}$ を基に更新する．||
|`partial_query(idx, val)`|$A_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する．|関数プロトタイプ|
|`total_query(idx, val)`|$B_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する．|関数プロトタイプ|
|`query(l, r, 単位元)`|$\lbrack l, r)$ に対するクエリの解||


## 参考

- https://twitter.com/chokudai/status/1125634200084729857


## ToDo

- https://www.hamayanhamayan.com/entry/2017/04/12/180257
- クエリの平方分割 (木の圧縮)
  - https://www.slideshare.net/iwiwi/2-12188845/7
  - http://drken1215.hatenablog.com/entry/2018/08/14/193500
  - https://ei1333.github.io/algorithm/graph-decomp.html
- 木の平方分割
  - http://topcoder.g.hatena.ne.jp/iwiwi/20111205/1323099376
  - https://tubo28.me/compprog/algorithm/sqrt-decomp-tree/
  - http://noshi91.hatenablog.com/entry/2019/12/07/140433


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4087985/emthrm/C++14
