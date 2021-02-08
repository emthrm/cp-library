---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: "union-find \u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/union-find \u6728"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/union-find.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/union-find\
    \ \u6728\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \r\n\r\n#include <iostream>\r\n#include \"../../../data_structure/union-find/union-find.hpp\"\
    \r\n\r\nint main() {\r\n  int n, q;\r\n  std::cin >> n >> q;\r\n  UnionFind uf(n);\r\
    \n  while (q--) {\r\n    int com, x, y;\r\n    std::cin >> com >> x >> y;\r\n\
    \    if (com == 0) {\r\n      uf.unite(x, y);\r\n    } else if (com == 1) {\r\n\
    \      std::cout << uf.same(x, y) << '\\n';\r\n    }\r\n  }\r\n  return 0;\r\n\
    }\r\n"
  dependsOn:
  - data_structure/union-find/union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/union-find.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union-find/union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/union-find.test.cpp
- /verify/test/data_structure/union-find/union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find \u6728/union-find \u6728"
---
