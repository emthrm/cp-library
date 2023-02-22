# 分割数 (partition function)

自然数 $n$ を $m$ 個以下の正の整数の和で表す方法の総数の内、$n = m$ を満たすもの。

和の順序は問わず、$2 + 1 + 1$ と $1 + 2 + 1$ を区別しない。

分割数 $p(n)$ の母関数は

$$
  \sum_{n = 0}^\infty p(n) x^n = \prod_{n = 1}^{\infty} \dfrac{1}{1 - x^n}
$$

である。


## 時間計算量

||時間計算量|
|:--|:--|
||$O(NM)$|
|$n = m$ 版|$O(N\log{N})$|


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<std::vector<T>> partition_function(const int n, const int m);`|分割数の数表|


### $n = m$ 版

|名前|戻り値|
|:--|:--|
|`template <typename T>`<br>`std::vector<T> partition_function_by_fps(const int n);`|$n = m$ のときの分割数の数表|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.66-67，マイナビ出版（2012）
- https://ja.wikipedia.org/wiki/%E5%88%86%E5%89%B2%E6%95%B0
- https://ja.wikipedia.org/wiki/%E3%82%AA%E3%82%A4%E3%83%A9%E3%83%BC%E3%81%AE%E4%BA%94%E8%A7%92%E6%95%B0%E5%AE%9A%E7%90%86


## TODO

- オイラーの五角数定理 (Euler's pentagonal number theorem)
  - https://en.wikipedia.org/wiki/Pentagonal_number_theorem
  - https://atcoder.jp/contests/abc279/tasks/abc279_h
- $O(N\sqrt{N})$ で求める。
  - http://degwer.hatenablog.com/entries/2017/08/29
  - https://qiita.com/drken/items/f2ea4b58b0d21621bd51
  - https://judge.yosupo.jp/problem/partition_function


## Submissons

- https://yukicoder.me/submissions/701499
- [$n = m$ 版](https://judge.yosupo.jp/submission/3791)
