---
title: 一元二次方程式 (quadratic equation)
documentation_of: //include/emthrm/math/quadratic_equation.hpp
---

$$
  ax^2 + bx + c = 0
$$


## 時間計算量

$O(1)$


## 仕様

|名前|戻り値|要件|
|:--|:--|:--|
|`std::vector<double> quadratic_equation(double a, double b, double c, const double eps = 1e-8);`|$ax^2 + bx + c = 0$ を満たす $x$|$a, b, c$ のいずれかは非零である。|


## 参考文献

- https://yukicoder.me/problems/no/955/editorial


## TODO

- 三次方程式 (cubic equation)
  - https://ja.wikipedia.org/wiki/%E4%B8%89%E6%AC%A1%E6%96%B9%E7%A8%8B%E5%BC%8F
  - https://tubo28.me/compprog/algorithm/cubic/
  - https://cafecoder.top/contests/test003/tasks/test003_b


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/1039/review/4338571/emthrm/C++14
