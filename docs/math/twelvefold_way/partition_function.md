# 分割数 (partition function)

$n$ を $m$ 個以下に分割する方法の総数の内, $n = m$ を満たすもの．

$m$ 個の区別はないため $(4, 1, 1)$ と $(1, 4, 1)$ は同じ分け方となる．

母関数は

$$P(x) = \prod_{n = 1}^{\infty} \dfrac{1}{1 - x^n}$$

である．


## 時間計算量

||時間計算量|
|:--:|:--:|
||$O(NM)$|
|$n = m$ 版|$O(N\log{N})$|


## 使用法

||説明|
|:--:|:--:|
|`partition_function_init<T>(group, sum)`|分割数の数表|

- $n = m$ 版

||説明|
|:--:|:--:|
|`partition_function_init_with_fps<T>(n)`|$n = m$ のときの分割数の数表|


## 参考

- プログラミングコンテストチャレンジブック \[第2版\] pp.66-67
- https://ja.wikipedia.org/wiki/%E5%88%86%E5%89%B2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E3%81%AE%E4%BA%94%E8%A7%92%E6%95%B0%E5%AE%9A%E7%90%86


## ToDo

- $n = m$ の場合のみを $O(N\sqrt{N})$ で求める．
  - http://degwer.hatenablog.com/entries/2017/08/29
  - https://qiita.com/drken/items/f2ea4b58b0d21621bd51
  - https://judge.yosupo.jp/problem/partition_function


## Verified

- https://atcoder.jp/contests/dwacon2018-prelims/submissions/9309239
- [$n = m$ 版](https://judge.yosupo.jp/submission/3791)
