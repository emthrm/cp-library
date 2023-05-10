---
title: 離散対数問題 (discrete logarithm problem)
documentation_of: //include/emthrm/math/mod_log.hpp
---

$g^x \equiv y \pmod{p}$ ($g = \text{const.},\ y \in \mathbb{Z},\ p \in \mathbb{P}$) を満たす $x$ を求める問題である。


## 時間計算量

$O(\sqrt{P} \log{P})$


## 仕様

### baby-step giant-step

|名前|戻り値|
|:--|:--|
|`int mod_log(long long g, long long y, const int m);`|$g^x \equiv y \pmod{m}$ を満たす最小の非負整数 $x$。ただし存在しないときは $-1$ を返す。|


## 参考文献

- http://sonickun.hatenablog.com/entry/2016/11/20/192743


## TODO

- 一般化
  - https://maspypy.com/%e3%83%a2%e3%83%8e%e3%82%a4%e3%83%89%e4%bd%9c%e7%94%a8%e3%81%ab%e9%96%a2%e3%81%99%e3%82%8b%e9%9b%a2%e6%95%a3%e5%af%be%e6%95%b0%e5%95%8f%e9%a1%8c
  - https://twitter.com/kotatsugame_t/status/1640549382658605056
- Pohlig–Hellman algorithm
  - http://sonickun.hatenablog.com/entry/2016/11/20/192743
  - https://yukicoder.me/problems/no/950
  - https://twitter.com/nuo_chocorusk/status/1205509988912783360
  - https://twitter.com/maspy_stars/status/1205499459993362432


## Submissons

https://judge.yosupo.jp/submission/3457
