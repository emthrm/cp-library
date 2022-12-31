---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/emthrm/math/division.hpp\"\n\n\n\n#include <cassert>\n\
    #include <type_traits>\n\nnamespace emthrm {\n\ntemplate <typename T, typename\
    \ U>\nstd::common_type_t<T, U> floor_div(const T a, const U b)  {\n  assert(b\
    \ != 0);\n  return a / b - ((int{a < 0} ^ int{b < 0}) & int{a % b != 0});\n}\n\
    \ntemplate <typename T, typename U>\nstd::common_type_t<T, U> ceil_div(const T\
    \ a, const U b)  {\n  assert(b != 0);\n  return a / b + int{(a < 0) == (b < 0)\
    \ && a % b != 0};\n}\n\n}  // namespace emthrm\n\n\n"
  code: "#ifndef EMTHRM_MATH_DIVISION_HPP_\n#define EMTHRM_MATH_DIVISION_HPP_\n\n\
    #include <cassert>\n#include <type_traits>\n\nnamespace emthrm {\n\ntemplate <typename\
    \ T, typename U>\nstd::common_type_t<T, U> floor_div(const T a, const U b)  {\n\
    \  assert(b != 0);\n  return a / b - ((int{a < 0} ^ int{b < 0}) & int{a % b !=\
    \ 0});\n}\n\ntemplate <typename T, typename U>\nstd::common_type_t<T, U> ceil_div(const\
    \ T a, const U b)  {\n  assert(b != 0);\n  return a / b + int{(a < 0) == (b <\
    \ 0) && a % b != 0};\n}\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_MATH_DIVISION_HPP_\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/math/division.hpp
  requiredBy: []
  timestamp: '2022-12-31 20:40:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/math/division.hpp
layout: document
title: "\u5207\u308A\u6368\u3066\u9664\u7B97 (floor division)\u30FB\u5207\u308A\u4E0A\
  \u3052\u9664\u7B97"
---


## 使用法

||説明|
|:--:|:--:|
|`floor_div(a, b)`|$\left\lfloor \frac{A}{B} \right\rfloor$|
|`ceil_div(a, b)`|$\left\lceil \frac{A}{B} \right\rceil$|


## 参考

- https://twitter.com/noshi91/status/1439230342850695170
- https://github.com/NyaanNyaan/library/blob/6abcedf4fd779ce0a42a8b50d3cbbfa3ae5aef1a/misc/int_div.hpp
