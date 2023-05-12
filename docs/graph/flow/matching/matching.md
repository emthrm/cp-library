---
title: [
  二部グラフの最大マッチング,
  Hopcroft–Karp algorithm,
  二部グラフの重み付き最大マッチング,
  一般グラフの最大マッチング (maximum matching)
]
documentation_of: [
  //include/emthrm/graph/flow/matching/bipartite_matching.hpp,
  //include/emthrm/graph/flow/matching/hopcroft-karp_algorithm.hpp,
  //include/emthrm/graph/flow/matching/weighted_bipartite_matching.hpp,
  //include/emthrm/graph/flow/matching/maximum_matching.hpp
]
---

### マッチング (matching)

互いに端点を共有しない辺集合である。


### 辺被覆 (edge cover)

任意の頂点がいずれかの端点となっている辺集合である。


### 独立集合 (independent set) / 安定集合 (stable set)

互いに隣接していない頂点集合である。


### 頂点被覆 (vertex cover)

任意の辺に対して少なくとも一方の端点を含む頂点集合である。


### クリーク (clique)

無向グラフに対して完全グラフな部分グラフである。


## 性質

1. 孤立点のないグラフに対して (最大マッチングのサイズ) + (最小辺被覆のサイズ) = (頂点数) が成り立つ。

2. (最大独立集合のサイズ) + (最小頂点被覆のサイズ) = (頂点数)

3. 二部グラフ $(U, V, E)$ に対して $\lvert U \rvert = \lvert V \rvert \implies (\text{完全二部マッチングの個数}) \equiv \lvert A \rvert \pmod{2}$ が成り立つ。ただし $A$ は $a_{ij} = \begin{cases} 1 & (\lbrace U_i, V_j \rbrace \in E), \\\\ 0 & (\text{otherwise}) \end{cases}$ を満たす $\lvert U \rvert \times \lvert V \rvert$ 型行列である。

4. 二部グラフに対して、最大マッチングのサイズは最小頂点被覆のサイズに等しい。

5. 有向非巡回グラフの最小パス被覆は二部グラフの最大マッチングに帰着できる。


### Hall's theorem

二部グラフ $(U, V, E)$ に対して、以下は同値である。

- $U$ の元をすべて被覆するマッチングが存在する。
- $\forall S \subseteq U,\ \lvert S \rvert \leq \lvert \Gamma(S) \rvert$.


### Dilworth's theorem

任意の有限な半順序集合に対して、反鎖 (antichain) の最大サイズは共通部分のない鎖 (chain) に分解したときの最小サイズに等しい。

特に有向非巡回グラフ $G$ では、$\forall u, v \in V(G)$ に対して

$$
  u \leq v \iff u \text{ から } v \text{ に到達可能である。}
$$

と定義すると、$(V(G), \leq)$ は半順序集合である。$(V(G), \leq)$ に対して、共通部分のない鎖に分解したときの最小サイズは最小パス被覆のサイズを意味する。


## 時間計算量

||時間計算量|
|:--|:--|
|二部グラフの最大マッチング|$O(\lvert V \rvert \lvert E \rvert)$|
|Hopcroft–Karp algorithm|$O(\lvert E \rvert \sqrt{\lvert V \rvert})$|
|二部グラフの重み付き最大マッチング|$O(\lvert E \rvert \lvert V \rvert \log{\lvert V \rvert})$|
|一般グラフの最大マッチング|$O({\lvert V \rvert}^3 + \lvert E \rvert)$|


## 仕様

### 二部グラフの最大マッチング

