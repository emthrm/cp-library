---
title: 行列式 (determinant)
documentation_of: //include/emthrm/math/matrix/determinant.hpp
---


## 時間計算量

$O(N^3)$


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T, typename U>`<br>`U det(const Matrix<T>& a, const U eps);`|$\lvert A \rvert$|


## 参考文献

- https://github.com/beet-aizu/library/blob/ebcad58b8480962339b18e316b826e56752b90c8/matrix/matrix.cpp


## TODO

- 固有多項式 (characteristic polynomial)
  - https://ja.wikipedia.org/wiki/%E5%9B%BA%E6%9C%89%E5%A4%9A%E9%A0%85%E5%BC%8F
  - https://github.com/yosupo06/library-checker-problems/issues/665
  - https://judge.yosupo.jp/problem/characteristic_polynomial
  - 問題例 "[DETERMINATION](https://yukicoder.me/problems/no/1907)"
  - 問題例 "[Inversion of Tree](https://atcoder.jp/contests/abc323/tasks/abc323_g)"
- 任意の法の下での行列式
  - https://judge.yosupo.jp/problem/matrix_det_arbitrary_mod
  - https://github.com/yosupo06/library-checker-problems/issues/750
- 巡回行列 (circulant matrix) の行列式
  - https://ja.wikipedia.org/wiki/%E5%B7%A1%E5%9B%9E%E8%A1%8C%E5%88%97
  - https://mathlandscape.com/circulant-matrix/
  - 問題例「第59回TechFUL Coding Battle『Techちゃんと魔法の宝石』」
    - https://kotatsugame.hatenablog.com/entry/2023/06/26/235357


## Submissons

https://judge.yosupo.jp/submission/2714
