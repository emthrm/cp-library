---
title: xorshift
documentation_of: util/xorshift.hpp
---

疑似乱数列生成法の一種である．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`xor128.rand()`|`int` 型の乱数||
|`xor128.rand(ub)`|`int` 型の乱数|$[0, \mathrm{ub})$|
|`xor128.rand(lb, ub)`|`int` 型の乱数|$[\mathrm{lb}, \mathrm{ub})$|
|`xor128.randll()`|`long long` 型の乱数||
|`xor128.randll(ub)`|`long long` 型の乱数|$[0, \mathrm{ub})$|
|`xor128.randll(lb, ub)`|`long long` 型の乱数|$[\mathrm{lb}, \mathrm{ub})$|

周期は $2^{128} - 1$ である．


## 参考

- https://ja.wikipedia.org/wiki/Xorshift
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!XorShift128.cpp~~
- https://nodchip.hatenadiary.org/entry/20090111/1231667839
