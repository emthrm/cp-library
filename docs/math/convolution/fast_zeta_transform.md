---
title: 高速ゼータ変換 (fast zeta transform)
documentation_of: //include/emthrm/math/convolution/fast_zeta_transform.hpp
---

$g(S) = \sum_{S \subseteq T} f(T)$ または $g(S) = \sum_{T \subseteq S} f(T)$ を高速に求める。


## 時間計算量

$O(N\log{N})$


## 仕様

### Yates's algorithm

|名前|戻り値|
|:--|:--|
|`template <bool ADDS_SUPERSET, typename Ring, typename BinOp = std::plus<Ring>>`<br>`std::vector<Ring> fast_zeta_transform(std::vector<Ring> a, const Ring ID = 0, const BinOp bin_op = BinOp());`|$A$ に高速ゼータ変換を行ったもの|`ADDS_SUPERSET` は上位集合に対する変換かを表す。|


## 参考文献

- F. Yates: The Design and Analysis of Factorial Experiments, *Technical Communication*, Vol. 35 (1937).
- https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
- https://naoyat.hatenablog.jp/entry/zeta-moebius
- https://todo314.hatenadiary.org/entry/20120614/1339695202
- http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#qef794e9
- ~~https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform~~


## Submissons

https://atcoder.jp/contests/arc100/submissions/10208329
