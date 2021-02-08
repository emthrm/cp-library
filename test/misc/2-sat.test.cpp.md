---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.hpp
    title: "\u8FBA"
  - icon: ':question:'
    path: graph/scc.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3 (strongly connected components)"
  - icon: ':x:'
    path: misc/2-sat.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    document_title: "\u305D\u306E\u4ED6/2-SAT"
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/edge.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u305D\u306E\u4ED6/2-SAT\r\n */\r\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \r\n\r\n#include <iostream>\r\n#include <string>\r\n#include <vector>\r\n#include\
    \ \"../../misc/2-sat.hpp\"\r\n\r\nint main() {\r\n  std::string p, cnf;\r\n  int\
    \ n, m;\r\n  std::cin >> p >> cnf >> n >> m;\r\n  TwoSat ts(n);\r\n  while (m--)\
    \ {\r\n    int a, b, zero;\r\n    std::cin >> a >> b >> zero;\r\n    if (a < 0)\
    \ {\r\n      a = ts.negate(-a - 1);\r\n    } else {\r\n      --a;\r\n    }\r\n\
    \    if (b < 0) {\r\n      b = ts.negate(-b - 1);\r\n    } else {\r\n      --b;\r\
    \n    }\r\n    ts.add_or(a, b);\r\n  }\r\n  std::vector<bool> ans = ts.build();\r\
    \n  std::cout << \"s \";\r\n  if (ans.empty()) {\r\n    std::cout << \"UNSATISFIABLE\\\
    n\";\r\n    return 0;\r\n  }\r\n  std::cout << \"SATISFIABLE\\nv \";\r\n  for\
    \ (int i = 0; i < n; ++i) std::cout << (i + 1) * (ans[i] ? 1 : -1) << ' ';\r\n\
    \  std::cout << \"0\\n\";\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - misc/2-sat.hpp
  - graph/edge.hpp
  - graph/scc.hpp
  isVerificationFile: true
  path: test/misc/2-sat.test.cpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/2-sat.test.cpp
layout: document
redirect_from:
- /verify/test/misc/2-sat.test.cpp
- /verify/test/misc/2-sat.test.cpp.html
title: "\u305D\u306E\u4ED6/2-SAT"
---
