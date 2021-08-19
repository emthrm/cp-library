---
title: Knuth-Yao speedup
documentation_of: dynamic_programming/knuth_yao_speedup.hpp
---

$N \times N$ 型重み行列 $W$ を考える．ただし $i > j$ を満たす $1 \leq \forall i, j \leq n$ に対して $w_{ij} = \infty$ が成り立つ．

- $W$ は Monge property を満たし，
- $W$ は単調，すなわち任意の $1 \leq i \leq k \leq l \leq j \leq N$ に対して $w_{kl} \leq w_{ij}$ を満たす

とき，

$$f(i, j) \mathrel{:=} \begin{cases} 0 & (i = j) \\ \min_{i \leq k < j} \lbrace f(i, k) + f(k + 1, j) \rbrace + w_{ij} & (i < j) \end{cases}$$

で定義される $f$ について $f(i, j) \ (1 \leq i \leq j \leq N)$ を $O(N^2)$ で計算できる．


### Monge property

二変数関数 $f$ を考える．$\forall i \leq j,\ k \leq l$ に対して $f(i, l) + f(j, k) \geq f(i, k) + f(j, l)$ が成り立つとき，$f$ は Monge property を満たす．


## 時間計算量

$O(N^2)$


## 使用法

||説明|
|:--:|:--:|
|`knuth_yao_speedup(w, ∞)`|重み行列 $W$ について上で定義した $f$|


## 参考

- https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html


## ToDo

- 最適二分探索木問題
  - https://atcoder.jp/contests/atc002/tasks/atc002_c
  - Hu-Tucker algorithm
    - https://ei1333.github.io/luzhiled/snippets/dp/hu-tucker.html
    - https://github.com/beet-aizu/library/blob/master/algorithm/optimalbinarytree.cpp
    - ~~https://lumakernel.github.io/ecasdqina/algorithm/Hu-Tucker~~
    - https://atcoder.jp/contests/kupc2012/submissions/29656
- monotone minima
  - https://dic.kimiyuki.net/monotone-minima
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://ei1333.github.io/luzhiled/snippets/dp/monotone-minima.html
  - https://github.com/beet-aizu/library/blob/master/algorithm/monotoneminima.cpp
  - https://lumakernel.github.io/ecasdqina/math/Monge
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Monotone-Minima
  - http://sigma425.hatenablog.com/entry/2015/12/01/162720
- SMAWK algorithm
  - https://en.wikipedia.org/wiki/SMAWK_algorithm
  - https://dic.kimiyuki.net/smawk-algorithm
  - https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/1348327542.html
  - https://drive.google.com/drive/folders/1FMOglXlDlyg6FJiP5QTJ0iSMq7XA2mqy
  - https://noshi91.github.io/Library/algorithm/smawk.cpp
- オフライン・オンライン変換
  - https://qiita.com/tmaehara/items/0687af2cfb807cde7860
  - https://github.com/ei1333/library/blob/master/dp/online-offline-dp.cpp
  - https://docs.google.com/presentation/d/1cgPtVG4j4Ima6Exf_Kw1IdYVfmfDJSGwaEgOMgPkWHg
- divide and conquer
  - https://ferin-tech.hatenablog.com/entry/2018/02/23/071343
  - https://www.hamayanhamayan.com/entry/2017/03/20/234711
  - https://ei1333.github.io/algorithm/dynamic-programming.html
  - https://ei1333.github.io/luzhiled/snippets/dp/divide-and-conquer-optimization.html
  - https://lumakernel.github.io/ecasdqina/dynamic-programming/speedup/Divide-and-Conquer-Optimization


## Verified

https://atcoder.jp/contests/kupc2012/submissions/25148833
