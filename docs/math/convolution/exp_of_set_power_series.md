---
title: 集合冪級数 (set power series) の指数
documentation_of: //include/emthrm/math/convolution/exp_of_set_power_series.hpp
---

[集合冪級数](./subset_convolution.md) $(\lbrace f \in 2^{\lbrack n \rbrack} \to K \rbrace, +, \ast)$ を考える。$f(\emptyset) = 0$ を満たす $f \in 2^{\lbrack n \rbrack} \to K$ に対して

$$
  \exp{f} \mathrel{:=} \sum_{k = 0}^\infty \frac{f^k}{k!}
$$

で定義される $\exp$ である。


## 時間計算量

$O(2^N N^2)$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <int MaxN, typename T>`<br>`std::vector<T> exp_of_set_power_series(const std::vector<T>& f);`|$\exp{f}$|$n \leq \mathrm{MaxN}$<br>$f(\emptyset) = 0$|


## 参考文献

- https://suisen-kyopro.hatenablog.com/entry/2023/04/07/041318
- https://nyaannyaan.github.io/library/set-function/exp-of-set-power-series.hpp


## TODO

- 集合冪級数
  - https://maspypy.com/category/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0
  - 多項式との合成
    - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90
    - https://suisen-kyopro.hatenablog.com/entry/2023/04/07/041318
    - https://nyaannyaan.github.io/library/set-function/polynomial-composite-set-power-series.hpp
    - https://judge.yosupo.jp/problem/polynomial_composite_set_power_series
    - https://judge.yosupo.jp/problem/power_projection_of_set_power_series
    - 問題例 "[We Love Forest](https://atcoder.jp/contests/abc253/tasks/abc253_h)"
      - https://atcoder.jp/contests/abc253/editorial/4028
  - 対数
    - 問題例 "[Lights Out on Connected Graph](https://atcoder.jp/contests/arc105/tasks/arc105_f)"
      - https://twitter.com/noshi91/status/1315347967990140928
      - https://twitter.com/noshi91/status/1315504267927584768
      - https://twitter.com/noshi91/status/1339077655715430401
      - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b#toc3
      - https://nyaannyaan.github.io/library/set-function/subset-convolution.hpp.html
    - 問題例 "[Connectivity 2](https://atcoder.jp/contests/abc213/tasks/abc213_g)"
      - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b#toc2
      - https://atcoder.jp/contests/abc213/submissions/24925408
    - 問題例 "[Electric Circuit](https://atcoder.jp/contests/abc321/tasks/abc321_g)"
      - https://atcoder.jp/contests/abc321/tasks/abc321_g
  - 累乗
    - https://twitter.com/_su1sen/status/1425871066916790281
    - 問題例 "[K-Coloring](https://atcoder.jp/contests/abc294/tasks/abc294_h)"
      - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-4-%e5%95%8f%e9%a1%8c%e4%be%8b#toc5
      - https://twitter.com/noshi91/status/1637451650402234373
  - 平方根
    - 問題例 "[Hierarchical Phylogeny](https://atcoder.jp/contests/xmascon20/tasks/xmascon20_h)"
      - https://hos-lyric.hatenablog.com/entry/2021/01/14/201231
      - https://twitter.com/heno_code/status/1342124587849400320
      - https://twitter.com/tpyneriver/status/1356095139035242497
  - 高速化
    - https://37zigen.com/subset-convolution/#i-2
    - https://twitter.com/tpyneriver/status/1425483346927177736


## Submissons

https://judge.yosupo.jp/problem/exp_of_set_power_series
