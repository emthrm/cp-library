---
title: 接尾辞配列 (suffix array)
documentation_of: //include/emthrm/string/suffix_array.hpp
---

文字列の全接尾辞を辞書順に並べた配列である。


## 時間計算量

テキスト長を $N$、パターン長を $M$ とおくと $\langle O(N\log{N}), O(M\log{N}) \rangle$


## 仕様

```cpp
template <typename T = std::string>
struct SuffixArray;
```

- `T`：$S$ の要素型

#### メンバ変数

|名前|説明|
|:--|:--|
|`std::vector<int> sa`|接尾辞配列|
|`std::vector<int> rank`|$\mathrm{rank}_i$ は `S[i:]` の接尾辞配列中での位置を表す。|

#### メンバ関数

|名前|効果・戻り値|
|:--|:--|
|`template <typename U = char>`<br>`explicit SuffixArray(const T& s_, const U sentinel = 0);`|$S$ に対してオブジェクトを構築する。|
|`std::vector<int> match(T* t) const;`|$T$ が出現する文字列 $S$ 中の位置|


## 参考文献

- https://github.com/beet-aizu/library/blob/2ecdc969043f5276c3782a7752592bd3fe856524/string/suffixarray.cpp
- 秋葉拓哉，岩田陽一，北川宜稔：プログラミングコンテストチャレンジブック \[第2版\]，pp.335-339，マイナビ出版（2012）
- http://wk1080id.hatenablog.com/entry/2018/12/25/005926


## TODO

- パターンマッチングを $O(M + \log{N})$ に高速化する。
  - ~~http://www.prefield.com/algorithm/string/suffix_array.html~~
- SA-IS
  - https://qiita.com/flare/items/ac11972dbc590a91980d
  - ~~https://topcoder.g.hatena.ne.jp/iwiwi/20110720/1311168147~~
  - https://mametter.hatenablog.com/entry/20180130/p1
  - https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html
  - http://gasin.hatenadiary.jp/entry/2017/06/08/101525
  - http://sile.hatenablog.jp/entry/20101213/1292190698
  - ~~https://lumakernel.github.io/ecasdqina/string/SA-IS~~
  - https://github.com/atcoder/ac-library/blob/master/atcoder/string.hpp#L51
  - https://gist.github.com/tjkendev/99d7330fe5642004b68268b31ba38ad4
  - https://docs.google.com/presentation/d/1R9ZgXqX4bpkO3nYkVoqU9Ng2uCIKLbf-UJ2C6hlVYFI
  - https://github.com/defineProgram/JOISS-2020/blob/master/doc/SA-IS.pdf
- 接尾辞オートマトン (suffix automaton)
  - https://ja.wikipedia.org/wiki/%E6%8E%A5%E5%B0%BE%E8%BE%9E%E3%82%AA%E3%83%BC%E3%83%88%E3%83%9E%E3%83%88%E3%83%B3
  - https://w.atwiki.jp/uwicoder/pages/2842.html
  - https://github.com/KodamaD/JOISS2020/blob/master/docs/presentation.pdf
  - https://github.com/spaghetti-source/algorithm/blob/master/string/suffix_automaton.cc
  - https://codeforces.com/contest/1780/problem/G
- 接尾辞木 (suffix tree)
  - https://ja.wikipedia.org/wiki/%E6%8E%A5%E5%B0%BE%E8%BE%9E%E6%9C%A8
  - https://qiita.com/goonew/items/548fe90e9f68c6bba9e9
  - https://docs.google.com/presentation/d/1m-FpwlEg47kHCQx7FSImN0bPY7XJToRVbSMeCsLpI7g
  - https://github.com/spaghetti-source/algorithm/blob/master/string/suffix_tree.cc
  - ~~https://github.com/eandbsoftware/libraryCPP/tree/master/Ukkonen~~


## Submissons

https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_14_B/review/4972832/emthrm/C++17
