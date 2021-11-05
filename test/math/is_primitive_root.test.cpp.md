---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euler_phi/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: math/is_primitive_root.hpp
    title: "\u539F\u59CB\u6839\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.hpp
    title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u4E8C\u5206\u7D2F\u4E57\u6CD5\
      , \u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: math/prime_factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3 (prime factorization)"
  - icon: ':heavy_check_mark:'
    path: util/xorshift.hpp
    title: xorshift
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1409
    document_title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
    links:
    - https://yukicoder.me/problems/no/1409
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/is_primitive_root.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A\r\n */\r\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1409\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n#include <vector>\r\n#include \"../../util/xorshift.hpp\"\
    \r\n#include \"../../math/is_primitive_root.hpp\"\r\n#include \"../../math/mod_pow.hpp\"\
    \r\n\r\nint main() {\r\n  int t;\r\n  std::cin >> t;\r\n  while (t--) {\r\n  \
    \  int v, x;\r\n    std::cin >> v >> x;\r\n    int p = v * x + 1, root = 0;\r\n\
    \    do {\r\n      root = xor128.rand(1, p);\r\n    } while (!is_primitive_root(root,\
    \ p));\r\n    long long xth_root = mod_pow(root, v, p);\r\n    std::vector<int>\
    \ a(x, 1);\r\n    for (int i = 1; i < x; ++i) a[i] = a[i - 1] * xth_root % p;\r\
    \n    std::sort(a.begin(), a.end());\r\n    for (int i = 0; i < x; ++i) std::cout\
    \ << a[i] << \" \\n\"[i + 1 == x];\r\n  }\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - util/xorshift.hpp
  - math/is_primitive_root.hpp
  - math/euler_phi/euler_phi.hpp
  - math/prime_factorization.hpp
  - math/mod_pow.hpp
  isVerificationFile: true
  path: test/math/is_primitive_root.test.cpp
  requiredBy: []
  timestamp: '2021-03-03 13:33:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/is_primitive_root.test.cpp
layout: document
redirect_from:
- /verify/test/math/is_primitive_root.test.cpp
- /verify/test/math/is_primitive_root.test.cpp.html
title: "\u6570\u5B66/\u539F\u59CB\u6839\u5224\u5B9A"
---
