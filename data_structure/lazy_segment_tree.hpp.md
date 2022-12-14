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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/lazy_segment_tree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n * @docs docs/data_structure/segment_tree.md\n */\n\n#pragma once\n#include\
    \ <algorithm>\n// #include <cassert>\n#include <limits>\n#include <vector>\n\n\
    template <typename T>\nstruct LazySegmentTree {\n  using Monoid = typename T::Monoid;\n\
    \  using OperatorMonoid = typename T::OperatorMonoid;\n\n  explicit LazySegmentTree(const\
    \ int n)\n      : LazySegmentTree(std::vector<Monoid>(n, T::m_id())) {}\n\n  explicit\
    \ LazySegmentTree(const std::vector<Monoid>& a)\n      : n(a.size()), height(0)\
    \ {\n    while ((1 << height) < n) ++height;\n    p2 = 1 << height;\n    lazy.assign(p2,\
    \ T::o_id());\n    data.assign(p2 << 1, T::m_id());\n    std::copy(a.begin(),\
    \ a.end(), data.begin() + p2);\n    for (int i = p2 - 1; i > 0; --i) {\n     \
    \ data[i] = T::m_merge(data[i << 1], data[(i << 1) + 1]);\n    }\n  }\n\n  void\
    \ set(int idx, const Monoid val) {\n    idx += p2;\n    for (int i = height; i\
    \ > 0; --i) {\n      propagate(idx >> i);\n    }\n    data[idx] = val;\n    for\
    \ (int i = 1; i <= height; ++i) {\n      const int current_idx = idx >> i;\n \
    \     data[current_idx] =\n          T::m_merge(data[current_idx << 1], data[(current_idx\
    \ << 1) + 1]);\n    }\n  }\n\n  void apply(int idx, const OperatorMonoid val)\
    \ {\n    idx += p2;\n    for (int i = height; i > 0; --i) {\n      propagate(idx\
    \ >> i);\n    }\n    data[idx] = T::apply(data[idx], val);\n    for (int i = 1;\
    \ i <= height; ++i) {\n      const int current_idx = idx >> i;\n      data[current_idx]\
    \ =\n          T::m_merge(data[current_idx << 1], data[(current_idx << 1) + 1]);\n\
    \    }\n  }\n\n  void apply(int left, int right, const OperatorMonoid val) {\n\
    \    if (right <= left) return;\n    left += p2;\n    right += p2;\n    const\
    \ int ctz_left = __builtin_ctz(left);\n    for (int i = height; i > ctz_left;\
    \ --i) {\n      propagate(left >> i);\n    }\n    const int ctz_right = __builtin_ctz(right);\n\
    \    for (int i = height; i > ctz_right; --i) {\n      propagate(right >> i);\n\
    \    }\n    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {\n      if\
    \ (l & 1) apply_sub(l++, val);\n      if (r & 1) apply_sub(--r, val);\n    }\n\
    \    for (int i = left >> (ctz_left + 1); i > 0; i >>= 1) {\n      data[i] = T::m_merge(data[i\
    \ << 1], data[(i << 1) + 1]);\n    }\n    for (int i = right >> (ctz_right + 1);\
    \ i > 0; i >>= 1) {\n      data[i] = T::m_merge(data[i << 1], data[(i << 1) +\
    \ 1]);\n    }\n  }\n\n  Monoid get(int left, int right) {\n    if (right <= left)\
    \ return T::m_id();\n    left += p2;\n    right += p2;\n    const int ctz_left\
    \ = __builtin_ctz(left);\n    for (int i = height; i > ctz_left; --i) {\n    \
    \  propagate(left >> i);\n    }\n    const int ctz_right = __builtin_ctz(right);\n\
    \    for (int i = height; i > ctz_right; --i) {\n      propagate(right >> i);\n\
    \    }\n    Monoid res_l = T::m_id(), res_r = T::m_id();\n    for (; left < right;\
    \ left >>= 1, right >>= 1) {\n      if (left & 1) res_l = T::m_merge(res_l, data[left++]);\n\
    \      if (right & 1) res_r = T::m_merge(data[--right], res_r);\n    }\n    return\
    \ T::m_merge(res_l, res_r);\n  }\n\n  Monoid operator[](const int idx) {\n   \
    \ const int node = idx + p2;\n    for (int i = height; i > 0; --i) {\n      propagate(node\
    \ >> i);\n    }\n    return data[node];\n  }\n\n  template <typename G>\n  int\
    \ find_right(int left, const G g) {\n    if (left >= n) return n;\n    left +=\
    \ p2;\n    for (int i = height; i > 0; --i) {\n      propagate(left >> i);\n \
    \   }\n    Monoid val = T::m_id();\n    do {\n      while (!(left & 1)) left >>=\
    \ 1;\n      Monoid nxt = T::m_merge(val, data[left]);\n      if (!g(nxt)) {\n\
    \        while (left < p2) {\n          propagate(left);\n          left <<= 1;\n\
    \          nxt = T::m_merge(val, data[left]);\n          if (g(nxt)) {\n     \
    \       val = nxt;\n            ++left;\n          }\n        }\n        return\
    \ left - p2;\n      }\n      val = nxt;\n      ++left;\n    } while (__builtin_popcount(left)\
    \ > 1);\n    return n;\n  }\n\n  template <typename G>\n  int find_left(int right,\
    \ const G g) {\n    if (right <= 0) return -1;\n    right += p2;\n    for (int\
    \ i = height; i > 0; --i) {\n      propagate((right - 1) >> i);\n    }\n    Monoid\
    \ val = T::m_id();\n    do {\n      --right;\n      while (right > 1 && (right\
    \ & 1)) right >>= 1;\n      Monoid nxt = T::m_merge(data[right], val);\n     \
    \ if (!g(nxt)) {\n        while (right < p2) {\n          propagate(right);\n\
    \          right = (right << 1) + 1;\n          nxt = T::m_merge(data[right],\
    \ val);\n          if (g(nxt)) {\n            val = nxt;\n            --right;\n\
    \          }\n        }\n        return right - p2;\n      }\n      val = nxt;\n\
    \    } while (__builtin_popcount(right) > 1);\n    return -1;\n  }\n\n private:\n\
    \  const int n;\n  int p2, height;\n  std::vector<Monoid> data;\n  std::vector<OperatorMonoid>\
    \ lazy;\n\n  void apply_sub(const int idx, const OperatorMonoid& val) {\n    data[idx]\
    \ = T::apply(data[idx], val);\n    if (idx < p2) lazy[idx] = T::o_merge(lazy[idx],\
    \ val);\n  }\n\n  void propagate(const int idx) {\n    // assert(1 <= idx && idx\
    \ < p2);\n    apply_sub(idx << 1, lazy[idx]);\n    apply_sub((idx << 1) + 1, lazy[idx]);\n\
    \    lazy[idx] = T::o_id();\n  }\n};\n\nnamespace monoid {\n\ntemplate <typename\
    \ T>\nstruct RangeMinimumAndUpdateQuery {\n  using Monoid = T;\n  using OperatorMonoid\
    \ = T;\n  static constexpr Monoid m_id() { return std::numeric_limits<Monoid>::max();\
    \ }\n  static constexpr OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::max();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ std::min(a, b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                const OperatorMonoid& b) {\n    return b\
    \ == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return b == o_id() ? a : b;\n  }\n};\n\ntemplate <typename T>\nstruct\
    \ RangeMaximumAndUpdateQuery {\n  using Monoid = T;\n  using OperatorMonoid =\
    \ T;\n  static constexpr Monoid m_id() {\n    return std::numeric_limits<Monoid>::lowest();\n\
    \  }\n  static constexpr OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::lowest();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ std::max(a, b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid&\
    \ a,\n                                const OperatorMonoid& b) {\n    return b\
    \ == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return b == o_id()? a : b;\n  }\n};\n\ntemplate <typename T, T Inf>\n\
    struct RangeMinimumAndAddQuery {\n  using Monoid = T;\n  using OperatorMonoid\
    \ = T;\n  static constexpr Monoid m_id() { return Inf; }\n  static constexpr OperatorMonoid\
    \ o_id() { return 0; }\n  static Monoid m_merge(const Monoid& a, const Monoid&\
    \ b) {\n    return std::min(a, b);\n  }\n  static OperatorMonoid o_merge(const\
    \ OperatorMonoid& a,\n                                const OperatorMonoid& b)\
    \ {\n    return a + b;\n  }\n  static Monoid apply(const Monoid& a, const OperatorMonoid&\
    \ b) {\n    return a + b;\n  }\n};\n\ntemplate <typename T, T Inf>\nstruct RangeMaximumAndAddQuery\
    \ {\n  using Monoid = T;\n  using OperatorMonoid = T;\n  static constexpr Monoid\
    \ m_id() { return -Inf; }\n  static constexpr OperatorMonoid o_id() { return 0;\
    \ }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return std::max(a,\
    \ b);\n  }\n  static OperatorMonoid o_merge(const OperatorMonoid& a,\n       \
    \                         const OperatorMonoid& b) {\n    return a + b;\n  }\n\
    \  static Monoid apply(const Monoid& a, const OperatorMonoid& b) {\n    return\
    \ a + b;\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumAndUpdateQuery {\n\
    \  using Monoid = struct { T sum; int len; };\n  using OperatorMonoid = T;\n \
    \ static std::vector<Monoid> init(const int n) {\n    return std::vector<Monoid>(n,\
    \ Monoid{0, 1});\n  }\n  static constexpr Monoid m_id() { return {0, 0}; }\n \
    \ static constexpr OperatorMonoid o_id() {\n    return std::numeric_limits<OperatorMonoid>::max();\n\
    \  }\n  static Monoid m_merge(const Monoid& a, const Monoid& b) {\n    return\
    \ Monoid{a.sum + b.sum, a.len + b.len};\n  }\n  static OperatorMonoid o_merge(const\
    \ OperatorMonoid& a,\n                                const OperatorMonoid& b)\
    \ {\n    return b == o_id() ? a : b;\n  }\n  static Monoid apply(const Monoid&\
    \ a, const OperatorMonoid& b) {\n    return Monoid{b == o_id() ? a.sum : b * a.len,\
    \ a.len};\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumAndAddQuery {\n  using\
    \ Monoid = struct { T sum; int len; };\n  using OperatorMonoid = T;\n  static\
    \ std::vector<Monoid> init(const int n) {\n    return std::vector<Monoid>(n, Monoid{0,\
    \ 1});\n  }\n  static constexpr Monoid m_id() { return {0, 0}; }\n  static constexpr\
    \ OperatorMonoid o_id() { return 0; }\n  static Monoid m_merge(const Monoid& a,\
    \ const Monoid& b) {\n    return Monoid{a.sum + b.sum, a.len + b.len};\n  }\n\
    \  static OperatorMonoid o_merge(const OperatorMonoid& a,\n                  \
    \              const OperatorMonoid& b) {\n    return a + b;\n  }\n  static Monoid\
    \ apply(const Monoid& a, const OperatorMonoid& b) {\n    return Monoid{a.sum +\
    \ b * a.len, a.len};\n  }\n};\n\n}  // namespace monoid\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/lazy_segment_tree.hpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_minimum_query_and_range_add_query.test.cpp
  - test/data_structure/lazy_segment_tree.test.cpp
  - test/data_structure/range_sum_query_and_range_add_query.test.cpp
  - test/data_structure/range_sum_query_and_range_update_query.test.cpp
  - test/data_structure/range_minimum_query_and_range_update_query.test.cpp
  - test/graph/tree/lowest_common_ancestor_by_euler_tour.test.cpp
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
  - https://mugen1337.github.io/procon/DataStructure/BinaryTrieMonoid.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/dynamic_segment_tree.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/dynamic_lazy_segment_tree.cpp
  - https://www.hamayanhamayan.com/entry/2019/02/09/103140
  - https://twitter.com/noshi91/status/1338881669525172224
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
    - https://mugen1337.github.io/procon/DataStructure/RangeTree.cpp
    - https://sotanishy.github.io/cp-library-cpp/data-structure/range_tree.cpp
    - https://yukicoder.me/problems/no/1625
  - 四分木 (quadtree)
    - https://ja.wikipedia.org/wiki/%E5%9B%9B%E5%88%86%E6%9C%A8
    - https://sotanishy.github.io/cp-library-cpp/data-structure/quadtree.cpp
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
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/persistent_segment_tree.cpp
- segment tree Beats
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
  - https://mugen1337.github.io/procon/SegmentTree/SegmentTreeBeats.cpp
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/segment_tree_beats.cpp
  - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  - https://onlinejudge.u-aizu.ac.jp/problems/0427
  - https://atcoder.jp/contests/abc256/tasks/abc256_h
- 双対セグメント木
  - https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/
  - https://ei1333.github.io/luzhiled/snippets/structure/segment-tree.html
  - https://sotanishy.github.io/cp-library-cpp/data-structure/segtree/dual_segment_tree.cpp
  - https://judge.yosupo.jp/problem/range_affine_point_get
- 区間等差数列加算クエリ / 区間等差数列更新クエリ
  - https://null-mn.hatenablog.com/entry/2021/08/22/064325
  - https://twitter.com/yosupot/status/1104175527923986432
  - https://twitter.com/kuma_program/status/1358762477589155840
- $A_{l \oplus x} A_{(l + 1) \oplus x} \cdots A_{(r - 1) \oplus x}$
  - https://codeforces.com/contest/1401/problem/F
  - https://codeforces.com/contest/1654/problem/F
  - https://twitter.com/SSRS_cp/status/1505543549601054720
  - https://yukicoder.me/problems/no/1891
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
