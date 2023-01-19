---
title: 逆元 (inverse element)
documentation_of: include/emthrm/math/mod_inv.hpp
---

$ax \equiv 1 \pmod{m}$ を満たす $x = a^{-1}$ である。
- $a^{-1}$ が存在するとき $a \cdot a^{-1} + my = 1$ を満たす $y \in \mathbb{Z}$ が存在する。[拡張 Euclid の互除法](ext_gcd.md)を用い、時間計算量 $O(\log{M})$ で $(a^{-1}, y)$ を求められる。
- Fermat の小定理より、$m \in \mathbb{P}$ かつ $a \perp m$ を満たすとき $a^{-1} \equiv a^{m - 2} \pmod{m}$ が成り立つ。時間計算量 $O(\log{M})$ で求められる。
- [オイラーの定理](euler_phi/euler_phi.md###オイラーの定理)より、$a \perp m$ を満たすとき $a^{-1} \equiv a^{\varphi(m) - 1} \pmod{m}$ が成り立つ。時間計算量 $O(\sqrt{M})$ で求められる。


## 時間計算量

$O(\log{M})$


## 仕様

|名前|戻り値|
|:--|:--|
|`long long mod_inv(long long a, const int m);`|$a$ の逆元。ただし存在しないときは $-1$ を返す。|


## 参考文献

- https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
- https://github.com/kirika-comp/articles/blob/c16612f266202ec6ce0f462601dd4db110add534/pre-seisuuron.pdf
