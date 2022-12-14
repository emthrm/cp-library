---
title: 平方分割 (sqrt decomposition)
documentation_of: include/emthrm/misc/sqrt_decomposition.hpp
---


## 時間計算量

$\langle O(N), O(\sqrt{N}) \rangle$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`SqrtDecomposition(n)`|サイズ $N$ の平方分割を考える．||
|`block_size`|ブロックのサイズ||
|`n`|ブロックの数||
|[`ls[i]`, `rs[i]`)|ブロック $i$ に対応する列のインデックス||
|`partial_update(idx, val)`|$\mathrm{val}$ を基に $A_{\mathrm{idx}}$ を更新する．|関数プロトタイプ|
|`total_update(idx, val)`|$\mathrm{val}$ を基に $B_{\mathrm{idx}}$ を更新する．|関数プロトタイプ|
|`update(l, r, val)`|$\mathrm{val}$ を基に $\lbrack l, r)$ を更新する．||
|`partial_query(idx, &val)`|$A_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する．|関数プロトタイプ|
|`total_query(idx, &val)`|$B_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する．|関数プロトタイプ|
|`query(l, r, 単位元)`|$\lbrack l, r)$ に対するクエリの解||


## 参考

- https://twitter.com/chokudai/status/1125634200084729857


## ToDo

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


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4087985/emthrm/C++14
