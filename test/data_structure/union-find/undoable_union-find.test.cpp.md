---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/data_structure/union-find/undoable_union-find.hpp
    title: "undo \u53EF\u80FD union-find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    IGNORE: ''
    PROBLEM: https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\
      \u30BF\u69CB\u9020/undo \u53EF\u80FD union-find"
    links:
    - https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e
  bundledCode: "#line 1 \"test/data_structure/union-find/undoable_union-find.test.cpp\"\
    \n/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\
    \u69CB\u9020/undo \u53EF\u80FD union-find\n *\n * verification-helper: IGNORE\n\
    \ * verification-helper: PROBLEM https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <utility>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/data_structure/union-find/undoable_union-find.hpp\"\
    \n\n\n\n#line 6 \"include/emthrm/data_structure/union-find/undoable_union-find.hpp\"\
    \n\nnamespace emthrm {\n\nstruct UndoableUnionFind {\n  explicit UndoableUnionFind(const\
    \ int n) : data(n, -1) {}\n\n  int root(const int ver) const {\n    return data[ver]\
    \ < 0 ? ver : root(data[ver]);\n  }\n\n  bool unite(int u, int v) {\n    u = root(u);\n\
    \    history.emplace_back(u, data[u]);\n    v = root(v);\n    history.emplace_back(v,\
    \ data[v]);\n    if (u == v) return false;\n    if (data[u] > data[v]) std::swap(u,\
    \ v);\n    data[u] += data[v];\n    data[v] = u;\n    return true;\n  }\n\n  bool\
    \ is_same(const int u, const int v) const { return root(u) == root(v); }\n\n \
    \ int size(const int ver) const { return -data[root(ver)]; }\n\n  void undo()\
    \ {\n    for (int i = 0; i < 2; ++i) {\n      data[history.back().first] = history.back().second;\n\
    \      history.pop_back();\n    }\n  }\n\n  void snapshot() { history.clear();\
    \ }\n\n  void rollback() {\n    while (!history.empty()) undo();\n  }\n\n private:\n\
    \  std::vector<int> data;\n  std::vector<std::pair<int, int>> history;\n};\n\n\
    }  // namespace emthrm\n\n\n#line 15 \"test/data_structure/union-find/undoable_union-find.test.cpp\"\
    \n\nint main() {\n  int n, m, k;\n  std::cin >> n >> m >> k;\n  std::vector<int>\
    \ u(m), v(m), s(n);\n  for (int i = 0; i < m; ++i) {\n    std::cin >> u[i] >>\
    \ v[i];\n    --u[i]; --v[i];\n  }\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> s[i];\n    --s[i];\n  }\n  emthrm::UndoableUnionFind union_find(n);\n  std::map<std::pair<int,\
    \ int>, std::vector<int>> edges;\n  for (int i = 0; i < m; ++i) {\n    if (s[u[i]]\
    \ == s[v[i]]) {\n      union_find.unite(u[i], v[i]);\n    } else {\n      edges[std::minmax(s[u[i]],\
    \ s[v[i]])].emplace_back(i);\n    }\n  }\n  union_find.snapshot();\n  int q;\n\
    \  std::cin >> q;\n  std::map<std::pair<int, int>, std::vector<int>> queries;\n\
    \  std::vector<int> a(q), b(q);\n  for (int i = 0; i < q; ++i) {\n    std::cin\
    \ >> a[i] >> b[i];\n    --a[i]; --b[i];\n    queries[std::minmax(s[a[i]], s[b[i]])].emplace_back(i);\n\
    \  }\n  std::vector<int> ans(q);\n  for (const auto& sasb_query : queries) {\n\
    \    if (const auto it = edges.find(sasb_query.first); it != edges.end()) {\n\
    \      for (const int id : it->second) {\n        union_find.unite(u[id], v[id]);\n\
    \      }\n    }\n    for (const int id : sasb_query.second) {\n      ans[id] =\
    \ union_find.is_same(a[id], b[id]);\n    }\n    union_find.rollback();\n  }\n\
    \  for (int i = 0; i < q; ++i) {\n    std::cout << ans[i] << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020/undo \u53EF\u80FD union-find\n *\n * verification-helper: IGNORE\n\
    \ * verification-helper: PROBLEM https://atcoder.jp/contests/joi2022yo2/tasks/joi2022_yo2_e\n\
    \ */\n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <utility>\n\
    #include <vector>\n\n#include \"emthrm/data_structure/union-find/undoable_union-find.hpp\"\
    \n\nint main() {\n  int n, m, k;\n  std::cin >> n >> m >> k;\n  std::vector<int>\
    \ u(m), v(m), s(n);\n  for (int i = 0; i < m; ++i) {\n    std::cin >> u[i] >>\
    \ v[i];\n    --u[i]; --v[i];\n  }\n  for (int i = 0; i < n; ++i) {\n    std::cin\
    \ >> s[i];\n    --s[i];\n  }\n  emthrm::UndoableUnionFind union_find(n);\n  std::map<std::pair<int,\
    \ int>, std::vector<int>> edges;\n  for (int i = 0; i < m; ++i) {\n    if (s[u[i]]\
    \ == s[v[i]]) {\n      union_find.unite(u[i], v[i]);\n    } else {\n      edges[std::minmax(s[u[i]],\
    \ s[v[i]])].emplace_back(i);\n    }\n  }\n  union_find.snapshot();\n  int q;\n\
    \  std::cin >> q;\n  std::map<std::pair<int, int>, std::vector<int>> queries;\n\
    \  std::vector<int> a(q), b(q);\n  for (int i = 0; i < q; ++i) {\n    std::cin\
    \ >> a[i] >> b[i];\n    --a[i]; --b[i];\n    queries[std::minmax(s[a[i]], s[b[i]])].emplace_back(i);\n\
    \  }\n  std::vector<int> ans(q);\n  for (const auto& sasb_query : queries) {\n\
    \    if (const auto it = edges.find(sasb_query.first); it != edges.end()) {\n\
    \      for (const int id : it->second) {\n        union_find.unite(u[id], v[id]);\n\
    \      }\n    }\n    for (const int id : sasb_query.second) {\n      ans[id] =\
    \ union_find.is_same(a[id], b[id]);\n    }\n    union_find.rollback();\n  }\n\
    \  for (int i = 0; i < q; ++i) {\n    std::cout << ans[i] << '\\n';\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/data_structure/union-find/undoable_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/undoable_union-find.test.cpp
  requiredBy: []
  timestamp: '2023-02-26 01:10:01+09:00'
  verificationStatus: TEST_WAITING_JUDGE
  verifiedWith: []
documentation_of: test/data_structure/union-find/undoable_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp
- /verify/test/data_structure/union-find/undoable_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
  /undo \u53EF\u80FD union-find"
---
