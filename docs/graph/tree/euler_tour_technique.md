---
title: Euler tour technique
documentation_of: //include/emthrm/graph/tree/euler_tour_technique.hpp
---

根付き木を列として表現するデータ構造である。


## 時間計算量

$O(\lvert V \rvert)$


## 仕様

```cpp
template <typename CostType>
struct EulerTourTechnique;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> preorder`|頂点属性の Euler tour|
|`std::vector<int> depth`|`depth[i]` は頂点 `preorder[i]` の深さを表す。|
|`std::vector<int> left`|`left[i]` は `preorder` に頂点 $i$ が現れるインデックスの最小値を表す。|
|`std::vector<int> right`|`right[i]` は `preorder` に頂点 $i$ が現れるインデックスの最大値を表す。|
|`std::vector<int> down`|`down[i]` は `tour` に頂点 $i$ へ下る辺が現れるインデックスを表す。|
|`std::vector<int> up`|`up[i]` は `tour` に頂点 $i$ から上る辺が現れるインデックスを表す。|
|`std::vector<CostType> tour`|Euler tour|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit EulerTourTechnique(const std::vector<std::vector<Edge<CostType>>> &graph, const int root = 0);`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`template <typename Fn>`<br>`void update_v(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の頂点に対して $f$ を基に更新する。|
|`template <typename T, typename Fn>`<br>`T query_v(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の頂点に対する $f$ を基にしたクエリの解|
|`template <typename T, typename Fn>`<br>`T query_e(const int u, const int v, const Fn f) const;`|頂点 $u$ から $v$ へ下る辺に対する $f$ を基にしたクエリの解|
|`template <typename Fn>`<br>`void update_subtree_e(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する。|
|`template <typename T, typename Fn>`<br>`T query_subtree_e(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の辺に対する $f$ を基にしたクエリの解|


## 参考文献

- Robert E. Tarjan and Uzi Vishkin: Finding biconnected componemts and computing tree functions in logarithmic parallel time, *25th Annual Symposium on Foundations of Computer Science, 1984.*, pp. 12–20 (1984). https://doi.org/10.1109/SFCS.1984.715896
- ~~http://beet-aizu.hatenablog.com/entry/2019/07/08/174727~~
- https://twitter.com/3SAT_IS_IN_P/status/1296040678820990982
- https://github.com/spaghetti-source/algorithm/blob/41bc0bbb1767692eb9bdeeceb332b2b8cc17329a/graph/least_common_ancestor_sparsetable.cc


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14
