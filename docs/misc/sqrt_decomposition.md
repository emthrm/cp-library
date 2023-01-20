---
title: 平方分割 (sqrt decomposition)
documentation_of: include/emthrm/misc/sqrt_decomposition.hpp
---


## 時間計算量

$\langle O(N), O(\sqrt{N}) \rangle$


## 仕様

```cpp
struct SqrtDecomposition;
```

#### メンバ変数

|名前|説明|
|:--|:--|
|`const int block_size`|ブロックのサイズ|
|`const int n`|ブロックの数|
|`std::vector<int> ls`<br>`std::vector<int> rs`|[`ls[i]`, `rs[i]`) はブロック $i$ に対応する列のインデックス|
|`std::vector<bool> to_be_eval`|ブロックを評価すべきか。|

#### メンバ関数

|名前|効果・戻り値|備考|
|:--|:--|:--|
|`explicit SqrtDecomposition(const int n_);`|サイズ $N$ のオブジェクトを構築する。||
|`template <typename T> void partial_update(const int idx, const T val);`|$\mathrm{val}$ を基に $A_{\mathrm{idx}}$ を更新する。|関数プロトタイプ|
|`template <typename T> void total_update(const int idx, const T val);`|$\mathrm{val}$ を基にブロック $\mathrm{idx}$ を更新する。|関数プロトタイプ|
|`template <typename T> void update(const int l, const int r, const T val);`|$\mathrm{val}$ を基に $\lbrack l, r)$ を更新する。||
|`template <typename T> void partial_query(const int idx, T* val);`|$A_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する。|関数プロトタイプ|
|`template <typename T> void total_query(const int idx, T* val);`|ブロック $\mathrm{idx}$ を基にクエリの解 $\mathrm{val}$ を更新する。|関数プロトタイプ|
|`template <typename T> T query(const int l, const int r, const T id);`|$\lbrack l, r)$ に対するクエリの解|$\mathrm{id}$ は単位元である。|


## 参考文献

- https://twitter.com/chokudai/status/1125634200084729857


## TODO

- https://www.hamayanhamayan.com/entry/2017/04/12/180257
- 指定された頂点たちの最小共通祖先関係を保って木を圧縮してできる補助的な木
  - https://dic.kimiyuki.net/auxiliary-tree
  - https://www.slideshare.net/iwiwi/2-12188845/7
  - http://drken1215.hatenablog.com/entry/2018/08/14/193500
  - https://sotanishy.github.io/cp-library-cpp/tree/auxiliary_tree.cpp
  - https://atcoder.jp/contests/typical90/tasks/typical90_ai
- 木の平方分割
  - http://topcoder.g.hatena.ne.jp/iwiwi/20111205/1323099376
  - https://tubo28.me/compprog/algorithm/sqrt-decomp-tree/
  - http://noshi91.hatenablog.com/entry/2019/12/07/140433


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4087985/emthrm/C++14
