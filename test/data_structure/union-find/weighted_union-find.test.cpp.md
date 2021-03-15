---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union-find/weighted_union-find.hpp
    title: "\u91CD\u307F\u3064\u304D union-find \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/\u91CD\u307F\
      \u3064\u304D union-find \u6728"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/weighted_union-find.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/\u91CD\u307F\
    \u3064\u304D union-find \u6728\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../data_structure/union-find/weighted_union-find.hpp\"\
    \r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  WeightedUnionFind<int>\
    \ uf(n);\r\n  while (q--) {\r\n    int query;\r\n    std::cin >> query;\r\n  \
    \  if (query == 0) {\r\n      int x, y, z;\r\n      std::cin >> x >> y >> z;\r\
    \n      uf.unite(x, y, z);\r\n    } else if (query == 1) {\r\n      int x, y;\r\
    \n      std::cin >> x >> y;\r\n      if (uf.same(x, y)) {\r\n        std::cout\
    \ << uf.diff(x, y) << '\\n';\r\n      } else {\r\n        std::cout << \"?\\n\"\
    ;\r\n      }\r\n    }\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - data_structure/union-find/weighted_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/weighted_union-find.test.cpp
  requiredBy: []
  timestamp: '2021-02-13 04:45:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union-find/weighted_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/weighted_union-find.test.cpp
- /verify/test/data_structure/union-find/weighted_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/\u91CD\u307F\u3064\u304D\
  \ union-find \u6728"
---
