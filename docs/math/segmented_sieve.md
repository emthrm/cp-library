---
title: 区間篩 (segmented sieve)
documentation_of: math/segmented_sieve.hpp
---

区間 $[L, H)$ における素数を列挙するアルゴリズムである．


## 時間計算量

$O(\sqrt{H}\log{\log{\sqrt{H}}} + \frac{(H - L)\sqrt{H}}{\log{H}})$ ?


## 使用法

||説明|
|:--:|:--:|
|`segmented_sieve(low, high)`|$i \ (\mathrm{low} \leq i < \mathrm{high})$ が素数であるか．|


## 参考

- http://www.prefield.com/algorithm/math/segment_sieve.html


## ToDo

- https://uwitenpen.hatenadiary.org/entries/2011/12/03


## Verified

