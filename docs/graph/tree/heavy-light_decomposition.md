---
title: HL 分解 (heavy-light decomposition)
documentation_of: include/emthrm/graph/tree/heavy-light_decomposition.hpp
---

heavy edge と light edge に分類された辺を基にして、木を分解する方法である。


## 時間計算量

$\langle O(\lvert V \rvert), O(\log{\lvert V \rvert}) \rangle$


## 仕様

```cpp
template <typename CostType>
struct HeavyLightDecomposition;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> parent`|`parent[i]` は頂点 $i$ の親の頂点番号を表す。|
|`std::vector<int> subtree`|`subtree[i]` は頂点 $i$ の部分木の大きさを表す。|
|`std::vector<int> id`|`id[i]` は頂点 $i$ の ID を表す。|
|`std::vector<int> inv`|`inv[i]` はID $i$ の頂点番号を表す。|
|`std::vector<int> head`|`head[i]` は頂点 $i$ を含む heavy path の先頭の頂点番号を表す。|
|`std::vector<CostType> cost`|`cost[i]` は辺 (`inv[i]`, `inv[i + 1]`) の重みを表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit HeavyLightDecomposition(const std::vector<std::vector<Edge<CostType>>>& graph, const int root = 0);`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`template <typename Fn> void update_v(int u, int v, const Fn f) const;`|頂点 $u, v$ 間の頂点に対して $f$ を基に更新する。|
|`template <typename F, typename G, typename T> T query_v(int u, int v, const F f, const G g, const T id_t) const;`|頂点 $u, v$ 間の頂点に対する $f$ を基に $g$ でまとめたクエリの解|
|`template <typename Fn> void update_subtree_v(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の頂点に対して $f$ を基に更新する。|
|`template <typename T, typename Fn> T query_subtree_v(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の頂点に対する $f$ を基にしたクエリの解|
|`template <typename Fn> void update_e(int u, int v, const Fn f) const;`|頂点 $u, v$ 間の辺に対して $f$ を基に更新する。|
|`template <typename F, typename G, typename T> T query_e(int u, int v, const F f, const G g, const T id_t) const;`|頂点 $u, v$ 間の辺に対する $f$ を基に $g$ でまとめたクエリの解|
|`template <typename Fn> void update_subtree_e(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の辺に対して $f$ を基に更新する。|
|`template <typename T, typename Fn> T query_subtree_e(const int ver, const Fn f) const;`|頂点 $\mathrm{ver}$ の部分木の辺に対する $f$ を基にしたクエリの解|
|`int lowest_common_ancestor(int u, int v) const;`|頂点 $u, v$ の[最小共通祖先](lowest_common_ancestor.md)|


## 参考文献

- https://www.slideshare.net/hcpc_hokudai/study-20150107
- http://beet-aizu.hatenablog.com/entry/2017/12/12/235950
- https://github.com/beet-aizu/library/blob/627950ae389af108b3c3f431f057c58891b0ba72/tree/heavylightdecomposition.cpp
- https://codeforces.com/blog/entry/53170


## TODO

- 高速化
  - http://yosupo.hatenablog.com/entry/2015/10/02/233244


## Submissons

- https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084766/emthrm/C++14
