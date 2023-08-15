---
title: [
  添え字 and での畳み込み,
  添え字 or での畳み込み,
  添え字 xor での畳み込み,
  添え字 gcd での畳み込み,
  添え字 lcm での畳み込み
]
documentation_of: [
  //include/emthrm/math/convolution/and_convolution.hpp,
  //include/emthrm/math/convolution/or_convolution.hpp,
  //include/emthrm/math/convolution/xor_convolution.hpp,
  //include/emthrm/math/convolution/gcd_convolution.hpp,
  //include/emthrm/math/convolution/lcm_convolution.hpp
]
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
- Bernard J. Fino and V. Ralph Algazi: Unified Matrix Treatment of the Fast Walsh-Hadamard Transform, *IEEE Transactions on Computers*, Vol. C-25, No. 11, pp. 1142–1146 (1976). https://doi.org/10.1109/TC.1976.1674569
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
- 凸性のある畳み込み
  - https://twitter.com/hotmanww/status/1482185138125832192
  - https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
  - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
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
