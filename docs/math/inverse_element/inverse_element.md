# 逆元 (inverse element)

$ax \equiv 1 \pmod{m}$ を満たす $x = a^{-1}$．


## 時間計算量

||時間計算量|
|:--:|:--:|
|拡張 Euclid の互除法版|$O(\log{M})$|
|拡張 Euclid の互除法版2|$O(\log{M})$|
|Fermat の小定理版|$O(\log{M})$|
|オイラーの定理版|$O(\sqrt{M})$|
|数表|$O(N)$|


## 使用法

- 拡張 Euclid の互除法版

||説明|備考|
|:--:|:--:|:--:|
|`mod_inv_extgcd(a, mod)`|$a$ の逆元|存在しない場合は $-1$ となる．|

- 拡張 Euclid の互除法版2

||説明|備考|
|:--:|:--:|:--:|
|`mod_inv_extgcd2(a, mod)`|$a$ の逆元|存在しない場合は $-1$ となる．|

- Fermat の小定理版

||説明|備考|
|:--:|:--:|:--:|
|`mod_inv_fermat(a, mod)`|$a$ の逆元|$\mathrm{mod}$ は素数でなければならない．|

- オイラーの定理版

||説明|
|:--:|:--:|
|`mod_inv_phi(a, mod)`|$a$ の逆元|

- 数表

||説明|備考|
|:--:|:--:|:--:|
|`inv_init(n, mod)`|$n$ 以下の逆元の数表|$n! \perp \mathrm{mod}$ (e.g. $0 \leq n < \mathrm{mod}$ を満たす素数)|


## 参考

- https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
- https://github.com/kirika-comp/articles/blob/pre-releases/pre-seisuuron.pdf

数表
- http://drken1215.hatenablog.com/entry/2018/06/08/210000


## Verified

- 拡張 Euclid の互除法版
- 拡張 Euclid の互除法版2
- Fermat の小定理版
- オイラーの定理版
- [数表](https://atcoder.jp/contests/dwacon2017-honsen/submissions/9318092)
