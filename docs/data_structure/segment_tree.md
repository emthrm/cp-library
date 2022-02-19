# セグメント木 (segment tree)

[モノイド](../../../.verify-helper/docs/static/algebraic_structure.md)であるデータに対して高速に区間クエリを処理する完全二分木である．


## 時間計算量

$\langle O(N), O(\log{N}) \rangle$


## 使用法

- セグメント木

||説明|備考|
|:--:|:--:|:--:|
|`SegmentTree<T>(n)`|要素数 $N$ のセグメント木||
|`SegmentTree<T>(a)`|$A$ のセグメント木||
|`set(idx, val)`|$A_{\mathrm{idx}} = \mathrm{val}$||
|`get(left, right)`|$[\mathrm{left}, \mathrm{right})$ における解答クエリ||
|`operator()[idx]`|$A_{\mathrm{idx}}$||
|`find_right(left, g)`|`g(get(left, right + 1)) = false` を満たす最小の $\mathrm{right}$|存在しないときは $n$ となる．|
|`find_left(right, g)`|`g(get(left, right)) = false` を満たす最大の $\mathrm{left}$|存在しないときは $-1$ となる．|

`T` はモノイドを表す構造体であり，以下の型エイリアスと静的メンバ関数を必要とする．

||説明|
|:--:|:--:|
|`T::Monoid`|モノイド|
|`T::id()`|単位元|
|`T::merge(a, b)`||

- 遅延伝播セグメント木

||説明|
|:--:|:--:|
|`LazySegmentTree<T>(n)`|要素数 $N$ の遅延伝播セグメント木|
|`LazySegmentTree<T>(a)`|$A$ の遅延伝播セグメント木|
|`set(idx, val)`|$A_{\mathrm{idx}} = \mathrm{val}$|
|`apply(idx, val)`|$\mathrm{idx}$ における変更クエリ|
|`apply(left, right, val)`|$[\mathrm{left}, \mathrm{right})$ における変更クエリ|
|`get(left, right)`|$[\mathrm{left}, \mathrm{right})$ における解答クエリ|
|`operator()[idx]`|$A_{\mathrm{idx}}$|
|`find_right(left, g)`|`g(get(left, right + 1)) = false` を満たす最小の $\mathrm{right}$|存在しない場合は $n$ となる．|
|`find_left(right, g)`|`g(get(left, right)) = false` を満たす最大の $\mathrm{left}$|存在しない場合は $-1$ となる．|

`T` はモノイドを表す構造体であり，以下の型エイリアスと静的メンバ関数を必要とする．

||説明|
|:--:|:--:|
|`T::Monoid`|モノイド|
|`T::OperatorMonoid`|作用素モノイド|
|`T::m_id()`|モノイドの単位元|
|`T::o_id()`|作用素モノイドの単位元|
|`T::m_merge(a, b)`||
|`T::o_merge(a, b)`||
|`T::apply(a, b)`||


## 参考

- https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
- https://beet-aizu.hatenablog.com/entry/2019/11/27/125906
- http://kagamiz.hatenablog.com/entry/2012/12/18/220849

セグメント木
- https://tsutaj.hatenablog.com/entry/2017/03/29/204841
- https://github.com/atcoder/ac-library/blob/8de49c6f150d2e5af851cbbd074aee552bf2bec9/atcoder/segtree.hpp

遅延伝播セグメント木
- https://tsutaj.hatenablog.com/entry/2017/03/30/224339
- https://kazuma8128.hatenablog.com/entry/2017/12/29/081929
- https://smijake3.hatenablog.com/entry/2018/11/03/100133
- https://github.com/atcoder/ac-library/blob/0dd2c18e8bfc41f5f7a4a985b78c47aae945e9aa/atcoder/lazysegtree.hpp


## ToDo

- https://www.hamayanhamayan.com/entry/2017/07/08/173120
- https://ei1333.hateblo.jp/entry/2017/12/14/000000
- 動的構築セグメント木
  - https://scrapbox.io/data-structures/Dynamic_Segment_Tree
  - http://kazuma8128.hatenablog.com/entry/2018/11/29/093827
  - https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644
  - http://degwer.hatenablog.com/entry/20131211/1386757368
  - https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/DynamicSegmentTree
  - https://www.hamayanhamayan.com/entry/2019/02/09/103140
