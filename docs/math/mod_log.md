---
title: 離散対数問題 (discrete logarithm problem)
documentation_of: include/emthrm/math/mod_log.hpp
---

$g^x \equiv y \pmod{p}$ ($g = \text{const.},\ y \in \mathbb{Z},\ p \in \mathbb{P}$) を満たす $x$ を求める問題である。


## 時間計算量

$O(\sqrt{P} \log{P})$


## 仕様

### baby-step giant-step

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`mod_log(g, y, m)`|$g^x \equiv y \pmod{m}$ を満たす最小の非負整数 $x$|存在しないときは $-1$ となる。|


## 参考文献

- http://sonickun.hatenablog.com/entry/2016/11/20/192743


## TODO

- Pohlig–Hellman algorithm
  - http://sonickun.hatenablog.com/entry/2016/11/20/192743
  - https://yukicoder.me/problems/no/950
  - https://twitter.com/nuo_chocorusk/status/1205509988912783360
  - https://twitter.com/maspy_stars/status/1205499459993362432


## Submissons

https://judge.yosupo.jp/submission/3457
