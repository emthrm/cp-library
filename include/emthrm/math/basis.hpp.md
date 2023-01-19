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
  bundledCode: "#line 1 \"include/emthrm/math/basis.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <bitset>\n#include <iterator>\n#include <vector>\n\nnamespace emthrm\
    \ {\n\ntemplate <int D>\nstruct Basis {\n  std::vector<std::bitset<D>> v;\n  std::vector<int>\
    \ msb;\n\n  Basis() = default;\n\n  bool add(std::bitset<D> val) {\n    const\
    \ int n = rank();\n    if (n == D) return false;\n    for (int i = 0; i < n; ++i)\
    \ {\n      if (val[msb[i]]) val ^= v[i];\n    }\n    if (val.none()) return false;\n\
    \    int m = D - 1;\n    while (!val[m]) --m;\n    if (v.empty()) {\n      v.emplace_back(val);\n\
    \      msb.emplace_back(m);\n      return true;\n    }\n    const int idx = std::distance(std::upper_bound(msb.rbegin(),\
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
    \    }\n    return false;\n  }\n};\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_BASIS_HPP_\n#define EMTHRM_MATH_BASIS_HPP_\n\n#include\
    \ <algorithm>\n#include <bitset>\n#include <iterator>\n#include <vector>\n\nnamespace\
    \ emthrm {\n\ntemplate <int D>\nstruct Basis {\n  std::vector<std::bitset<D>>\
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
    \    }\n    return false;\n  }\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_BASIS_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/basis.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/basis.test.cpp
documentation_of: include/emthrm/math/basis.hpp
layout: document
title: "\u57FA\u5E95 (basis)"
---


## 仕様

```cpp
template <int D>
struct Basis;
```

- `D`：ビット幅

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<std::bitset<D>> v`|ベクトル空間|
|`std::vector<int> msb`|$i$ 番目のベクトルの最上位ビット|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`Basis();`|デフォルトコンストラクタ|
|`bool add(std::bitset<D> val);`|ベクトル $\mathrm{val}$ を加えたのち、実際に要素数が増えたかを返す。|
|`int rank() const;`|要素数|
|`inline bool operator<(const Basis& x) const;`||


## 参考文献

- http://www.kupc.jp/static/media/K.290ca2fd.pdf
- https://xuzijian629.hatenablog.com/entry/2019/10/30/013225
- https://atcoder.jp/contests/kupc2012/submissions/7660727


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2416/review/5214392/emthrm/C++17