```cpp
struct BipartiteMatching;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> match`|マッチした相手。ただし存在しないときは $-1$ となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit BipartiteMatching(const int n);`|頂点数 $N$ のオブジェクトを構築する。|
|`void add_edge(const int u, const int v);`|辺 $(u, v)$ を加える。|
|`int solve();`|最大マッチングのサイズ|
|`void fix(const int ver);`|頂点 $\mathrm{ver}$ に対するマッチングを固定する。|
|`int activate(const int ver);`|頂点 $\mathrm{ver}$ を有効にしたのち、最大マッチングのサイズの変化量を返す。|
|`int deactivate(const int ver);`|頂点 $\mathrm{ver}$ を無効にしたのち、最大マッチングのサイズの変化量を返す。|


### Hopcroft–Karp algorithm

```cpp
struct HopcroftKarp;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> match`|マッチした相手。ただし存在しないときは $-1$ となる。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit HopcroftKarp(const int left, const int right);`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフに対してオブジェクトを構築する。|
|`void add_edge(const int u, const int v);`|辺 $(u, v)$ を加える。|
|`int solve();`|最大マッチングのサイズ|


### 二部グラフの重み付き最大マッチング

```cpp
template <typename T>
struct WeightedBipartiteMatching;
```

- `T`：重みを表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit WeightedBipartiteMatching(const int left, const int right);`|頂点数 $\mathrm{left}$ と $\mathrm{right}$ の二部グラフに対してオブジェクトを構築する。|
|`void add_edge(const int src, const int dst, const T cost);`|重み $\mathrm{cost}$ の辺 $(\mathrm{src}, \mathrm{dst})$ を加える。||
|`T solve();`|重み付き最大マッチングの重み||
|`std::vector<int> matching() const;`|マッチした相手。ただし存在しないときは $-1$ が格納される。|


### 一般グラフの最大マッチング

|名前|戻り値|
|:--|:--|
|`int maximum_matching(const std::vector<std::vector<int>>& graph);`|無向グラフ $\mathrm{graph}$ の最大マッチングのサイズ|


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.195-199，マイナビ出版（2012）

性質3
- https://pekempey.hatenablog.com/entry/2016/11/29/200605

性質5・Dilworth's theorem
- Robert P. Dilworth: A Decomposition Theorem for Partially Ordered Sets, *Annals of Mathematics*, Vol. 51, No. 1, pp. 161–166 (1950). https://doi.org/10.2307/1969503
- https://en.wikipedia.org/wiki/Dilworth%27s_theorem
- ~~https://lumakernel.github.io/ecasdqina/math/dilworth-theorem~~
- https://anta1.hatenadiary.org/entry/20120816/1345046832

Hall's theorem
- Philip Hall: On Representatives of Subsets, *Journal of the London Mathematical Society*, Vol. s1-10, No. 1, pp. 26–30 (1935). https://doi.org/10.1112/jlms/s1-10.37.26
- https://mathtrain.jp/hall

二部グラフの最大マッチング
- https://ei1333.github.io/algorithm/bipartite-matching.html

Hopcroft–Karp algorithm
- John E. Hopcroft and Richard M. Karp: An $n^{5/2}$ Algorithm for Maximum Matchings in Bipartite Graphs, *SIAM Journal on Computing*, Vol. 2, No. 4, pp. 225–231 (1973). https://doi.org/10.1137/0202019
- https://tiramister.net/blog/posts/hopcroft-karp/
- https://ei1333.github.io/luzhiled/snippets/graph/hopcroft-karp.html

二部グラフの重み付き最大マッチング
- https://qiita.com/drken/items/e805e3f514acceb87602

一般グラフの最大マッチング
- W. T. Tutte: The Factorization of Linear Graphs, *Journal of the London Mathematical Society*, Vol. s1-22, No. 2, pp. 107–111 (1947). https://doi.org/10.1112/jlms/s1-22.2.107
- https://kopricky.github.io/code/Academic/maximum_matching_memo.html


## TODO

- https://www.slideshare.net/wata_orz/ss-12131479
- https://drive.google.com/file/d/1RD66csuDTAYXPmuCsiPi3HWBwtLg95T5
- 一般グラフの最大マッチング
  - ~~https://min-25.hatenablog.com/entry/2016/11/21/222625~~
  - https://judge.yosupo.jp/problem/general_matching
  - Edmonds' Algorithm
    - ~~http://www.prefield.com/algorithm/graph/maximum_matching.html~~
    - https://github.com/spaghetti-source/algorithm/blob/master/graph/gabow_edmonds.cc
    - https://www.dropbox.com/sh/7uhazzp6wvx9mi7/AACpEgmn--Grp9nVD3NOD9Hia
    - https://www.slideshare.net/hcpc_hokudai/ss-120540096
    - https://qiita.com/Kutimoti_T/items/5b579773e0a24d650bdf
- 一般グラフの重み付き最大マッチング
  - ~~https://min-25.hatenablog.com/entry/2016/11/21/222625~~
  - ~~http://www.prefield.com/algorithm/graph/minimum_weight_matching.html~~
  - https://judge.yosupo.jp/problem/general_weighted_matching
- 木の最小辺被覆
  - https://twitter.com/Ymgch_K/status/964058288747831296
- 最大独立集合
  - https://37zigen.com/maximum-independent-set-algorithm/
  - https://drive.google.com/drive/folders/1MlboOgOEnu_zx55pGhZK80IT3hN6H-Ji
  - https://ei1333.github.io/luzhiled/snippets/graph/maximum-independent-set.html
  - https://github.com/ei1333/library/blob/master/graph/others/maximum-independent-set.hpp
  - https://github.com/primenumber/ProconLib/blob/master/Graph/MaximumIndependentSet.cpp
  - https://mugen1337.github.io/procon/Graph2/WeightedMaximumIndependentSet.cpp
  - https://sotanishy.github.io/cp-library-cpp/graph/maximum_independent_set.cpp
  - https://sotanishy.github.io/cp-library-cpp/graph/maximum_weight_independent_set.hpp
  - https://judge.yosupo.jp/problem/maximum_independent_set
- 木上の独立集合
  - https://github.com/noshi91/blog/tree/master/codes/typical90/
  - https://atcoder.jp/contests/typical90/tasks/typical90_z
  - https://twitter.com/noshi91/status/1387447778167513088
  - https://twitter.com/noshi91/status/1387448827838353411
  - https://twitter.com/noshi91/status/1387456359587729411
- 二部グラフの最小頂点被覆
  - https://www.slideshare.net/drken1215/2-86838670
- 最大クリーク
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/maximal_cliques.cc
  - https://ei1333.github.io/luzhiled/snippets/graph/maximum-clique.html
  - https://github.com/ei1333/library/blob/master/graph/others/maximum-clique.hpp
  - https://www.t3nro.net/2017/04/maximum-clique-problem/
- ハンガリアン法 (Hungarian method)
  - https://ei1333.github.io/algorithm/hungarian.html
  - https://ei1333.github.io/luzhiled/snippets/graph/hungarian.html
  - ~~http://www.prefield.com/algorithm/math/hungarian.html~~
  - https://github.com/primenumber/ProconLib/blob/master/Graph/Hungarian.cpp
  - https://judge.yosupo.jp/problem/assignment
- 安定マッチング (stable matching)
  - https://ja.wikipedia.org/wiki/%E5%AE%89%E5%AE%9A%E7%B5%90%E5%A9%9A%E5%95%8F%E9%A1%8C
  - https://mathtrain.jp/galeshapley
  - ~~https://github.com/eandbsoftware/libraryCPP/blob/master/!StableMatching.cpp~~
  - https://sotanishy.github.io/cp-library-cpp/misc/stable_matching.hpp
- FKT algorithm
  - https://en.wikipedia.org/wiki/FKT_algorithm
  - https://www.ioi-jp.org/camp/2017/2017-sp_camp-kumabe2.pdf
- クリークの列挙
  - https://sotanishy.github.io/cp-library-cpp/graph/enumerate_cliques.cpp
  - https://judge.yosupo.jp/problem/enumerate_cliques


## Submissons

- [二部グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_7_A/review/5876417/emthrm/C++17)
- [Hopcroft–Karp algorithm](https://judge.yosupo.jp/submission/2723)
- [二部グラフの重み付き最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2429/review/4092692/emthrm/C++14)
- [一般グラフの最大マッチング](https://onlinejudge.u-aizu.ac.jp/solutions/problem/3032/review/5853683/emthrm/C++17)
