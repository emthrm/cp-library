---
title: 高速ゼータ変換 (fast zeta transform)
documentation_of: include/emthrm/math/convolution/fast_zeta_transform.hpp
---

$g(S) = \sum_{S \subseteq T} f(T)$ または $g(S) = \sum_{T \subseteq S} f(T)$ を高速に求める。


## 時間計算量

$O(N\log{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename Ring> std::vector<Ring> fast_zeta_transform(std::vector<Ring> a, const bool adds_superset, const Ring ID = 0, const std::function<Ring(const Ring&, const Ring&)> fn = [](const Ring& a, const Ring& b) -> Ring { return a + b; });`|$A$ に高速ゼータ変換を行ったもの|`adds_superset` は上位集合に対する変換かを表す。|


## 参考文献

- https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
- https://naoyat.hatenablog.jp/entry/zeta-moebius
- https://todo314.hatenadiary.org/entry/20120614/1339695202
- http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#qef794e9
- ~~https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform~~


## Submissons

https://atcoder.jp/contests/arc100/submissions/10208329
