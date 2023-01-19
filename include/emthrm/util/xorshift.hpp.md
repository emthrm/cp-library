---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/is_primitive_root.test.cpp
    title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/util/xorshift.hpp\"\n\n\n\n#include <ctime>\n\
    \nnamespace emthrm {\n\nstruct Xor128 {\n  Xor128() : x(123456789), y(362436069),\
    \ z(521288629), w(std::time(nullptr)) {}\n  int rand() {\n    unsigned int t =\
    \ x ^ (x << 11);\n    x = y; y = z; z = w;\n    return w = (w ^ (w >> 19)) ^ (t\
    \ ^ (t >> 8));\n  }\n  int rand(const int ub) {\n    const int res = rand() %\
    \ ub;\n    return res < 0 ? res + ub : res;\n  }\n  int rand(const int lb, const\
    \ int ub) { return lb + rand(ub - lb); }\n  long long randll() {\n    return (static_cast<unsigned\
    \ long long>(rand()) << 32) | rand();\n  }\n  long long randll(const long long\
    \ ub) {\n    const long long res = randll() % ub;\n    return res < 0 ? res +\
    \ ub : res;\n  }\n  long long randll(const long long lb, const long long ub) {\n\
    \    return lb + randll(ub - lb);\n  }\n private:\n  unsigned int x, y, z, w;\n\
    } xor128;\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_UTIL_XORSHIFT_HPP_\n#define EMTHRM_UTIL_XORSHIFT_HPP_\n\n\
    #include <ctime>\n\nnamespace emthrm {\n\nstruct Xor128 {\n  Xor128() : x(123456789),\
    \ y(362436069), z(521288629), w(std::time(nullptr)) {}\n  int rand() {\n    unsigned\
    \ int t = x ^ (x << 11);\n    x = y; y = z; z = w;\n    return w = (w ^ (w >>\
    \ 19)) ^ (t ^ (t >> 8));\n  }\n  int rand(const int ub) {\n    const int res =\
    \ rand() % ub;\n    return res < 0 ? res + ub : res;\n  }\n  int rand(const int\
    \ lb, const int ub) { return lb + rand(ub - lb); }\n  long long randll() {\n \
    \   return (static_cast<unsigned long long>(rand()) << 32) | rand();\n  }\n  long\
    \ long randll(const long long ub) {\n    const long long res = randll() % ub;\n\
    \    return res < 0 ? res + ub : res;\n  }\n  long long randll(const long long\
    \ lb, const long long ub) {\n    return lb + randll(ub - lb);\n  }\n private:\n\
    \  unsigned int x, y, z, w;\n} xor128;\n\n}  // namespace emthrm\n\n#endif  //\
    \ EMTHRM_UTIL_XORSHIFT_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/util/xorshift.hpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/is_primitive_root.test.cpp
documentation_of: include/emthrm/util/xorshift.hpp
layout: document
title: xorshift
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
