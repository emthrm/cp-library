---
title: 高速ゼータ変換 (fast zeta transform)
documentation_of: math/convolution/fzt.hpp
---

$g(S) = \sum_{S \subseteq T} f(T)$ または $g(S) = \sum_{T \subseteq S} f(T)$ を高速に求める．


## 時間計算量

$O(N\log{N})$


## 使用法

||説明|
|:--:|:--:|
|`fzt(a, 上位集合に対する FZT か?, 単位元 = 0, 二項演算 = +)`|$A$ に FMT を行ったもの|


## 参考

- http://topcoder.g.hatena.ne.jp/iwiwi/20120422/1335065228
- https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
- https://todo314.hatenadiary.org/entry/20120614/1339695202
- http://compro.tsutajiro.com/archive/181015_incexc.pdf
- http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#qef794e9
- https://lumakernel.github.io/ecasdqina/algorithm/FastZetaTransform


## Verified

https://atcoder.jp/contests/arc100/submissions/10208329
