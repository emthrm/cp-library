---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/fast_mobius_transform.hpp
    title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (fast Mobius transform)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/fast_zeta_transform.hpp
    title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u5909\u63DB (fast zeta transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/convolution/and_convolution.test.cpp
    title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u6DFB\u3048\u5B57 and \u3067\u306E\
      \u7573\u307F\u8FBC\u307F"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/convolution/and_convolution.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <vector>\n\n#line 1 \"include/emthrm/math/convolution/fast_mobius_transform.hpp\"\
    \n\n\n\n#include <bit>\n#line 6 \"include/emthrm/math/convolution/fast_mobius_transform.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <bool ADDS_SUPERSET, typename T>\nstd::vector<T>\
    \ fast_mobius_transform(std::vector<T> a, const T id = 0) {\n  const int n = std::bit_ceil(a.size());\n\
    \  a.resize(n, id);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int s = 0;\
    \ s < n; ++s) {\n      if (s & i) continue;\n      if constexpr (ADDS_SUPERSET)\
    \ {\n        a[s] -= a[s | i];\n      } else {\n        a[s | i] -= a[s];\n  \
    \    }\n    }\n  }\n  return a;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/convolution/fast_zeta_transform.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/convolution/fast_zeta_transform.hpp\"\n\
    #include <functional>\n#line 7 \"include/emthrm/math/convolution/fast_zeta_transform.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <bool ADDS_SUPERSET, typename Ring, typename\
    \ BinOp = std::plus<Ring>>\nstd::vector<Ring> fast_zeta_transform(\n    std::vector<Ring>\
    \ a, const Ring ID = 0, const BinOp bin_op = BinOp()) {\n  const int n = std::bit_ceil(a.size());\n\
    \  a.resize(n, ID);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int s = 0;\
    \ s < n; ++s) {\n      if (s & i) continue;\n      if constexpr (ADDS_SUPERSET)\
    \ {\n        a[s] = bin_op(a[s], a[s | i]);\n      } else {\n        a[s | i]\
    \ = bin_op(a[s | i], a[s]);\n      }\n    }\n  }\n  return a;\n}\n\n}  // namespace\
    \ emthrm\n\n\n#line 9 \"include/emthrm/math/convolution/and_convolution.hpp\"\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nstd::vector<T> and_convolution(std::vector<T>\
    \ a, std::vector<T> b,\n                               const T id = 0) {\n  int\
    \ n = std::max(a.size(), b.size());\n  a.resize(n, id);\n  b.resize(n, id);\n\
    \  a = fast_zeta_transform<true>(a, id);\n  b = fast_zeta_transform<true>(b, id);\n\
    \  n = a.size();\n  for (int i = 0; i < n; ++i) {\n    a[i] *= b[i];\n  }\n  return\
    \ fast_mobius_transform<true>(a);\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_CONVOLUTION_AND_CONVOLUTION_HPP_\n#define EMTHRM_MATH_CONVOLUTION_AND_CONVOLUTION_HPP_\n\
    \n#include <algorithm>\n#include <vector>\n\n#include \"emthrm/math/convolution/fast_mobius_transform.hpp\"\
    \n#include \"emthrm/math/convolution/fast_zeta_transform.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T>\nstd::vector<T> and_convolution(std::vector<T> a,\
    \ std::vector<T> b,\n                               const T id = 0) {\n  int n\
    \ = std::max(a.size(), b.size());\n  a.resize(n, id);\n  b.resize(n, id);\n  a\
    \ = fast_zeta_transform<true>(a, id);\n  b = fast_zeta_transform<true>(b, id);\n\
    \  n = a.size();\n  for (int i = 0; i < n; ++i) {\n    a[i] *= b[i];\n  }\n  return\
    \ fast_mobius_transform<true>(a);\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_CONVOLUTION_AND_CONVOLUTION_HPP_\n"
  dependsOn:
  - include/emthrm/math/convolution/fast_mobius_transform.hpp
  - include/emthrm/math/convolution/fast_zeta_transform.hpp
  isVerificationFile: false
  path: include/emthrm/math/convolution/and_convolution.hpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/convolution/and_convolution.test.cpp
documentation_of: include/emthrm/math/convolution/and_convolution.hpp
layout: document
title: "\u6DFB\u3048\u5B57 and \u3067\u306E\u7573\u307F\u8FBC\u307F"
---

$C_k = \sum_{k = i \circ j} A_i B_j$ を求める。ただし $\circ$ は二項演算である。

添え字 xor での畳み込みには『高速ウォルシュ・アダマール変換 (fast Walsh-Hadamard transform)』を用いる。


## 時間計算量

$O(N\log{N})$


## 仕様

### 添え字 and での畳み込み

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> and_convolution(std::vector<T> a, std::vector<T> b, const T id = 0);`|$A, B$ に対する添え字 and での畳み込み|


### 添え字 or での畳み込み

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> or_convolution(std::vector<T> a, std::vector<T> b, const T id = 0);`|$A, B$ に対する添え字 or での畳み込み|


### 添え字 xor での畳み込み

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> xor_convolution(std::vector<T> a, std::vector<T> b, const T id = 0);`|$A, B$ に対する添え字 xor での畳み込み|


### 添え字 gcd での畳み込み

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> gcd_convolution(std::vector<T> a, std::vector<T> b);`|$A, B$ に対する添え字 gcd での畳み込み|


### 添え字 lcm での畳み込み

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> lcm_convolution(std::vector<T> a, std::vector<T> b, const int n = -1);`|$A, B$ に対する添え字 lcm での畳み込み|


## 参考文献

- https://leaf1415.hatenablog.com/entry/2021/08/04/125751
- https://codeforces.com/blog/entry/48417
- http://kazuma8128.hatenablog.com/entry/2018/05/31/144519
- ~~https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform~~

高速ウォルシュ・アダマール変換
- https://sapphire15.hatenablog.com/entry/2021/09/13/114900
- https://cympfh.cc/aiura/hadamard-xor-convolution
- https://pctprobability.hatenadiary.com/entry/2022/01/10/185418
- https://twitter.com/maspy_stars/status/1350467886775603200

添え字 gcd での畳み込み
- https://noshi91.hatenablog.com/entry/2019/09/23/002445
- https://aprilganmo.hatenablog.com/entry/2020/07/24/190816

添え字 lcm での畳み込み
- https://aprilganmo.hatenablog.com/entry/2020/07/24/190816
- https://yukicoder.me/problems/no/1760


## TODO

- https://noshi91.hatenablog.com/entry/2020/10/27/175112
- 添え字 gcd での畳み込みを $O(N\log{\log{N}})$ に高速化する。
  - http://noshi91.hatenablog.com/entry/2018/12/27/121649
  - https://github.com/drken1215/algorithm/blob/master/MathAlgebra/fast_gcd_convolution.cpp
- 添え字 xor での畳み込みにおける逆元
  - https://yukicoder.me/problems/no/1753/editorial
- subset convolution
  - https://github.com/yosupo06/library-checker-problems/issues/297
  - https://judge.yosupo.jp/problem/subset_convolution
  - https://twitter.com/noshi91/status/1315347967990140928
  - https://twitter.com/noshi91/status/1315504267927584768
  - ~~https://twitter.com/beet_aizu/status/1339049679728779264~~
  - https://twitter.com/noshi91/status/1339077655715430401
  - https://ngtkana.hatenablog.com/entry/2021/04/25/135636
  - https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h
  - https://hos-lyric.hatenablog.com/entry/2021/01/14/201231
  - https://twitter.com/heno_code/status/1342124587849400320
  - https://twitter.com/tpyneriver/status/1356095139035242497
  - https://twitter.com/gmm_tea/status/1355754279751938053
  - https://twitter.com/Ryuhei_Mori/status/1356074005447340035
  - https://twitter.com/noshi91/status/1356075579896811523
  - https://atcoder.jp/contests/abc213/tasks/abc213_g
  - https://twitter.com/tpyneriver/status/1425483346927177736
  - https://twitter.com/_su1sen/status/1425871066916790281
  - https://atcoder.jp/contests/abc213/submissions/24925408
  - https://atcoder.jp/contests/abc213/submissions/24953805
  - https://sotanishy.github.io/cp-library-cpp/convolution/subset_convolution.hpp
  - https://atcoder.jp/contests/abc236/tasks/abc236_h
  - https://twitter.com/noshi91/status/1485246655419260939
  - https://yukicoder.me/problems/no/1901
  - https://atcoder.jp/contests/abc253/editorial/4028
- 凸性のある畳み込み
  - https://twitter.com/hotmanww/status/1482185138125832192
- relaxed multiplication
  - https://hly1204.github.io/library/math/formal_power_series/relaxed_convolution.hpp
  - https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c
  - https://hotman78.hatenablog.com/entry/2023/01/04/173507
  - https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae#toc38
  - https://twitter.com/noshi91/status/1618178939578634240
  - https://atcoder.jp/contests/abc230/tasks/abc230_h
  - https://atcoder.jp/contests/abc230/editorial/3036
  - https://twitter.com/noshi91/status/1466764432961585166
  - https://codeforces.com/contest/1792/problem/F2
  - https://twitter.com/SSRS_cp/status/1617927451958718467


## Submissons

- [添え字 and での畳み込み](https://judge.yosupo.jp/submission/32176)
- 添え字 or での畳み込み
- [添え字 xor での畳み込み](https://judge.yosupo.jp/submission/32459)
- [添え字 gcd での畳み込み](https://judge.yosupo.jp/submission/79257)
- [添え字 lcm での畳み込み](https://judge.yosupo.jp/submission/79261)
