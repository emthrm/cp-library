---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/modint.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: math/twelvefold_way/bell_number/bell_number.hpp
    title: "\u30D9\u30EB\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
    document_title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\
      \u6570"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/twelvefold_way/bell_number/bell_number.hpp: line 6: #pragma once found\
    \ in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\
    \u30EB\u6570\n */\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_G\"\
    \n\n#include <iostream>\n\n#include \"../../../../math/modint.hpp\"\n#include\
    \ \"../../../../math/twelvefold_way/bell_number/bell_number.hpp\"\n\nint main()\
    \ {\n  using ModInt = MInt<0>;\n  ModInt::set_mod(1000000007);\n  int n, k;\n\
    \  std::cin >> n >> k;\n  std::cout << bell_number<0>(n, k) << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - math/modint.hpp
  - math/twelvefold_way/bell_number/bell_number.hpp
  isVerificationFile: true
  path: test/math/twelvefold_way/bell_number/bell_number.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/twelvefold_way/bell_number/bell_number.test.cpp
layout: document
redirect_from:
- /verify/test/math/twelvefold_way/bell_number/bell_number.test.cpp
- /verify/test/math/twelvefold_way/bell_number/bell_number.test.cpp.html
title: "\u6570\u5B66/\u5199\u50CF12\u76F8/\u30D9\u30EB\u6570/\u30D9\u30EB\u6570"
---
