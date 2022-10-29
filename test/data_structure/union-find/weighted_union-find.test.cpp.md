---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union-find/weighted_union-find.hpp
    title: "\u91CD\u307F\u3064\u304D union-find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u91CD\u307F\u3064\u304D\
      \ union-find"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/weighted_union-find.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u91CD\u307F\u3064\
    \u304D union-find\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <iostream>\n\n#include \"../../../data_structure/union-find/weighted_union-find.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  WeightedUnionFind<int>\
    \ union_find(n);\n  while (q--) {\n    int query;\n    std::cin >> query;\n  \
    \  if (query == 0) {\n      int x, y, z;\n      std::cin >> x >> y >> z;\n   \
    \   union_find.unite(x, y, z);\n    } else if (query == 1) {\n      int x, y;\n\
    \      std::cin >> x >> y;\n      if (union_find.is_same(x, y)) {\n        std::cout\
    \ << union_find.diff(x, y) << '\\n';\n      } else {\n        std::cout << \"\
    ?\\n\";\n      }\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/union-find/weighted_union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/weighted_union-find.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union-find/weighted_union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/weighted_union-find.test.cpp
- /verify/test/data_structure/union-find/weighted_union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/\u91CD\u307F\u3064\u304D union-find"
---
