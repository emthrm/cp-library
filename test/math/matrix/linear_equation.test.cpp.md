---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: include/emthrm/graph/shortest_path/dijkstra.hpp
    title: "Dijkstra \u6CD5"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/gauss_jordan.hpp
    title: "\u30AC\u30A6\u30B9\u30FB\u30B8\u30E7\u30EB\u30C0\u30F3\u306E\u6D88\u53BB\
      \u6CD5 (Gauss\u2013Jordan elimination)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/matrix/linear_equation.hpp
    title: "\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F (linear equation)"
  - icon: ':question:'
    path: include/emthrm/math/matrix/matrix.hpp
    title: "\u884C\u5217 (matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    ERROR: 1e-8
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171
    document_title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\
      \u5F0F"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171
  bundledCode: "#line 1 \"test/math/matrix/linear_equation.test.cpp\"\n/*\n * @title\
    \ \u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F\n *\n *\
    \ verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171\n\
    \ * verification-helper: ERROR 1e-8\n */\n\n#include <iomanip>\n#include <iostream>\n\
    #include <vector>\n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title\
    \ \u8FBA\n */\n\n#ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\
    \n#include <compare>\n\nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct\
    \ Edge {\n  CostType cost;\n  int src, dst;\n\n  explicit Edge(const int src,\
    \ const int dst, const CostType cost = 0)\n      : cost(cost), src(src), dst(dst)\
    \ {}\n\n  auto operator<=>(const Edge& x) const = default;\n};\n\n}  // namespace\
    \ emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n#line 1 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#line 11 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n\n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n\
    #ifndef EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 13 \"include/emthrm/graph/shortest_path/dijkstra.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename CostType>\nstruct Dijkstra {\n  const CostType inf;\n\
    \n  Dijkstra(const std::vector<std::vector<Edge<CostType>>>& graph,\n        \
    \   const CostType inf = std::numeric_limits<CostType>::max())\n      : inf(inf),\
    \ is_built(false), graph(graph) {}\n\n  std::vector<CostType> build(const int\
    \ s) {\n    is_built = true;\n    const int n = graph.size();\n    std::vector<CostType>\
    \ dist(n, inf);\n    dist[s] = 0;\n    prev.assign(n, -1);\n    std::priority_queue<std::pair<CostType,\
    \ int>,\n                        std::vector<std::pair<CostType, int>>,\n    \
    \                    std::greater<std::pair<CostType, int>>> que;\n    que.emplace(0,\
    \ s);\n    while (!que.empty()) {\n      const auto [d, ver] = que.top();\n  \
    \    que.pop();\n      if (d > dist[ver]) continue;\n      for (const Edge<CostType>&\
    \ e : graph[ver]) {\n        if (dist[ver] + e.cost < dist[e.dst]) {\n       \
    \   dist[e.dst] = dist[ver] + e.cost;\n          prev[e.dst] = ver;\n        \
    \  que.emplace(dist[e.dst], e.dst);\n        }\n      }\n    }\n    return dist;\n\
    \  }\n\n  std::vector<int> build_path(int t) const {\n    assert(is_built);\n\
    \    std::vector<int> res;\n    for (; t != -1; t = prev[t]) {\n      res.emplace_back(t);\n\
    \    }\n    std::reverse(res.begin(), res.end());\n    return res;\n  }\n\n private:\n\
    \  bool is_built;\n  std::vector<int> prev;\n  std::vector<std::vector<Edge<CostType>>>\
    \ graph;\n};\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/matrix/linear_equation.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/matrix/linear_equation.hpp\"\n#include <cmath>\n\
    #line 7 \"include/emthrm/math/matrix/linear_equation.hpp\"\n\n#line 1 \"include/emthrm/math/matrix/gauss_jordan.hpp\"\
    \n\n\n\n#line 5 \"include/emthrm/math/matrix/gauss_jordan.hpp\"\n\n#line 1 \"\
    include/emthrm/math/matrix/matrix.hpp\"\n\n\n\n#line 5 \"include/emthrm/math/matrix/matrix.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <typename T>\nstruct Matrix {\n  explicit Matrix(const\
    \ int m, const int n, const T def = 0)\n      : data(m, std::vector<T>(n, def))\
    \ {}\n\n  int nrow() const { return data.size(); }\n  int ncol() const { return\
    \ data.front().size(); }\n\n  Matrix pow(long long exponent) const {\n    const\
    \ int n = nrow();\n    Matrix<T> res(n, n, 0), tmp = *this;\n    for (int i =\
    \ 0; i < n; ++i) {\n      res[i][i] = 1;\n    }\n    for (; exponent > 0; exponent\
    \ >>= 1) {\n      if (exponent & 1) res *= tmp;\n      tmp *= tmp;\n    }\n  \
    \  return res;\n  }\n\n  inline const std::vector<T>& operator[](const int i)\
    \ const { return data[i]; }\n  inline std::vector<T>& operator[](const int i)\
    \ { return data[i]; }\n\n  Matrix& operator=(const Matrix& x) = default;\n\n \
    \ Matrix& operator+=(const Matrix& x) {\n    const int m = nrow(), n = ncol();\n\
    \    for (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n; ++j) {\n    \
    \    data[i][j] += x[i][j];\n      }\n    }\n    return *this;\n  }\n\n  Matrix&\
    \ operator-=(const Matrix& x) {\n    const int m = nrow(), n = ncol();\n    for\
    \ (int i = 0; i < m; ++i) {\n      for (int j = 0; j < n; ++j) {\n        data[i][j]\
    \ -= x[i][j];\n      }\n    }\n    return *this;\n  }\n\n  Matrix& operator*=(const\
    \ Matrix& x) {\n    const int m = nrow(), l = ncol(), n = x.ncol();\n    std::vector<std::vector<T>>\
    \ res(m, std::vector<T>(n, 0));\n    for (int i = 0; i < m; ++i) {\n      for\
    \ (int k = 0; k < l; ++k) {\n        for (int j = 0; j < n; ++j) {\n         \
    \ res[i][j] += data[i][k] * x[k][j];\n        }\n      }\n    }\n    data.swap(res);\n\
    \    return *this;\n  }\n\n  Matrix operator+(const Matrix& x) const { return\
    \ Matrix(*this) += x; }\n  Matrix operator-(const Matrix& x) const { return Matrix(*this)\
    \ -= x; }\n  Matrix operator*(const Matrix& x) const { return Matrix(*this) *=\
    \ x; }\n\n private:\n  std::vector<std::vector<T>> data;\n};\n\n}  // namespace\
    \ emthrm\n\n\n#line 7 \"include/emthrm/math/matrix/gauss_jordan.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <bool IS_EXTENDED = false, typename T>\nint gauss_jordan(Matrix<T>*\
    \ a, const T eps = 1e-8) {\n  const int m = a->nrow(), n = a->ncol();\n  int rank\
    \ = 0;\n  for (int col = 0; col < (IS_EXTENDED ? n - 1 : n); ++col) {\n    int\
    \ pivot = -1;\n    T mx = eps;\n    for (int row = rank; row < m; ++row) {\n \
    \     const T abs = ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col]);\n\
    \      if (abs > mx) {\n        pivot = row;\n        mx = abs;\n      }\n   \
    \ }\n    if (pivot == -1) continue;\n    std::swap((*a)[rank], (*a)[pivot]);\n\
    \    T tmp = (*a)[rank][col];\n    for (int col2 = 0; col2 < n; ++col2) {\n  \
    \    (*a)[rank][col2] /= tmp;\n    }\n    for (int row = 0; row < m; ++row) {\n\
    \      if (row != rank &&\n          ((*a)[row][col] < 0 ? -(*a)[row][col] : (*a)[row][col])\
    \ > eps) {\n        tmp = (*a)[row][col];\n        for (int col2 = 0; col2 < n;\
    \ ++col2) {\n          (*a)[row][col2] -= (*a)[rank][col2] * tmp;\n        }\n\
    \      }\n    }\n    ++rank;\n  }\n  return rank;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 10 \"include/emthrm/math/matrix/linear_equation.hpp\"\n\nnamespace emthrm\
    \ {\n\ntemplate <typename T, typename U = double>\nstd::vector<U> linear_equation(const\
    \ Matrix<T>& a, const std::vector<T>& b,\n                               const\
    \ U eps = 1e-8) {\n  const int m = a.nrow(), n = a.ncol();\n  Matrix<U> c(m, n\
    \ + 1);\n  for (int i = 0; i < m; ++i) {\n    std::copy(a[i].begin(), a[i].end(),\
    \ c[i].begin());\n    c[i].back() = b[i];\n  }\n  const int rank = gauss_jordan<true>(&c,\
    \ eps);\n  for (int row = rank; row < m; ++row) {\n    if ((c[row].back() < 0\
    \ ? -c[row].back() : c[row].back()) > eps) {\n      return std::vector<U>{};\n\
    \    }\n  }\n  std::vector<U> res(n, 0);\n  for (int i = 0, j = 0; i < rank; ++i)\
    \ {\n    while ((c[i][j] < 0 ? -c[i][j] : c[i][j]) <= eps) ++j;\n    res[j++]\
    \ = c[i].back();\n  }\n  return res;\n}\n\n}  // namespace emthrm\n\n\n#line 16\
    \ \"test/math/matrix/linear_equation.test.cpp\"\n\nint main() {\n  while (true)\
    \ {\n    int n, s, t;\n    std::cin >> n >> s >> t;\n    if (n == 0 && s == 0\
    \ && t == 0) break;\n    --s; --t;\n    std::vector<int> q(n);\n    for (int i\
    \ = 0; i < n; ++i) {\n      std::cin >> q[i];\n    }\n    std::vector<std::vector<emthrm::Edge<int>>>\
    \ graph(n);\n    for (int i = 0; i < n; ++i) {\n      for (int j = 0; j < n; ++j)\
    \ {\n        int a;\n        std::cin >> a;\n        if (a > 0) graph[i].emplace_back(i,\
    \ j, a);\n      }\n    }\n    emthrm::Dijkstra<int> dijkstra(graph);\n    const\
    \ std::vector<int> dist = dijkstra.build(t);\n    if (dist[s] == dijkstra.inf)\
    \ {\n      std::cout << \"impossible\\n\";\n      continue;\n    }\n    emthrm::Matrix<int>\
    \ a(n, n, 0);\n    std::vector<int> b(n, 0);\n    for (int i = 0; i < n; ++i)\
    \ {\n      if (i == t) {\n        a[i][i] = 1;\n      } else {\n        std::vector<emthrm::Edge<int>>\
    \ edges;\n        if (q[i] == 0) {\n          edges = graph[i];\n        } else\
    \ if (q[i] == 1) {\n          for (const emthrm::Edge<int>& e : graph[i]) {\n\
    \            if (dist[e.dst] + e.cost == dist[i]) edges.emplace_back(e);\n   \
    \       }\n        }\n        a[i][i] = -edges.size();\n        for (const emthrm::Edge<int>&\
    \ e : edges) {\n          ++a[i][e.dst];\n          b[i] -= e.cost;\n        }\n\
    \      }\n    }\n    std::cout << std::fixed << std::setprecision(8)\n       \
    \       << emthrm::linear_equation(a, b)[s] << '\\n';\n  }\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\
    \u5F0F\n *\n * verification-helper: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171\n\
    \ * verification-helper: ERROR 1e-8\n */\n\n#include <iomanip>\n#include <iostream>\n\
    #include <vector>\n\n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/shortest_path/dijkstra.hpp\"\
    \n#include \"emthrm/math/matrix/linear_equation.hpp\"\n#include \"emthrm/math/matrix/matrix.hpp\"\
    \n\nint main() {\n  while (true) {\n    int n, s, t;\n    std::cin >> n >> s >>\
    \ t;\n    if (n == 0 && s == 0 && t == 0) break;\n    --s; --t;\n    std::vector<int>\
    \ q(n);\n    for (int i = 0; i < n; ++i) {\n      std::cin >> q[i];\n    }\n \
    \   std::vector<std::vector<emthrm::Edge<int>>> graph(n);\n    for (int i = 0;\
    \ i < n; ++i) {\n      for (int j = 0; j < n; ++j) {\n        int a;\n       \
    \ std::cin >> a;\n        if (a > 0) graph[i].emplace_back(i, j, a);\n      }\n\
    \    }\n    emthrm::Dijkstra<int> dijkstra(graph);\n    const std::vector<int>\
    \ dist = dijkstra.build(t);\n    if (dist[s] == dijkstra.inf) {\n      std::cout\
    \ << \"impossible\\n\";\n      continue;\n    }\n    emthrm::Matrix<int> a(n,\
    \ n, 0);\n    std::vector<int> b(n, 0);\n    for (int i = 0; i < n; ++i) {\n \
    \     if (i == t) {\n        a[i][i] = 1;\n      } else {\n        std::vector<emthrm::Edge<int>>\
    \ edges;\n        if (q[i] == 0) {\n          edges = graph[i];\n        } else\
    \ if (q[i] == 1) {\n          for (const emthrm::Edge<int>& e : graph[i]) {\n\
    \            if (dist[e.dst] + e.cost == dist[i]) edges.emplace_back(e);\n   \
    \       }\n        }\n        a[i][i] = -edges.size();\n        for (const emthrm::Edge<int>&\
    \ e : edges) {\n          ++a[i][e.dst];\n          b[i] -= e.cost;\n        }\n\
    \      }\n    }\n    std::cout << std::fixed << std::setprecision(8)\n       \
    \       << emthrm::linear_equation(a, b)[s] << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/shortest_path/dijkstra.hpp
  - include/emthrm/math/matrix/linear_equation.hpp
  - include/emthrm/math/matrix/gauss_jordan.hpp
  - include/emthrm/math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/linear_equation.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/linear_equation.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/linear_equation.test.cpp
- /verify/test/math/matrix/linear_equation.test.cpp.html
title: "\u6570\u5B66/\u884C\u5217/\u9023\u7ACB\u4E00\u6B21\u65B9\u7A0B\u5F0F"
---
