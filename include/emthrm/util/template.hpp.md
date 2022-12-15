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
  bundledCode: "#line 1 \"include/emthrm/util/template.hpp\"\n/**\n * @brief \u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n#define _USE_MATH_DEFINES\n#include <bits/stdc++.h>\n\
    using namespace std;\n#define FOR(i,m,n) for(int i=(m);i<(n);++i)\n#define REP(i,n)\
    \ FOR(i,0,n)\n#define ALL(v) (v).begin(),(v).end()\nusing ll = long long;\nconstexpr\
    \ int INF = 0x3f3f3f3f;\nconstexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\nconstexpr\
    \ double EPS = 1e-8;\nconstexpr int MOD = 998244353;\n// constexpr int MOD = 1000000007;\n\
    constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};\nconstexpr int DY8[]{1,\
    \ 1, 0, -1, -1, -1, 0, 1};\nconstexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};\n\
    template <typename T, typename U>\ninline bool chmax(T& a, U b) { return a < b\
    \ ? (a = b, true) : false; }\ntemplate <typename T, typename U>\ninline bool chmin(T&\
    \ a, U b) { return a > b ? (a = b, true) : false; }\nstruct IOSetup {\n  IOSetup()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \    std::cout << std::fixed << std::setprecision(20);\n  }\n} iosetup;\n"
  code: "/**\n * @brief \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n#define _USE_MATH_DEFINES\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define FOR(i,m,n) for(int i=(m);i<(n);++i)\n\
    #define REP(i,n) FOR(i,0,n)\n#define ALL(v) (v).begin(),(v).end()\nusing ll =\
    \ long long;\nconstexpr int INF = 0x3f3f3f3f;\nconstexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;\n\
    constexpr double EPS = 1e-8;\nconstexpr int MOD = 998244353;\n// constexpr int\
    \ MOD = 1000000007;\nconstexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};\nconstexpr\
    \ int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};\nconstexpr int DX8[]{0, -1, -1, -1, 0,\
    \ 1, 1, 1};\ntemplate <typename T, typename U>\ninline bool chmax(T& a, U b) {\
    \ return a < b ? (a = b, true) : false; }\ntemplate <typename T, typename U>\n\
    inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }\nstruct\
    \ IOSetup {\n  IOSetup() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \    std::cout << std::fixed << std::setprecision(20);\n  }\n} iosetup;\n"
  dependsOn: []
  isVerificationFile: false
  path: include/emthrm/util/template.hpp
  requiredBy: []
  timestamp: '2022-12-14 20:29:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/emthrm/util/template.hpp
layout: document
redirect_from:
- /library/include/emthrm/util/template.hpp
- /library/include/emthrm/util/template.hpp.html
title: "\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
