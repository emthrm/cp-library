---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/data_structure/union-find/weighted_union-find.hpp
    title: "\u91CD\u307F\u3064\u304D union-find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\
      \u30BF\u69CB\u9020/\u91CD\u307F\u3064\u304D union-find"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/data_structure/union-find/weighted_union-find.test.cpp\"\
    \n/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\
    \u69CB\u9020/\u91CD\u307F\u3064\u304D union-find\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\n */\n\
    \n#include <iostream>\n\n#line 1 \"include/emthrm/data_structure/union-find/weighted_union-find.hpp\"\
    \n\n\n\n#include <utility>\n#include <vector>\n\nnamespace emthrm {\n\ntemplate\
    \ <typename Abelian>\nstruct WeightedUnionFind {\n  explicit WeightedUnionFind(const\
    \ int n, const Abelian ID = 0)\n      : ID(ID), parent(n, -1), data(n, ID) {}\n\
    \n  int root(const int ver) {\n    if (parent[ver] < 0) return ver;\n    const\
    \ int r = root(parent[ver]);\n    data[ver] += data[parent[ver]];\n    return\
    \ parent[ver] = r;\n  }\n\n  bool unite(int u, int v, Abelian wt) {\n    wt +=\
    \ weight(u);\n    wt -= weight(v);\n    u = root(u);\n    v = root(v);\n    if\
    \ (u == v) return false;\n    if (parent[u] > parent[v]) {\n      std::swap(u,\
    \ v);\n      wt = -wt;\n    }\n    parent[u] += parent[v];\n    parent[v] = u;\n\
    \    data[v] = wt;\n    return true;\n  }\n\n  bool is_same(const int u, const\
    \ int v) { return root(u) == root(v); }\n\n  int size(const int ver) { return\
    \ -parent[root(ver)]; }\n\n  Abelian diff(const int u, const int v) { return weight(v)\
    \ - weight(u); }\n\n private:\n  const Abelian ID;\n  std::vector<int> parent;\n\
    \  std::vector<Abelian> data;\n\n  Abelian weight(const int ver) {\n    root(ver);\n\
    \    return data[ver];\n  }\n};\n\n}  // namespace emthrm\n\n\n#line 10 \"test/data_structure/union-find/weighted_union-find.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::WeightedUnionFind<int>\
    \ union_find(n);\n  while (q--) {\n    int query;\n    std::cin >> query;\n  \
    \  if (query == 0) {\n      int x, y, z;\n      std::cin >> x >> y >> z;\n   \
    \   union_find.unite(x, y, z);\n    } else if (query == 1) {\n      int x, y;\n\
    \      std::cin >> x >> y;\n      if (union_find.is_same(x, y)) {\n        std::cout\
    \ << union_find.diff(x, y) << '\\n';\n      } else {\n        std::cout << \"\
    ?\\n\";\n      }\n    }\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020/\u91CD\u307F\u3064\u304D union-find\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\n */\n\
    \n#include <iostream>\n\n#include \"emthrm/data_structure/union-find/weighted_union-find.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  emthrm::WeightedUnionFind<int>\
    \ union_find(n);\n  while (q--) {\n    int query;\n    std::cin >> query;\n  \
    \  if (query == 0) {\n      int x, y, z;\n      std::cin >> x >> y >> z;\n   \
    \   union_find.unite(x, y, z);\n    } else if (query == 1) {\n      int x, y;\n\
    \      std::cin >> x >> y;\n      if (union_find.is_same(x, y)) {\n        std::cout\
    \ << union_find.diff(x, y) << '\\n';\n      } else {\n        std::cout << \"\
    ?\\n\";\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/weighted_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/weighted_union-find.test.cpp
  requiredBy: []
  timestamp: '2023-02-26 01:10:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union-find/weighted_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/weighted_union-find.test.cpp
- /verify/test/data_structure/union-find/weighted_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
  /\u91CD\u307F\u3064\u304D union-find"
---
