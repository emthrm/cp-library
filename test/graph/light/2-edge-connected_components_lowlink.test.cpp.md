---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://atcoder.jp/contests/arc039/tasks/arc039_d
  bundledCode: "#line 1 \"test/graph/light/2-edge-connected_components_lowlink.test.cpp\"\
    \n#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc039/tasks/arc039_d\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#line 2 \"graph/light/2-edge-connected_components_lowlink.hpp\"\
    \n// #include <algorithm>\r\n#include <utility>\r\n#line 2 \"graph/light/lowlink.hpp\"\
    \n#include <algorithm>\r\n#line 5 \"graph/light/lowlink.hpp\"\n\r\nstruct Lowlink\
    \ {\r\n  std::vector<std::vector<int>> graph;\r\n  std::vector<int> ap;\r\n  std::vector<std::pair<int,\
    \ int>> bridge;\r\n\r\n  Lowlink(const std::vector<std::vector<int>> &graph) :\
    \ graph(graph) {\r\n    int n = graph.size();\r\n    order.assign(n, -1);\r\n\
    \    lowlink.resize(n);\r\n    int tm = 0;\r\n    for (int i = 0; i < n; ++i)\
    \ {\r\n      if (order[i] == -1) dfs(-1, i, tm);\r\n    }\r\n    // std::sort(ap.begin(),\
    \ ap.end());\r\n    // std::sort(bridge.begin(), bridge.end(), [](const pair<int,\
    \ int> &a, const pair<int, int> &b) -> bool {\r\n    //   int as, ad, bs, bd;\r\
    \n    //   std::tie(as, ad) = a;\r\n    //   std::tie(bs, bd) = b;\r\n    // \
    \  return as != bs ? as < bs : ad < bd;\r\n    // });\r\n  }\r\n\r\n  std::vector<int>\
    \ order, lowlink;\r\nprivate:\r\n  void dfs(int par, int ver, int &tm) {\r\n \
    \   order[ver] = lowlink[ver] = tm++;\r\n    int cnt = 0;\r\n    bool is_ap =\
    \ false;\r\n    for (int e : graph[ver]) {\r\n      if (order[e] == -1) {\r\n\
    \        ++cnt;\r\n        dfs(ver, e, tm);\r\n        if (lowlink[e] < lowlink[ver])\
    \ lowlink[ver] = lowlink[e];\r\n        if (order[ver] <= lowlink[e]) {\r\n  \
    \        is_ap = true;\r\n          if (order[ver] < lowlink[e]) bridge.emplace_back(std::minmax(ver,\
    \ e));\r\n        }\r\n      } else if (e != par) {\r\n        if (order[e] <\
    \ lowlink[ver]) lowlink[ver] = order[e];\r\n      }\r\n    }\r\n    if (par ==\
    \ -1) {\r\n      if (cnt >= 2) ap.emplace_back(ver);\r\n    } else {\r\n     \
    \ if (is_ap) ap.emplace_back(ver);\r\n    }\r\n  }\r\n};\r\n#line 6 \"graph/light/2-edge-connected_components_lowlink.hpp\"\
    \n\r\nstruct TwoEdgeConnectedComponents : Lowlink {\r\n  std::vector<int> id;\r\
    \n  std::vector<std::vector<int>> vertices, comp;\r\n\r\n  TwoEdgeConnectedComponents(const\
    \ std::vector<std::vector<int>> &graph, bool heavy = false) : Lowlink(graph),\
    \ heavy(heavy) {\r\n    int n = graph.size();\r\n    id.assign(n, -1);\r\n   \
    \ int now = 0;\r\n    for (int i = 0; i < n; ++i) {\r\n      if (id[i] == -1)\
    \ dfs(-1, i, now);\r\n    }\r\n    comp.resize(now);\r\n    for (const std::pair<int,\
    \ int> &e : this->bridge) {\r\n      int u = id[e.first], v = id[e.second];\r\n\
    \      comp[u].emplace_back(v);\r\n      comp[v].emplace_back(u);\r\n    }\r\n\
    \    // if (heavy) {\r\n    //   for (int i = 0; i < now; ++i) std::sort(vertices[i].begin(),\
    \ vertices[i].end());\r\n    // }\r\n  }\r\n\r\nprivate:\r\n  bool heavy;\r\n\r\
    \n  void dfs(int par, int ver, int &now) {\r\n    if (par != -1 && this->order[par]\
    \ >= this->lowlink[ver]) {\r\n      id[ver] = id[par];\r\n    } else {\r\n   \
    \   id[ver] = now++;\r\n      if (heavy) vertices.emplace_back();\r\n    }\r\n\
    \    if (heavy) vertices[id[ver]].emplace_back(ver);\r\n    for (int e : this->graph[ver])\
    \ {\r\n      if (id[e] == -1) dfs(ver, e, now);\r\n    }\r\n  }\r\n};\r\n#line\
    \ 2 \"graph/light/tree/lca_doubling.hpp\"\n#include <cassert>\r\n#line 5 \"graph/light/tree/lca_doubling.hpp\"\
    \n\r\nstruct LCADoubling {\r\n  std::vector<int> depth, dist;\r\n\r\n  LCADoubling(const\
    \ std::vector<std::vector<int>> &graph) : graph(graph) {\r\n    n = graph.size();\r\
    \n    depth.resize(n);\r\n    dist.resize(n);\r\n    while ((1 << table_h) <=\
    \ n) ++table_h;\r\n    parent.resize(table_h, std::vector<int>(n));\r\n  }\r\n\
    \r\n  void build(int root = 0) {\r\n    is_built = true;\r\n    dfs(-1, root,\
    \ 0, 0);\r\n    for (int i = 0; i + 1 < table_h; ++i) for (int ver = 0; ver <\
    \ n; ++ver) {\r\n      parent[i + 1][ver] = parent[i][ver] == -1 ? -1 : parent[i][parent[i][ver]];\r\
    \n    }\r\n  }\r\n\r\n  int query(int u, int v) const {\r\n    assert(is_built);\r\
    \n    if (depth[u] > depth[v]) std::swap(u, v);\r\n    for (int i = 0; i < table_h;\
    \ ++i) {\r\n      if ((depth[v] - depth[u]) >> i & 1) v = parent[i][v];\r\n  \
    \  }\r\n    if (u == v) return u;\r\n    for (int i = table_h - 1; i >= 0; --i)\
    \ {\r\n      if (parent[i][u] != parent[i][v]) {\r\n        u = parent[i][u];\r\
    \n        v = parent[i][v];\r\n      }\r\n    }\r\n    return parent[0][u];\r\n\
    \  }\r\n\r\n  int distance(int u, int v) const {\r\n    assert(is_built);\r\n\
    \    return dist[u] + dist[v] - dist[query(u, v)] * 2;\r\n  }\r\n\r\nprivate:\r\
    \n  bool is_built = false;\r\n  int n, table_h = 1;\r\n  std::vector<std::vector<int>>\
    \ graph, parent;\r\n\r\n  void dfs(int par, int ver, int now_depth, int now_dist)\
    \ {\r\n    depth[ver] = now_depth;\r\n    dist[ver] = now_dist;\r\n    parent[0][ver]\
    \ = par;\r\n    for (int e : graph[ver]) {\r\n      if (e != par) dfs(ver, e,\
    \ now_depth + 1, now_dist + 1);\r\n    }\r\n  }\r\n};\r\n#line 8 \"test/graph/light/2-edge-connected_components_lowlink.test.cpp\"\
    \n\r\nint main() {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  while (m--) {\r\n    int x, y;\r\n    std::cin >> x >> y;\r\n\
    \    --x; --y;\r\n    graph[x].emplace_back(y);\r\n    graph[y].emplace_back(x);\r\
    \n  }\r\n  TwoEdgeConnectedComponents twcc(graph);\r\n  LCADoubling lca(twcc.comp);\r\
    \n  lca.build();\r\n  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    int\
    \ a, b, c;\r\n    std::cin >> a >> b >> c;\r\n    --a; --b; --c;\r\n    a = twcc.id[a];\r\
    \n    b = twcc.id[b];\r\n    c = twcc.id[c];\r\n    std::cout << (lca.distance(a,\
    \ b) + lca.distance(b, c) == lca.distance(a, c) ? \"OK\\n\" : \"NG\\n\");\r\n\
    \  }\r\n  return 0;\r\n}\r\n"
  code: "#define IGNORE\r\n#define PROBLEM \"https://atcoder.jp/contests/arc039/tasks/arc039_d\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../graph/light/2-edge-connected_components_lowlink.hpp\"\
    \r\n#include \"../../../graph/light/tree/lca_doubling.hpp\"\r\n\r\nint main()\
    \ {\r\n  int n, m;\r\n  std::cin >> n >> m;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  while (m--) {\r\n    int x, y;\r\n    std::cin >> x >> y;\r\n\
    \    --x; --y;\r\n    graph[x].emplace_back(y);\r\n    graph[y].emplace_back(x);\r\
    \n  }\r\n  TwoEdgeConnectedComponents twcc(graph);\r\n  LCADoubling lca(twcc.comp);\r\
    \n  lca.build();\r\n  int q;\r\n  std::cin >> q;\r\n  while (q--) {\r\n    int\
    \ a, b, c;\r\n    std::cin >> a >> b >> c;\r\n    --a; --b; --c;\r\n    a = twcc.id[a];\r\
    \n    b = twcc.id[b];\r\n    c = twcc.id[c];\r\n    std::cout << (lca.distance(a,\
    \ b) + lca.distance(b, c) == lca.distance(a, c) ? \"OK\\n\" : \"NG\\n\");\r\n\
    \  }\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/graph/light/2-edge-connected_components_lowlink.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/light/2-edge-connected_components_lowlink.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/2-edge-connected_components_lowlink.test.cpp
- /verify/test/graph/light/2-edge-connected_components_lowlink.test.cpp.html
title: test/graph/light/2-edge-connected_components_lowlink.test.cpp
---
