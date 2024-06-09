---
title: ワイルドカード ? を用いたパターンマッチング
documentation_of: //include/emthrm/string/wildcard_pattern_matching.hpp
---


## 時間計算量

テキスト長を $N$、パターン長を $M$ とおくと $O((N + M)\log(N + M))$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T = std::string>`<br>`requires requires { typename T::value_type; }`<br>`std::vector<int> wildcard_pattern_matching(const T& t, const T& p, const typename T::value_type wildcard);`|`T[i:i+len(P)] = P` を満たすすべての $i$|


## 参考文献

- https://qiita.com/MatsuTaku/items/cd5581fab97d7e74a7b3
- https://atcoder.jp/contests/abc307/editorial/6598


## TODO

- 高速化
  - https://noshi91.hatenablog.com/entry/2024/05/26/060854


## Submissons

https://judge.yosupo.jp/submission/209950
