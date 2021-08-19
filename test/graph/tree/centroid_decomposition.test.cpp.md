---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':heavy_check_mark:'
    path: graph/tree/centroid_decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3 (centroid decompositon)"
  - icon: ':question:'
    path: math/convolution/fast_fourier_transform.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3\r\n */\r\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \r\n\r\n#include <cmath>\r\n#include <functional>\r\n#include <iostream>\r\n#include\
    \ <vector>\r\n#include \"../../../graph/edge.hpp\"\r\n#include \"../../../graph/tree/centroid_decomposition.hpp\"\
    \r\n#include \"../../../math/convolution/fast_fourier_transform.hpp\"\r\n\r\n\
    int main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<std::vector<Edge<bool>>>\
    \ graph(n);\r\n  for (int i = 0; i < n - 1; ++i) {\r\n    int a, b;\r\n    std::cin\
    \ >> a >> b;\r\n    graph[a].emplace_back(a, b);\r\n    graph[b].emplace_back(b,\
    \ a);\r\n  }\r\n  CentroidDecomposition<bool> cd(graph);\r\n  std::vector<bool>\
    \ visited(n, false);\r\n  std::vector<long long> x(n, 0);\r\n  std::function<void(int)>\
    \ rec = [n, &graph, &cd, &visited, &x, &rec](int root) -> void {\r\n    visited[root]\
    \ = true;\r\n    std::vector<int> cnt{1};\r\n    for (const Edge<bool> &child\
    \ : graph[root]) {\r\n      if (visited[child.dst]) continue;\r\n      std::vector<int>\
    \ sub_cnt{0};\r\n      std::function<void(int, int, int)> dfs = [&graph, &visited,\
    \ &cnt, &sub_cnt, &dfs](int par, int ver, int dist) -> void {\r\n        if (cnt.size()\
    \ <= dist) cnt.resize(dist + 1, 0);\r\n        ++cnt[dist];\r\n        if (sub_cnt.size()\
    \ <= dist) sub_cnt.resize(dist + 1, 0);\r\n        ++sub_cnt[dist];\r\n      \
    \  for (const Edge<bool> &e : graph[ver]) {\r\n          if (!visited[e.dst] &&\
    \ e.dst != par) dfs(ver, e.dst, dist + 1);\r\n        }\r\n      };\r\n      dfs(root,\
    \ child.dst, 1);\r\n      std::vector<fast_fourier_transform::Real> f = fast_fourier_transform::convolution(sub_cnt,\
    \ sub_cnt);\r\n      for (int i = 0; i < f.size() && i < n; ++i) x[i] -= std::round(f[i]);\r\
    \n    }\r\n    std::vector<fast_fourier_transform::Real> f = fast_fourier_transform::convolution(cnt,\
    \ cnt);\r\n    for (int i = 0; i < f.size() && i < n; ++i) x[i] += std::round(f[i]);\r\
    \n    for (int e : cd.comp[root]) rec(e);\r\n  };\r\n  rec(cd.root);\r\n  for\
    \ (int i = 1; i < n; ++i) std::cout << x[i] / 2 << \" \\n\"[i + 1 == n];\r\n \
    \ return 0;\r\n}\r\n"
  dependsOn:
  - graph/edge.hpp
  - graph/tree/centroid_decomposition.hpp
  - math/convolution/fast_fourier_transform.hpp
  isVerificationFile: true
  path: test/graph/tree/centroid_decomposition.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 23:02:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/centroid_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/centroid_decomposition.test.cpp
- /verify/test/graph/tree/centroid_decomposition.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
---
