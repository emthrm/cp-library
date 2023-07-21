---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/partially_persistent_union-find.hpp
    title: "\u90E8\u5206\u6C38\u7D9A union-find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/agc002/tasks/agc002_d
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\
      \u30BF\u69CB\u9020/\u90E8\u5206\u6C38\u7D9A union-find"
    links:
    - https://atcoder.jp/contests/agc002/tasks/agc002_d
  bundledCode: "#line 1 \"test/data_structure/union-find/partially_persistent_union-find.test.cpp\"\
    \n/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\
    \u69CB\u9020/\u90E8\u5206\u6C38\u7D9A union-find\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/agc002/tasks/agc002_d\n\
    \ */\n\n#include <iostream>\n#include <numeric>\n\n#line 1 \"include/emthrm/data_structure/union-find/partially_persistent_union-find.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <iterator>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace emthrm {\n\nstruct PartiallyPersistentUnionFind {\n  explicit\
    \ PartiallyPersistentUnionFind(const int n)\n      : data(n, -1), last(n, -1),\
    \ history(n, {{-1, -1}}) {}\n\n  int root(const int t, const int ver) const {\n\
    \    return last[ver] == -1 || t < last[ver] ? ver : root(t, data[ver]);\n  }\n\
    \n  bool unite(const int t, int u, int v) {\n    u = root(t, u);\n    v = root(t,\
    \ v);\n    if (u == v) return false;\n    if (data[u] > data[v]) std::swap(u,\
    \ v);\n    data[u] += data[v];\n    data[v] = u;\n    last[v] = t;\n    history[u].emplace_back(t,\
    \ data[u]);\n    return true;\n  }\n\n  bool is_same(const int t, const int u,\
    \ const int v) const {\n    return root(t, u) == root(t, v);\n  }\n\n  int size(const\
    \ int t, int ver) const {\n    ver = root(t, ver);\n    return -std::prev(std::lower_bound(history[ver].begin(),\n\
    \                                       history[ver].end(),\n                \
    \                       std::make_pair(t, 0)))->second;\n  }\n\n private:\n  std::vector<int>\
    \ data, last;\n  std::vector<std::vector<std::pair<int, int>>> history;\n};\n\n\
    }  // namespace emthrm\n\n\n#line 12 \"test/data_structure/union-find/partially_persistent_union-find.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  emthrm::PartiallyPersistentUnionFind\
    \ union_find(n);\n  for (int i = 1; i <= m; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    --a; --b;\n    union_find.unite(i, a, b);\n  }\n  int q;\n \
    \ std::cin >> q;\n  while (q--) {\n    int x, y, z;\n    std::cin >> x >> y >>\
    \ z;\n    --x; --y;\n    int lb = 0, ub = m;\n    while (ub - lb > 1) {\n    \
    \  const int mid = std::midpoint(lb, ub);\n      (union_find.size(mid, x) + (union_find.is_same(mid,\
    \ x, y) ?\n       0 : union_find.size(mid, y)) >= z ? ub : lb) = mid;\n    }\n\
    \    std::cout << lb + 1 << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020/\u90E8\u5206\u6C38\u7D9A union-find\n *\n * verification-helper:\
    \ IGNORE\n * verification-helper: PROBLEM https://atcoder.jp/contests/agc002/tasks/agc002_d\n\
    \ */\n\n#include <iostream>\n#include <numeric>\n\n#include \"emthrm/data_structure/union-find/partially_persistent_union-find.hpp\"\
    \n\nint main() {\n  int n, m;\n  std::cin >> n >> m;\n  emthrm::PartiallyPersistentUnionFind\
    \ union_find(n);\n  for (int i = 1; i <= m; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    --a; --b;\n    union_find.unite(i, a, b);\n  }\n  int q;\n \
    \ std::cin >> q;\n  while (q--) {\n    int x, y, z;\n    std::cin >> x >> y >>\
    \ z;\n    --x; --y;\n    int lb = 0, ub = m;\n    while (ub - lb > 1) {\n    \
    \  const int mid = std::midpoint(lb, ub);\n      (union_find.size(mid, x) + (union_find.is_same(mid,\
    \ x, y) ?\n       0 : union_find.size(mid, y)) >= z ? ub : lb) = mid;\n    }\n\
    \    std::cout << lb + 1 << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/partially_persistent_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/partially_persistent_union-find.test.cpp
  requiredBy: []
  timestamp: '2023-07-21 12:14:05+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/data_structure/union-find/partially_persistent_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/partially_persistent_union-find.test.cpp
- /verify/test/data_structure/union-find/partially_persistent_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
  /\u90E8\u5206\u6C38\u7D9A union-find"
---
