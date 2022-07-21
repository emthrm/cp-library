---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/fenwick_tree/2d_fenwick_tree.hpp
    title: "2\u6B21\u5143 Fenwick tree"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick\
      \ tree"
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/2d_fenwick_tree.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick\
    \ tree\n */\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\
    \n\n#include <iostream>\n#include <tuple>\n#include <queue>\n\n#include \"../../../data_structure/fenwick_tree/2d_fenwick_tree.hpp\"\
    \n\nint main() {\n  int h, w, t, q;\n  std::cin >> h >> w >> t >> q;\n  FenwickTree2D<int>\
    \ baked(h, w), unbaked(h, w);\n  std::queue<std::tuple<int, int, int>> que;\n\
    \  while (q--) {\n    int t_i, c, h_1, w_1;\n    std::cin >> t_i >> c >> h_1 >>\
    \ w_1;\n    --h_1; --w_1;\n    while (!que.empty() && std::get<0>(que.front())\
    \ <= t_i) {\n      const int y = std::get<1>(que.front()), x = std::get<2>(que.front());\n\
    \      que.pop();\n      unbaked.add(y, x, -1);\n      baked.add(y, x, 1);\n \
    \   }\n    if (c == 0) {\n      unbaked.add(h_1, w_1, 1);\n      que.emplace(t_i\
    \ + t, h_1, w_1);\n    } else if (c == 1) {\n      if (baked.get(h_1, w_1) ==\
    \ 1) baked.add(h_1, w_1, -1);\n    } else if (c == 2) {\n      int h_2, w_2;\n\
    \      std::cin >> h_2 >> w_2;\n      --h_2; --w_2;\n      std::cout << baked.sum(h_1,\
    \ w_1, h_2, w_2) << ' '\n                << unbaked.sum(h_1, w_1, h_2, w_2) <<\
    \ '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/fenwick_tree/2d_fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick tree"
---
