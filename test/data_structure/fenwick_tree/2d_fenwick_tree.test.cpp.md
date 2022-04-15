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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/fenwick_tree/2d_fenwick_tree.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143\
    \ Fenwick tree\r\n */\r\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\
    \r\n\r\n#include <iostream>\r\n#include <tuple>\r\n#include <queue>\r\n\r\n#include\
    \ \"../../../data_structure/fenwick_tree/2d_fenwick_tree.hpp\"\r\n\r\nint main()\
    \ {\r\n  int h, w, t, q;\r\n  std::cin >> h >> w >> t >> q;\r\n  FenwickTree2D<int>\
    \ baked(h, w), unbaked(h, w);\r\n  std::queue<std::tuple<int, int, int>> que;\r\
    \n  while (q--) {\r\n    int t_i, c, h_1, w_1;\r\n    std::cin >> t_i >> c >>\
    \ h_1 >> w_1;\r\n    --h_1; --w_1;\r\n    while (!que.empty() && std::get<0>(que.front())\
    \ <= t_i) {\r\n      const int y = std::get<1>(que.front()), x = std::get<2>(que.front());\r\
    \n      que.pop();\r\n      unbaked.add(y, x, -1);\r\n      baked.add(y, x, 1);\r\
    \n    }\r\n    if (c == 0) {\r\n      unbaked.add(h_1, w_1, 1);\r\n      que.emplace(t_i\
    \ + t, h_1, w_1);\r\n    } else if (c == 1) {\r\n      if (baked.get(h_1, w_1)\
    \ == 1) baked.add(h_1, w_1, -1);\r\n    } else if (c == 2) {\r\n      int h_2,\
    \ w_2;\r\n      std::cin >> h_2 >> w_2;\r\n      --h_2; --w_2;\r\n      std::cout\
    \ << baked.sum(h_1, w_1, h_2, w_2) << ' '\r\n                << unbaked.sum(h_1,\
    \ w_1, h_2, w_2) << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/fenwick_tree/2d_fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 17:10:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp
- /verify/test/data_structure/fenwick_tree/2d_fenwick_tree.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/Fenwick tree/2\u6B21\u5143 Fenwick tree"
---
