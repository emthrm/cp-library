---
title: 切り捨て除算 (floor division)・切り上げ除算
documentation_of: //include/emthrm/math/division.hpp
---


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T, typename U>`<br>`std::common_type_t<T, U> floor_div(const T a, const U b);`|$\left\lfloor \frac{A}{B} \right\rfloor$|
|`template <typename T, typename U>`<br>`std::common_type_t<T, U> ceil_div(const T a, const U b);`|$\left\lceil \frac{A}{B} \right\rceil$|


## 参考文献

- https://twitter.com/noshi91/status/1439230342850695170
- https://github.com/NyaanNyaan/library/blob/6abcedf4fd779ce0a42a8b50d3cbbfa3ae5aef1a/misc/int_div.hpp
