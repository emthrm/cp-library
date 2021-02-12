---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/convolution/fft.hpp
    title: "\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (fast Fourier transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    document_title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/graph/light/tree/centroid_decomposition.test.cpp\"\n\
    /*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3\r\n */\r\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#include <cmath>\r\n#include <functional>\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#line 3 \"graph/light/tree/centroid_decomposition.hpp\"\n\r\nstruct\
    \ CentroidDecomposition {\r\n  int root;\r\n  std::vector<std::vector<int>> comp;\r\
    \n  std::vector<int> par;\r\n\r\n  CentroidDecomposition(const std::vector<std::vector<int>>\
    \ &graph) : graph(graph) {\r\n    int n = graph.size();\r\n    alive.assign(n,\
    \ true);\r\n    subtree.resize(n);\r\n    comp.resize(n);\r\n    par.assign(n,\
    \ -1);\r\n    root = build(0);\r\n  }\r\n\r\nprivate:\r\n  const std::vector<std::vector<int>>\
    \ graph;\r\n  std::vector<bool> alive;\r\n  std::vector<int> subtree;\r\n\r\n\
    \  int build(int s) {\r\n    int centroid = search_centroid(-1, s, calc_subtree(-1,\
    \ s) / 2);\r\n    alive[centroid] = false;\r\n    for (int e : graph[centroid])\
    \ {\r\n      if (alive[e]) {\r\n        comp[centroid].emplace_back(build(e));\r\
    \n        par[e] = centroid;\r\n      }\r\n    }\r\n    alive[centroid] = true;\r\
    \n    return centroid;\r\n  }\r\n\r\n  int calc_subtree(int par, int ver) {\r\n\
    \    subtree[ver] = 1;\r\n    for (int e : graph[ver]) {\r\n      if (e != par\
    \ && alive[e]) subtree[ver] += calc_subtree(ver, e);\r\n    }\r\n    return subtree[ver];\r\
    \n  }\r\n\r\n  int search_centroid(int par, int ver, int half) const {\r\n   \
    \ for (int e : graph[ver]) {\r\n      if (e != par && alive[e] && subtree[e] >\
    \ half) return search_centroid(ver, e, half);\r\n    }\r\n    return ver;\r\n\
    \  }\r\n};\r\n#line 2 \"math/convolution/fft.hpp\"\n#include <algorithm>\r\n#include\
    \ <cassert>\r\n#line 5 \"math/convolution/fft.hpp\"\n#include <utility>\r\n#line\
    \ 7 \"math/convolution/fft.hpp\"\n\r\nnamespace fft {\r\nusing Real = double;\r\
    \nstruct Complex {\r\n  Real re, im;\r\n  Complex(Real re = 0, Real im = 0) :\
    \ re(re), im(im) {}\r\n  inline Complex operator+(const Complex &x) const { return\
    \ Complex(re + x.re, im + x.im); }\r\n  inline Complex operator-(const Complex\
    \ &x) const { return Complex(re - x.re, im - x.im); }\r\n  inline Complex operator*(const\
    \ Complex &x) const { return Complex(re * x.re - im * x.im, re * x.im + im * x.re);\
    \ }\r\n  inline Complex mul_real(Real r) const { return Complex(re * r, im * r);\
    \ }\r\n  inline Complex mul_pin(Real r) const { return Complex(-im * r, re * r);\
    \ }\r\n  inline Complex conj() const { return Complex(re, -im); }\r\n};\r\n\r\n\
    std::vector<int> butterfly{0};\r\nstd::vector<std::vector<Complex>> zeta{{{1,\
    \ 0}}};\r\n\r\nvoid calc(int n) {\r\n  int prev_n = butterfly.size();\r\n  if\
    \ (n <= prev_n) return;\r\n  butterfly.resize(n);\r\n  int prev_lg = zeta.size(),\
    \ lg = __builtin_ctz(n);\r\n  for (int i = 1; i < prev_n; ++i) butterfly[i] <<=\
    \ lg - prev_lg;\r\n  for (int i = prev_n; i < n; ++i) butterfly[i] = (butterfly[i\
    \ >> 1] >> 1) | ((i & 1) << (lg - 1));\r\n  zeta.resize(lg);\r\n  for (int i =\
    \ prev_lg; i < lg; ++i) {\r\n    zeta[i].resize(1 << i);\r\n    Real angle = -3.14159265358979323846\
    \ * 2 / (1 << (i + 1));\r\n    for (int j = 0; j < (1 << (i - 1)); ++j) {\r\n\
    \      zeta[i][j << 1] = zeta[i - 1][j];\r\n      Real theta = angle * ((j <<\
    \ 1) + 1);\r\n      zeta[i][(j << 1) + 1] = {std::cos(theta), std::sin(theta)};\r\
    \n    }\r\n  }\r\n}\r\n\r\nvoid sub_dft(std::vector<Complex> &a) {\r\n  int n\
    \ = a.size();\r\n  assert(__builtin_popcount(n) == 1);\r\n  calc(n);\r\n  int\
    \ shift = __builtin_ctz(butterfly.size()) - __builtin_ctz(n);\r\n  for (int i\
    \ = 0; i < n; ++i) {\r\n    int j = butterfly[i] >> shift;\r\n    if (i < j) std::swap(a[i],\
    \ a[j]);\r\n  }\r\n  for (int block = 1; block < n; block <<= 1) {\r\n    int\
    \ den = __builtin_ctz(block);\r\n    for (int i = 0; i < n; i += (block << 1))\
    \ for (int j = 0; j < block; ++j) {\r\n      Complex tmp = a[i + j + block] *\
    \ zeta[den][j];\r\n      a[i + j + block] = a[i + j] - tmp;\r\n      a[i + j]\
    \ = a[i + j] + tmp;\r\n    }\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nstd::vector<Complex>\
    \ dft(const std::vector<T> &a) {\r\n  int sz = a.size(), lg = 1;\r\n  while ((1\
    \ << lg) < sz) ++lg;\r\n  std::vector<Complex> c(1 << lg);\r\n  for (int i = 0;\
    \ i < sz; ++i) c[i].re = a[i];\r\n  sub_dft(c);\r\n  return c;\r\n}\r\n\r\nstd::vector<Real>\
    \ real_idft(std::vector<Complex> &a) {\r\n  int n = a.size(), half = n >> 1, quarter\
    \ = half >> 1;\r\n  assert(__builtin_popcount(n) == 1);\r\n  calc(n);\r\n  a[0]\
    \ = (a[0] + a[half] + (a[0] - a[half]).mul_pin(1)).mul_real(0.5);\r\n  int den\
    \ = __builtin_ctz(half);\r\n  for (int i = 1; i < quarter; ++i) {\r\n    int j\
    \ = half - i;\r\n    Complex tmp1 = a[i] + a[j].conj(), tmp2 = ((a[i] - a[j].conj())\
    \ * zeta[den][j]).mul_pin(1);\r\n    a[i] = (tmp1 - tmp2).mul_real(0.5);\r\n \
    \   a[j] = (tmp1 + tmp2).mul_real(0.5).conj();\r\n  }\r\n  if (quarter > 0) a[quarter]\
    \ = a[quarter].conj();\r\n  a.resize(half);\r\n  sub_dft(a);\r\n  std::reverse(a.begin()\
    \ + 1, a.end());\r\n  Real r = 1.0 / half;\r\n  std::vector<Real> res(n);\r\n\
    \  for (int i = 0; i < n; ++i) res[i] = (i & 1 ? a[i >> 1].im : a[i >> 1].re)\
    \ * r;\r\n  return res;\r\n}\r\n\r\nvoid idft(std::vector<Complex> &a) {\r\n \
    \ int n = a.size();\r\n  sub_dft(a);\r\n  std::reverse(a.begin() + 1, a.end());\r\
    \n  Real r = 1.0 / n;\r\n  for (int i = 0; i < n; ++i) a[i] = a[i].mul_real(r);\r\
    \n}\r\n\r\ntemplate <typename T>\r\nstd::vector<Real> convolution(const std::vector<T>\
    \ &a, const std::vector<T> &b) {\r\n  int a_sz = a.size(), b_sz = b.size(), sz\
    \ = a_sz + b_sz - 1, lg = 1;\r\n  while ((1 << lg) < sz) ++lg;\r\n  int n = 1\
    \ << lg;\r\n  std::vector<Complex> c(n);\r\n  for (int i = 0; i < a_sz; ++i) c[i].re\
    \ = a[i];\r\n  for (int i = 0; i < b_sz; ++i) c[i].im = b[i];\r\n  sub_dft(c);\r\
    \n  c[0] = Complex(c[0].re * c[0].im, 0);\r\n  int half = n >> 1;\r\n  for (int\
    \ i = 1; i < half; ++i) {\r\n    Complex i_square = c[i] * c[i], j_square = c[n\
    \ - i] * c[n - i];\r\n    c[i] = (j_square.conj() - i_square).mul_pin(0.25);\r\
    \n    c[n - i] = (i_square.conj() - j_square).mul_pin(0.25);\r\n  }\r\n  c[half]\
    \ = Complex(c[half].re * c[half].im, 0);\r\n  std::vector<Real> res = real_idft(c);\r\
    \n  res.resize(sz);\r\n  return res;\r\n}\r\n}  // fft\r\n#line 12 \"test/graph/light/tree/centroid_decomposition.test.cpp\"\
    \n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<int>>\
    \ graph(n);\r\n  for (int i = 0; i < n - 1; ++i) {\r\n    int a, b;\r\n    std::cin\
    \ >> a >> b;\r\n    graph[a].emplace_back(b);\r\n    graph[b].emplace_back(a);\r\
    \n  }\r\n  CentroidDecomposition cd(graph);\r\n  std::vector<bool> visited(n,\
    \ false);\r\n  std::vector<long long> x(n, 0);\r\n  std::function<void(int)> rec\
    \ = [n, &graph, &cd, &visited, &x, &rec](int root) -> void {\r\n    visited[root]\
    \ = true;\r\n    std::vector<int> cnt{1};\r\n    for (int child : graph[root])\
    \ {\r\n      if (visited[child]) continue;\r\n      std::vector<int> sub_cnt{0};\r\
    \n      std::function<void(int, int, int)> dfs = [&graph, &visited, &cnt, &sub_cnt,\
    \ &dfs](int par, int ver, int dist) -> void {\r\n        if (cnt.size() <= dist)\
    \ cnt.resize(dist + 1, 0);\r\n        ++cnt[dist];\r\n        if (sub_cnt.size()\
    \ <= dist) sub_cnt.resize(dist + 1, 0);\r\n        ++sub_cnt[dist];\r\n      \
    \  for (int e : graph[ver]) {\r\n          if (!visited[e] && e != par) dfs(ver,\
    \ e, dist + 1);\r\n        }\r\n      };\r\n      dfs(root, child, 1);\r\n   \
    \   std::vector<fft::Real> f = fft::convolution(sub_cnt, sub_cnt);\r\n      for\
    \ (int i = 0; i < f.size() && i < n; ++i) x[i] -= std::round(f[i]);\r\n    }\r\
    \n    std::vector<fft::Real> f = fft::convolution(cnt, cnt);\r\n    for (int i\
    \ = 0; i < f.size() && i < n; ++i) x[i] += std::round(f[i]);\r\n    for (int e\
    \ : cd.comp[root]) rec(e);\r\n  };\r\n  rec(cd.root);\r\n  for (int i = 1; i <\
    \ n; ++i) std::cout << x[i] / 2 << \" \\n\"[i + 1 == n];\r\n  return 0;\r\n}\r\
    \n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3\r\n */\r\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#include <cmath>\r\n#include <functional>\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#include \"../../../../graph/light/tree/centroid_decomposition.hpp\"\
    \r\n#include \"../../../../math/convolution/fft.hpp\"\r\n\r\nint main() {\r\n\
    \  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<int>> graph(n);\r\n\
    \  for (int i = 0; i < n - 1; ++i) {\r\n    int a, b;\r\n    std::cin >> a >>\
    \ b;\r\n    graph[a].emplace_back(b);\r\n    graph[b].emplace_back(a);\r\n  }\r\
    \n  CentroidDecomposition cd(graph);\r\n  std::vector<bool> visited(n, false);\r\
    \n  std::vector<long long> x(n, 0);\r\n  std::function<void(int)> rec = [n, &graph,\
    \ &cd, &visited, &x, &rec](int root) -> void {\r\n    visited[root] = true;\r\n\
    \    std::vector<int> cnt{1};\r\n    for (int child : graph[root]) {\r\n     \
    \ if (visited[child]) continue;\r\n      std::vector<int> sub_cnt{0};\r\n    \
    \  std::function<void(int, int, int)> dfs = [&graph, &visited, &cnt, &sub_cnt,\
    \ &dfs](int par, int ver, int dist) -> void {\r\n        if (cnt.size() <= dist)\
    \ cnt.resize(dist + 1, 0);\r\n        ++cnt[dist];\r\n        if (sub_cnt.size()\
    \ <= dist) sub_cnt.resize(dist + 1, 0);\r\n        ++sub_cnt[dist];\r\n      \
    \  for (int e : graph[ver]) {\r\n          if (!visited[e] && e != par) dfs(ver,\
    \ e, dist + 1);\r\n        }\r\n      };\r\n      dfs(root, child, 1);\r\n   \
    \   std::vector<fft::Real> f = fft::convolution(sub_cnt, sub_cnt);\r\n      for\
    \ (int i = 0; i < f.size() && i < n; ++i) x[i] -= std::round(f[i]);\r\n    }\r\
    \n    std::vector<fft::Real> f = fft::convolution(cnt, cnt);\r\n    for (int i\
    \ = 0; i < f.size() && i < n; ++i) x[i] += std::round(f[i]);\r\n    for (int e\
    \ : cd.comp[root]) rec(e);\r\n  };\r\n  rec(cd.root);\r\n  for (int i = 1; i <\
    \ n; ++i) std::cout << x[i] / 2 << \" \\n\"[i + 1 == n];\r\n  return 0;\r\n}\r\
    \n"
  dependsOn:
  - math/convolution/fft.hpp
  isVerificationFile: true
  path: test/graph/light/tree/centroid_decomposition.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/light/tree/centroid_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/graph/light/tree/centroid_decomposition.test.cpp
- /verify/test/graph/light/tree/centroid_decomposition.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
---
