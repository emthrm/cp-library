# ラグランジュ補間 (Lagrange interpolation)

$x_i \neq x_j \ (1 \leq i < j \leq N)$ を満たす $(x_i, y_i)$ について $f(x_i) = y_i$ を満たす $N - 1$ 次以下の多項式 $f$ を求める．


### ラグランジュの補間多項式 (interpolation polynomial in the Lagrange form)

$$f(x) = \sum_{i = 1}^N f(x_i) \prod_{j \neq i} \dfrac{x - x_j}{x_i - x_j} = \sum_{i = 1}^N \dfrac{f(x_i)}{g^{\prime}(x_i)} \prod_{j \neq i} (x - x_j) \text{ where } g(x) = \prod_{i = 1}^N (x - x_i). \\ \left( \because g^{\prime}(x) = \sum_{i = 1}^N \prod_{j \neq i} (x - x_j) \text{ より } g^{\prime}(x_i) = \prod_{j \neq i} (x - x_j)\text{．}\right)$$


## 時間計算量

||時間計算量|
|:--:|:--:|
|評価版|$O(N^2)$|
|評価版2|$O(N)$|
|多項式補間|$O(N(\log{N})^2)$|


## 使用法

- 評価版

||説明|備考|
|:--:|:--:|:--:|
|`lagrange_interpolation(x, y, t)`|$f(t) \text{ s.t. } f(x_i) = y_i$|$x$ は互いに異なる．|

- 評価版2

||説明|備考|
|:--:|:--:|:--:|
|`lagrange_interpolation(y, t)`|$f(t) \text{ s.t. } f(i) = y_i$|$t < 0,\ N \leq t$|

- 多項式補間

||説明|
|:--:|:--:|
|`polynomial_interpolation<多項式>(x, y)`|$f \text{ s.t. } f(x_i) = y_i$|


## 参考

- ラグランジュ補間
  - https://mathtrain.jp/hokan
  - https://tubo28.me/compprog/algorithm/lagrange_interpolation/
- スプライン補間 (spline interpolation)
  - https://en.wikipedia.org/wiki/Spline_interpolation
  - https://docs.google.com/presentation/d/1n-RR-AjQN8oq0DkDKBFi9Ccg53HsDUHKtOsC8z7S-To
- 多項式補間
  - https://github.com/ei1333/library/blob/master/math/fps/polynomial-interpolation.cpp


## ToDo

- ニュートン補間 (Newtonian interpolation)
  - https://ja.wikipedia.org/wiki/%E3%83%8B%E3%83%A5%E3%83%BC%E3%83%88%E3%83%B3%E8%A3%9C%E9%96%93
  - https://twitter.com/noshi91/status/1160191749416898560


## Verified

- [評価版](https://atcoder.jp/contests/arc033/submissions/10088080)
- [評価版2](https://atcoder.jp/contests/arc033/submissions/10510969)
- [多項式補間](https://judge.yosupo.jp/submission/3794)
