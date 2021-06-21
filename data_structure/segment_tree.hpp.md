---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_minimum_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (range\
      \ minimum query)"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_sum_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (range\
      \ sum query)"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/segment_tree.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/segment_tree.md
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/segment_tree.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @docs docs/data_structure/segment_tree.md\n\
    \ */\n\n#pragma once\n#include <limits>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstruct SegmentTree {\n  using Monoid = typename T::Monoid;\n\n  SegmentTree(int\
    \ n) : SegmentTree(std::vector<Monoid>(n, T::id())) {}\n\n  SegmentTree(const\
    \ std::vector<Monoid> &a) : n(a.size()) {\n    while (p2 < n) p2 <<= 1;\n    dat.assign(p2\
    \ << 1, T::id());\n    for (int i = 0; i < n; ++i) dat[i + p2] = a[i];\n    for\
    \ (int i = p2 - 1; i > 0; --i) dat[i] = T::merge(dat[i << 1], dat[(i << 1) + 1]);\n\
    \  }\n\n  void set(int idx, Monoid val) {\n    idx += p2;\n    dat[idx] = val;\n\
    \    while (idx >>= 1) dat[idx] = T::merge(dat[idx << 1], dat[(idx << 1) + 1]);\n\
    \  }\n\n  Monoid get(int left, int right) const {\n    Monoid l_res = T::id(),\
    \ r_res = T::id();\n    for (left += p2, right += p2; left < right; left >>= 1,\
    \ right >>= 1) {\n      if (left & 1) l_res = T::merge(l_res, dat[left++]);\n\
    \      if (right & 1) r_res = T::merge(dat[--right], r_res);\n    }\n    return\
    \ T::merge(l_res, r_res);\n  }\n\n  Monoid operator[](const int idx) const { return\
    \ dat[idx + p2]; }\n\n  template <typename G>\n  int find_right(int left, G g)\
    \ {\n    if (left >= n) return n;\n    Monoid val = T::id();\n    left += p2;\n\
    \    do {\n      while (!(left & 1)) left >>= 1;\n      Monoid nx = T::merge(val,\
    \ dat[left]);\n      if (!g(nx)) {\n        while (left < p2) {\n          left\
    \ <<= 1;\n          nx = T::merge(val, dat[left]);\n          if (g(nx)) {\n \
    \           val = nx;\n            ++left;\n          }\n        }\n        return\
    \ left - p2;\n      }\n      val = nx;\n      ++left;\n    } while (__builtin_popcount(left)\
    \ > 1);\n    return n;\n  }\n\n  template <typename G>\n  int find_left(int right,\
    \ G g) {\n    if (right <= 0) return -1;\n    Monoid val = T::id();\n    right\
    \ += p2;\n    do {\n      --right;\n      while (right > 1 && (right & 1)) right\
    \ >>= 1;\n      Monoid nx = T::merge(dat[right], val);\n      if (!g(nx)) {\n\
    \        while (right < p2) {\n          right = (right << 1) + 1;\n         \
    \ nx = T::merge(dat[right], val);\n          if (g(nx)) {\n            val = nx;\n\
    \            --right;\n          }\n        }\n        return right - p2;\n  \
    \    }\n      val = nx;\n    } while (__builtin_popcount(right) > 1);\n    return\
    \ -1;\n  }\n\nprivate:\n  int n, p2 = 1;\n  std::vector<Monoid> dat;\n};\n\nnamespace\
    \ monoid {\ntemplate <typename T>\nstruct RangeMinimumQuery {\n  using Monoid\
    \ = T;\n  static constexpr Monoid id() { return std::numeric_limits<Monoid>::max();\
    \ }\n  static Monoid merge(const Monoid &a, const Monoid &b) { return std::min(a,\
    \ b); }\n};\n\ntemplate <typename T>\nstruct RangeMaximumQuery {\n  using Monoid\
    \ = T;\n  static constexpr Monoid id() { return std::numeric_limits<Monoid>::lowest();\
    \ }\n  static Monoid merge(const Monoid &a, const Monoid &b) { return std::max(a,\
    \ b); }\n};\n\ntemplate <typename T>\nstruct RangeSumQuery {\n  using Monoid =\
    \ T;\n  static constexpr Monoid id() { return 0; }\n  static Monoid merge(const\
    \ Monoid &a, const Monoid &b) { return a + b; }\n};\n}  // monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:26:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_sum_query.test.cpp
  - test/data_structure/segment_tree.test.cpp
  - test/data_structure/range_minimum_query.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.hpp
- /library/data_structure/segment_tree.hpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
# セグメント木 (segment tree)

[モノイド](../../../.verify-helper/docs/static/algebraic_structure.md)であるデータに対して高速に区間クエリを処理する完全二分木である．


## 時間計算量

$\langle O(N), O(\log{N}) \rangle$


## 使用法

- セグメント木

||説明|備考|
|:--:|:--:|:--:|
|`SegmentTree<T>(n)`|要素数 $n$ のセグメント木||
|`SegmentTree<T>(a)`|$A$ のセグメント木||
|`set(idx, val)`|$A_{\mathrm{idx}} = \mathrm{val}$||
|`get(left, right)`|$[\mathrm{left}, \mathrm{right})$ における取得クエリ||
|`operator()[idx]`|$A_{\mathrm{idx}}$||
|`find_right(left, g)`|`g(get(left, right + 1)) = false` を満たす最小の $\mathrm{right}$|存在しない場合は $n$ となる．|
|`find_left(right, g)`|`g(get(left, right)) = false` を満たす最大の $\mathrm{left}$|存在しない場合は $-1$ となる．|

`T` はモノイドを表す構造体であり，以下の型エイリアスと静的メンバ関数を必要とする．

||説明|
|:--:|:--:|
|`T::Monoid`|モノイド|
|`T::id()`|単位元|
|`T::merge(a, b)`||

- 遅延伝播セグメント木

||説明|
|:--:|:--:|
|`LazySegmentTree<T>(n)`|要素数 $n$ の遅延伝播セグメント木|
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
  - フラクショナルカスケーディング (fractional cascading)
    - https://en.wikipedia.org/wiki/Fractional_cascading
    - http://sntea.hatenablog.com/entry/2017/09/28/003418
    - https://www.slideshare.net/okuraofvegetable/ss-65377588
    - https://www.slideshare.net/satashun/2013-25814388
    - https://qiita.com/nariaki3551/items/3c5e59b3ece31a4dfce8
    - https://lumakernel.github.io/ecasdqina/data-structure/SegmentTree/FractionalCascadingSegmentTree
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
- 区間等差数列加算区間最小値クエリ
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
