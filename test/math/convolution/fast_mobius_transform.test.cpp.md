---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/convolution/fast_mobius_transform.hpp
    title: "\u9AD8\u901F\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (fast Mobius transform)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    ERROR: 1e-7
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
    document_title: "\u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\
      \u30A6\u30B9\u5909\u63DB"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446
  bundledCode: "#line 1 \"test/math/convolution/fast_mobius_transform.test.cpp\"\n\
    /*\n * @title \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\u30A6\
    \u30B9\u5909\u63DB\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446\n\
    \ * verification-helper: ERROR 1e-7\n */\n\n#include <cmath>\n#include <iomanip>\n\
    #include <iostream>\n#include <numeric>\n#include <vector>\n\n#line 1 \"include/emthrm/math/convolution/fast_mobius_transform.hpp\"\
    \n\n\n\n#include <bit>\n#line 6 \"include/emthrm/math/convolution/fast_mobius_transform.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <bool ADDS_SUPERSET, typename T>\nstd::vector<T>\
    \ fast_mobius_transform(std::vector<T> a, const T id = 0) {\n  const int n = std::bit_ceil(a.size());\n\
    \  a.resize(n, id);\n  for (int i = 1; i < n; i <<= 1) {\n    for (int s = 0;\
    \ s < n; ++s) {\n      if (s & i) continue;\n      if constexpr (ADDS_SUPERSET)\
    \ {\n        a[s] -= a[s | i];\n      } else {\n        a[s | i] -= a[s];\n  \
    \    }\n    }\n  }\n  return a;\n}\n\n}  // namespace emthrm\n\n\n#line 15 \"\
    test/math/convolution/fast_mobius_transform.test.cpp\"\n\nint main() {\n  int\
    \ n;\n  long long m;\n  std::cin >> n >> m;\n  std::vector<long long> a(n);\n\
    \  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n  std::vector<double>\
    \ p(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> p[i];\n    p[i] /= 100;\n\
    \  }\n  std::vector<long long> g(1 << n, 0);\n  for (int i = 1; i < (1 << n);\
    \ ++i) {\n    long long l = 1;\n    for (int j = 0; j < n; ++j) {\n      if (i\
    \ >> j & 1) {\n        l /= std::gcd(l, a[j]);\n        if (l > m / a[j]) {\n\
    \          l = m + 1;\n          break;\n        }\n        l *= a[j];\n     \
    \ }\n    }\n    g[i] = m / l;\n  }\n  g = emthrm::fast_mobius_transform<false>(g);\n\
    \  double ans = 0;\n  for (int bit = 0; bit < (1 << n); ++bit) {\n    double prob\
    \ = 1;\n    for (int i = 0; i < n; ++i) {\n      prob *= (bit >> i & 1 ? p[i]\
    \ : 1 - p[i]);\n    }\n    ans += prob * std::abs(g[bit]);\n  }\n  std::cout <<\
    \ std::fixed << std::setprecision(8) << ans << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u7573\u307F\u8FBC\u307F/\u9AD8\u901F\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2446\n\
    \ * verification-helper: ERROR 1e-7\n */\n\n#include <cmath>\n#include <iomanip>\n\
    #include <iostream>\n#include <numeric>\n#include <vector>\n\n#include \"emthrm/math/convolution/fast_mobius_transform.hpp\"\
    \n\nint main() {\n  int n;\n  long long m;\n  std::cin >> n >> m;\n  std::vector<long\
    \ long> a(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >> a[i];\n  }\n \
    \ std::vector<double> p(n);\n  for (int i = 0; i < n; ++i) {\n    std::cin >>\
    \ p[i];\n    p[i] /= 100;\n  }\n  std::vector<long long> g(1 << n, 0);\n  for\
    \ (int i = 1; i < (1 << n); ++i) {\n    long long l = 1;\n    for (int j = 0;\
    \ j < n; ++j) {\n      if (i >> j & 1) {\n        l /= std::gcd(l, a[j]);\n  \
    \      if (l > m / a[j]) {\n          l = m + 1;\n          break;\n        }\n\
    \        l *= a[j];\n      }\n    }\n    g[i] = m / l;\n  }\n  g = emthrm::fast_mobius_transform<false>(g);\n\
    \  double ans = 0;\n  for (int bit = 0; bit < (1 << n); ++bit) {\n    double prob\
    \ = 1;\n    for (int i = 0; i < n; ++i) {\n      prob *= (bit >> i & 1 ? p[i]\
    \ : 1 - p[i]);\n    }\n    ans += prob * std::abs(g[bit]);\n  }\n  std::cout <<\
    \ std::fixed << std::setprecision(8) << ans << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/convolution/fast_mobius_transform.hpp
  isVerificationFile: true
  path: test/math/convolution/fast_mobius_transform.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 01:48:23+09:00'
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
