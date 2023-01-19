---
title: xorshift
documentation_of: include/emthrm/util/xorshift.hpp
---

疑似乱数列生成法の一種である。


## 仕様

```cpp
struct Xor128;
```

周期は $2^{128} - 1$ である。

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`int rand();`|`int` 型の乱数||
|`int rand(const int ub);`|`int` 型の乱数|$[0, \mathrm{ub})$|
|`int rand(const int lb, const int ub);`|`int` 型の乱数|$[\mathrm{lb}, \mathrm{ub})$|
|`long long randll();`|`long long` 型の乱数||
|`long long randll(const long long ub);`|`long long` 型の乱数|$[0, \mathrm{ub})$|
|`long long randll(const long long lb, const long long ub);`|`long long` 型の乱数|$[\mathrm{lb}, \mathrm{ub})$|


## 備考

[Zobrist hashing](https://en.wikipedia.org/wiki/Zobrist_hashing) に用いるのは危険である。


## 参考文献

- https://ja.wikipedia.org/wiki/Xorshift
- ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!XorShift128.cpp~~
- https://nodchip.hatenadiary.org/entry/20090111/1231667839

備考
- https://twitter.com/noshi91/status/1515709212122390537
