---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: include/emthrm/graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/graph/tree/centroid_decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
  - icon: ':question:'
    path: include/emthrm/math/convolution/fast_fourier_transform.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/graph/tree/centroid_decomposition.test.cpp\"\n/*\n\
    \ * @title \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3\n *\n * verification-helper:\
    \ PROBLEM https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\n */\n\
    \n#include <cmath>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 1 \"include/emthrm/graph/tree/centroid_decomposition.hpp\"\n\n\n\n#include\
    \ <ranges>\n#line 6 \"include/emthrm/graph/tree/centroid_decomposition.hpp\"\n\
    \n#line 1 \"include/emthrm/graph/edge.hpp\"\n/**\n * @title \u8FBA\n */\n\n#ifndef\
    \ EMTHRM_GRAPH_EDGE_HPP_\n#define EMTHRM_GRAPH_EDGE_HPP_\n\n#include <compare>\n\
    \nnamespace emthrm {\n\ntemplate <typename CostType>\nstruct Edge {\n  CostType\
    \ cost;\n  int src, dst;\n\n  explicit Edge(const int src, const int dst, const\
    \ CostType cost = 0)\n      : cost(cost), src(src), dst(dst) {}\n\n  auto operator<=>(const\
    \ Edge& x) const = default;\n};\n\n}  // namespace emthrm\n\n#endif  // EMTHRM_GRAPH_EDGE_HPP_\n\
    #line 8 \"include/emthrm/graph/tree/centroid_decomposition.hpp\"\n\nnamespace\
    \ emthrm {\n\ntemplate <typename CostType>\nstruct CentroidDecomposition {\n \
    \ int root;\n  std::vector<int> parent;\n  std::vector<std::vector<int>> g;\n\n\
    \  explicit CentroidDecomposition(\n      const std::vector<std::vector<Edge<CostType>>>&\
    \ graph)\n      : graph(graph) {\n    const int n = graph.size();\n    parent.assign(n,\
    \ -1);\n    g.resize(n);\n    is_alive.assign(n, true);\n    subtree.resize(n);\n\
    \    root = build(0);\n  }\n\n private:\n  std::vector<bool> is_alive;\n  std::vector<int>\
    \ subtree;\n  const std::vector<std::vector<Edge<CostType>>> graph;\n\n  int build(const\
    \ int s) {\n    const int centroid = search_centroid(-1, s, calc_subtree(-1, s)\
    \ / 2);\n    is_alive[centroid] = false;\n    for (const int e : graph[centroid]\n\
    \                     | std::views::transform(&Edge<CostType>::dst)) {\n     \
    \ if (is_alive[e]) {\n        g[centroid].emplace_back(build(e));\n        parent[e]\
    \ = centroid;\n      }\n    }\n    is_alive[centroid] = true;\n    return centroid;\n\
    \  }\n\n  int calc_subtree(const int par, const int ver) {\n    subtree[ver] =\
    \ 1;\n    for (const int e : graph[ver]\n                     | std::views::transform(&Edge<CostType>::dst))\
    \ {\n      if (e != par && is_alive[e]) {\n        subtree[ver] += calc_subtree(ver,\
    \ e);\n      }\n    }\n    return subtree[ver];\n  }\n\n  int search_centroid(const\
    \ int par, const int ver, const int half) const {\n    for (const int e : graph[ver]\n\
    \                     | std::views::transform(&Edge<CostType>::dst)) {\n     \
    \ if (e != par && is_alive[e] && subtree[e] > half) {\n        return search_centroid(ver,\
    \ e, half);\n      }\n    }\n    return ver;\n  }\n};\n\n}  // namespace emthrm\n\
    \n\n#line 1 \"include/emthrm/math/convolution/fast_fourier_transform.hpp\"\n\n\
    \n\n#include <algorithm>\n#include <bit>\n#include <cassert>\n#line 8 \"include/emthrm/math/convolution/fast_fourier_transform.hpp\"\
    \n#include <iterator>\n#line 11 \"include/emthrm/math/convolution/fast_fourier_transform.hpp\"\
    \n\nnamespace emthrm {\n\nnamespace fast_fourier_transform {\n\nusing Real = double;\n\
    \nstruct Complex {\n  Real re, im;\n  explicit Complex(const Real re = 0, const\
    \ Real im = 0) : re(re), im(im) {}\n  inline Complex operator+(const Complex&\
    \ x) const {\n    return Complex(re + x.re, im + x.im);\n  }\n  inline Complex\
    \ operator-(const Complex& x) const {\n    return Complex(re - x.re, im - x.im);\n\
    \  }\n  inline Complex operator*(const Complex& x) const {\n    return Complex(re\
    \ * x.re - im * x.im, re * x.im + im * x.re);\n  }\n  inline Complex mul_real(const\
    \ Real r) const {\n    return Complex(re * r, im * r);\n  }\n  inline Complex\
    \ mul_pin(const Real r) const {\n    return Complex(-im * r, re * r);\n  }\n \
    \ inline Complex conj() const { return Complex(re, -im); }\n};\n\nstd::vector<int>\
    \ butterfly{0};\nstd::vector<std::vector<Complex>> zeta{{Complex(1, 0)}};\n\n\
    void init(const int n) {\n  const int prev_n = butterfly.size();\n  if (n <= prev_n)\
    \ return;\n  butterfly.resize(n);\n  const int prev_lg = zeta.size();\n  const\
    \ int lg = std::countr_zero(static_cast<unsigned int>(n));\n  for (int i = 1;\
    \ i < prev_n; ++i) {\n    butterfly[i] <<= lg - prev_lg;\n  }\n  for (int i =\
    \ prev_n; i < n; ++i) {\n    butterfly[i] = (butterfly[i >> 1] >> 1) | ((i & 1)\
    \ << (lg - 1));\n  }\n  zeta.resize(lg);\n  for (int i = prev_lg; i < lg; ++i)\
    \ {\n    zeta[i].resize(1 << i);\n    const Real angle = -3.14159265358979323846\
    \ * 2 / (1 << (i + 1));\n    for (int j = 0; j < (1 << (i - 1)); ++j) {\n    \
    \  zeta[i][j << 1] = zeta[i - 1][j];\n      const Real theta = angle * ((j <<\
    \ 1) + 1);\n      zeta[i][(j << 1) + 1] = Complex(std::cos(theta), std::sin(theta));\n\
    \    }\n  }\n}\n\nvoid dft(std::vector<Complex>* a) {\n  assert(std::has_single_bit(a->size()));\n\
    \  const int n = a->size();\n  init(n);\n  const int shift =\n      std::countr_zero(butterfly.size())\
    \ - std::countr_zero(a->size());\n  for (int i = 0; i < n; ++i) {\n    const int\
    \ j = butterfly[i] >> shift;\n    if (i < j) std::swap((*a)[i], (*a)[j]);\n  }\n\
    \  for (int block = 1, den = 0; block < n; block <<= 1, ++den) {\n    for (int\
    \ i = 0; i < n; i += (block << 1)) {\n      for (int j = 0; j < block; ++j) {\n\
    \        const Complex tmp = (*a)[i + j + block] * zeta[den][j];\n        (*a)[i\
    \ + j + block] = (*a)[i + j] - tmp;\n        (*a)[i + j] = (*a)[i + j] + tmp;\n\
    \      }\n    }\n  }\n}\n\ntemplate <typename T>\nstd::vector<Complex> real_dft(const\
    \ std::vector<T>& a) {\n  const int n = a.size();\n  std::vector<Complex> c(std::bit_ceil(a.size()));\n\
    \  for (int i = 0; i < n; ++i) {\n    c[i].re = a[i];\n  }\n  dft(&c);\n  return\
    \ c;\n}\n\nvoid idft(std::vector<Complex>* a) {\n  const int n = a->size();\n\
    \  dft(a);\n  std::reverse(std::next(a->begin()), a->end());\n  const Real r =\
    \ 1. / n;\n  std::transform(a->begin(), a->end(), a->begin(),\n              \
    \   [r](const Complex& c) -> Complex { return c.mul_real(r); });\n}\n\ntemplate\
    \ <typename T>\nstd::vector<Real> convolution(const std::vector<T>& a,\n     \
    \                         const std::vector<T>& b) {\n  const int a_size = a.size(),\
    \ b_size = b.size(), c_size = a_size + b_size - 1;\n  const int n = std::max(std::bit_ceil(static_cast<unsigned\
    \ int>(c_size)), 2U);\n  const int hlf = n >> 1, qtr = hlf >> 1;\n  std::vector<Complex>\
    \ c(n);\n  for (int i = 0; i < a_size; ++i) {\n    c[i].re = a[i];\n  }\n  for\
    \ (int i = 0; i < b_size; ++i) {\n    c[i].im = b[i];\n  }\n  dft(&c);\n  c.front()\
    \ = Complex(c.front().re * c.front().im, 0);\n  for (int i = 1; i < hlf; ++i)\
    \ {\n    const Complex i_square = c[i] * c[i], j_square = c[n - i] * c[n - i];\n\
    \    c[i] = (j_square.conj() - i_square).mul_pin(0.25);\n    c[n - i] = (i_square.conj()\
    \ - j_square).mul_pin(0.25);\n  }\n  c[hlf] = Complex(c[hlf].re * c[hlf].im, 0);\n\
    \  c.front() = (c.front() + c[hlf]\n               + (c.front() - c[hlf]).mul_pin(1)).mul_real(0.5);\n\
    \  const int den = std::countr_zero(static_cast<unsigned int>(hlf));\n  for (int\
    \ i = 1; i < qtr; ++i) {\n    const int j = hlf - i;\n    const Complex tmp1 =\
    \ c[i] + c[j].conj();\n    const Complex tmp2 = ((c[i] - c[j].conj()) * zeta[den][j]).mul_pin(1);\n\
    \    c[i] = (tmp1 - tmp2).mul_real(0.5);\n    c[j] = (tmp1 + tmp2).mul_real(0.5).conj();\n\
    \  }\n  if (qtr > 0) c[qtr] = c[qtr].conj();\n  c.resize(hlf);\n  idft(&c);\n\
    \  std::vector<Real> res(c_size);\n  for (int i = 0; i < c_size; i += 2) {\n \
    \   res[i] = c[i >> 1].re;\n  }\n  for (int i = 1; i < c_size; i += 2) {\n   \
    \ res[i] = c[i >> 1].im;\n  }\n  return res;\n}\n\n}  // namespace fast_fourier_transform\n\
    \n}  // namespace emthrm\n\n\n#line 15 \"test/graph/tree/centroid_decomposition.test.cpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b);\n    graph[b].emplace_back(b, a);\n\
    \  }\n  emthrm::CentroidDecomposition<bool> centroid_decomposition(graph);\n \
    \ std::vector<bool> is_visited(n, false);\n  std::vector<long long> x(n, 0);\n\
    \  const auto f = [n, &graph, &centroid_decomposition, &is_visited, &x](\n   \
    \   auto f, const int root) -> void {\n    is_visited[root] = true;\n    std::vector<int>\
    \ nums{1};\n    for (const emthrm::Edge<bool>& child : graph[root]) {\n      if\
    \ (is_visited[child.dst]) continue;\n      std::vector<int> nums_sub{0};\n   \
    \   const auto dfs = [&graph, &is_visited, &nums, &nums_sub](\n          auto\
    \ dfs, const int par, const int ver, const int dist) -> void {\n        if (std::cmp_less_equal(nums.size(),\
    \ dist)) nums.resize(dist + 1, 0);\n        ++nums[dist];\n        if (std::cmp_less_equal(nums_sub.size(),\
    \ dist)) {\n          nums_sub.resize(dist + 1, 0);\n        }\n        ++nums_sub[dist];\n\
    \        for (const emthrm::Edge<bool>& e : graph[ver]) {\n          if (!is_visited[e.dst]\
    \ && e.dst != par) {\n            dfs(dfs, ver, e.dst, dist + 1);\n          }\n\
    \        }\n      };\n      dfs(dfs, root, child.dst, 1);\n      const std::vector<emthrm::fast_fourier_transform::Real>\
    \ fft =\n          emthrm::fast_fourier_transform::convolution(nums_sub, nums_sub);\n\
    \      for (int i = 0; std::cmp_less(i, fft.size()) && i < n; ++i) {\n       \
    \ x[i] -= std::round(fft[i]);\n      }\n    }\n    const std::vector<emthrm::fast_fourier_transform::Real>\
    \ fft =\n        emthrm::fast_fourier_transform::convolution(nums, nums);\n  \
    \  for (int i = 0; std::cmp_less(i, fft.size()) && i < n; ++i) {\n      x[i] +=\
    \ std::round(fft[i]);\n    }\n    for (const int e : centroid_decomposition.g[root])\
    \ f(f, e);\n  };\n  f(f, centroid_decomposition.root);\n  for (int i = 1; i <\
    \ n; ++i) {\n    std::cout << x[i] / 2 << \" \\n\"[i + 1 == n];\n  }\n  return\
    \ 0;\n}\n"
  code: "/*\n * @title \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3\n *\n *\
    \ verification-helper: PROBLEM https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\n\
    \ */\n\n#include <cmath>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#include \"emthrm/graph/edge.hpp\"\n#include \"emthrm/graph/tree/centroid_decomposition.hpp\"\
    \n#include \"emthrm/math/convolution/fast_fourier_transform.hpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<emthrm::Edge<bool>>>\
    \ graph(n);\n  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n    graph[a].emplace_back(a, b);\n    graph[b].emplace_back(b, a);\n\
    \  }\n  emthrm::CentroidDecomposition<bool> centroid_decomposition(graph);\n \
    \ std::vector<bool> is_visited(n, false);\n  std::vector<long long> x(n, 0);\n\
    \  const auto f = [n, &graph, &centroid_decomposition, &is_visited, &x](\n   \
    \   auto f, const int root) -> void {\n    is_visited[root] = true;\n    std::vector<int>\
    \ nums{1};\n    for (const emthrm::Edge<bool>& child : graph[root]) {\n      if\
    \ (is_visited[child.dst]) continue;\n      std::vector<int> nums_sub{0};\n   \
    \   const auto dfs = [&graph, &is_visited, &nums, &nums_sub](\n          auto\
    \ dfs, const int par, const int ver, const int dist) -> void {\n        if (std::cmp_less_equal(nums.size(),\
    \ dist)) nums.resize(dist + 1, 0);\n        ++nums[dist];\n        if (std::cmp_less_equal(nums_sub.size(),\
    \ dist)) {\n          nums_sub.resize(dist + 1, 0);\n        }\n        ++nums_sub[dist];\n\
    \        for (const emthrm::Edge<bool>& e : graph[ver]) {\n          if (!is_visited[e.dst]\
    \ && e.dst != par) {\n            dfs(dfs, ver, e.dst, dist + 1);\n          }\n\
    \        }\n      };\n      dfs(dfs, root, child.dst, 1);\n      const std::vector<emthrm::fast_fourier_transform::Real>\
    \ fft =\n          emthrm::fast_fourier_transform::convolution(nums_sub, nums_sub);\n\
    \      for (int i = 0; std::cmp_less(i, fft.size()) && i < n; ++i) {\n       \
    \ x[i] -= std::round(fft[i]);\n      }\n    }\n    const std::vector<emthrm::fast_fourier_transform::Real>\
    \ fft =\n        emthrm::fast_fourier_transform::convolution(nums, nums);\n  \
    \  for (int i = 0; std::cmp_less(i, fft.size()) && i < n; ++i) {\n      x[i] +=\
    \ std::round(fft[i]);\n    }\n    for (const int e : centroid_decomposition.g[root])\
    \ f(f, e);\n  };\n  f(f, centroid_decomposition.root);\n  for (int i = 1; i <\
    \ n; ++i) {\n    std::cout << x[i] / 2 << \" \\n\"[i + 1 == n];\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - include/emthrm/graph/edge.hpp
  - include/emthrm/graph/tree/centroid_decomposition.hpp
  - include/emthrm/math/convolution/fast_fourier_transform.hpp
  isVerificationFile: true
  path: test/graph/tree/centroid_decomposition.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/centroid_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/centroid_decomposition.test.cpp
- /verify/test/graph/tree/centroid_decomposition.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
---
