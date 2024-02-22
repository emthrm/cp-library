---
title: 重心分解 (centroid decompositon)
documentation_of: //include/emthrm/graph/tree/centroid_decomposition.hpp
---

重心を基にした木の分解法の一つである。木上で分割統治法を行うときに有用である。


## 時間計算量

$O(\lvert V \rvert \log{\lvert V \rvert})$


## 仕様

```cpp
template <typename CostType>
struct CentroidDecomposition;
```

- `CostType`：辺のコストを表す型

#### メンバ変数

|名前|説明|
|:--|:--|
|`int root`|重心分解した木の根|
|`std::vector<int> parent`|`parent[i]` は `g` における頂点 $i$ の親を表す。ただし存在しないときは $-1$ となる。|
|`std::vector<std::vector<int>> g`|重心分解を行った木|

#### メンバ関数

|名前|効果|
|:--|:--|
|`explicit CentroidDecomposition(const std::vector<std::vector<Edge<CostType>>>& graph);`|木 $\mathrm{graph}$ に対してオブジェクトを構築する。|


## 参考文献

- http://compro.tsutajiro.com/archive/190207_divcon.pdf
- ~~https://lumakernel.github.io/ecasdqina/graph/CentroidDecomposition~~


## TODO

- ~~https://twitter.com/beet_aizu/status/1142651943971540992~~
- $1/3$ 重心分解
  - https://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d
  - https://twitter.com/noshi91/status/1549081194859761664
  - https://twitter.com/NachiaVivias/status/1549184577511788544
  - https://twitter.com/SSRS_cp/status/1640566437734653953
  - https://twitter.com/noshi91/status/1640569780100034560
  - https://twitter.com/noshi91/status/1673744350998851584
  - https://twitter.com/noshi91/status/1683485568737345543
  - https://twitter.com/noshi91/status/1720487757238432233
  - https://twitter.com/noshi91/status/1758542680517476658
  - 問題例 "[Paken Land](https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_o)"
    - https://atcoder.jp/contests/pakencamp-2022-day1/submissions/40109596
  - 問題例 "[Tree Distance 3](https://yukicoder.me/problems/no/2634)"


## Submissons

https://atcoder.jp/contests/abc291/submissions/39252522
