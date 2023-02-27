---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/segment_tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (segment tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728 (range sum query)"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/data_structure/range_sum_query.test.cpp\"\n/*\n * @title\
    \ \u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (range sum\
    \ query)\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\n\
    \ */\n\n#include <iostream>\n\n#line 1 \"include/emthrm/data_structure/segment_tree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <bit>\n#include <limits>\n#include <vector>\n\
    \nnamespace emthrm {\n\ntemplate <typename T>\nstruct SegmentTree {\n  using Monoid\
    \ = typename T::Monoid;\n\n  explicit SegmentTree(const int n)\n      : SegmentTree(std::vector<Monoid>(n,\
    \ T::id())) {}\n\n  explicit SegmentTree(const std::vector<Monoid>& a)\n     \
    \ : n(a.size()), p2(std::bit_ceil(a.size())) {\n    dat.assign(p2 << 1, T::id());\n\
    \    std::copy(a.begin(), a.end(), dat.begin() + p2);\n    for (int i = p2 - 1;\
    \ i > 0; --i) {\n      dat[i] = T::merge(dat[i << 1], dat[(i << 1) + 1]);\n  \
    \  }\n  }\n\n  void set(int idx, const Monoid val) {\n    idx += p2;\n    dat[idx]\
    \ = val;\n    while (idx >>= 1) dat[idx] = T::merge(dat[idx << 1], dat[(idx <<\
    \ 1) + 1]);\n  }\n\n  Monoid get(int left, int right) const {\n    Monoid res_l\
    \ = T::id(), res_r = T::id();\n    for (left += p2, right += p2; left < right;\
    \ left >>= 1, right >>= 1) {\n      if (left & 1) res_l = T::merge(res_l, dat[left++]);\n\
    \      if (right & 1) res_r = T::merge(dat[--right], res_r);\n    }\n    return\
    \ T::merge(res_l, res_r);\n  }\n\n  Monoid operator[](const int idx) const { return\
    \ dat[idx + p2]; }\n\n  template <typename G>\n  int find_right(int left, const\
    \ G g) {\n    if (left >= n) [[unlikely]] return n;\n    Monoid val = T::id();\n\
    \    left += p2;\n    do {\n      while (!(left & 1)) left >>= 1;\n      Monoid\
    \ nxt = T::merge(val, dat[left]);\n      if (!g(nxt)) {\n        while (left <\
    \ p2) {\n          left <<= 1;\n          nxt = T::merge(val, dat[left]);\n  \
    \        if (g(nxt)) {\n            val = nxt;\n            ++left;\n        \
    \  }\n        }\n        return left - p2;\n      }\n      val = nxt;\n      ++left;\n\
    \    } while (!std::has_single_bit(static_cast<unsigned int>(left)));\n    return\
    \ n;\n  }\n\n  template <typename G>\n  int find_left(int right, const G g) {\n\
    \    if (right <= 0) [[unlikely]] return -1;\n    Monoid val = T::id();\n    right\
    \ += p2;\n    do {\n      --right;\n      while (right > 1 && (right & 1)) right\
    \ >>= 1;\n      Monoid nxt = T::merge(dat[right], val);\n      if (!g(nxt)) {\n\
    \        while (right < p2) {\n          right = (right << 1) + 1;\n         \
    \ nxt = T::merge(dat[right], val);\n          if (g(nxt)) {\n            val =\
    \ nxt;\n            --right;\n          }\n        }\n        return right - p2;\n\
    \      }\n      val = nxt;\n    } while (!std::has_single_bit(static_cast<unsigned\
    \ int>(right)));\n    return -1;\n  }\n\n private:\n  const int n, p2;\n  std::vector<Monoid>\
    \ dat;\n};\n\nnamespace monoid {\n\ntemplate <typename T>\nstruct RangeMinimumQuery\
    \ {\n  using Monoid = T;\n  static constexpr Monoid id() { return std::numeric_limits<Monoid>::max();\
    \ }\n  static Monoid merge(const Monoid& a, const Monoid& b) {\n    return std::min(a,\
    \ b);\n  }\n};\n\ntemplate <typename T>\nstruct RangeMaximumQuery {\n  using Monoid\
    \ = T;\n  static constexpr Monoid id() { return std::numeric_limits<Monoid>::lowest();\
    \ }\n  static Monoid merge(const Monoid& a, const Monoid& b) {\n    return std::max(a,\
    \ b);\n  }\n};\n\ntemplate <typename T>\nstruct RangeSumQuery {\n  using Monoid\
    \ = T;\n  static constexpr Monoid id() { return 0; }\n  static Monoid merge(const\
    \ Monoid& a, const Monoid& b) { return a + b; }\n};\n\n}  // namespace monoid\n\
    \n}  // namespace emthrm\n\n\n#line 10 \"test/data_structure/range_sum_query.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::SegmentTree<emthrm::monoid::RangeSumQuery<long\
    \ long>> seg(n);\n  while (q--) {\n    int com, x, y;\n    std::cin >> com >>\
    \ x >> y; --x;\n    if (com == 0) {\n      seg.set(x, seg[x] + y);\n    } else\
    \ {\n      --y;\n      std::cout << seg.get(x, y + 1) << '\\n';\n    }\n  }\n\
    \  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728 (range sum query)\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\n\
    \ */\n\n#include <iostream>\n\n#include \"emthrm/data_structure/segment_tree.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::SegmentTree<emthrm::monoid::RangeSumQuery<long\
    \ long>> seg(n);\n  while (q--) {\n    int com, x, y;\n    std::cin >> com >>\
    \ x >> y; --x;\n    if (com == 0) {\n      seg.set(x, seg[x] + y);\n    } else\
    \ {\n      --y;\n      std::cout << seg.get(x, y + 1) << '\\n';\n    }\n  }\n\
    \  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/segment_tree.hpp
  isVerificationFile: true
  path: test/data_structure/range_sum_query.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_sum_query.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_sum_query.test.cpp
- /verify/test/data_structure/range_sum_query.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (range\
  \ sum query)"
---
