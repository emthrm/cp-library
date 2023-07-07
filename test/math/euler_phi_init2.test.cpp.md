---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/euler_phi.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570 (Euler's totient\
      \ function)"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/euler_phi_init2.hpp
    title: "\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570 (Euler's totient\
      \ function) \u306E\u6570\u88682"
  - icon: ':heavy_check_mark:'
    path: include/emthrm/math/prime_sieve.hpp
    title: prime sieve
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    document_title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
      \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\
      2"
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/math/euler_phi_init2.test.cpp\"\n/*\n * @title \u6570\
    \u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\u30A4\u30E9\
    \u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682\n *\n * verification-helper:\
    \ PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\n */\n\
    \n#include <iostream>\n#include <vector>\n\n#line 1 \"include/emthrm/math/euler_phi.hpp\"\
    \n\n\n\n#include <cassert>\n\nnamespace emthrm {\n\nlong long euler_phi(long long\
    \ n) {\n  assert(n >= 1);\n  long long res = n;\n  for (long long i = 2; i * i\
    \ <= n; ++i) {\n    if (n % i == 0) [[unlikely]] {\n      res -= res / i;\n  \
    \    while (n % i == 0) n /= i;\n    }\n  }\n  return n > 1 ? res - res / n :\
    \ res;\n}\n\n}  // namespace emthrm\n\n\n#line 1 \"include/emthrm/math/euler_phi_init2.hpp\"\
    \n\n\n\n#include <numeric>\n#line 6 \"include/emthrm/math/euler_phi_init2.hpp\"\
    \n\n#line 1 \"include/emthrm/math/prime_sieve.hpp\"\n\n\n\n#line 6 \"include/emthrm/math/prime_sieve.hpp\"\
    \n\nnamespace emthrm {\n\ntemplate <bool GETS_ONLY_PRIME>\nstd::vector<int> prime_sieve(const\
    \ int n) {\n  std::vector<int> smallest_prime_factor(n + 1), prime;\n  std::iota(smallest_prime_factor.begin(),\
    \ smallest_prime_factor.end(), 0);\n  for (int i = 2; i <= n; ++i) {\n    if (smallest_prime_factor[i]\
    \ == i) [[unlikely]] prime.emplace_back(i);\n    for (const int p : prime) {\n\
    \      if (i * p > n || p > smallest_prime_factor[i]) break;\n      smallest_prime_factor[i\
    \ * p] = p;\n    }\n  }\n  return GETS_ONLY_PRIME ? prime : smallest_prime_factor;\n\
    }\n\n}  // namespace emthrm\n\n\n#line 8 \"include/emthrm/math/euler_phi_init2.hpp\"\
    \n\nnamespace emthrm {\n\nstd::vector<long long> euler_phi_init2(const long long\
    \ low,\n                                       const long long high) {\n  std::vector<long\
    \ long> phi(high - low), rem(high - low);\n  std::iota(phi.begin(), phi.end(),\
    \ low);\n  std::iota(rem.begin(), rem.end(), low);\n  long long root = 1;\n  while\
    \ ((root + 1) * (root + 1) < high) ++root;\n  for (const int p : prime_sieve<true>(root))\
    \ {\n    for (long long i = (low + p - 1) / p * p; i < high; i += p) {\n     \
    \ phi[i - low] -= phi[i - low] / p;\n      while (rem[i - low] % p == 0) rem[i\
    \ - low] /= p;\n    }\n  }\n  for (int i = 0; i < high - low; ++i) {\n    if (rem[i]\
    \ > 1) phi[i] -= phi[i] / rem[i];\n  }\n  return phi;\n}\n\n}  // namespace emthrm\n\
    \n\n#line 12 \"test/math/euler_phi_init2.test.cpp\"\n\nint main() {\n  constexpr\
    \ int L = 999000000, H = 1000000000;\n  const std::vector<long long> ans = emthrm::euler_phi_init2(L,\
    \ H + 1);\n  int n;\n  std::cin >> n;\n  std::cout << (n >= L ? ans[n - L] : emthrm::euler_phi(n))\
    \ << '\\n';\n  return 0;\n}\n"
  code: "/*\n * @title \u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\
    \u6570/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u8868\
    2\n *\n * verification-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\n\
    \ */\n\n#include <iostream>\n#include <vector>\n\n#include \"emthrm/math/euler_phi.hpp\"\
    \n#include \"emthrm/math/euler_phi_init2.hpp\"\n\nint main() {\n  constexpr int\
    \ L = 999000000, H = 1000000000;\n  const std::vector<long long> ans = emthrm::euler_phi_init2(L,\
    \ H + 1);\n  int n;\n  std::cin >> n;\n  std::cout << (n >= L ? ans[n - L] : emthrm::euler_phi(n))\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - include/emthrm/math/euler_phi.hpp
  - include/emthrm/math/euler_phi_init2.hpp
  - include/emthrm/math/prime_sieve.hpp
  isVerificationFile: true
  path: test/math/euler_phi_init2.test.cpp
  requiredBy: []
  timestamp: '2023-02-25 16:35:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/euler_phi_init2.test.cpp
layout: document
redirect_from:
- /verify/test/math/euler_phi_init2.test.cpp
- /verify/test/math/euler_phi_init2.test.cpp.html
title: "\u6570\u5B66/\u30AA\u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570/\u30AA\
  \u30A4\u30E9\u30FC\u306E $\\varphi$ \u95A2\u6570\u306E\u6570\u88682"
---
