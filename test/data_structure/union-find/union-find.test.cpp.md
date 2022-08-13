---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data_structure/union-find/union-find.hpp
    title: union-find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    document_title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/union-find"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data_structure/union-find/union-find.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\n * @brief \u30C7\u30FC\u30BF\u69CB\u9020/union-find/union-find\n */\n\
    #define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include <iostream>\n\n#include \"../../../data_structure/union-find/union-find.hpp\"\
    \n\nint main() {\n  int n, q;\n  std::cin >> n >> q;\n  UnionFind union_find(n);\n\
    \  while (q--) {\n    int com, x, y;\n    std::cin >> com >> x >> y;\n    if (com\
    \ == 0) {\n      union_find.unite(x, y);\n    } else if (com == 1) {\n      std::cout\
    \ << union_find.is_same(x, y) << '\\n';\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - data_structure/union-find/union-find.hpp
  isVerificationFile: true
  path: test/data_structure/union-find/union-find.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union-find/union-find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union-find/union-find.test.cpp
- /verify/test/data_structure/union-find/union-find.test.cpp.html
title: "\u30C7\u30FC\u30BF\u69CB\u9020/union-find/union-find"
---
