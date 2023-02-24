---
title: segmented sieve
documentation_of: //include/emthrm/math/segmented_sieve.hpp
---


## 時間計算量

$O\left(\sqrt{H}\log{\log{H}} + \frac{(H - L)\sqrt{H}}{\log{H}}\right)$ ?


## 仕様

|名前|戻り値|
|:--|:--|
|`std::vector<bool> segmented_sieve(const long long low, const long long high);`|$i$ ($\mathrm{low} \leq i < \mathrm{high}$) が素数であるか。|


## 参考文献

- http://www.prefield.com/algorithm/math/segment_sieve.html


## TODO

- https://uwitenpen.hatenadiary.org/entries/2011/12/03


## Submissons

https://atcoder.jp/contests/math-and-algorithm/submissions/29613055
