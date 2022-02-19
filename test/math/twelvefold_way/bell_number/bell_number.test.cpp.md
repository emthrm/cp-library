---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':x:'
    path: math/twelvefold_way/bell_number/bell_number.hpp
    title: "\u30D9\u30EB\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\
      \u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/bell_number/bell_number.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\
    \u30EB\u6570\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G\"\
    \r\n\r\n#include <iostream>\r\n\r\n#include \"../../../../math/modint.hpp\"\r\n\
    #include \"../../../../math/twelvefold_way/bell_number/bell_number.hpp\"\r\n\r\
    \nint main() {\r\n  using ModInt = MInt<0>;\r\n  ModInt::set_mod(1000000007);\r\
    \n  int n, k;\r\n  std::cin >> n >> k;\r\n  std::cout << bell_number<0>(n, k)\
    \ << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/modint.hpp
  - math/twelvefold_way/bell_number/bell_number.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/bell_number/bell_number.test.cpp
  requiredBy: []
  timestamp: '2022-02-19 03:53:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/twelvefold_way/bell_number/bell_number.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/bell_number/bell_number.test.cpp
- /verify/test/math/twelvefold_way/bell_number/bell_number.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\u6570"
---
