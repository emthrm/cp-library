---
title: 平方分割 (sqrt decomposition)
documentation_of: misc/sqrt_decomposition.hpp
---


## 時間計算量

$\langle O(N), O(\sqrt{N}) \rangle$


## 使用法

||説明|備考|
|:--:|:--:|:--:|
|`SqrtDecomposition(n)`|サイズ $N$ の平方分割を考える．||
|`b`|ブロックのサイズ||
|`n`|ブロックの数||
|[`left[i]`, `right[i]`)|ブロック $i$ に対応する列のインデックス||
|`partial_update(idx, val)`|$A_{\mathrm{idx}}$ に対して $\mathrm{val}$ を基に更新する．|関数プロトタイプ|
|`total_update(idx, val)`|$B_{\mathrm{idx}}$ に対して $\mathrm{val}$ を基に更新する．|関数プロトタイプ|
|`update(l, r, val)`|$\lbrack l, r)$ に対して $\mathrm{val}$ を基に更新する．||
|`partial_query(idx, val)`|$A_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する．|関数プロトタイプ|
|`total_query(idx, val)`|$B_{\mathrm{idx}}$ を基にクエリの解 $\mathrm{val}$ を更新する．|関数プロトタイプ|
|`query(l, r, 単位元)`|$\lbrack l, r)$ に対するクエリの解||


## 参考

- https://twitter.com/chokudai/status/1125634200084729857


## ToDo

- https://www.hamayanhamayan.com/entry/2017/04/12/180257
- クエリの平方分割 (木の圧縮)
  - https://www.slideshare.net/iwiwi/2-12188845/7
  - http://drken1215.hatenablog.com/entry/2018/08/14/193500
  - https://ei1333.github.io/algorithm/graph-decomp.html
- 木の平方分割
  - http://topcoder.g.hatena.ne.jp/iwiwi/20111205/1323099376
  - https://tubo28.me/compprog/algorithm/sqrt-decomp-tree/
  - http://noshi91.hatenablog.com/entry/2019/12/07/140433


## Verified

https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4087985/emthrm/C++14
