---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc170/tasks/abc170_d
    document_title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
    links:
    - https://atcoder.jp/contests/abc170/tasks/abc170_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/fast_divisor.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7D04\u6570\u5217\u6319\r\n */\r\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc170/tasks/abc170_d\"\r\n\r\n#include <algorithm>\r\
    \n#include <iostream>\r\n#include <set>\r\n#include <vector>\r\n#include \"../../math/fast_divisor.hpp\"\
    \r\n\r\nint main() {\r\n  int n;\r\n  std::cin >> n;\r\n  std::vector<int> a(n);\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> a[i];\r\n  }\r\n  Divisor\
    \ divisor(*std::max_element(a.begin(), a.end()));\r\n  std::multiset<int> s(a.begin(),\
    \ a.end());\r\n  int ans = 0;\r\n  for (int i = 0; i < n; ++i) {\r\n    s.erase(s.lower_bound(a[i]));\r\
    \n    bool meets = true;\r\n    for (const int d : divisor.query(a[i])) {\r\n\
    \      meets &= s.find(d) == s.end();\r\n    }\r\n    ans += meets;\r\n    s.emplace(a[i]);\r\
    \n  }\r\n  std::cout << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/fast_divisor.test.cpp
  requiredBy: []
  timestamp: '2021-09-23 22:47:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/fast_divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/fast_divisor.test.cpp
- /verify/test/math/fast_divisor.test.cpp.html
title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
---
