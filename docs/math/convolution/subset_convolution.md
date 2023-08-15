---
title: subset convolution
documentation_of: //include/emthrm/math/convolution/subset_convolution.hpp
---

環 $K$ を終域とする関数 $f, g \colon 2^{\lbrack n \rbrack} \to K$ が与えられるとする。$S \subseteq \lbrack n \rbrack$ すべてに対して
$$
  (f \ast g)(S) \mathrel{:=} \sum_{T \subseteq S} f(T) g(S \setminus T)
$$
を高速に求めるアルゴリズムである。


## 時間計算量

$O(2^N N^2)$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`template <int MaxN, typename T>`<br>`std::vector<T> subset_convolution(const std::vector<T>& f, const std::vector<T>& g);`|$f \ast g$|$n \leq \mathrm{MaxN}$|


## 参考文献

- Andreas Björklund, Thore Husfeldt, Petteri Kaski, and Mikko Koivisto: Fourier meets möbius: fast subset convolution, *STOC '07: Proceedings of the thirty-ninth annual ACM symposium on Theory of computing*, pp. 67–74 (2007). https://doi.org/10.1145/1250790.1250801
- https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-1-%e9%83%a8%e5%88%86%e9%9b%86%e5%90%88%e7%95%b3%e3%81%bf%e8%be%bc%e3%81%bf
- https://www.slideshare.net/wata_orz/ss-12131479
- https://hos-lyric.hatenablog.com/entry/2021/01/14/201231
- https://37zigen.com/subset-convolution/
- https://nyaannyaan.github.io/library/set-function/subset-convolution.hpp.html


## Submissons

https://judge.yosupo.jp/submission/155785
