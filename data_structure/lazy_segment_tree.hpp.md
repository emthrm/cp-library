---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/lazy_segment_tree.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_minimum_query_and_range_add_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (range minimum query and range add query)"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_minimum_query_and_range_update_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (range minimum query and range update query)"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_sum_query_and_range_add_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (range sum query and range add query)"
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_sum_query_and_range_update_query.test.cpp
    title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\
      \u30F3\u30C8\u6728 (range sum query and range update query)"
  - icon: ':heavy_check_mark:'
    path: test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
    title: "\u30B0\u30E9\u30D5/\u6728/\u6700\u5C0F\u5171\u901A\u7956\u5148 \u30AA\u30A4\
      \u30E9\u30FC\u30C4\u30A2\u30FC\u7248"
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data_structure/segment_tree.md
    document_title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/lazy_segment_tree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\r\n * @brief \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \r\n * @docs docs/data_structure/segment_tree.md\r\n */\r\n\r\n#pragma once\r\n\
    #include <algorithm>\r\n// #include <cassert>\r\n#include <limits>\r\n#include\
    \ <vector>\r\n\r\ntemplate <typename T>\r\nstruct LazySegmentTree {\r\n  using\
    \ Monoid = typename T::Monoid;\r\n  using OperatorMonoid = typename T::OperatorMonoid;\r\
    \n\r\n  LazySegmentTree(int n) : LazySegmentTree(std::vector<Monoid>(n, T::m_id()))\
    \ {}\r\n\r\n  LazySegmentTree(const std::vector<Monoid> &a) : n(a.size()) {\r\n\
    \    while ((1 << height) < n) ++height;\r\n    p2 = 1 << height;\r\n    lazy.assign(p2,\
    \ T::o_id());\r\n    dat.assign(p2 << 1, T::m_id());\r\n    for (int i = 0; i\
    \ < n; ++i) dat[i + p2] = a[i];\r\n    for (int i = p2 - 1; i > 0; --i) dat[i]\
    \ = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);\r\n  }\r\n\r\n  void set(int idx,\
    \ const Monoid val) {\r\n    idx += p2;\r\n    for (int i = height; i > 0; --i)\
    \ propagate(idx >> i);\r\n    dat[idx] = val;\r\n    for (int i = 1; i <= height;\
    \ ++i) {\r\n      int current_idx = idx >> i;\r\n      dat[current_idx] = T::m_merge(dat[current_idx\
    \ << 1], dat[(current_idx << 1) + 1]);\r\n    }\r\n  }\r\n\r\n  void apply(int\
    \ idx, const OperatorMonoid val) {\r\n    idx += p2;\r\n    for (int i = height;\
    \ i > 0; --i) propagate(idx >> i);\r\n    dat[idx] = T::apply(dat[idx], val);\r\
    \n    for (int i = 1; i <= height; ++i) {\r\n      int current_idx = idx >> i;\r\
    \n      dat[current_idx] = T::m_merge(dat[current_idx << 1], dat[(current_idx\
    \ << 1) + 1]);\r\n    }\r\n  }\r\n\r\n  void apply(int left, int right, const\
    \ OperatorMonoid val) {\r\n    if (right <= left) return;\r\n    left += p2;\r\
    \n    right += p2;\r\n    int left_ctz = __builtin_ctz(left);\r\n    for (int\
    \ i = height; i > left_ctz; --i) propagate(left >> i);\r\n    int right_ctz =\
    \ __builtin_ctz(right);\r\n    for (int i = height; i > right_ctz; --i) propagate(right\
    \ >> i);\r\n    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {\r\n \
    \     if (l & 1) sub_apply(l++, val);\r\n      if (r & 1) sub_apply(--r, val);\r\
    \n    }\r\n    for (int i = left >> (left_ctz + 1); i > 0; i >>= 1) dat[i] = T::m_merge(dat[i\
    \ << 1], dat[(i << 1) + 1]);\r\n    for (int i = right >> (right_ctz + 1); i >\
    \ 0; i >>= 1) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);\r\n  }\r\n\r\
    \n  Monoid get(int left, int right) {\r\n    if (right <= left) return T::m_id();\r\
    \n    left += p2;\r\n    right += p2;\r\n    int left_ctz = __builtin_ctz(left);\r\
    \n    for (int i = height; i > left_ctz; --i) propagate(left >> i);\r\n    int\
    \ right_ctz = __builtin_ctz(right);\r\n    for (int i = height; i > right_ctz;\
    \ --i) propagate(right >> i);\r\n    Monoid l_res = T::m_id(), r_res = T::m_id();\r\
    \n    for (; left < right; left >>= 1, right >>= 1) {\r\n      if (left & 1) l_res\
    \ = T::m_merge(l_res, dat[left++]);\r\n      if (right & 1) r_res = T::m_merge(dat[--right],\
    \ r_res);\r\n    }\r\n    return T::m_merge(l_res, r_res);\r\n  }\r\n\r\n  Monoid\
    \ operator[](const int idx) {\r\n    int node = idx + p2;\r\n    for (int i =\
    \ height; i > 0; --i) propagate(node >> i);\r\n    return dat[node];\r\n  }\r\n\
    \r\n  template <typename G>\r\n  int find_right(int left, G g) {\r\n    if (left\
    \ >= n) return n;\r\n    left += p2;\r\n    for (int i = height; i > 0; --i) propagate(left\
    \ >> i);\r\n    Monoid val = T::m_id();\r\n    do {\r\n      while (!(left & 1))\
    \ left >>= 1;\r\n      Monoid nx = T::m_merge(val, dat[left]);\r\n      if (!g(nx))\
    \ {\r\n        while (left < p2) {\r\n          propagate(left);\r\n         \
    \ left <<= 1;\r\n          nx = T::m_merge(val, dat[left]);\r\n          if (g(nx))\
    \ {\r\n            val = nx;\r\n            ++left;\r\n          }\r\n       \
    \ }\r\n        return left - p2;\r\n      }\r\n      val = nx;\r\n      ++left;\r\
    \n    } while (__builtin_popcount(left) > 1);\r\n    return n;\r\n  }\r\n\r\n\
    \  template <typename G>\r\n  int find_left(int right, G g) {\r\n    if (right\
    \ <= 0) return -1;\r\n    right += p2;\r\n    for (int i = height; i > 0; --i)\
    \ propagate((right - 1) >> i);\r\n    Monoid val = T::m_id();\r\n    do {\r\n\
    \      --right;\r\n      while (right > 1 && (right & 1)) right >>= 1;\r\n   \
    \   Monoid nx = T::m_merge(dat[right], val);\r\n      if (!g(nx)) {\r\n      \
    \  while (right < p2) {\r\n          propagate(right);\r\n          right = (right\
    \ << 1) + 1;\r\n          nx = T::m_merge(dat[right], val);\r\n          if (g(nx))\
    \ {\r\n            val = nx;\r\n            --right;\r\n          }\r\n      \
    \  }\r\n        return right - p2;\r\n      }\r\n      val = nx;\r\n    } while\
    \ (__builtin_popcount(right) > 1);\r\n    return -1;\r\n  }\r\n\r\nprivate:\r\n\
    \  int n, p2, height = 0;\r\n  std::vector<Monoid> dat;\r\n  std::vector<OperatorMonoid>\
    \ lazy;\r\n\r\n  void sub_apply(int idx, const OperatorMonoid &val) {\r\n    dat[idx]\
    \ = T::apply(dat[idx], val);\r\n    if (idx < p2) lazy[idx] = T::o_merge(lazy[idx],\
    \ val);\r\n  }\r\n\r\n  void propagate(int idx) {\r\n    // assert(1 <= idx &&\
    \ idx < p2);\r\n    sub_apply(idx << 1, lazy[idx]);\r\n    sub_apply((idx << 1)\
    \ + 1, lazy[idx]);\r\n    lazy[idx] = T::o_id();\r\n  }\r\n};\r\n\r\nnamespace\
    \ monoid {\r\ntemplate <typename T>\r\nstruct RangeMinimumAndUpdateQuery {\r\n\
    \  using Monoid = T;\r\n  using OperatorMonoid = T;\r\n  static constexpr Monoid\
    \ m_id() { return std::numeric_limits<Monoid>::max(); }\r\n  static constexpr\
    \ OperatorMonoid o_id() { return std::numeric_limits<OperatorMonoid>::max(); }\r\
    \n  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::min(a,\
    \ b); }\r\n  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid\
    \ &b) { return b == o_id() ? a : b; }\r\n  static Monoid apply(const Monoid &a,\
    \ const OperatorMonoid &b) { return b == o_id()? a : b; }\r\n};\r\n\r\ntemplate\
    \ <typename T>\r\nstruct RangeMaximumAndUpdateQuery {\r\n  using Monoid = T;\r\
    \n  using OperatorMonoid = T;\r\n  static constexpr Monoid m_id() { return std::numeric_limits<Monoid>::lowest();\
    \ }\r\n  static constexpr OperatorMonoid o_id() { return std::numeric_limits<OperatorMonoid>::lowest();\
    \ }\r\n  static Monoid m_merge(const Monoid &a, const Monoid &b) { return std::max(a,\
    \ b); }\r\n  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid\
    \ &b) { return b == o_id() ? a : b; }\r\n  static Monoid apply(const Monoid &a,\
    \ const OperatorMonoid &b) { return b == o_id()? a : b; }\r\n};\r\n\r\ntemplate\
    \ <typename T, T Inf>\r\nstruct RangeMinimumAndAddQuery {\r\n  using Monoid =\
    \ T;\r\n  using OperatorMonoid = T;\r\n  static constexpr Monoid m_id() { return\
    \ Inf; }\r\n  static constexpr OperatorMonoid o_id() { return 0; }\r\n  static\
    \ Monoid m_merge(const Monoid &a, const Monoid &b) { return std::min(a, b); }\r\
    \n  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid\
    \ &b) { return a + b; }\r\n  static Monoid apply(const Monoid &a, const OperatorMonoid\
    \ &b) { return a + b; }\r\n};\r\n\r\ntemplate <typename T, T Inf>\r\nstruct RangeMaximumAndAddQuery\
    \ {\r\n  using Monoid = T;\r\n  using OperatorMonoid = T;\r\n  static constexpr\
    \ Monoid m_id() { return -Inf; }\r\n  static constexpr OperatorMonoid o_id() {\
    \ return 0; }\r\n  static Monoid m_merge(const Monoid &a, const Monoid &b) { return\
    \ std::max(a, b); }\r\n  static OperatorMonoid o_merge(const OperatorMonoid &a,\
    \ const OperatorMonoid &b) { return a + b; }\r\n  static Monoid apply(const Monoid\
    \ &a, const OperatorMonoid &b) { return a + b; }\r\n};\r\n\r\ntemplate <typename\
    \ T>\r\nstruct RangeSumAndUpdateQuery {\r\n  using Monoid = struct {\r\n    T\
    \ sum;\r\n    int len;\r\n  };\r\n  using OperatorMonoid = T;\r\n  static std::vector<Monoid>\
    \ init(int n) { return std::vector<Monoid>(n, Monoid{0, 1}); }\r\n  static constexpr\
    \ Monoid m_id() { return {0, 0}; }\r\n  static constexpr OperatorMonoid o_id()\
    \ { return std::numeric_limits<OperatorMonoid>::max(); }\r\n  static Monoid m_merge(const\
    \ Monoid &a, const Monoid &b) { return Monoid{a.sum + b.sum, a.len + b.len}; }\r\
    \n  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid\
    \ &b) { return b == o_id() ? a : b; }\r\n  static Monoid apply(const Monoid &a,\
    \ const OperatorMonoid &b) { return Monoid{b == o_id() ? a.sum : b * a.len, a.len};\
    \ }\r\n};\r\n\r\ntemplate <typename T>\r\nstruct RangeSumAndAddQuery {\r\n  using\
    \ Monoid = struct {\r\n    T sum;\r\n    int len;\r\n  };\r\n  using OperatorMonoid\
    \ = T;\r\n  static std::vector<Monoid> init(int n) { return std::vector<Monoid>(n,\
    \ Monoid{0, 1}); }\r\n  static constexpr Monoid m_id() { return {0, 0}; }\r\n\
    \  static constexpr OperatorMonoid o_id() { return 0; }\r\n  static Monoid m_merge(const\
    \ Monoid &a, const Monoid &b) { return Monoid{a.sum + b.sum, a.len + b.len}; }\r\
    \n  static OperatorMonoid o_merge(const OperatorMonoid &a, const OperatorMonoid\
    \ &b) { return a + b; }\r\n  static Monoid apply(const Monoid &a, const OperatorMonoid\
    \ &b) { return Monoid{a.sum + b * a.len, a.len}; }\r\n};\r\n}  // monoid\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2021-04-27 20:26:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
  - test/data_structure/range_sum_query_and_range_update_query.test.cpp
  - test/data_structure/range_sum_query_and_range_add_query.test.cpp
  - test/data_structure/range_minimum_query_and_range_update_query.test.cpp
  - test/data_structure/range_minimum_query_and_range_add_query.test.cpp
  - test/data_structure/lazy_segment_tree.test.cpp
documentation_of: data_structure/lazy_segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/lazy_segment_tree.hpp
- /library/data_structure/lazy_segment_tree.hpp.html
title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
