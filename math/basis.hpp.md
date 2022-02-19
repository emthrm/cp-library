---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/basis.test.cpp
    title: "\u6570\u5B66/\u57FA\u5E95"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/basis.hpp\"\n#include <algorithm>\r\n#include <bitset>\r\
    \n#include <iterator>\r\n#include <vector>\r\n\r\ntemplate <int D>\r\nstruct Basis\
    \ {\r\n  std::vector<std::bitset<D>> v;\r\n  std::vector<int> msb;\r\n\r\n  Basis()\
    \ = default;\r\n\r\n  bool add(std::bitset<D> val) {\r\n    const int n = rank();\r\
    \n    if (n == D) return false;\r\n    for (int i = 0; i < n; ++i) {\r\n     \
    \ if (val[msb[i]]) val ^= v[i];\r\n    }\r\n    if (val.none()) return false;\r\
    \n    int m = D - 1;\r\n    while (!val[m]) --m;\r\n    if (v.empty()) {\r\n \
    \     v.emplace_back(val);\r\n      msb.emplace_back(m);\r\n      return true;\r\
    \n    }\r\n    const int idx = std::distance(std::upper_bound(msb.rbegin(), msb.rend(),\
    \ m),\r\n                                  msb.rend());\r\n    v.emplace(std::next(v.begin(),\
    \ idx), val);\r\n    msb.emplace(std::next(msb.begin(), idx), m);\r\n    for (int\
    \ i = idx + 1; i <= n; ++i) {\r\n      if (v[idx][msb[i]]) v[idx] ^= v[i];\r\n\
    \    }\r\n    for (int i = idx - 1; i >= 0; --i) {\r\n      if (v[i][m]) v[i]\
    \ ^= v[idx];\r\n    }\r\n    return true;\r\n  }\r\n\r\n  int rank() const { return\
    \ v.size(); }\r\n\r\n  inline bool operator<(const Basis& x) const {\r\n    const\
    \ int n = v.size();\r\n    if (n != x.rank()) return n < x.rank();\r\n    if (n\
    \ == D) return false;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (msb[i]\
    \ != x.msb[i]) return msb[i] < x.msb[i];\r\n    }\r\n    for (int i = 0; i < n;\
    \ ++i) {\r\n      for (int j = msb[i] - 1; ; --j) {\r\n        if (v[i][j] !=\
    \ x.v[i][j]) return x.v[i][j];\r\n      }\r\n    }\r\n    return false;\r\n  }\r\
    \n};\r\n"
  code: "#pragma once\r\n#include <algorithm>\r\n#include <bitset>\r\n#include <iterator>\r\
    \n#include <vector>\r\n\r\ntemplate <int D>\r\nstruct Basis {\r\n  std::vector<std::bitset<D>>\
    \ v;\r\n  std::vector<int> msb;\r\n\r\n  Basis() = default;\r\n\r\n  bool add(std::bitset<D>\
    \ val) {\r\n    const int n = rank();\r\n    if (n == D) return false;\r\n   \
    \ for (int i = 0; i < n; ++i) {\r\n      if (val[msb[i]]) val ^= v[i];\r\n   \
    \ }\r\n    if (val.none()) return false;\r\n    int m = D - 1;\r\n    while (!val[m])\
    \ --m;\r\n    if (v.empty()) {\r\n      v.emplace_back(val);\r\n      msb.emplace_back(m);\r\
    \n      return true;\r\n    }\r\n    const int idx = std::distance(std::upper_bound(msb.rbegin(),\
    \ msb.rend(), m),\r\n                                  msb.rend());\r\n    v.emplace(std::next(v.begin(),\
    \ idx), val);\r\n    msb.emplace(std::next(msb.begin(), idx), m);\r\n    for (int\
    \ i = idx + 1; i <= n; ++i) {\r\n      if (v[idx][msb[i]]) v[idx] ^= v[i];\r\n\
    \    }\r\n    for (int i = idx - 1; i >= 0; --i) {\r\n      if (v[i][m]) v[i]\
    \ ^= v[idx];\r\n    }\r\n    return true;\r\n  }\r\n\r\n  int rank() const { return\
    \ v.size(); }\r\n\r\n  inline bool operator<(const Basis& x) const {\r\n    const\
    \ int n = v.size();\r\n    if (n != x.rank()) return n < x.rank();\r\n    if (n\
    \ == D) return false;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (msb[i]\
    \ != x.msb[i]) return msb[i] < x.msb[i];\r\n    }\r\n    for (int i = 0; i < n;\
    \ ++i) {\r\n      for (int j = msb[i] - 1; ; --j) {\r\n        if (v[i][j] !=\
    \ x.v[i][j]) return x.v[i][j];\r\n      }\r\n    }\r\n    return false;\r\n  }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/basis.hpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/basis.test.cpp
documentation_of: math/basis.hpp
layout: document
title: "\u57FA\u5E95 (basis)"
---


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Basis<D>()`|長さ $D$ の基底を考える．||
|`v`|ベクトル空間||
|`msb[i]`|$i$ 番目のベクトルの最上位ビット||
|`add(val)`|ベクトル $\mathrm{val}$ を加える．|返り値は要素数が増えたか．|
|`rank()`|要素数||
|`operator<(x)`|||


## 参考

- http://www.kupc.jp/static/media/K.290ca2fd.pdf
- https://xuzijian629.hatenablog.com/entry/2019/10/30/013225
- https://atcoder.jp/contests/kupc2012/submissions/7660727


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2416/review/5214392/emthrm/C++17
