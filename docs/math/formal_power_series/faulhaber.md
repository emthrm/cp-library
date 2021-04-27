# ファウルハーバーの公式 (Faulhaber's formula)

$$S_k(n) = \sum_{i = 1}^{n - 1} i^k$$

と定義すると

$$S_k(n + 1) = \dfrac{1}{k + 1} \sum_{i = 0}^k \binom{k + 1}{i} B_i n^{k + 1 - i}$$

である．ここで $B$ は[ベルヌーイ数](bernoulli_number)である．


## 時間計算量

||時間計算量|
|:--:|:--:|
|形式的冪級数版|$O(K\log{K})$|
|ラグランジュ補間版|$O(K \log{\max(K, M)})$|


## 使用法

- 形式的冪級数版

||説明|
|:--:|:--:|
|`faulhaber_by_fps<T>(n, k)`|$S_k(n)$|

- ラグランジュ補間版

||説明|
|:--:|:--:|
|`faulhaber_by_lagrange_interpolation<T>(n, k)`|$S_k(n)$|


## 参考

- https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A1%E3%82%A6%E3%83%AB%E3%83%8F%E3%83%BC%E3%83%90%E3%83%BC%E3%81%AE%E5%85%AC%E5%BC%8F


## Verified

- [形式的冪級数版](https://yukicoder.me/submissions/431468)
- [ラグランジュ補間版](https://yukicoder.me/submissions/437458)
