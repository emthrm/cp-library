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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3\n */\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <cmath>\n#include <functional>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../../graph/edge.hpp\"\n#include \"../../../graph/tree/centroid_decomposition.hpp\"\
    \n#include \"../../../math/convolution/fast_fourier_transform.hpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::vector<std::vector<Edge<bool>>> graph(n);\n\
    \  for (int i = 0; i < n - 1; ++i) {\n    int a, b;\n    std::cin >> a >> b;\n\
    \    graph[a].emplace_back(a, b);\n    graph[b].emplace_back(b, a);\n  }\n  CentroidDecomposition<bool>\
    \ centroid_decomposition(graph);\n  std::vector<bool> is_visited(n, false);\n\
    \  std::vector<long long> x(n, 0);\n  const std::function<void(int)> f =\n   \
    \   [n, &graph, &centroid_decomposition, &is_visited, &x, &f](const int root)\n\
    \          -> void {\n        is_visited[root] = true;\n        std::vector<int>\
    \ nums{1};\n        for (const Edge<bool>& child : graph[root]) {\n          if\
    \ (is_visited[child.dst]) continue;\n          std::vector<int> nums_sub{0};\n\
    \          const std::function<void(int, int, int)> dfs =\n              [&graph,\
    \ &is_visited, &nums, &nums_sub, &dfs](\n                  const int par, const\
    \ int ver, const int dist) -> void {\n                if (nums.size() <= dist)\
    \ nums.resize(dist + 1, 0);\n                ++nums[dist];\n                if\
    \ (nums_sub.size() <= dist) nums_sub.resize(dist + 1, 0);\n                ++nums_sub[dist];\n\
    \                for (const Edge<bool>& e : graph[ver]) {\n                  if\
    \ (!is_visited[e.dst] && e.dst != par) {\n                    dfs(ver, e.dst,\
    \ dist + 1);\n                  }\n                }\n              };\n     \
    \     dfs(root, child.dst, 1);\n          const std::vector<fast_fourier_transform::Real>\
    \ fft =\n              fast_fourier_transform::convolution(nums_sub, nums_sub);\n\
    \          for (int i = 0; i < fft.size() && i < n; ++i) {\n            x[i] -=\
    \ std::round(fft[i]);\n          }\n        }\n        const std::vector<fast_fourier_transform::Real>\
    \ fft =\n            fast_fourier_transform::convolution(nums, nums);\n      \
    \  for (int i = 0; i < fft.size() && i < n; ++i) {\n          x[i] += std::round(fft[i]);\n\
    \        }\n        for (const int e : centroid_decomposition.g[root]) f(e);\n\
    \      };\n  f(centroid_decomposition.root);\n  for (int i = 1; i < n; ++i) {\n\
    \    std::cout << x[i] / 2 << \" \\n\"[i + 1 == n];\n  }\n  return 0;\n}\n"
  dependsOn:
  - graph/edge.hpp
  - graph/tree/centroid_decomposition.hpp
  - math/convolution/fast_fourier_transform.hpp
  isVerificationFile: true
  path: test/graph/tree/centroid_decomposition.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/tree/centroid_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/graph/tree/centroid_decomposition.test.cpp
- /verify/test/graph/tree/centroid_decomposition.test.cpp.html
title: "\u30B0\u30E9\u30D5/\u6728/\u91CD\u5FC3\u5206\u89E3"
---
