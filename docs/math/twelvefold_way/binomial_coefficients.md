---
title: [
  パスカルの三角形 (Pascal's triangle),
  二項係数 (binomial coefficients) の数表 巨大な $n$ 版
]
documentation_of: [
  //include/emthrm/math/twelvefold_way/pascal.hpp,
  //include/emthrm/math/twelvefold_way/large_nCk_init.hpp
]
---

# 二項係数 (binomial coefficients)

$$
  \binom{n}{k} = \binom{n - 1}{r - 1} + \binom{n - 1}{r} = \frac{n!}{k!\,(n - k)!}
$$


## 時間計算量

||時間計算量|
|:--|:--|
|パスカルの三角形|$O(N^2)$|
|二項係数|$\langle O(N + \log{M}), O(1) \rangle$|
|二項係数 巨大な $n$ 版|$O(K + \log{M})$|
|二項係数の数表 巨大な $n$ 版|$O(K)$|


## 仕様

### パスカルの三角形

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> pascal(const int n);`|$n$ 段のパスカルの三角形|


### [二項係数](../../../include/emthrm/math/modint.hpp)


### [二項係数 巨大な $n$ 版](../../../include/emthrm/math/modint.hpp)


### 二項係数の数表 巨大な $n$ 版

|名前|戻り値|
|:--|:--|
|`template <unsigned int T>`<br>`std::vector<MInt<T>> large_nCk_init(long long n, const int k);`|$\binom{n}{r}$ ($0 \leq r \leq k$) の数表|


## 参考文献

http://drken1215.hatenablog.com/entry/2018/06/08/210000

パスカルの三角形
- Blaise Pascal: Traité du triangle arithmétique , avec quelques autres petits traitez sur la mesme matière (1665).


## TODO

- https://w.atwiki.jp/uwicoder/pages/2118.html
- https://ferin-tech.hatenablog.com/entry/2018/01/17/010829
- https://qiita.com/Kiri8128/items/dfdadf85ba2ea14026b6
- https://judge.yosupo.jp/problem/binomial_coefficient
- $\sum_{i = 0}^M \binom{N}{i}$
  - https://nyaannyaan.github.io/library/modulo/multipoint-binomial-sum.hpp.html
  - https://twitter.com/noshi91/status/1349778791262945280
  - https://atcoder.jp/contests/abc235/tasks/abc235_g
  - https://yukicoder.me/problems/no/2206


## Submissons

- [パスカルの三角形](https://atcoder.jp/contests/abc254/submissions/32252670)
- [二項係数](https://yukicoder.me/submissions/625071)
- [二項係数 巨大な $n$ 版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/5265683/emthrm/C++17)
- [二項係数の数表 巨大な $n$ 版](https://yukicoder.me/submissions/820076)
