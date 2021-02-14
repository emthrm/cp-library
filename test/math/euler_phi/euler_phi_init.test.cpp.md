---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euler_phi/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: math/euler_phi/euler_phi_init.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    document_title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
      \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/euler_phi/euler_phi_init.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
    \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\
    \r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \r\n\r\n#include <iostream>\r\n#include <vector>\r\n#include \"../../../math/euler_phi/euler_phi_init.hpp\"\
    \r\n#include \"../../../math/euler_phi/euler_phi.hpp\"\r\n\r\nint main() {\r\n\
    \  constexpr int M = 1000000;\r\n  std::vector<int> ans = euler_phi_init(1000000);\r\
    \n  int n;\r\n  std::cin >> n;\r\n  std::cout << (n <= M ? ans[n] : euler_phi(n))\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/euler_phi/euler_phi_init.hpp
  - math/euler_phi/euler_phi.hpp
  isVerificationFile: true
  path: test/math/euler_phi/euler_phi_init.test.cpp
  requiredBy: []
  timestamp: '2021-02-12 01:21:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/euler_phi/euler_phi_init.test.cpp
layout: document
redirect_from:
- /verify/test/math/euler_phi/euler_phi_init.test.cpp
- /verify/test/math/euler_phi/euler_phi_init.test.cpp.html
title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
  \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868"
---