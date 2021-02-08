---
title: 中国剰余定理 (Chinese remainder theorem)
documentation_of: math/crt.hpp
---

連立合同式

$$x \equiv b_i \pmod{m_i} \ (i = 1, 2,\ldots, k)$$

について

$$b_i \equiv b_j \pmod{\gcd(m_i, m_j)} \ (1 \leq \forall i, j \leq k)$$

が成り立つならば連立合同式を満たす

$$x \equiv r \pmod{\mathrm{lcm}(m_1, m_2,..., m_k)}$$

が一意に存在する．


## 時間計算量

$\mathrm{lcm}(m_1, m_2,..., m_k) = \mathrm{lcm}(M)$ とおくと $O(N \log{\mathrm{lcm}(M)})$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`crt(b, m)`|$x \equiv r \pmod{\mathrm{lcm}(m_1,...)} \text{ s.t. } x \equiv b_i \pmod{m_i}$|存在しない場合は $(0, -1)$ となる．|


## 参考

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
- Lucas の定理 (Lucas's theorem)
  - https://en.wikipedia.org/wiki/Lucas%27s_theorem
  - https://mathtrain.jp/lucastheorem
  - http://spinda2.blog48.fc2.com/blog-entry-399.html
  - https://ferin-tech.hatenablog.com/entry/2018/01/17/010829


## Verified

https://yukicoder.me/submissions/444959
