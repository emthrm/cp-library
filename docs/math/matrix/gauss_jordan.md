---
title: ガウス・ジョルダンの消去法 (Gauss–Jordan elimination)
documentation_of: include/emthrm/math/matrix/gauss_jordan.hpp
---

行基本変形を用いて行列を行階段形に変形するアルゴリズムである．


## 時間計算量

$O(M^2 N)$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`gauss_jordan(&a, ε = 1e-8, 拡大係数行列か? = false)`|行列 $A$ のランク|$A$ は行階段形に変形される．<br>要素の型は実数型または `ModInt` である．|


## 参考

- http://drken1215.hatenablog.com/entry/2019/03/20/202800


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0004/review/4088546/emthrm/C++14
