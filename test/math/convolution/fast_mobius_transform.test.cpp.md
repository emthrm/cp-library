---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/fast_mobius_transform.hpp
    title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (fast Mobius transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-7
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\
      \u30A6\u30B9\u5909\u63DB"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
  bundledCode: "#line 1 \"test/math/convolution/fast_mobius_transform.test.cpp\"\n\
    /*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446\"\
    \r\n#define ERROR \"1e-7\"\r\n\r\n#include <algorithm>\r\n#include <cmath>\r\n\
    #include <iomanip>\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#line 3\
    \ \"math/convolution/fast_mobius_transform.hpp\"\n\r\ntemplate <typename T>\r\n\
    std::vector<T> fast_mobius_transform(std::vector<T> a,\r\n                   \
    \                  const bool adds_superset, const T id = 0) {\r\n  int n = a.size(),\
    \ p = 1;\r\n  while ((1 << p) < n) ++p;\r\n  n = 1 << p;\r\n  a.resize(n, id);\r\
    \n  if (adds_superset) {\r\n    for (int i = 1; i < n; i <<= 1) {\r\n      for\
    \ (int s = 0; s < n; ++s) {\r\n        if (s & i) continue;\r\n        a[s] -=\
    \ a[s | i];\r\n      }\r\n    }\r\n  } else {\r\n    for (int i = 1; i < n; i\
    \ <<= 1) {\r\n      for (int s = 0; s < n; ++s) {\r\n        if (s & i) continue;\r\
    \n        a[s | i] -= a[s];\r\n      }\r\n    }\r\n  }\r\n  return a;\r\n}\r\n\
    #line 14 \"test/math/convolution/fast_mobius_transform.test.cpp\"\n\r\nint main()\
    \ {\r\n  int n;\r\n  long long m;\r\n  std::cin >> n >> m;\r\n  std::vector<long\
    \ long> a(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> a[i];\r\n\
    \  }\r\n  std::vector<double> p(n);\r\n  for (int i = 0; i < n; ++i) {\r\n   \
    \ std::cin >> p[i];\r\n    p[i] /= 100;\r\n  }\r\n  std::vector<long long> g(1\
    \ << n, 0);\r\n  for (int i = 1; i < (1 << n); ++i) {\r\n    long long l = 1;\r\
    \n    for (int j = 0; j < n; ++j) {\r\n      if (i >> j & 1) {\r\n        l /=\
    \ std::__gcd(l, a[j]);\r\n        if (l > m / a[j]) {\r\n          l = m + 1;\r\
    \n          break;\r\n        }\r\n        l *= a[j];\r\n      }\r\n    }\r\n\
    \    g[i] = m / l;\r\n  }\r\n  g = fast_mobius_transform(g, false);\r\n  double\
    \ ans = 0;\r\n  for (int bit = 0; bit < (1 << n); ++bit) {\r\n    double prob\
    \ = 1;\r\n    for (int i = 0; i < n; ++i) {\r\n      prob *= (bit >> i & 1 ? p[i]\
    \ : 1 - p[i]);\r\n    }\r\n    ans += prob * std::abs(g[bit]);\r\n  }\r\n  std::cout\
    \ << std::fixed << std::setprecision(8) << ans << '\\n';\r\n  return 0;\r\n}\r\
    \n"
  code: "/*\r\n * @brief \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB\r\n */\r\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446\"\
    \r\n#define ERROR \"1e-7\"\r\n\r\n#include <algorithm>\r\n#include <cmath>\r\n\
    #include <iomanip>\r\n#include <iostream>\r\n#include <vector>\r\n\r\n#include\
    \ \"../../../math/convolution/fast_mobius_transform.hpp\"\r\n\r\nint main() {\r\
    \n  int n;\r\n  long long m;\r\n  std::cin >> n >> m;\r\n  std::vector<long long>\
    \ a(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin >> a[i];\r\n  }\r\n\
    \  std::vector<double> p(n);\r\n  for (int i = 0; i < n; ++i) {\r\n    std::cin\
    \ >> p[i];\r\n    p[i] /= 100;\r\n  }\r\n  std::vector<long long> g(1 << n, 0);\r\
    \n  for (int i = 1; i < (1 << n); ++i) {\r\n    long long l = 1;\r\n    for (int\
    \ j = 0; j < n; ++j) {\r\n      if (i >> j & 1) {\r\n        l /= std::__gcd(l,\
    \ a[j]);\r\n        if (l > m / a[j]) {\r\n          l = m + 1;\r\n          break;\r\
    \n        }\r\n        l *= a[j];\r\n      }\r\n    }\r\n    g[i] = m / l;\r\n\
    \  }\r\n  g = fast_mobius_transform(g, false);\r\n  double ans = 0;\r\n  for (int\
    \ bit = 0; bit < (1 << n); ++bit) {\r\n    double prob = 1;\r\n    for (int i\
    \ = 0; i < n; ++i) {\r\n      prob *= (bit >> i & 1 ? p[i] : 1 - p[i]);\r\n  \
    \  }\r\n    ans += prob * std::abs(g[bit]);\r\n  }\r\n  std::cout << std::fixed\
    \ << std::setprecision(8) << ans << '\\n';\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - math/convolution/fast_mobius_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_mobius_transform.test.cpp
  requiredBy: []
  timestamp: '2022-02-16 22:30:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/convolution/fast_mobius_transform.test.cpp
layout: document
redirect_from:
- /verify/test/math/convolution/fast_mobius_transform.test.cpp
- /verify/test/math/convolution/fast_mobius_transform.test.cpp.html
title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\
  \u5909\u63DB"
---