- 2D セグメント木
  - https://www.hamayanhamayan.com/entry/2017/12/09/015937
  - https://ei1333.github.io/algorithm/segment-tree.html
  - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
  - https://codeforces.com/blog/entry/74181?#comment-583268
  - https://github.com/ei1333/library/blob/master/structure/segment-tree-2d-2.cpp
  - https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/SegmentTree2D
  - https://github.com/primenumber/ProconLib/blob/master/Structure/SegmentTree2D.cpp
  - https://algoogle.hadrori.jp/algorithm/2d-segment-tree.html
  - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  - https://onlinejudge.u-aizu.ac.jp/beta/room.html#ACPC2021Day2/problems/H
  - https://codeforces.com/contest/1575/problem/L
  - https://twitter.com/PCTprobability/status/1444372565435170816
  - https://onlinejudge.u-aizu.ac.jp/problems/1068
  - フラクショナルカスケーディング (fractional cascading)
    - https://en.wikipedia.org/wiki/Fractional_cascading
    - http://sntea.hatenablog.com/entry/2017/09/28/003418
    - https://www.slideshare.net/okuraofvegetable/ss-65377588
    - https://www.slideshare.net/satashun/2013-25814388
    - https://qiita.com/nariaki3551/items/3c5e59b3ece31a4dfce8
    - https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/FractionalCascadingSegmentTree
  - range tree
    - https://en.wikipedia.org/wiki/Range_tree
    - https://kopricky.github.io/code/SegmentTrees/rangetree_pointupdate.html
    - https://yukicoder.me/problems/no/1625
- 永続セグメント木
  - https://scrapbox.io/data-structures/Persistent_Segment_Tree
  - https://scrapbox.io/data-structures/Persistent_Lazy_Segment_Tree
  - http://sigma425.hatenablog.com/entry/2014/12/30/164148
  - https://ei1333.github.io/algorithm/segment-tree.html
  - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
  - https://github.com/beet-aizu/library/blob/master/segtree/persistent/ushi.cpp
  - https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/PersistentSegmentTree
  - https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/PersistentLazySegmentTree
  - https://github.com/primenumber/ProconLib/blob/master/Structure/SegmentTreePersistent.cpp
  - http://monyone.github.io/teihen_library/#PersistentDynamicSumSegmentTree
- segment tree beats
  - https://rsm9.hatenablog.com/entry/2021/02/01/220408
  - https://twitter.com/fuppy_kyopro/status/1356599033439997952
  - https://codeforces.com/blog/entry/57319
  - https://hackmd.io/@a4YdmMWJSTa0aHKUX3wNcA/S1MJhbSLV
  - https://smijake3.hatenablog.com/entry/2019/04/28/021457
  - https://smijake3.hatenablog.com/entry/2019/05/18/145531
  - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
  - https://kmyk.github.io/competitive-programming-library/library/data_structure/segment_tree_beats.hpp.html
  - https://github.com/tjkendev/segment-tree-beats
  - https://tjkendev.github.io/procon-library/cpp/range_query/segment_tree_beats_1.html
  - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  - https://onlinejudge.u-aizu.ac.jp/problems/0427
- 双対セグメント木
  - https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/
  - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
- 区間等差数列加算クエリ / 区間等差数列更新クエリ
  - https://null-mn.hatenablog.com/entry/2021/08/22/064325
  - https://twitter.com/yosupot/status/1104175527923986432
  - https://twitter.com/kuma_program/status/1358762477589155840
- 定数時間アルゴリズム
  - https://docs.google.com/presentation/d/1AvECxRv7hLbCNdXjERzhuJuYcV5fYFPpLA_S4QppbRI


## Verified

- [セグメント木](https://judge.yosupo.jp/submission/25800)
  - [range minimum query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_A/review/4890699/emthrm/C++17)
  - range maximum query
  - [range sum query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_B/review/4890707/emthrm/C++14)
- [遅延伝播セグメント木](https://judge.yosupo.jp/submission/26157)
  - [range minimum query and range update query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_F/review/4899784/emthrm/C++17)
  - range maximum query and range update query
  - [range minimum query and range add query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_H/review/4899786/emthrm/C++17)
  - range maximum query and range add query
  - [range sum query and range update query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_I/review/4899787/emthrm/C++17)
  - [range sum query and range add query](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4899788/emthrm/C++17)
