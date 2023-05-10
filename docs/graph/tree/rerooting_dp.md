---
title: 全方位木 DP
documentation_of: //include/emthrm/graph/tree/rerooting_dp.hpp
---


## 仕様

|名前|戻り値|
|:--|:--|
|`template <typename CostType, typename CommutativeSemigroup, typename E, typename F, typename G>`<br>`std::vector<CommutativeSemigroup> rerooting_dp(const std::vector<std::vector<Edge<CostType>>>& graph, const std::vector<CommutativeSemigroup>& def, const E merge, const F f, const G g);`|木 $\mathrm{graph}$ に対する全方位木 DP|


## 例

- [木の直径](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_A/review/6390469/emthrm/C++17)
- [高橋王国の分割統治](https://atcoder.jp/contests/arc028/submissions/29989915)
- [限界集落](https://atcoder.jp/contests/njpc2017/submissions/29991480)
- [Driving on a Tree](https://atcoder.jp/contests/s8pc-4/submissions/29991981)
- [The Fair Nut and the Best Path](https://codeforces.com/contest/1084/submission/149080099)
- [Subtree](https://atcoder.jp/contests/dp/submissions/29989850)
- [Maximum White Subtree](https://codeforces.com/contest/1324/submission/149079224)
- [Distributing Integers](https://atcoder.jp/contests/abc160/submissions/29989897)
- [Distance Sums 2](https://atcoder.jp/contests/abc220/submissions/29989935)
- [Expensive Expense](https://atcoder.jp/contests/abc222/submissions/29989944)
- [Vertex Deletion](https://atcoder.jp/contests/abc223/submissions/29989873)


## 参考文献

- https://ei1333.hateblo.jp/entry/2017/04/10/224413
- https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e
- https://snuke.hatenablog.com/entry/2019/01/16/203626
- https://rsk0315.hatenablog.com/entry/2021/06/27/013506
- https://null-mn.hatenablog.com/entry/2020/04/14/124151
- https://twitter.com/noshi91/status/1438937367847456772


## Submissons

https://judge.yosupo.jp/submission/138885
