---
title: Lucas の定理 (Lucas's theorem)
documentation_of: //include/emthrm/math/twelvefold_way/lucas.hpp
---

$p \in \mathbb{P},\ n, k \in \mathrm{N}$ に対して、

$$
  \binom{n}{k} \equiv \prod_{i \in \mathbb{N}} \binom{\left\lfloor \frac{n}{p^i} \right\rfloor \bmod{p}}{\left\lfloor \frac{k}{p^i} \right\rfloor \bmod{p}} \pmod{p}
$$

が成り立つ。


## 時間計算量

$O(P + \log_P{N})$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <int P>`<br>`MInt<P> lucas(int n, int k);`|$\binom{n}{k} \bmod{p}$|


## 参考文献

- Edouard Lucas: Théorie des Fonctions Numériques Simplement Périodiques, *American Journal of Mathematics*, Vol. 1 (1878).
  - No. 2, pp. 184–196. https://doi.org/10.2307/2369308
  - No. 3, pp. 197–240. https://doi.org/10.2307/2369311
  - No. 4, pp. 289–321. https://doi.org/10.2307/2369373
- https://manabitimes.jp/math/1324


## Submissons

https://atcoder.jp/contests/arc117/submissions/21896797
