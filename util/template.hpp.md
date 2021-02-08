---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ util/template.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\r\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\r\n */\r\n\r\n#pragma\
    \ once\r\n\r\n#define _USE_MATH_DEFINES\r\n#include <bits/stdc++.h>\r\nusing namespace\
    \ std;\r\n#define FOR(i,m,n) for(int i=(m);i<(n);++i)\r\n#define REP(i,n) FOR(i,0,n)\r\
    \n#define ALL(v) (v).begin(),(v).end()\r\nusing ll = long long;\r\nconstexpr int\
    \ INF = 0x3f3f3f3f;\r\nconstexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\r\nconstexpr\
    \ double EPS = 1e-8;\r\nconstexpr int MOD = 1000000007;\r\n// constexpr int MOD\
    \ = 998244353;\r\nconstexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};\r\n\
    constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0,\
    \ 1, 1, 1};\r\ntemplate <typename T, typename U> inline bool chmax(T &a, U b)\
    \ { return a < b ? (a = b, true) : false; }\r\ntemplate <typename T, typename\
    \ U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }\r\n\
    struct IOSetup {\r\n  IOSetup() {\r\n    std::cin.tie(nullptr);\r\n    std::ios_base::sync_with_stdio(false);\r\
    \n    std::cout << std::fixed << std::setprecision(20);\r\n  }\r\n} iosetup;\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: util/template.hpp
  requiredBy: []
  timestamp: '2021-02-09 04:38:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/template.hpp
layout: document
redirect_from:
- /library/util/template.hpp
- /library/util/template.hpp.html
title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
