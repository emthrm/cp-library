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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ math/fast_divisor.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/*\n * @brief \u6570\u5B66/\u7D04\u6570\u5217\u6319\n */\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/abc170/tasks/abc170_d\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <set>\n#include <vector>\n\n#include \"../../math/fast_divisor.hpp\"\
    \n\nint main() {\n  int n;\n  std::cin >> n;\n  std::vector<int> a(n);\n  for\
    \ (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  const Divisor divisor(*std::max_element(a.begin(),\
    \ a.end()));\n  std::multiset<int> s(a.begin(), a.end());\n  int ans = 0;\n  for\
    \ (int i = 0; i < n; ++i) {\n    s.erase(s.lower_bound(a[i]));\n    bool meets\
    \ = true;\n    for (const int d : divisor.query(a[i])) {\n      meets &= s.find(d)\
    \ == s.end();\n    }\n    ans += meets;\n    s.emplace(a[i]);\n  }\n  std::cout\
    \ << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/fast_divisor.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 04:59:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/fast_divisor.test.cpp
layout: document
redirect_from:
- /verify/test/math/fast_divisor.test.cpp
- /verify/test/math/fast_divisor.test.cpp.html
title: "\u6570\u5B66/\u7D04\u6570\u5217\u6319"
---
