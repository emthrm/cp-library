---
title: Mo's algorithm
documentation_of: misc/mo.hpp
---

- オフラインである．
- 要素の更新がない．
- $[L, R]$ の結果から $[L - 1, R],\ [L + 1, R],\ [L, R - 1],\ [L, R + 1]$ の結果が容易に得られる．

上記の条件を満たすことによって区間に関するクエリを高速に処理することができるアルゴリズムである．


## 時間計算量

$1$回あたりの伸縮に $O(\alpha)$ かかるとおくと $O(Q\log{Q} + \alpha N\sqrt{Q})$．


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`Mo(left, right)`|クエリ $\lbrace [\mathrm{left}, \mathrm{right}) \rbrace$ の Mo's algorithm を考える．||
|`process()`|現在のクエリのインデックス|存在しない場合は $-1$ となる．|
|`add(idx)`|$A_{\mathrm{idx}}$ をクエリの範囲に追加する．|関数プロトタイプ|
|`del(idx)`|$A_{\mathrm{idx}}$ をクエリの範囲から削除する．|関数プロトタイプ|


## 参考

- https://ei1333.hateblo.jp/entry/2017/09/11/211011
- https://snuke.hatenablog.com/entry/2016/07/01/000000


## ToDo

- https://www.hamayanhamayan.com/entry/2017/04/18/012937
- Rollback 平方分割
  - https://snuke.hatenablog.com/entry/2016/07/01/000000
  - https://lumakernel.github.io/ecasdqina/algorithm/MoEx
  - https://github.com/ei1333/library/blob/master/other/mo-rollback.cpp
- 木上の Mo's algorithm，時空間 Mo's algorithm
  - https://ei1333.hateblo.jp/entry/2017/09/11/211011
  - https://ei1333.github.io/algorithm/mo.html
  - https://lumakernel.github.io/ecasdqina/algorithm/Mo
  - https://lumakernel.github.io/ecasdqina/algorithm/Mo3D
  - https://codeforces.com/blog/entry/43230
  - https://codeforces.com/blog/entry/55574
  - https://codeforces.com/contest/1476/problem/G
  - https://twitter.com/SSRS_cp/status/1355193120204312576


## Verified

https://judge.yosupo.jp/submission/17371
