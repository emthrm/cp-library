---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/graph/light/tree/hld.2.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\r\n\r\n\
    #include <iostream>\r\n#include <vector>\r\n#line 2 \"graph/light/tree/hld.hpp\"\
    \n#include <algorithm>\r\n#include <utility>\r\n#line 5 \"graph/light/tree/hld.hpp\"\
    \n\r\nstruct HLD {\r\n  std::vector<int> parent, subtree, id, inv, head;\r\n\r\
    \n  HLD(const std::vector<std::vector<int>> &graph, int root = 0) : graph(graph)\
    \ {\r\n    int n = graph.size();\r\n    parent.assign(n, -1);\r\n    subtree.assign(n,\
    \ 1);\r\n    id.resize(n);\r\n    inv.resize(n);\r\n    head.resize(n);\r\n  \
    \  dfs1(root);\r\n    head[root] = root;\r\n    int now_id = 0;\r\n    dfs2(root,\
    \ now_id);\r\n  }\r\n\r\n  template <typename Fn>\r\n  void v_update(int u, int\
    \ v, Fn f) const {\r\n    while (true) {\r\n      if (id[u] > id[v]) std::swap(u,\
    \ v);\r\n      f(std::max(id[head[v]], id[u]), id[v] + 1);\r\n      if (head[u]\
    \ == head[v]) return;\r\n      v = parent[head[v]];\r\n    }\r\n  }\r\n\r\n  template\
    \ <typename T, typename F, typename G>\r\n  T v_query(int u, int v, F f, G g,\
    \ const T ID) const {\r\n    T left = ID, right = ID;\r\n    while (true) {\r\n\
    \      if (id[u] > id[v]) {\r\n        std::swap(u, v);\r\n        std::swap(left,\
    \ right);\r\n      }\r\n      left = g(left, f(std::max(id[head[v]], id[u]), id[v]\
    \ + 1));\r\n      if (head[u] == head[v]) break;\r\n      v = parent[head[v]];\r\
    \n    }\r\n    return g(left, right);\r\n  }\r\n\r\n  template <typename Fn>\r\
    \n  void subtree_v_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver]);\
    \ }\r\n\r\n  template <typename T, typename Fn>\r\n  T subtree_v_query(int ver,\
    \ Fn f) const { return f(id[ver], id[ver] + subtree[ver]); }\r\n\r\n  template\
    \ <typename Fn>\r\n  void e_update(int u, int v, Fn f) const {\r\n    while (true)\
    \ {\r\n      if (id[u] > id[v]) std::swap(u, v);\r\n      if (head[u] == head[v])\
    \ {\r\n        f(id[u], id[v]);\r\n        break;\r\n      } else {\r\n      \
    \  f(id[head[v]] - 1, id[v]);\r\n        v = parent[head[v]];\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  template <typename T, typename F, typename G>\r\n  T e_query(int\
    \ u, int v, F f, G g, const T ID) const {\r\n    T left = ID, right = ID;\r\n\
    \    while (true) {\r\n      if (id[u] > id[v]) {\r\n        std::swap(u, v);\r\
    \n        std::swap(left, right);\r\n      }\r\n      if (head[u] == head[v])\
    \ {\r\n        left = g(left, f(id[u], id[v]));\r\n        break;\r\n      } else\
    \ {\r\n        left = g(left, f(id[head[v]] - 1, id[v]));\r\n        v = parent[head[v]];\r\
    \n      }\r\n    }\r\n    return g(left, right);\r\n  }\r\n\r\n  template <typename\
    \ Fn>\r\n  void subtree_e_update(int ver, Fn f) const { f(id[ver], id[ver] + subtree[ver]\
    \ - 1); }\r\n\r\n  template <typename T, typename Fn>\r\n  T subtree_e_query(int\
    \ ver, Fn f) const { return f(id[ver], id[ver] + subtree[ver] - 1); }\r\n\r\n\
    \  int lca(int u, int v) const {\r\n    while (true) {\r\n      if (id[u] > id[v])\
    \ std::swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n      v = parent[head[v]];\r\
    \n    }\r\n  }\r\n\r\nprivate:\r\n  std::vector<std::vector<int>> graph;\r\n\r\
    \n  void dfs1(int ver) {\r\n    for (int &e : graph[ver]) {\r\n      if (e !=\
    \ parent[ver]) {\r\n        parent[e] = ver;\r\n        dfs1(e);\r\n        subtree[ver]\
    \ += subtree[e];\r\n        if (subtree[e] > subtree[graph[ver].front()]) std::swap(e,\
    \ graph[ver].front());\r\n      }\r\n    }\r\n  }\r\n\r\n  void dfs2(int ver,\
    \ int &now_id) {\r\n    id[ver] = now_id++;\r\n    inv[id[ver]] = ver;\r\n   \
    \ for (int e : graph[ver]) {\r\n      if (e != parent[ver]) {\r\n        head[e]\
    \ = (e == graph[ver].front() ? head[ver] : e);\r\n        dfs2(e, now_id);\r\n\
    \      }\r\n    }\r\n  }\r\n};\r\n#line 6 \"test/graph/light/tree/hld.2.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int k;\r\n    std::cin >>\
    \ k;\r\n    while (k--) {\r\n      int c;\r\n      std::cin >> c;\r\n      graph[i].emplace_back(c);\r\
    \n      graph[c].emplace_back(i);\r\n    }\r\n  }\r\n  HLD hld(graph, 0);\r\n\
    \  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    int u, v;\r\n    std::cin\
    \ >> u >> v;\r\n    std::cout << hld.lca(u, v) << '\\n';\r\n  }\r\n  return 0;\r\
    \n}\r\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../../graph/light/tree/hld.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    int k;\r\n    std::cin >>\
    \ k;\r\n    while (k--) {\r\n      int c;\r\n      std::cin >> c;\r\n      graph[i].emplace_back(c);\r\
    \n      graph[c].emplace_back(i);\r\n    }\r\n  }\r\n  HLD hld(graph, 0);\r\n\
    \  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    int u, v;\r\n    std::cin\
    \ >> u >> v;\r\n    std::cout << hld.lca(u, v) << '\\n';\r\n  }\r\n  return 0;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/light/tree/hld.2.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 04:45:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/light/tree/hld.2.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/tree/hld.2.test.cpp
- /verify/test/graph/light/tree/hld.2.test.cpp.html
title: test/graph/light/tree/hld.2.test.cpp
---
