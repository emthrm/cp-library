# 原始根 (primitive root)

正の整数 $n$ に対して $\mathrm{ord}_n(g) = \varphi(n)$ を満たす $n$ が存在するとき，$g$ の属する法 $n$ の剰余類 $g \bmod n$ である．


### 位数 (multiplicative order)

互いに素な整数 $a$ と正の整数 $n$ に対して $a^k \equiv 1 \pmod{n}$ を満たす最小の正整数 $k$ である．


## 使用法

- 原始根判定

||説明|
|:--:|:--:|
|`is_primitive_root(primitive_root, mod)`|$\mathrm{primitive\_root}$ は $\mathrm{mod}$ を法とする原始根であるか|


## 参考

- https://ja.wikipedia.org/wiki/%E6%8C%87%E6%95%B0_(%E5%88%9D%E7%AD%89%E6%95%B4%E6%95%B0%E8%AB%96)

原始根判定
  - https://lumakernel.github.io/ecasdqina/math/general


## ToDo

- https://37zigen.com/primitive-root/
- 位数
  - https://github.com/beet-aizu/library/blob/e480647072b3a5cb2016e9137c024ccc043a897f/mod/order.cpp


## Verified

- [原始根判定](https://yukicoder.me/submissions/414440)
