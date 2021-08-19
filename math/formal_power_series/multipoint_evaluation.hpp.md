---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series/polynomial_interpolation.hpp
    title: "\u591A\u9805\u5F0F\u88DC\u9593"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/multipoint_evaluation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/multipoint evaluation"
  - icon: ':heavy_check_mark:'
    path: test/math/formal_power_series/polynomial_interpolation.test.cpp
    title: "\u6570\u5B66/\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570/\u591A\u9805\u5F0F\u88DC\
      \u9593"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/formal_power_series/multipoint_evaluation.hpp\"\n#include\
    \ <vector>\r\n\r\ntemplate <template <typename> class C, typename T>\r\nstruct\
    \ MultipointEvaluation {\r\n  std::vector<C<T>> node;\r\n  std::vector<T> val;\r\
    \n\r\n  MultipointEvaluation(const std::vector<T> &xs) : n(xs.size()), val(xs.size())\
    \ {\r\n    node.resize(n << 1);\r\n    for (int i = 0; i < n; ++i) node[n + i]\
    \ = C<T>{-xs[i], 1};\r\n    for (int i = n - 1; i > 0; --i) node[i] = node[i <<\
    \ 1] * node[(i << 1) + 1];\r\n  }\r\n\r\n  void calc(const C<T> &f) { dfs(f, 1);\
    \ }\r\n\r\nprivate:\r\n  int n;\r\n\r\n  void dfs(C<T> poly, int pos) {\r\n  \
    \  poly %= node[pos];\r\n    if (pos < n) {\r\n      dfs(poly, pos << 1);\r\n\
    \      dfs(poly, (pos << 1) + 1);\r\n    } else {\r\n      val[pos - n] = poly[0];\r\
    \n    }\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include <vector>\r\n\r\ntemplate <template <typename> class\
    \ C, typename T>\r\nstruct MultipointEvaluation {\r\n  std::vector<C<T>> node;\r\
    \n  std::vector<T> val;\r\n\r\n  MultipointEvaluation(const std::vector<T> &xs)\
    \ : n(xs.size()), val(xs.size()) {\r\n    node.resize(n << 1);\r\n    for (int\
    \ i = 0; i < n; ++i) node[n + i] = C<T>{-xs[i], 1};\r\n    for (int i = n - 1;\
    \ i > 0; --i) node[i] = node[i << 1] * node[(i << 1) + 1];\r\n  }\r\n\r\n  void\
    \ calc(const C<T> &f) { dfs(f, 1); }\r\n\r\nprivate:\r\n  int n;\r\n\r\n  void\
    \ dfs(C<T> poly, int pos) {\r\n    poly %= node[pos];\r\n    if (pos < n) {\r\n\
    \      dfs(poly, pos << 1);\r\n      dfs(poly, (pos << 1) + 1);\r\n    } else\
    \ {\r\n      val[pos - n] = poly[0];\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/formal_power_series/multipoint_evaluation.hpp
  requiredBy:
  - math/formal_power_series/polynomial_interpolation.hpp
  timestamp: '2021-04-27 20:17:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/formal_power_series/polynomial_interpolation.test.cpp
  - test/math/formal_power_series/multipoint_evaluation.test.cpp
documentation_of: math/formal_power_series/multipoint_evaluation.hpp
layout: document
title: multipoint evaluation
---

複数の $x$ に対して $f(x)$ を求めるアルゴリズムである．


## 時間計算量

$\langle O(N(\log{N})^2), O(N(\log{N})^2) \rangle$


## 使用法

||説明|
|:--:|:--:|
|`MultipointEvaluation<多項式, T>(xs)`|multipoint evaluation を考える．|
|`node`|subproduct tree|
|`val`|$\lbrace f(x) \mid x \in \mathrm{xs} \rbrace$|
|`calc(f)`|多項式 $f$ に対して `val` を構築する．|


## 参考

- https://www.sci.kanagawa-u.ac.jp/info/matsuo/pub/pdf/IKM09.pdf
- https://judge.yosupo.jp/submission/3271
- https://scrapbox.io/ecasdqina-cp/%E5%A4%9A%E9%A0%85%E5%BC%8F%E3%82%92%E3%83%9E%E3%83%BC%E3%82%B8%E3%81%99%E3%82%8B%E4%B8%80%E8%88%AC%E7%9A%84%EF%BC%88%EF%BC%9F%EF%BC%89%E3%81%AA%E3%83%86%E3%82%AF


## ToDo

- https://drive.google.com/drive/folders/1gszRctvUfme7ST-K3DsrH7FIU64kHcsD


## Verified

https://judge.yosupo.jp/submission/3793
