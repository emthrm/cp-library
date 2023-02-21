---
title: 多項式 (polynomial)
documentation_of: include/emthrm/math/polynomial.hpp
---


## 時間計算量

||時間計算量|
|:--|:--|
|加減算|$O(N)$|
|スカラー倍|$O(N)$|
|乗算|$O(N\log{N})$|
|除算|$O(N^2)$|
|剰余演算|$O(N^2)$|
|ホーナー法 (Horner's rule)|$O(N)$|
|形式微分|$O(N)$|
|累乗||
|`translate`|$O(N\log{N})$|


## 仕様

```cpp
template <typename T>
struct Polynomial;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<T> coef`|係数列|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit Polynomial(const int deg = 0);`|$\mathrm{deg}$ 次まで係数列をもつオブジェクトを構築する。|
|`explicit Polynomial(const std::vector<T>& coef);`|係数列を $\mathrm{coef}$ とするオブジェクトを構築する。|
|`Polynomial(const std::initializer_list<T> init);`|初期化子リストを受け取るコンストラクタ|
|`template <typename InputIter>`<br>`explicit Polynomial(const InputIter first, const InputIter last);`|イテレータ範囲コンストラクタ|
|`inline const T& operator[](const int term) const;`<br>`inline T& operator[](const int term);`|${\lbrack x^{\mathrm{term}} \rbrack}f$|
|`void resize(const int deg);`|$\mathrm{deg}$ 次まで係数列をもつ。|
|`void shrink();`|正規化を行う。|
|`int degree() const;`|現在の次数|
|`Polynomial& operator=(const std::vector<T>& coef_);`<br>`Polynomial& operator=(const Polynomial& x);`|代入演算子|
|`Polynomial& operator+=(const Polynomial& x);`<br>`Polynomial operator+(const Polynomial& x) const;`|加算|
|`Polynomial& operator-=(const Polynomial& x);`<br>`Polynomial operator-(const Polynomial& x) const;`|減算|
|`Polynomial& operator*=(const T x);`<br>`Polynomial& operator*=(const Polynomial& x);`<br>`Polynomial operator*(const T x) const;`<br>`Polynomial operator*(const Polynomial& x) const;`|乗算|
|`Polynomial& operator/=(const T x);`<br>`Polynomial& operator/=(const Polynomial& x);`<br>`Polynomial operator/(const T x) const;`<br>`Polynomial operator/(const Polynomial& x) const;`|除算|
|`Polynomial& operator%=(const Polynomial& x);`<br>`Polynomial operator%(const Polynomial& x) const;`|剰余演算|
|`std::pair<Polynomial, Polynomial> divide(Polynomial x) const;`|$x$ で割った商とあまり|
|`Polynomial& operator<<=(const int n);`<br>`FormalPowerSeries operator<<(const int n) const;`|$x^n f$|
|`bool operator==(Polynomial x) const;`<br>`bool operator!=(const Polynomial& x) const;`|比較演算子|
|`Polynomial operator+() const;`|$+{f}$|
|`Polynomial operator-() const;`|$-{f}$|
|`T horner(const T x) const;`|$f(x)$|
|`Polynomial differential() const;`|$f^{\prime}$|
|`Polynomial pow(int exponent) const;`|$f^{\mathrm{exponent}}$|
|`Polynomial translate(const T c) const;`|$f(x + c)$|

#### 静的メンバ関数

|名前|効果|
|:--|:--|
|`static void set_mult(const Mult mult);`|乗算を定義する。|

#### メンバ型

|名前|説明|
|:--|:--|
|`Mult`|`std::function<std::vector<T>(const std::vector<T>&, const std::vector<T>&)>`|


## 参考文献

- https://github.com/beet-aizu/library/blob/29e15f77befa18d06b1f61221c509b5a58f4cb4c/polynomial/polynomial.cpp
- https://github.com/primenumber/ProconLib/blob/dc175741e461e88f69350532b47fa57527b38fa3/Math/Polynomial.cpp


## TODO

- http://www.math.kobe-u.ac.jp/Asir/ca.pdf
- 除算の高速化
  - https://github.com/spaghetti-source/algorithm/blob/master/math/polynomial_int.cc
  - http://people.csail.mit.edu/madhu/ST12/scribe/lect06.pdf
  - https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae#toc10
  - https://judge.yosupo.jp/problem/division_of_polynomials
- DKA 法 (Durand–Kerner–Aberth method)
  - https://drive.google.com/file/d/1Fb5TPXzEQVKzYDwhNN2XZpWZWa49aCIY
- Bairstow's method
  - https://en.wikipedia.org/wiki/Bairstow%27s_method
- 微積分
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/pepsin-amylase/20141208/
