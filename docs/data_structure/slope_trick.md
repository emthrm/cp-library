---
title: slope trick
documentation_of: data_structure/slope_trick.hpp
---

各区分の傾きが整数な凸区分線形関数 (convex piecewise linear function) を管理するテクニック


## 時間計算量

区分の数を $N$ とおく．

||時間計算量|
|:--:|:--:|
|最小値の取得|$O(1)$|
|$\mathrm{argmin}_x f(x)$|$O(1)$|
|$f(x)$|$O(N)$|
|定数の加算|$O(1)$|
|$(x - a)^+$ の加算|$O(\log{N})$|
|$(a - x)^+$ の加算|$O(\log{N})$|
|$\lvert x - a \rvert$ の加算|$O(\log{N})$|
|累積 $\min$|amortized $O(1)$|
|逆側累積 $\min$|amortized $O(1)$|
|平行移動|$O(1)$|
|スライド最小値|$O(1)$|


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`inf`|$\infty$||
|`SlopeTrick<T>(min_f = 0, ∞)`|$f(x) = \mathrm{min\_f}$ を管理する．||
|`min()`|$\min_x f(x)$||
|`argmin()`|$\mathrm{argmin}_x f(x)$||
|`f(x)`|$f(x)$|
|`constant_function(c)`|$f(x) \gets f(x) + c$||
|`x_minus_a(a)`|$f(x) \gets f(x) + (x - a)^+$||
|`a_minus_x(a)`|$f(x) \gets f(x) + (a - x)^+$||
|`abs_x_minus_a(a)`|$f(x) \gets f(x) + \lvert x - a \rvert$||
|`cumulative_min()`|$f(x) \gets \min_{y \leq x} f(y)$||
|`rumulative_min()`|$f(x) \gets \min_{y \geq x} f(y)$||
|`translate(a)`|$f(x) \gets f(x - a)$||
|`sliding_window_minimum(a, b)`|$f(x) \gets \min_{y \in \lbrack x - b, x - a \rbrack} f(y)$|$a \leq b$ でなければならない．|


## 参考

- https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
- https://github.com/ei1333/library/blob/6c2f9fa7ff07da182f3832f827c0c84d52e2e8d8/structure/others/slope-trick.cpp


## ToDo

- 一般化
  - https://github.com/ei1333/library/blob/af69da96544930d59e797c12ca977918df5e2a58/structure/others/generalized-slope-trick.cpp


## Verified

https://atcoder.jp/contests/arc123/submissions/24994392
