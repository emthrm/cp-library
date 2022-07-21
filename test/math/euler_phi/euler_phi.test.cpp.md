---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/euler_phi/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    document_title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
      \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/euler_phi/euler_phi.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
    \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\n */\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\n\n#include\
    \ <iostream>\n#include \"../../../math/euler_phi/euler_phi.hpp\"\n\nint main()\
    \ {\n  int n;\n  std::cin >> n;\n  std::cout << euler_phi(n) << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - math/euler_phi/euler_phi.hpp
  isVerificationFile: true
  path: test/math/euler_phi/euler_phi.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/euler_phi/euler_phi.test.cpp
layout: document
redirect_from:
- /verify/test/math/euler_phi/euler_phi.test.cpp
- /verify/test/math/euler_phi/euler_phi.test.cpp.html
title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
  \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
---
