---
title: xorshift
documentation_of: include/emthrm/util/xorshift.hpp
---

疑似乱数列生成法の一種である。


## 仕様

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`xor128.rand()`|`int` 型の乱数||
|`xor128.rand(ub)`|`int` 型の乱数|$[0, \mathrm{ub})$|
|`xor128.rand(lb, ub)`|`int` 型の乱数|$[\mathrm{lb}, \mathrm{ub})$|
|`xor128.randll()`|`long long` 型の乱数||
|`xor128.randll(ub)`|`long long` 型の乱数|$[0, \mathrm{ub})$|
|`xor128.randll(lb, ub)`|`long long` 型の乱数|$[\mathrm{lb}, \mathrm{ub})$|

周期は $2^{128} - 1$ である。


## 備考

[Zobrist hashing](https://en.wikipedia.org/wiki/Zobrist_hashing) に用いるのは危険である。


## 参考文献

- https://ja.wikipedia.org/wiki/Xorshift
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!XorShift128.cpp~~
- https://nodchip.hatenadiary.org/entry/20090111/1231667839

#### 備考
- https://twitter.com/noshi91/status/1515709212122390537
