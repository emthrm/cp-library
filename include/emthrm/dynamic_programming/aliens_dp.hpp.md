---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/dynamic_programming/aliens_dp.hpp\"\n\n\n\
    \nnamespace emthrm {\n\ntemplate <typename Real = double, typename F, typename\
    \ T>\nReal aliens_dp(const F calc, const int d, const T& max_abs_c, int repeat)\
    \ {\n  const auto l = [calc, d](const Real lambda) -> Real {\n    return -lambda\
    \ * d + calc(lambda);\n  };\n  Real ub = max_abs_c * 3, lb = -ub;\n  while (repeat--)\
    \ {\n    const Real mid1 = (lb + lb + ub) / 3, mid2 = (lb + ub + ub) / 3;\n  \
    \  if (l(mid1) > l(mid2)) {\n      ub = mid2;\n    } else {\n      lb = mid1;\n\
    \    }\n  }\n  return l(ub);\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_DYNAMIC_PROGRAMMING_ALIENS_DP_HPP_\n#define EMTHRM_DYNAMIC_PROGRAMMING_ALIENS_DP_HPP_\n\
    \nnamespace emthrm {\n\ntemplate <typename Real = double, typename F, typename\
    \ T>\nReal aliens_dp(const F calc, const int d, const T& max_abs_c, int repeat)\
    \ {\n  const auto l = [calc, d](const Real lambda) -> Real {\n    return -lambda\
    \ * d + calc(lambda);\n  };\n  Real ub = max_abs_c * 3, lb = -ub;\n  while (repeat--)\
    \ {\n    const Real mid1 = (lb + lb + ub) / 3, mid2 = (lb + ub + ub) / 3;\n  \
    \  if (l(mid1) > l(mid2)) {\n      ub = mid2;\n    } else {\n      lb = mid1;\n\
    \    }\n  }\n  return l(ub);\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_DYNAMIC_PROGRAMMING_ALIENS_DP_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/dynamic_programming/aliens_dp.hpp
  requiredBy: []
  timestamp: '2022-12-16 05:33:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/dynamic_programming/aliens_dp.hpp
layout: document
title: Aliens DP
---

$n$ 頂点有向非巡回グラフ $G = (V, E \mathrel{:=} \lbrace (i, j) \in \lbrace 0, 1, \ldots, n - 1 \rbrace \times \lbrace 0, 1, \ldots, n - 1 \rbrace \mid i < j \rbrace)$ を考える。辺 $(i, j) \in E$ の重みを $c(i, j)$ とおく。

$c$ が [concave quadrangle inequality](./knuth_yao_speedup.md) を満たすならば、ちょうど $d$ 辺通る始点 $0$、終点 $n - 1$ の道の内、最短のものの長さを高速に求められる。


## 時間計算量

$G$ 上で始点 $0$、終点 $n - 1$ の最短路長を $O(f(N))$ 時間で求められるとおくと $O(f(N) \log{\max_{(i, j) \in E} \lvert c(i, j)} \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename Real = double, typename F, typename T>`<br>`Real aliens_dp(const F calc, const int d, const T& max_abs_c, int repeat);`|辺の重みを $c(i, j) \gets c(i, j) + \lambda$ とした $G$ に対する始点 $0$、終点 $n - 1$ の最短路長を $\mathrm{calc}(\lambda)$、三分探索の反復回数を $\mathrm{repeat}$ としたとき、$G$ 上でちょうど $d$ 辺通る始点 $0$、終点 $n - 1$ の道の内、最短のものの長さ|


## 参考文献

- https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge
- https://github.com/LumaKernel/lib-cpp/blob/eb360cde5ad3e86a380de5745c7c741cfa165c37/src/dynamic-programming/speedup/AlienDP.md
- https://twitter.com/kyort0n/status/1378225258289766406
- https://twitter.com/noshi91/status/1481498494808784901
- https://twitter.com/noshi91/status/1436696351547412493


## TODO

- 通る辺の本数を $\lbrack d - k, d \rbrack$ とするとき
  - https://noshi91.hatenablog.com/entry/2022/01/13/001217
  - https://twitter.com/noshi91/status/1481465898062213123
  - https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge#%E3%81%9D%E3%81%AE%E4%BB%96
  - https://github.com/LumaKernel/lib-cpp/blob/eb360cde5ad3e86a380de5745c7c741cfa165c37/src/dynamic-programming/speedup/AlienDP.md#k%E3%82%92%E3%81%82%E3%82%8B%E7%AF%84%E5%9B%B2%E3%81%A8%E3%81%99%E3%82%8B%E3%81%A8%E3%81%8D
- [LARSCH algorithm](./knuth_yao_speedup.md) を用いた高速化
  - https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge#%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0
- 三分探索の上界と下界
  - https://twitter.com/noshi91/status/1481302364330274817
- $l(\lambda)$ を満たす最短路の内、通る辺の数が最小のもの
  - https://twitter.com/noshi91/status/1481537569301368836
- 実装上の工夫
  - https://twitter.com/tko919_/status/1480569460172156929
  - https://twitter.com/noshi91/status/1481285572333551618
  - https://twitter.com/maspy_stars/status/1436701397123096585
- 例
  - https://yukicoder.me/problems/no/1867
  - https://codeforces.com/contest/1279/problem/F
  - https://tiramistercp.hatenablog.com/entry/ecr079-f


## Submissons

https://atcoder.jp/contests/abc218/submissions/30355805
