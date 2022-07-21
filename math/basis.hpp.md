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
  bundledCode: "#line 2 \"math/basis.hpp\"\n#include <algorithm>\n#include <bitset>\n\
    #include <iterator>\n#include <vector>\n\ntemplate <int D>\nstruct Basis {\n \
    \ std::vector<std::bitset<D>> v;\n  std::vector<int> msb;\n\n  Basis() = default;\n\
    \n  bool add(std::bitset<D> val) {\n    const int n = rank();\n    if (n == D)\
    \ return false;\n    for (int i = 0; i < n; ++i) {\n      if (val[msb[i]]) val\
    \ ^= v[i];\n    }\n    if (val.none()) return false;\n    int m = D - 1;\n   \
    \ while (!val[m]) --m;\n    if (v.empty()) {\n      v.emplace_back(val);\n   \
    \   msb.emplace_back(m);\n      return true;\n    }\n    const int idx = std::distance(std::upper_bound(msb.rbegin(),\
    \ msb.rend(), m),\n                                  msb.rend());\n    v.emplace(std::next(v.begin(),\
    \ idx), val);\n    msb.emplace(std::next(msb.begin(), idx), m);\n    for (int\
    \ i = idx + 1; i <= n; ++i) {\n      if (v[idx][msb[i]]) v[idx] ^= v[i];\n   \
    \ }\n    for (int i = idx - 1; i >= 0; --i) {\n      if (v[i][m]) v[i] ^= v[idx];\n\
    \    }\n    return true;\n  }\n\n  int rank() const { return v.size(); }\n\n \
    \ inline bool operator<(const Basis& x) const {\n    const int n = v.size();\n\
    \    if (n != x.rank()) return n < x.rank();\n    if (n == D) return false;\n\
    \    for (int i = 0; i < n; ++i) {\n      if (msb[i] != x.msb[i]) return msb[i]\
    \ < x.msb[i];\n    }\n    for (int i = 0; i < n; ++i) {\n      for (int j = msb[i]\
    \ - 1; ; --j) {\n        if (v[i][j] != x.v[i][j]) return x.v[i][j];\n      }\n\
    \    }\n    return false;\n  }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bitset>\n#include <iterator>\n\
    #include <vector>\n\ntemplate <int D>\nstruct Basis {\n  std::vector<std::bitset<D>>\
    \ v;\n  std::vector<int> msb;\n\n  Basis() = default;\n\n  bool add(std::bitset<D>\
    \ val) {\n    const int n = rank();\n    if (n == D) return false;\n    for (int\
    \ i = 0; i < n; ++i) {\n      if (val[msb[i]]) val ^= v[i];\n    }\n    if (val.none())\
    \ return false;\n    int m = D - 1;\n    while (!val[m]) --m;\n    if (v.empty())\
    \ {\n      v.emplace_back(val);\n      msb.emplace_back(m);\n      return true;\n\
    \    }\n    const int idx = std::distance(std::upper_bound(msb.rbegin(), msb.rend(),\
    \ m),\n                                  msb.rend());\n    v.emplace(std::next(v.begin(),\
    \ idx), val);\n    msb.emplace(std::next(msb.begin(), idx), m);\n    for (int\
    \ i = idx + 1; i <= n; ++i) {\n      if (v[idx][msb[i]]) v[idx] ^= v[i];\n   \
    \ }\n    for (int i = idx - 1; i >= 0; --i) {\n      if (v[i][m]) v[i] ^= v[idx];\n\
    \    }\n    return true;\n  }\n\n  int rank() const { return v.size(); }\n\n \
    \ inline bool operator<(const Basis& x) const {\n    const int n = v.size();\n\
    \    if (n != x.rank()) return n < x.rank();\n    if (n == D) return false;\n\
    \    for (int i = 0; i < n; ++i) {\n      if (msb[i] != x.msb[i]) return msb[i]\
    \ < x.msb[i];\n    }\n    for (int i = 0; i < n; ++i) {\n      for (int j = msb[i]\
    \ - 1; ; --j) {\n        if (v[i][j] != x.v[i][j]) return x.v[i][j];\n      }\n\
    \    }\n    return false;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/basis.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
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
