---
title: 多項式 (polynomial)
documentation_of: include/emthrm/math/polynomial.hpp
---


## 時間計算量

||時間計算量|
|:--:|:--:|
|加減算|$O(N)$|
|スカラー倍|$O(N)$|
|乗算|$O(N\log{N})$|
|除算|$O(N^2)$|
|剰余演算|$O(N^2)$|
|ホーナー法 (Horner's rule)|$O(N)$|
|形式微分|$O(N)$|
|累乗||
|`translate(c)`|$O(N\log{N})$|


## 使用法

||説明|条件|
|:--:|:--:|:--:|
|`Polynomial<T>(deg = 0)`|次数 $\mathrm{deg}$ の多項式||
|`Polynomial<T>(coef)`|係数列を $\mathrm{coef}$ とする多項式||
|`coef`|係数列||
|`operator()[term]`|${\lbrack x^{\mathrm{term}} \rbrack}f$||
|`set_mul(mul)`|乗算を定義する．||
|`resize(deg)`|$\mathrm{deg}$ 次までを考える．|||
|`shrink()`|正規化を行う．||
|`degree()`|次数||
|`operator=(coef_)`|係数列 $\mathrm{coef\_}$ を代入する．||
|`operator=(x)`|多項式 $x$ を代入する．||
|`operator+=(x)`<br>`operator+(x)`|加算||
|`operator-=(x)`<br>`operator-(x)`|減算||
|`operator*=(x)`<br>`operator*(x)`|乗算||
|`divide(x)`|$x$ で割った商とあまり||
|`operator/=(x)`<br>`operator/(x)`|除算||
|`operator%=(x)`<br>`operator%(x)`|剰余演算||
|`operator<<=(n)`<br>`operator<<(n)`|$x^n f$||
|`operator==(x)`|$f = x$ であるか．||
|`operator!=(x)`|$f \neq x$ であるか．||
|`operator+()`|$+{f}$||
|`operator-()`|$-{f}$||
|`horner(x)`|$f(x)$||
|`differential()`|$f^{\prime}$|$\mathrm{deg}(f) \geq 0$|
|`pow(exponent)`|$f^{\mathrm{exponent}}$||
|`translate(c)`|$f(x + c)$||


## 参考

- https://github.com/beet-aizu/library/blob/29e15f77befa18d06b1f61221c509b5a58f4cb4c/polynomial/polynomial.cpp
- https://github.com/primenumber/ProconLib/blob/dc175741e461e88f69350532b47fa57527b38fa3/Math/Polynomial.cpp


## ToDo

- http://www.math.kobe-u.ac.jp/Asir/ca.pdf
- 除算の高速化
  - https://github.com/spaghetti-source/algorithm/blob/master/math/polynomial_int.cc
  - http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
  - https://judge.yosupo.jp/problem/division_of_polynomials
- DKA 法 (Durand–Kerner–Aberth method)
  - https://drive.google.com/file/d/1Fb5TPXzEQVKzYDwhNN2XZpWZWa49aCIY
- Bairstow's method
  - https://en.wikipedia.org/wiki/Bairstow%27s_method
- 微積分
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/pepsin-amylase/20141208/
