---
title: 中国剰余定理 (Chinese remainder theorem)
documentation_of: math/chinese_remainder_theorem.hpp
---

連立合同式

$$x \equiv b_i \pmod{m_i} \ (i = 1, 2,\ldots, k)$$

について

$$b_i \equiv b_j \pmod{\gcd(m_i, m_j)} \ (1 \leq \forall i, j \leq k)$$

が成り立つならば連立合同式を満たす

$$x \equiv r \pmod{\mathrm{lcm}(m_1, m_2,..., m_k)}$$

が一意に存在する．


## 時間計算量

$O(N \log{\mathrm{lcm}(m_1,...)})$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`chinese_remainder_theorem(b, m)`|$x \equiv r \pmod{\mathrm{lcm}(m_1,...)} \text{ s.t. } x \equiv b_i \pmod{m_i}$|存在しない場合は $(0, 0)$ となる．|


## 参考

- https://rsk0315.hatenablog.com/entry/2021/01/18/065720#crt
- https://github.com/atcoder/ac-library/blob/master/atcoder/math.hpp#L33-L80
- https://qiita.com/drken/items/ae02240cd1f8edfc86fd
- https://mathtrain.jp/remainder


## ToDo

- Garner のアルゴリズム
  - https://qiita.com/drken/items/ae02240cd1f8edfc86fd
  - https://github.com/drken1215/algorithm/blob/master/MathNumberTheory/garner.cpp
  - https://www.creativ.xyz/ect-gcd-crt-garner-927/
  - http://kirika-comp.hatenablog.com/entry/2017/12/18/143923
  - http://sugarknri.hatenablog.com/entry/2018/06/28/144407
  - https://lumakernel.github.io/ecasdqina/math/number-theory/Garner
  - https://cp-algorithms.com/algebra/chinese-remainder-theorem.html
  - http://flex.phys.tohoku.ac.jp/~maru/implementations/garner.php


## Verified

https://yukicoder.me/submissions/630411
