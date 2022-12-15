---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: include/emthrm/misc/2-sat.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.16/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: emthrm/misc/2-sat.hpp:\
    \ line -1: no such header\n"
  code: "/*\n * @brief \u305D\u306E\u4ED6/2-SAT\n */\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"emthrm/misc/2-sat.hpp\"\
    \n\nint main() {\n  std::string p, cnf;\n  int n, m;\n  std::cin >> p >> cnf >>\
    \ n >> m;\n  emthrm::TwoSat two_sat(n);\n  while (m--) {\n    int a, b, zero;\n\
    \    std::cin >> a >> b >> zero;\n    if (a < 0) {\n      a = two_sat.negate(-a\
    \ - 1);\n    } else {\n      --a;\n    }\n    if (b < 0) {\n      b = two_sat.negate(-b\
    \ - 1);\n    } else {\n      --b;\n    }\n    two_sat.add_or(a, b);\n  }\n  const\
    \ std::vector<bool> ans = two_sat.build();\n  std::cout << \"s \";\n  if (ans.empty())\
    \ {\n    std::cout << \"UNSATISFIABLE\\n\";\n    return 0;\n  }\n  std::cout <<\
    \ \"SATISFIABLE\\nv \";\n  for (int i = 0; i < n; ++i) {\n    std::cout << (i\
    \ + 1) * (ans[i] ? 1 : -1) << ' ';\n  }\n  std::cout << \"0\\n\";\n  return 0;\n\
    }\n"
  dependsOn:
  - include/emthrm/misc/2-sat.hpp
  isVerificationFile: true
  path: test/misc/2-sat.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 22:18:37+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/2-sat.test.cpp
layout: document
redirect_from:
- /verify/test/misc/2-sat.test.cpp
- /verify/test/misc/2-sat.test.cpp.html
title: "\u305D\u306E\u4ED6/2-SAT"
---
