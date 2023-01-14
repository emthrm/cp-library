---
title: ガウス・ジョルダンの消去法 (Gauss–Jordan elimination)
documentation_of: include/emthrm/math/matrix/gauss_jordan.hpp
---

行基本変形を用いて行列を行階段形に変形するアルゴリズムである。


## 時間計算量

$O(M^2 N)$


## 仕様

|名前|効果・戻り値|要件|備考|
|:--|:--|:--|:--|
|`gauss_jordan(&a, ε = 1e-8, 拡大係数行列か? = false)`|行列 $A$ のランク|要素の型は実数型または `ModInt` である。|$A$ は行階段形に変形される。|


## 参考文献

- http://drken1215.hatenablog.com/entry/2019/03/20/202800


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/0004/review/4088546/emthrm/C++14
