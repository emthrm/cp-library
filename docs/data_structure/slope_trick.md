---
title: slope trick
documentation_of: include/emthrm/data_structure/slope_trick.hpp
---

各区分の傾きが整数な凸区分線形関数 (convex piecewise linear function) を管理するテクニック


## 時間計算量

区分の数を $N$ とおく。

||時間計算量|
|:--|:--|
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


## 仕様

```cpp
template <typename T>
struct SegmentTree;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`const T inf`|$\infty$|

#### メンバ関数

|名前|効果・戻り値|要件|
|:--|:--|:--|
|`explicit SlopeTrick(const T min_f = 0, const T inf = std::numeric_limits<T>::max());`|$f(x) = \mathrm{min\_f}$ を管理する。||
|`T min() const;`|$\min_x f(x)$||
|`std::pair<T, T> argmin() const;`|$\mathrm{argmin}_x f(x)$||
|`template <typename U> U f(const U x);`|$f(x)$|
|`void constant_function(const T c);`|$f(x) \gets f(x) + c$||
|`void x_minus_a(const T a);`|$f(x) \gets f(x) + (x - a)^+$||
|`void a_minus_x(const T a);`|$f(x) \gets f(x) + (a - x)^+$||
|`void abs_x_minus_a(const T a);`|$f(x) \gets f(x) + \lvert x - a \rvert$||
|`void cumulative_min();`|$f(x) \gets \min \lbrace f(y) \mid y \leq x \rbrace$||
|`void rcumulative_min();`|$f(x) \gets \min \lbrace f(y) \mid y \geq x \rbrace$||
|`void translate(const T a);`|$f(x) \gets f(x - a)$||
|`void sliding_window_minimum(const T a, const T b);`|$f(x) \gets \min \lbrace f(y) \mid y \in \lbrack x - b, x - a \rbrack \rbrace$|$a \leq b$|


## 参考文献

- https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8
- https://github.com/ei1333/library/blob/6c2f9fa7ff07da182f3832f827c0c84d52e2e8d8/structure/others/slope-trick.cpp


## TODO

- 一般化
  - https://github.com/ei1333/library/blob/af69da96544930d59e797c12ca977918df5e2a58/structure/others/generalized-slope-trick.cpp


## Submissons

https://atcoder.jp/contests/arc123/submissions/24994392
