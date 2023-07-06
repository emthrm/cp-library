---
title: ランレングス圧縮 (run length encoding)
documentation_of: //include/emthrm/string/run_length_encoding.hpp
---


## 時間計算量

$O(\lvert S \rvert)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T = char, typename U>`<br>`requires requires { typename T::value_type; }`<br>`std::vector<std::pair<typename T::value_type, int>> run_length_encoding(const T& s);`|$S$ のランレングス圧縮|


## Submissons

https://atcoder.jp/contests/abc143/submissions/9291464
