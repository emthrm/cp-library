---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
    title: Fenwick tree (binary indexed tree)
  - icon: ':heavy_check_mark:'
    path: include/emthrm/misc/mo.hpp
    title: Mo's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    document_title: "\u305D\u306E\u4ED6/Mo's algorithm"
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/misc/mo.test.cpp\"\n/*\n * @title \u305D\u306E\u4ED6\
    /Mo's algorithm\n *\n * verification-helper: PROBLEM https://judge.yosupo.jp/problem/static_range_inversions_query\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <iterator>\n#include\
    \ <vector>\n\n#line 1 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\n\n\n#include <bit>\n#line 6 \"include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename Abelian>\nstruct FenwickTree {\n\
    \  explicit FenwickTree(const int n, const Abelian ID = 0)\n      : n(n), ID(ID),\
    \ data(n, ID) {}\n\n  void add(int idx, const Abelian val) {\n    for (; idx <\
    \ n; idx |= idx + 1) {\n      data[idx] += val;\n    }\n  }\n\n  Abelian sum(int\
    \ idx) const {\n    Abelian res = ID;\n    for (--idx; idx >= 0; idx = (idx &\
    \ (idx + 1)) - 1) {\n      res += data[idx];\n    }\n    return res;\n  }\n\n\
    \  Abelian sum(const int left, const int right) const {\n    return left < right\
    \ ? sum(right) - sum(left) : ID;\n  }\n\n  Abelian operator[](const int idx) const\
    \ { return sum(idx, idx + 1); }\n\n  int lower_bound(Abelian val) const {\n  \
    \  if (val <= ID) [[unlikely]] return 0;\n    int res = 0;\n    for (int mask\
    \ = std::bit_ceil(static_cast<unsigned int>(n + 1)) >> 1;\n         mask > 0;\
    \ mask >>= 1) {\n      const int idx = res + mask - 1;\n      if (idx < n && data[idx]\
    \ < val) {\n        val -= data[idx];\n        res += mask;\n      }\n    }\n\
    \    return res;\n  }\n\n private:\n  const int n;\n  const Abelian ID;\n  std::vector<Abelian>\
    \ data;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/misc/mo.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/misc/mo.hpp\"\n#include <cmath>\n#include <numeric>\n\
    #line 8 \"include/emthrm/misc/mo.hpp\"\n\nnamespace emthrm {\n\nstruct Mo {\n\
    \  explicit Mo(const std::vector<int>& ls, const std::vector<int>& rs)\n     \
    \ : n(ls.size()), ptr(0), nl(0), nr(0), ls(ls), rs(rs) {\n    const int width\
    \ = std::round(std::sqrt(n));\n    order.resize(n);\n    std::iota(order.begin(),\
    \ order.end(), 0);\n    std::sort(order.begin(), order.end(),\n              [&ls,\
    \ &rs, width](const int a, const int b) -> bool {\n                  if (ls[a]\
    \ / width != ls[b] / width) return ls[a] < ls[b];\n                  return (ls[a]\
    \ / width) & 1 ? rs[a] < rs[b] : rs[a] > rs[b];\n              });\n  }\n\n  int\
    \ process() {\n    if (ptr == n) [[unlikely]] return -1;\n    const int id = order[ptr++];\n\
    \    while (ls[id] < nl) add(--nl);\n    while (nr < rs[id]) add(nr++);\n    while\
    \ (nl < ls[id]) del(nl++);\n    while (rs[id] < nr) del(--nr);\n    return id;\n\
    \  }\n\n  void add(const int idx) const;\n\n  void del(const int idx) const;\n\
    \n private:\n  const int n;\n  int ptr, nl, nr;\n  std::vector<int> ls, rs, order;\n\
    };\n\n}  // namespace emthrm\n\n\n#line 14 \"test/misc/mo.test.cpp\"\n\nstd::vector<int>\
    \ a;\nlong long inv = 0;\nint l = 0, r = 0, m;\nconstexpr int M = 100000;\nemthrm::FenwickTree<int>\
    \ bit(M);\n\nvoid emthrm::Mo::add(const int idx) const {\n  if (idx + 1 == l)\
    \ {\n    inv += bit.sum(0, a[idx]);\n    --l;\n  } else if (idx == r) {\n    inv\
    \ += bit.sum(a[idx] + 1, m);\n    ++r;\n  }\n  bit.add(a[idx], 1);\n}\n\nvoid\
    \ emthrm::Mo::del(const int idx) const {\n  if (idx == l) {\n    inv -= bit.sum(0,\
    \ a[idx]);\n    ++l;\n  } else if (idx + 1 == r) {\n    inv -= bit.sum(a[idx]\
    \ + 1, m);\n    --r;\n  }\n  bit.add(a[idx], -1);\n}\n\nint main() {\n  int n,\
    \ q;\n  std::cin >> n >> q;\n  a.resize(n);\n  for (int i = 0; i < n; ++i) {\n\
    \    std::cin >> a[i];\n  }\n  std::vector<int> tmp = a;\n  std::sort(tmp.begin(),\
    \ tmp.end());\n  tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());\n\
    \  m = tmp.size();\n  for (int i = 0; i < n; ++i) {\n    a[i] = std::distance(tmp.begin(),\n\
    \                         std::lower_bound(tmp.begin(), tmp.end(), a[i]));\n \
    \ }\n  std::vector<int> ls(q), rs(q);\n  for (int i = 0; i < q; ++i) {\n    std::cin\
    \ >> ls[i] >> rs[i];\n  }\n  emthrm::Mo mo(ls, rs);\n  std::vector<long long>\
    \ ans(q);\n  for (int i = 0; i < q; ++i) {\n    const int idx = mo.process();\n\
    \    ans[idx] = inv;\n  }\n  for (int i = 0; i < q; ++i) {\n    std::cout << ans[i]\
    \ << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u305D\u306E\u4ED6/Mo's algorithm\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/static_range_inversions_query\n */\n\
    \n#include <algorithm>\n#include <iostream>\n#include <iterator>\n#include <vector>\n\
    \n#include \"emthrm/data_structure/fenwick_tree/fenwick_tree.hpp\"\n#include \"\
    emthrm/misc/mo.hpp\"\n\nstd::vector<int> a;\nlong long inv = 0;\nint l = 0, r\
    \ = 0, m;\nconstexpr int M = 100000;\nemthrm::FenwickTree<int> bit(M);\n\nvoid\
    \ emthrm::Mo::add(const int idx) const {\n  if (idx + 1 == l) {\n    inv += bit.sum(0,\
    \ a[idx]);\n    --l;\n  } else if (idx == r) {\n    inv += bit.sum(a[idx] + 1,\
    \ m);\n    ++r;\n  }\n  bit.add(a[idx], 1);\n}\n\nvoid emthrm::Mo::del(const int\
    \ idx) const {\n  if (idx == l) {\n    inv -= bit.sum(0, a[idx]);\n    ++l;\n\
    \  } else if (idx + 1 == r) {\n    inv -= bit.sum(a[idx] + 1, m);\n    --r;\n\
    \  }\n  bit.add(a[idx], -1);\n}\n\nint main() {\n  int n, q;\n  std::cin >> n\
    \ >> q;\n  a.resize(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n\
    \  }\n  std::vector<int> tmp = a;\n  std::sort(tmp.begin(), tmp.end());\n  tmp.erase(std::unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\n  m = tmp.size();\n  for (int i = 0; i < n; ++i) {\n\
    \    a[i] = std::distance(tmp.begin(),\n                         std::lower_bound(tmp.begin(),\
    \ tmp.end(), a[i]));\n  }\n  std::vector<int> ls(q), rs(q);\n  for (int i = 0;\
    \ i < q; ++i) {\n    std::cin >> ls[i] >> rs[i];\n  }\n  emthrm::Mo mo(ls, rs);\n\
    \  std::vector<long long> ans(q);\n  for (int i = 0; i < q; ++i) {\n    const\
    \ int idx = mo.process();\n    ans[idx] = inv;\n  }\n  for (int i = 0; i < q;\
    \ ++i) {\n    std::cout << ans[i] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/fenwick_tree/fenwick_tree.hpp
  - include/emthrm/misc/mo.hpp
  isVerificationFile: true
  path: test/misc/mo.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/mo.test.cpp
layout: document
redirect_from:
- /verify/test/misc/mo.test.cpp
- /verify/test/misc/mo.test.cpp.html
title: "\u305D\u306E\u4ED6/Mo's algorithm"
---
