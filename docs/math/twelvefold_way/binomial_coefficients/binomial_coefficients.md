# 二項係数 (binomial coefficients)

$$\binom{n}{k} = \binom{n - 1}{r - 1} + \binom{n - 1}{r} = \frac{n!}{k!\,(n - k)!} \text{．}$$


## 時間計算量

||時間計算量|
|:--:|:--:|
|パスカルの三角形|$O(N^2)$|
|二項係数|$\langle O(N + \log{M}), O(1) \rangle$|
|n は巨大|$O(K)$|
|n は巨大な固定値|$O(K)$|


## 使用法

- パスカルの三角形

||説明|
|:--:|:--:|
|`pascal<T>(n)`|$n$ 段のパスカルの三角形|

- 二項係数

||説明|備考|
|:--:|:--:|:--:|
|`BinomialCoefficients(mod, val = 10000000)`|二項係数を考える|$a! \perp \mathrm{mod}$ (e.g. $0 \leq a < \mathrm{mod}$ を満たす素数)|
|`fact[i]`|$i!$|
|`fact_inv[i]`|$\frac{1}{i!}$|
|`query(n, k)`|$\binom{n}{k}$|

- $n$ は巨大

||説明|
|:--:|:--:|
|`binom_large_n<T>(n, k)`|$\binom{n}{k}$|

- $n$ は巨大な固定値

||説明|
|:--:|:--:|
|`binom_large_n_init<T>(n, k)`|$\binom{n}{r} \ (0 \leq r \leq k)$ の数表|


## 参考

http://drken1215.hatenablog.com/entry/2018/06/08/210000


## ToDo

https://w.atwiki.jp/uwicoder/pages/2118.html


## Verified

- [パスカルの三角形](https://atcoder.jp/contests/cpsco2019-s3/submissions/9335288)
- [二項係数](https://yukicoder.me/submissions/414639)
- [$n$ は巨大](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/4092983/emthrm/C++14)
- [$n$ は巨大な固定値](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3071/review/4093004/emthrm/C++14)
