# 最小共通祖先 (lowest common ancestor)

根付き木のある2頂点に対して最も深い共通祖先である。


## 時間計算量

||時間計算量|
|:--|:--|
|ダブリング版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(\log{\lvert V \rvert}) \rangle$|
|オイラーツアー版|$\langle O(\lvert V \rvert \log{\lvert V \rvert}), O(1) \rangle$|


## 仕様

### ダブリング版

```cpp
template <typename CostType>
struct LowestCommonAncestorByDoubling;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> depth`|`depth[i]` は頂点 $i$ の深さを表す。|
|`std::vector<CostType> dist`|`dist[i]` は根と頂点 $i$ の間の距離を表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit LowestCommonAncestorByDoubling(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`void build(const int root = 0);`|根を $\mathrm{root}$ として構築する。|
|`int query(int u, int v) const;`|頂点 $u, v$ の最小共通祖先|
|`CostType distance(const int u, const int v) const;`|頂点 $u, v$ 間の距離|


### [オイラーツアー](euler_tour.md)版

```cpp
template <typename CostType>
struct LowestCommonAncestor : EulerTour<CostType>;
```

- `CostType`：辺のコストを表す型

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`explicit LowestCommonAncestor(const std::vector<std::vector<Edge<CostType>>>& graph, const int root = 0);`|根を $\mathrm{root}$ とする木 $\mathrm{graph}$ に対してオブジェクトを構築する。|
|`int query(int u, int v) const;`|頂点 $u, v$ の最小共通祖先|


### [HL 分解版](heavy-light_decomposition.md)


## 参考文献

- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.292-295，マイナビ出版（2012）
- https://yukicoder.me/wiki/lowest_common_ancestor

オイラーツアー版
- https://github.com/drken1215/algorithm/blob/efb8cf052b095e49e70135a6fb628308d06f49b2/DataStructureOnTree/euler_tour_on_nodes.cpp


## TODO

- Tarjan's off-line lowest common ancestors algorithm
  - http://www.prefield.com/algorithm/graph/least_common_ancestor.html
  - https://github.com/spaghetti-source/algorithm/blob/master/graph/least_common_ancestor_tarjan.cc
  - http://monyone.github.io/teihen_library/#OfflineLCA
- level ancestor problem
  - https://en.wikipedia.org/wiki/Level_ancestor_problem
  - https://www2.compute.dtu.dk/courses/02282/2018/levelancestor/levelancestor1x1.pdf
  - https://37zigen.com/level-ancestor-problem/
  - https://hdbn.hatenadiary.org/entry/20111125/1322194487
  - https://drive.google.com/drive/folders/1atQRO6Y9bHgLDH-YLq3obDwMxIuk7--h
  - https://noshi91.hatenablog.com/entry/2019/09/22/114149
  - https://suisen-kyopro.hatenablog.com/entry/2022/04/04/043452
  - https://twitter.com/GauravML/status/1415073033522319367
  - https://twitter.com/keijak/status/1510953079872663555
  - https://github.com/noshi91/n91lib_rs/blob/master/src/data_structure/level_ancestor.rs
  - https://judge.yosupo.jp/problem/jump_on_tree


## Submissons

- [ダブリング版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4084783/emthrm/C++14)
- [オイラーツアー版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2667/review/4084875/emthrm/C++14)
- [HL 分解版](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_C/review/4093404/emthrm/C++14)
