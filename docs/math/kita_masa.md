---
title: きたまさ法
documentation_of: math/kita_masa.hpp
---

$k$-階定数係数斉次線形漸化式の第 $n$ 項を高速に求めるアルゴリズムである．


## 時間計算量

$O(K^2 \log{N})$


## 使用法

||説明|
|:--:|:--:|
|`kita_masa(c, a, n)`|係数 $C$，初期値 $A$ で表される $k$-階定数係数斉次線形漸化式の第 $n$ 項|


## 参考

- https://lumakernel.github.io/ecasdqina/algorithm/Kitamasa
- ~~http://sugarknri.hatenablog.com/entry/2017/11/18/233936~~
- http://yosupo.hatenablog.com/entry/2015/03/27/025132
- https://tjkendev.github.io/procon-library/cpp/series/kitamasa.html


## ToDo

- https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
- 高速きたまさ法
  - http://misawa.github.io/others/fast_kitamasa_method.html
  - https://yukicoder.me/problems/no/215/editorial
  - http://kmjp.hatenablog.jp/entry/2015/06/03/1000
  - http://sugarknri.hatenablog.com/entry/2017/11/18/233936
- Bostan-Mori のアルゴリズム
  - http://q.c.titech.ac.jp/docs/progs/polynomial_division.html
  - https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a
  - https://atcoder.jp/contests/abc198/submissions/21708598
  - https://tsuchi.hateblo.jp/entry/2021/10/09/124804


## Verified

https://yukicoder.me/submissions/647774
