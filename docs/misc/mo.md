---
title: Mo's algorithm
documentation_of: //include/emthrm/misc/mo.hpp
---

- オフラインである。
- 要素の更新がない。
- $\lbrack L, R \rbrack$ の結果から $\lbrack L - 1, R \rbrack,\ \lbrack L + 1, R \rbrack,\ \lbrack L, R - 1 \rbrack,\ \lbrack L, R + 1 \rbrack$ の結果が容易に得られる。

上記の条件を満たすことによって区間に関するクエリを高速に処理できるアルゴリズムである。


## 時間計算量

一回の伸縮あたり $O(\alpha)$ 時間かかるとおくと $O(Q\log{Q} + \alpha N\sqrt{Q})$


## 仕様

```cpp
struct Mo;
```

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit Mo(const std::vector<int>& ls, const std::vector<int>& rs);`|クエリ集合 $\lbrace \lbrack \mathrm{ls}_i, \mathrm{rs}_i) \rbrace$ のオブジェクトを構築する。||
|`int process();`|現在のクエリのインデックス。ただし存在しないときは $-1$ を返す。|
|`void add(const int idx) const;`|$A_{\mathrm{idx}}$ をクエリの範囲に追加する。|関数プロトタイプ|
|`void del(const int idx) const;`|$A_{\mathrm{idx}}$ をクエリの範囲から削除する。|関数プロトタイプ|


## 参考文献

- https://codeforces.com/blog/entry/81716
- https://ei1333.hateblo.jp/entry/2017/09/11/211011
- https://snuke.hatenablog.com/entry/2016/07/01/000000


## TODO

- https://www.hamayanhamayan.com/entry/2017/04/18/012937
- Rollback 平方分割
  - https://snuke.hatenablog.com/entry/2016/07/01/000000
  - ~~https://lumakernel.github.io/ecasdqina/algorithm/MoEx~~
  - https://github.com/ei1333/library/blob/master/other/mo-rollback.cpp
- 木上の Mo's algorithm、時空間 Mo's algorithm
  - https://ei1333.hateblo.jp/entry/2017/09/11/211011
  - https://ei1333.github.io/algorithm/mo.html
  - ~~https://lumakernel.github.io/ecasdqina/algorithm/Mo~~
  - ~~https://lumakernel.github.io/ecasdqina/algorithm/Mo3D~~
  - https://twitter.com/heno_code/status/1518799816876118016
  - https://codeforces.com/blog/entry/43230
  - https://codeforces.com/blog/entry/55574
  - https://codeforces.com/contest/1476/problem/G
  - https://twitter.com/SSRS_cp/status/1355193120204312576


## Submissons

https://judge.yosupo.jp/submission/17371
